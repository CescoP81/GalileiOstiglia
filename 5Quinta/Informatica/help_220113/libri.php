<?php
   echo("REQUEST: ".$_REQUEST['scelta']."<br /><br />");

   if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc=null;

   echo("<a href=\"libri.php\">Lista dei libri</a> | ");
   echo("<a href=\"libri.php?scelta=formLibro\">Nuovo Inserimento</a>");
   echo("<br /><br />");

   switch($sc){
      case "formLibro":{
         echo("Devo visualizzare il form per inserire i dati di un nuovo libro.<br /><br />");

         echo("<form action=\"libri.php\" method=\"get\">
            Titolo: <input type=\"text\" name=\"titolo\"><br />
            Autore: <input type=\"text\" name=\"autore\"><br />
            Prezzo: <input type=\"text\" name=\"prezzo\"><br />
            <input type=\"hidden\" name=\"scelta\" value=\"addLibro\">
            <input type=\"submit\" value=\"Inserisci Libro\">;
         ");
         break;
      }
      case "addLibro":{
         echo("Devo costruire la query SQL per l'inserimento di nuovo libro.<br /><br />");
         $t = $_REQUEST['titolo'];
         $a = $_REQUEST['autore'];
         $p = $_REQUEST['prezzo'];

         $sql = "INSERT INTO libri(titolo, autore, prezzo) 
                  VALUES('$t', '$a', $p)";
         echo($sql);

         $db = new mysqli("localhost", "root","","helponline");
            if($db->query($sql))
               echo("Inserimento OK.");
            else
               echo("Problema in inserimento.");
         $db->close();
         break;
      }
      default:{
         echo("Devo visualizzare l'elenco dei libri a database...<br /><br />");
         $db = new mysqli("localhost", "root","","helponline");

         $sql = "SELECT *
                FROM libri 
                ORDER BY prezzo DESC";

         $resultSet = $db->query($sql);

         $record = $resultSet->fetch_assoc();
         while($record){
            echo($record['id'] . " - ".$record['titolo']. " - ".$record['autore']. " - ". $record['prezzo']."<br />");
            $record = $resultSet->fetch_assoc();
         }

         $db->close();
         break;
      }
   }
?>