<?php

$giorni = array("Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì", "Sabato", "Domenica");
for($i=0; $i<count($giorni); $i++)
   echo($giorni[$i]."<br />");

echo("<br /><br />");

$mesi = array(
   "gennaio" => 31,
   "febbraio" => 30,
   "marzo" => 31,
   "aprile" => 30,
   "maggio" => 31,
   "giugno" => 30
);

echo($mesi['gennaio']);
echo("<br>");
echo($mesi[1]);
?>