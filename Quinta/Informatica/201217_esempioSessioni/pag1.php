<?php
session_start();                                    // avvia una nuova sessione precedente oppure una nuova.
if(isset($_SESSION['cnt']) == false) $_SESSION['cnt'] = 0;  // controllo se cnt è un indice del vettore di sessione.

include('../head.html');
    echo("Contatore: ".$_SESSION['cnt']);    
    $_SESSION['cnt']++;

    echo("<br><br><a href=\"pag1.php\">Pagina 1</a>");
    echo("<br><br><a href=\"pag2.php\">Pagina 2</a>");
    echo("<br><br><a href=\"pag3.php\">Pagina 3</a>");
    echo("<br><br><a href=\"pag4.html\">Pagina 4</a>");
    echo("<br><br><a href=\"pag5.php\">Pagina 5</a>");
include('../foot.html');
?>