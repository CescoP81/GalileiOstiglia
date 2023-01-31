<?php
session_start();

if(!isset($_SESSION['cnt'])) $_SESSION['cnt'] = 0;

$_SESSION['cnt']++;
echo("Hai ricaricato ". $_SESSION['cnt']." volta/e la pagina (pagina 1)");
echo("<a href=\"es011.php\">Pag 2</a>");
?>