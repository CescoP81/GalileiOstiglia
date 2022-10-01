<?php
   require("require/testa.php");

   echo("Hello World in PHP...");
   echo("<button type=\"button\" class=\"btn btn-primary\">Primary</button>");
   echo("<br /><br />");

   for($i=1; $i<=10; $i++){
      echo($i." - ");
   }
   echo("<br />");
   
   $i=1;
   while($i<=10){
      echo($i." - ");
      $i++;
   }
   echo("<br />");
   
   $i = 15;
   echo($i." - ");
   $i = "Hello";
   echo($i." - ");
   $i = 15;
   $i = $i/9;
   echo($i." - ");
   echo("<br />");

   //localhost/francesco/prova.php?valore=17
   echo("Valore della request: " . $_REQUEST['valore']);

   require("require/coda.php");
?>