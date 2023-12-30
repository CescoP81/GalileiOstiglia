<?php
// richiamo il blocco iniziale HTML per precaricare dati e BootStrap
require("../funzioni.php");
require("../head.html");

   echo("Questo messaggio lo vedo spaziato e in carattere diverso dal solito");
   echo("<br />");
   helloWorld();
   // richiamo il blocco finale con chiusura pagina e caricamento JS di BootStrap
require("../foot.html");
?>