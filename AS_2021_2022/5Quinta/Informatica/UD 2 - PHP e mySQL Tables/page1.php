<html>
   <head>
   <!--
      Riferimento alla guida ufficiale BootStrap versione 5.1 
      https://getbootstrap.com/docs/5.1/getting-started/introduction/
   -->
   <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
      <title>Tabella di prova con BootStrap</title>
   </head>
   <body>
      <div class="container">
<?php
require("../funzioni.php");
   /* TABELLA NEL DB
   CREATE TABLE persone(
      id integer auto_increment,
      cognome varchar(30),
      nome varchar(30),
      primary key(id)
   );
   */
   

   // step 1 - CREARE COLLEGAMENTO TRA PHP E MYSQL
   // UTILIZZANDO UN OGGETTO MYSQLI
   $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);

   // Step 2 - Creo la sintassi SQL per la Query
   $sql = "SELECT * FROM persone";

   // Step 3 - Eseguo la query utilizzando l'oggeto db
   // $rs -> ResultSet -> Insieme dei record che soddifano la query in caso positivo.
   $rs = $db->query($sql);

   // Step 4 - Sfoglio/estrapolazione dei risultati
   $record = $rs->fetch_assoc();
   while($record){
      echo($record['id']." ".$record['cognome']." ".$record['nome']."<br />");
      $record = $rs->fetch_assoc();
   }
   

   // VISUALIZZO GLI STESSI DATI DI PRIMA IN FORMATO TABELLA BOOTSTRAP
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
?>
      </div>
   <!-- chiusura del body con inserimento richiami BootStrap Boundle JS -->
   <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
   </body>
</html>