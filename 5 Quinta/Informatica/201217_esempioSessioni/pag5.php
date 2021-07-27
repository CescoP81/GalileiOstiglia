<?php
session_start();                                    // avvia una nuova sessione precedente oppure una nuova.
if(isset($_SESSION['cnt']) == false) $_SESSION['cnt'] = 0;  // controllo se cnt è un indice del vettore di sessione.

include('../head.html');
    echo("Contatore Finale: ".$_SESSION['cnt']);    
    session_destroy(); 

    echo("<br><br><a href=\"pag1.php\">Pagina 1</a>");
include('../foot.html');
?>