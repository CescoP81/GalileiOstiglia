<?php
session_start();

if(!isset($_SESSION['cnt'])) $_SESSION['cnt'] = 0;

$_SESSION['cnt']++;
echo("Hai ricaricato ". $_SESSION['cnt']." volta/e la pagina (sono su pagina 2)<br />");
echo("<a href=\"es01.php\">Pag 1</a>");
?>