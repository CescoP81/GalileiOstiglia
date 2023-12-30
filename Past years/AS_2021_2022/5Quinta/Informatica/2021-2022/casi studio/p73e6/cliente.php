<?php
/**
 * La pagina cliente.php permette ad un proprietario loggato di vedere la propria anagrafica e lo
 * stato dei propri immobili.
 * Dalla tabella degli immobili è possibile anche produrre un PDF con il riepilogo; la pagina che produce il
 * PDF è nella cartella /cliente/pdfImmobili.php
 */
session_start();
if(isset($_REQUEST['sc'])) $sc = $_REQUEST['sc']; else $sc=null;
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;

require("require/funzioni.php");   // contiene funzioni sviluppate per le diverse pagine.
require("require/openPage.php");   // contiene il codice HTML standard di apertura di ogni pagina.

if($sc == "login"){ // se arrivo dal form di autenticazione
   $username = $_REQUEST['username'];
   $password = $_REQUEST['password'];

   $sql = "SELECT id, cognome, nome 
      FROM p73e6_proprietario 
      WHERE mail='$username' AND passwd='".md5($password)."'";
   $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
   $rs = $db->query($sql);
   $db->close();
   if($rs->num_rows == 1){
      $record = $rs->fetch_assoc();
      $_SESSION['loggato'] = true;
      $_SESSION['idProprietario'] = $record['id'];
      $_SESSION['cognomeProprietario'] = $record['cognome'];
      $_SESSION['nomeProprietario'] = $record['nome'];
   }
   else{
      echo("
         <div class=\"alert alert-danger\" role=\"alert\">
            Credenziali non valide.
         </div>");
      $_SESSION['loggato'] = false;
   }
}
if($sc == "logout"){ // se dal menu di navigazione viene chiesto il logout.
   $_SESSION['loggato'] = false;
}

if($_SESSION['loggato'] == true){ // se sono loggato visualizzo il menu operativo e l'interfaccia.
   echo("<div class=\"alert alert-success\">Proprietario: ".$_SESSION['nomeProprietario']." ".$_SESSION['cognomeProprietario']."
      <a href=\"cliente.php?sc=logout\"><button type=\"button\" class=\"btn btn-link btn-sm\">Logout</button></a>
   </div>");
   $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
   echo("<div class=\"row\">
      <div class=\"col col-4\">");
         $sql = "SELECT * FROM p73e6_proprietario WHERE id=".$_SESSION['idProprietario'];
         $rs = $db->query($sql);
         $record = $rs->fetch_assoc();
         echo("<div class=\"alert alert-primary\">Anagrafica</div>");
         echo($record['cognome']." ".$record['nome']."<br />");
         echo($record['via']." nr. ".$record['civico']." ".$record['citta']."<br />");
         echo($record['telefono']." ".$record['mail']."<br />");
      echo("</div>");

      echo("<div class=\"col col-8\">");
         echo("<div class=\"alert alert-primary\">Lista Immobili</div>");
         $sql = "SELECT i.nome AS 'Immobile', i.via, i.civico, i.metratura, i.piano, i.locali, 
            z.nome AS 'Zona', t.nome AS 'Tipologia' 
            FROM p73e6_immobile AS i, p73e6_zona AS z, p73e6_tipologia AS t, p73e6_possiede AS p 
            WHERE p.idProprietario='".$_SESSION['idProprietario']."' 
               AND p.idImmobile=i.id
               AND i.idZona=z.id AND i.idTipologia = t.id";
         $rs = $db->query($sql);
         showResultTable($rs, "");
         echo("<a href=\"cliente\pdfImmobili.php?idProprietario=".$_SESSION['idProprietario']."\" target=\"_blank\"><button type=\"button\" class=\"btn btn-outline-primary\">Stampa PDF</button></a>");
      echo("</div>");
   echo("</div>");
}else{ // se non sono loggato mostro il form per il login.
   showLoginForms();
}
require("require/closePage.php"); // contiene il codice HTML standard di chiusura di ogni pagina.
?>