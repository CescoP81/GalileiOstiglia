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

      case "formModifica":{
         // recupero dal vettore request l'id della persona selezionata.
         $idp = $_REQUEST['id_persona'];
         
         // aggancio al database e recupero dei dati presenti per il determinato id.
         $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);

         // interrogo il db e recupero i dati della persona.
         $sql = "SELECT * FROM persone WHERE id=$idp";
         $result = $db->query($sql);
         $record = $result->fetch_assoc();

         // stampa di verifica estrazione dati.
         //echo($record['nome']." ".$record['cognome']);

         // costruzione del form inserimento pre-compilato.
         echo("<form action=\"personeTable.php\" method=\"post\">
            <label for=\"campo_1\" class=\"form-label\">Cognome:</label>
            <input class=\"form-control\" type=\"text\" id=\"campo_1\" name=\"cognomeP\" value=\"".$record['cognome']."\" aria-label=\"default input example\">
            <label for=\"campo_2\" class=\"form-label\">Nome:</label>
            <input class=\"form-control\" type=\"text\" id=\"campo_2\" name=\"nomeP\" value=\"".$record['nome']."\" aria-label=\"default input example\">
            
            <input type=\"hidden\" name=\"scelta\" value=\"updatePersona\">
            <input type=\"hidden\" name=\"id_persona\" value=\"$idp\">
            <br />
            <button type=\"submit\" class=\"btn btn-primary\">Aggiorna dati Persona</button>
            </form>");

         $db->close();
         break;
      }

      case "updatePersona":{
         // recupero i dati dal vettore request e li metto i variabili semplici.
         $idp = $_REQUEST['id_persona'];
         $nome = $_REQUEST['nomeP'];
         $cognome = $_REQUEST['cognomeP'];

         // aggancio al db
         $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);

         // creo la query di UPDATE
         $sql = "UPDATE persone SET cognome='$cognome', nome='$nome' WHERE id=$idp";
         echo($sql);
         echo("<br><br>");

         if($db->query($sql))
            echo("Persona aggiornata correttamente.");
         else
            echo("Problema in fase di update.");
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
                     <td>
                        <a href=\"personeTable.php?scelta=deleteRecord&id_persona=".$record['id']."\">Delete</a> | 
                        <a href=\"personeTable.php?scelta=formModifica&id_persona=".$record['id']."\">
                        <svg xmlns=\"http://www.w3.org/2000/svg\" width=\"16\" height=\"16\" fill=\"currentColor\" class=\"bi bi-pen\" viewBox=\"0 0 16 16\">
                           <path d=\"m13.498.795.149-.149a1.207 1.207 0 1 1 1.707 1.708l-.149.148a1.5 1.5 0 0 1-.059 2.059L4.854 14.854a.5.5 0 0 1-.233.131l-4 1a.5.5 0 0 1-.606-.606l1-4a.5.5 0 0 1 .131-.232l9.642-9.642a.5.5 0 0 0-.642.056L6.854 4.854a.5.5 0 1 1-.708-.708L9.44.854A1.5 1.5 0 0 1 11.5.796a1.5 1.5 0 0 1 1.998-.001zm-.644.766a.5.5 0 0 0-.707 0L1.95 11.756l-.764 3.057 3.057-.764L14.44 3.854a.5.5 0 0 0 0-.708l-1.585-1.585z\"/>
                        </svg></a>
                  </tr>");
                  $record = $rs->fetch_assoc();
               }      
            echo("</tbody>");
            echo("<caption>Tabella 'persone' su DB scuola2021</caption>");
         echo("</table>");

         // Step 5 - Chiusura del collegamento con il db.
         $db->close();
         break;
      }
   }

require("../foot.html");
?>