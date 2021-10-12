<html>
   <head>
      <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
      <title>Tabella di prova con BootStrap</title>
   </head>
   <body>
      <div class="container">
<?php
   /* TABELLA NEL DB
   CREATE TABLE persone(
      id integer auto_increment,
      cognome varchar(30),
      nome varchar(30),
      primary key(id)
   );
   */
   define("MYSQL_HOST", "localhost");
   define("MYSQL_USER", "root");          // in5a??
   define("MYSQL_PASSWORD", "");          // in5a??
   define("MYSQL_DB", "scuola2122");      // in5a??

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

   echo("<table class=\"table table-dark table-striped table-hover\">
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


   // Step 5 - Chiusura del collegamento con il db.
   $db->close();
?>
      </div>
   <!-- chiusura del body con inserimento richiami BootStrap -->
   <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
   <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
   <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
   </body>
</html>