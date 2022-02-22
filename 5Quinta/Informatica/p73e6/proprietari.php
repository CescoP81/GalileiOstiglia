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
         showResultTable($rs, "Lista dei Proprietari");
         $db->close();
         break;
      }
      default:{

      }
   }
}
require("require/closePage.php"); // contiene il codice HTML standard di chiusura di ogni pagina.
?>