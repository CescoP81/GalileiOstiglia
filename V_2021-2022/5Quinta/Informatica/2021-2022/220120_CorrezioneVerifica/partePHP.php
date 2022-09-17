<?php
/* RISPOSTA QUESITO 4 
   i record estratti dalla query vengono visualizzati in forma testuale uno sotto l'altro.
*/

$db = new mysqli("localhost","user","password","database_name");
   $sql = "SELECT id, nome, razza FROM cane";
   $resultSet = $db->query($sql);

   while(($record = $resultSet->fetch_assoc()) != null){
      echo($record['id']." ".$record['nome']." ".$record['razza']."<br />");
   }
$db->close();


/* RISPOSTA QUESITO 5 
   Eseguire l’inserimento di un nuovo volontario nel database sapendo
   che sono create le variabili $_REQUEST[‘cognome’] e $_REQUEST[‘nome’]
*/

$c = $_REQUEST['cognome'];
$n = $_REQUEST['nome'];

$db = new mysqli("localhost","user","password","database_name");
   $sql = "INSERT INTO volontario(cognome, nome) VALUES('$c','$n')";

   if($db->query($sql)) echo("Inserimento avvenuto.");
   else echo("Problema in inserimento.");
   
$db->close();
?>