<?php
/* Questa pagina è dedicata alla gestione di proprietari, le operazioni che compie sono:
   - Visualizzazione del form per inserire un nuovo proprietario.
      - Inserimento di un nuovo proprietario nella rispettiva tabella
   - Visualizzazione di tutti i proprietari presenti nel database.
*/
session_start();
if(isset($_REQUEST['sc'])) $sc = $_REQUEST['sc']; else $sc=null;
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;

require("require/funzioni.php");   // contiene funzioni sviluppate per le diverse pagine.
require("require/openPage.php");   // contiene il codice HTML standard di apertura di ogni pagina.

if($_SESSION['loggato']){
   writeMenu();

   switch($sc){
      // visualizza il form di inserimento dati di un nuovo proprietario.
      case "nuovoProprietario":{
         echo("
            <div class=\"alert alert-success\">Form di insermento nuovo Proprietario</div>
            <form action=\"proprietari.php\" method=\"get\">
               <div class=\"container\">
                  <div class=\"row\">
                     <div class=\"col-6\">
                        <div class=\"mb-3\">
                           <label for=\"inCognome\" class=\"form-label\">Cognome:</label>
                           <input class=\"form-control\" type=\"text\" name=\"cognome\" id=\"inCognome\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                     <div class=\"col-6\">
                        <div class=\"mb-3\">
                           <label for=\"inNome\" class=\"form-label\">Nome:</label>
                           <input class=\"form-control\" type=\"text\" name=\"nome\" id=\"inNome\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                  </div>

                  <div class=\"row\">
                     <div class=\"col-6\">
                        <div class=\"mb-3\">
                           <label for=\"inVia\" class=\"form-label\">Via:</label>
                           <input class=\"form-control\" type=\"text\" name=\"via\" id=\"inVia\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                     <div class=\"col-1\">
                        <div class=\"mb-3\">
                           <label for=\"inCivico\" class=\"form-label\">Civico:</label>
                           <input class=\"form-control\" type=\"text\" name=\"civico\" id=\"inCivico\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                     <div class=\"col-5\">
                        <div class=\"mb-3\">
                           <label for=\"inCitta\" class=\"form-label\">Città:</label>
                           <input class=\"form-control\" type=\"text\" name=\"citta\" id=\"inCitta\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                  </div>

                  <div class=\"row\">
                     <div class=\"col-6\">
                        <div class=\"mb-3\">
                           <label for=\"inTelefono\" class=\"form-label\">Telefono:</label>
                           <input class=\"form-control\" type=\"text\" name=\"telefono\" id=\"inTelefono\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                     <div class=\"col-6\">
                        <div class=\"mb-3\">
                           <label for=\"inMail\" class=\"form-label\">Mail:</label>
                           <input class=\"form-control\" type=\"text\" name=\"mail\" id=\"inMail\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                  </div>

                  <div class=\"row\">
                     <div class=\"col\">
                        <input type=\"hidden\" name=\"sc\" value=\"addProprietario\">
                        <button type=\"submit\" class=\"btn btn-primary\">Inserisci</button>
                     </div>
                  </div>
               </div>
         </form>");
         break;
      }
      // aggiunge un proprietario alla relativa tabella nel database.
      case "addProprietario":{
         $cognome = $_REQUEST['cognome'];
         $nome =$_REQUEST['nome'];
         $via = $_REQUEST['via'];
         $civico = $_REQUEST['civico'];
         $citta = $_REQUEST['citta'];
         $telefono = $_REQUEST['telefono'];
         $mail = $_REQUEST['mail'];

         $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
            $sql = "INSERT INTO p73e6_proprietario(cognome, nome, via, civico, citta, telefono, mail) 
                  VALUES('$cognome', '$nome', '$via', $civico, '$citta', '$telefono', '$mail')";
            echo($sql);
            if($db->query($sql))
               echo("<div class=\"alert alert-success\" role=\"alert\">Proprietario Aggiunto.</div>");
            else
               echo("<div class=\"alert alert-danger\" role=\"alert\">Problema.</div>");
         $db->close();
         break;
      }
      // Visualizza la lista dei proprietari esistenti in una tabella.
      case "listaProprietari":{
         $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
         $sql = "SELECT * FROM p73e6_proprietario";
         $rs = $db->query($sql);
         showResultTable($rs, "Lista dei Proprietari", "proprietari.php", "mostraDettagli");
         $db->close();
         break;
      }
      case "mostraDettagli":{
         $idR = $_REQUEST['idRecord'];
         $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
         $sql = "SELECT * FROM p73e6_proprietario WHERE id=$idR";
         $rs = $db->query($sql);
         echo("<div class=\"alert alert-success\">Anagrafica del proprietario</div>");
         showResultTable($rs, "Anagrafica del Proprietario");
         echo("<br />");

         // Visualizzo i dati dell'immobile, per la zona e la tipologia recupero anche i rispettivi nomi nelle loro tabelle.
         $sql = "SELECT i.id, i.nome, i.via, i.civico, i.metratura, i.piano, i.locali, t.nome AS tipologia, z.nome AS zona, po.data_acquisto AS 'Data Acquisto'
                  FROM p73e6_immobile AS i, p73e6_possiede AS po, p73e6_proprietario AS pr,  p73e6_zona AS z, p73e6_tipologia AS t
                  WHERE pr.id=po.idProprietario AND po.idImmobile=i.id AND pr.id=$idR AND i.idZona=z.id AND i.idTipologia=t.id";
         //echo($sql);
         $rs = $db->query($sql);
         echo("<div class=\"alert alert-danger\">Immobili del proprietario</div>");
         showResultTable($rs, "Immobili del proprietario");
         echo("<br />");

         // Visualizzo il form di inserimento di una nuova associazione Proprietario<->Immobile
         echo("<div class=\"alert alert-info\">Associa nuovo immobile</div>");
         echo("<form action=\"proprietari.php\" method=\"get\">
            <div class=\"row\">
               <div class=\"col\">
                  <div class=\"mb-3\">
                     <label for=\"Zona\" class=\"form-label\">Zona:</label>
                     <select id=\"Zona\" name=\"idZona\">
                        <option value=\"0\">Select all City Zone</option>
                     </select>
                  </div>
               </div>
               <div class=\"col\">
                  <div class=\"mb-3\">
                     <label for=\"Immobile\" class=\"form-label\">Immobile:</label>
                     <select id=\"Immobile\" name=\"idImmobile\"></select>
                  </div>
               </div>
               <div class=\"col\">
                  <input type=\"hidden\" name=\"idProprietario\" value=\"".$idR."\">
                  <input type=\"hidden\" name=\"sc\" value=\"addPossiede\">
                  <input type=\"submit\" class=\"btn btn-primary\" value=\"Assegna Immobile\">
               </div>
            </div>
            </form>
         ");        
         $db->close();
         break;
      }
      case "addPossiede":{
         // Case che riceve l'ID di un proprietario e di un immobile quindi crea un nuovo record nella tabella POSSIEDE
         $idP = $_REQUEST['idProprietario'];
         $idI = $_REQUEST['idImmobile'];
         $oggi = date("Y/m/d");

         $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
         // controllo se esiste già un'associazione uguale prorietario-immobile
         $sql = "SELECT id 
                  FROM p73e6_possiede
                  WHERE idProprietario=$idP AND idImmobile=$idI";
         $rs = $db->query($sql);
         // se non ne esistono allora la creo, altrimento visualizzo un messaggio di errore.
         if($rs->num_rows == 0){
            $sql = "INSERT INTO p73e6_possiede(data_acquisto, idProprietario, idImmobile)
                  VALUES('$oggi', $idP, $idI)";
            //echo($sql);
            if($db->query($sql))
               echo("<div class=\"alert alert-success\">Nuovo acquisto completato.</div>");
            else
               echo("<div class=\"alert alert-danger\">Acquisto non completato.</div>");
         }
         else{
            echo("<div class=\"alert alert-danger\">ATTENZIONE: Questo immobile è già posseduto dallo stesso proprietario.</div>");
         }        
         echo("<a href=\"proprietari.php?sc=mostraDettagli&idRecord=$idP\"><input type=\"button\" class=\"btn btn-primary\"value=\"Back\"></a>");
         $db->close();
         break;
      }
      default:{

      }
   }
}
require("require/closePage.php"); // contiene il codice HTML standard di chiusura di ogni pagina.
?>