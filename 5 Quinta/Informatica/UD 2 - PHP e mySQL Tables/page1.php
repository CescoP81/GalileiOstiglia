<?php
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

   echo("<br><br>");
   echo("Seconda volta...");
   $record = $rs->fetch_assoc();
   while($record){
      echo($record['id']." ".$record['cognome']." ".$record['nome']."<br />");
      $record = $rs->fetch_assoc();
   }
   // Step 5 - Chiusura del collegamento con il db.
   $db->close();
?>