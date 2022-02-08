<?php
   /* Uso dello scritp:
      /word.php -> Estrae una parola random dall'intero elenco.
      /word.php?lang=xx -> IT - Estrare una parola random tra quelle italiane.
                           EN - Estrare una parola random tra quelle italiane.
   */
  if(isset($_REQUEST['lang'])) $lang = $_REQUEST['lang'];
  else $lang = null;

  $db = new mysqli("localhost","root","","scuola2122");
  if($lang){
      $sql = "SELECT testo FROM tpsi_parola WHERE lingua='$lang'";
      
      $rs = $db->query($sql);
      $parole = Array();

      $record = $rs->fetch_assoc();
      while($record){
         array_push($parole, $record['testo']);
         $record = $rs->fetch_assoc();
      }
      $db->close();

      for($i=0; $i<count($parole); $i++)
         echo($parole[$i]."<br />");
  }   
  else{
   $sql = "SELECT testo FROM tpsi_parola";
   $rs = $db->query($sql);
   $parole = Array();

   $record = $rs->fetch_assoc();
   while($record){
      array_push($parole, $record['testo']);
      $record = $rs->fetch_assoc();
   }
   $db->close();

   for($i=0; $i<count($parole); $i++)
      echo($parole[$i]."<br />");
  }
?>