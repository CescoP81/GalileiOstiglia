<?php
require("../funzioni.php");
require("../head.html");

/* Creo la barra di navigazione per la pagina di gestione tabella 'persone'*/
echo("<ul class=\"nav\">
  <li class=\"nav-item\"><a class=\"nav-link\" aria-current=\"page\" href=\"personeTable.php\">Visualizza Lista Persone</a></li>
  <li class=\"nav-item\"><a class=\"nav-link\" href=\"personeTable.php?scelta=formPersona\">Aggiungi Persona</a></li>
</ul>");

   /* scrivo il codice php con la switch-case e relativi spezzoni di codice per le diverse operazioni.*/
   if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
   else $sc = null;
   
   switch($sc){
      /* Il case formPersona semplicemente visualizza il form con componenti bootstrap per inserire due stringhe,
      associate al cognome e nome di una persona. Rispetto all'esempio base presente su bootstrap, sono aggiunti
      gli attributi 'name' nei componenti input, mentre action e method nell'apertura del form.
      */
      case "formPersona":{
         echo("<form action=\"personeTable.php\" method=\"post\">
            <label for=\"campo_1\" class=\"form-label\">Cognome:</label>
            <input class=\"form-control\" type=\"text\" id=\"campo_1\" name=\"cognomeP\" placeholder=\"Default input\" aria-label=\"default input example\">
            <label for=\"campo_2\" class=\"form-label\">Nome:</label>
            <input class=\"form-control\" type=\"text\" id=\"campo_2\" name=\"nomeP\" placeholder=\"Default input\" aria-label=\"default input example\">
            <input type=\"hidden\" name=\"scelta\" value=\"addPersona\">
            <br />
            <button type=\"submit\" class=\"btn btn-primary\">Aggiungi al Database</button>
            </form>");
         break;
      }

      /* Il case addPersona viene utilizzato quando la pagina è richiamata dal FORM di inserimento dati.
      In quel caso nella barra dell'indirizzo avremo le variabili scelta, nomeP e cognomeP da utilizzare 
      per la creazione della query SQL di inserimento di un nuovo record. Vedremo in un secondo momento
      come gestire l'eventualità che l'utente non inserisca il cognome o il nome e quindi avremmo un'anomalia
      in fase di inserimento dati.
      */
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

      case "deleteRecord":{
         // step 1: recupero l'id della persona che voglio cancellare -> PK del record.
         $idp = $_REQUEST['id_persona'];
         echo("Voglio cancellare la persona con PK: $idp");

         // step 2: mi collego al db.
         $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);

         // step 3: creo la stringa sql per la cancellazione.
         $sql = "DELETE FROM persone WHERE id=$idp";
         echo("<br>$sql");

         // step 4: eseguo la query sul db
         if($db->query($sql))
            echo("Cancellazione avvenuta con successo.");
         else
            echo("Problema in cancellazione.");

         $db->close();
         break;
      }

      /* Il case di default, cioè quando scelta non è definito nell'indirizzo HTTP di chiamata, oppure
      contiene un valore non valido per lo script, visualizza la tabella 'persone' del database.
      Possiamo far fare qualunque cosa al default, importante è gestire il caso anomalo in cui 'scelta' non sia definita.
      */
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
                  <th scope=\"col\">Gestione</th>
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
                     <td><a href=\"personeTable.php?scelta=deleteRecord&id_persona=".$record['id']."\">Delete</a>
                  </tr>");
                  $record = $rs->fetch_assoc();
               }      
            echo("</tbody>");
         echo("</table>");
         /*echo("<button type=\"button\" class=\"btn btn-success\">Invia Feedback</button>");
         echo("<button type=\"button\" class=\"btn btn-outline-success\">Invia Feedback</button>");
         */

         // Step 5 - Chiusura del collegamento con il db.
         $db->close();
         break;
      }
   }

require("../foot.html");
?>