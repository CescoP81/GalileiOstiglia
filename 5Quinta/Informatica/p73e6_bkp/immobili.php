<?php
/* Questa pagina è dedicata alla gestione degli immobili, le operazioni che compie sono:
   - Visualizzazione del form per inserire un nuovo immobile.
      - Inserimento di un nuovo immobile nella rispettiva tabella
   - Visualizzazione di tutti gli immobili presenti nel database.
*/
session_start();
if(isset($_REQUEST['sc'])) $sc = $_REQUEST['sc']; else $sc=null;
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;

require("require/funzioni.php");   // contiene funzioni sviluppate per le diverse pagine.
require("require/openPage.php");   // contiene il codice HTML standard di apertura di ogni pagina.

if($_SESSION['loggato']){
   writeMenu();

   switch($sc){
      case "nuovoImmobile":{
         echo("
            <div class=\"alert alert-danger\">Form di insermento nuovo Immobile</div>
            <form action=\"immobili.php\" method=\"get\">
               <div class=\"container\">
                  <div class=\"row\">
                     <div class=\"col-6\">
                        <div class=\"mb-3\">
                           <label for=\"inNome\" class=\"form-label\">Nome:</label>
                           <input class=\"form-control\" type=\"text\" name=\"nome\" id=\"inNome\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                     <div class=\"col-5\">
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
                  </div>

                  <div class=\"row\">
                     <div class=\"col\">
                        <div class=\"mb-3\">
                           <label for=\"inCitta\" class=\"form-label\">Metratura:</label>
                           <input class=\"form-control\" type=\"text\" name=\"metratura\" id=\"inMetratura\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>                     
                     <div class=\"col\">
                        <div class=\"mb-3\">
                           <label for=\"inPiano\" class=\"form-label\">Piano:</label>
                           <input class=\"form-control\" type=\"text\" name=\"piano\" id=\"inPiano\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                     <div class=\"col\">
                        <div class=\"mb-3\">
                           <label for=\"inLocali\" class=\"form-label\">Locali:</label>
                           <input class=\"form-control\" type=\"text\" name=\"locali\" id=\"inLocali\" placeholder=\"\" aria-label=\"default input example\">
                        </div>
                     </div>
                  </div>

                  <div class=\"row\">
                     <div class=\"col\">
                        <div class=\"mb-3\">
                           <label for=\"inZona\" class=\"form-label\">Zona Cittadina:</label>
                           <select class=\"form-select\" name=\"zona\" id=\"inZona\" aria-label=\"Default select example\">");
                              $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
                              $sql = "SELECT * FROM p73e6_zona";
                              $rs = $db->query($sql);
                              while($record = $rs->fetch_assoc())
                                 echo("<option value=\"".$record['id']."\">".$record['nome']."</option>");
                              $db->close();
                           echo("</select>
                        </div>
                     </div>
                     <div class=\"col\">
                        <div class=\"mb-3\">
                           <label for=\"inTipologia\" class=\"form-label\">Tipologia Immobile:</label>
                           <select class=\"form-select\" name=\"tipologia\" id=\"inTipologia\" aria-label=\"Default select example\">");
                           $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
                              $sql = "SELECT * FROM p73e6_tipologia";
                              $rs = $db->query($sql);
                              while($record = $rs->fetch_assoc())
                                 echo("<option value=\"".$record['id']."\">".$record['nome']."</option>");
                              $db->close();
                           echo("</select>
                        </div>                      
                     </div>
                  </div>

                  <div class=\"row\">
                     <div class=\"col\">
                        <input type=\"hidden\" name=\"sc\" value=\"addImmobile\">
                        <button type=\"submit\" class=\"btn btn-primary\">Inserisci</button>
                     </div>
                  </div>
               </div>
         </form>");
         break;
      }
      case "addImmobile":{
         $nome = $_REQUEST['nome'];
         $via = $_REQUEST['via'];
         $civico = $_REQUEST['civico'];
         $metratura = $_REQUEST['metratura'];
         $piano = $_REQUEST['piano'];
         $locali = $_REQUEST['locali'];
         $zona = $_REQUEST['zona'];
         $tipologia = $_REQUEST['tipologia'];

         $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
         $sql = "INSERT INTO p73e6_immobile(nome, via, civico, metratura, piano, locali, idZona, idTipologia)
               VALUES('$nome', '$via', $civico, $metratura, $piano, $locali, $zona, $tipologia)";
         if($db->query($sql))
            echo("<div class=\"alert alert-success\" role=\"alert\">Immobile Aggiunto.</div>");
         else
            echo("<div class=\"alert alert-danger\" role=\"alert\">Problema.</div>");
         $db->close();
         
         break;
      }
      case "listaImmobili":{
         $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
         $sql = "SELECT i.id, i.nome, i.via, i.civico, i.metratura, i.piano, i.locali, z.nome AS zona, t.nome AS tipologia
                  FROM p73e6_immobile AS i, p73e6_zona AS z, p73e6_tipologia AS t
                  WHERE i.idZona=z.id AND i.idTipologia=t.id";
         $rs = $db->query($sql);
         showResultTable($rs, "Lista degli Immobili");
         $db->close();
         break;
      }
      default:{
      }
   }
}
require("require/closePage.php"); // contiene il codice HTML standard di chiusura di ogni pagina.
?>