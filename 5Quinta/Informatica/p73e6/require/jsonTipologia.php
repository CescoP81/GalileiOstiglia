<?php
   header("Content-Type: application/json; charset=UTF-8");
   require("funzioni.php");
   $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
   $sql = "SELECT * FROM p73e6_tipologia";
   $rs = $db->query($sql);
   $nRecord = $rs->num_rows;
   
   echo("[");
   for($i=1; $i<=$nRecord; $i++){
      $record = $rs->fetch_assoc();
      $json = json_encode($record);
      echo($json);
      if($i < $nRecord)
         echo(",");
   }
   echo("]");
   $db->close();
?>