<?php
require("../funzioni.php");
require("../head.html");


/* Creo la barra di navigazione per la pagina di gestione tabella 'persone'*/
echo("<ul class=\"nav\">
  <li class=\"nav-item\">
    <a class=\"nav-link\" aria-current=\"page\" href=\"personeTable.php\">Visualizza Lista Persone</a>
  </li>
  <li class=\"nav-item\">
    <a class=\"nav-link\" href=\"personeTable.php?scelta=formPersona\">Aggiungi Persona</a>
  </li>
</ul>");

   /* scrivo il codice php con la switch-case e relativi spezzoni di codice per le diverse operazioni.*/
   if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
   else $sc = null;
   
   switch($sc){
      case "formPersona":{
         echo("<form action=\"personeTable.php\" method=\"post\">
            Cognome:
            <input class=\"form-control\" type=\"text\" name=\"cognomeP\" placeholder=\"Default input\" aria-label=\"default input example\">
            Nome:
            <input class=\"form-control\" type=\"text\" name=\"nomeP\" placeholder=\"Default input\" aria-label=\"default input example\">
            <input type=\"hidden\" name=\"scelta\" value=\"addPersona\">
            <button type=\"submit\" class=\"btn btn-primary\">Aggiungi al Database</button>
            </form>");
         break;
      }

      case "addPersona":{
         $nome = $_REQUEST['nomeP'];
         $cognome = $_REQUEST['cognomeP'];

         $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);
         $sql = "INSERT INTO persone(cognome, nome) VALUES('$cognome', '$nome')";

         //echo($sql);
         if($db->query($sql))
            echo("Inserimento avvenuto!");
         else
            echo("Problemi in inserimento record.");
         $db->close();
         break;
      }

      default:{
         $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);
         $sql = "SELECT * FROM persone";
         $rs = $db->query($sql);

         echo("<table class=\"table table-success table-striped table-hover\">
            <thead>
               <tr>
                  <th scope=\"col\">#</th>
                  <th scope=\"col\">Nome</th>
                  <th scope=\"col\">Cognome</th>
               </tr>
            </thead>");
            echo("<tbody>");
               $record = $rs->fetch_assoc();
               while($record){
                  //echo($record['id']." ".$record['cognome']." ".$record['nome']."<br />");
                  echo("<tr>
                     <th scope=\"row\">".$record['id']."</th>
                     <td>".$record['nome']."</td>
                     <td>".$record['cognome']."</td>
                  </tr>");
                  $record = $rs->fetch_assoc();
               }      
            echo("</tbody>");
         echo("</table>");
         echo("<button type=\"button\" class=\"btn btn-success\">Invia Feedback</button>");
         echo("<button type=\"button\" class=\"btn btn-outline-success\">Invia Feedback</button>");

         // Step 5 - Chiusura del collegamento con il db.
         $db->close();
         break;
      }
   }

require("../foot.html");
?>