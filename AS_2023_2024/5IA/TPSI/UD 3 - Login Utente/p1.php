<?php
session_start();
echo('Sono a pagina 1<br /><br />');
    if(!isset($_SESSION['cnt']))
        $_SESSION['cnt'] = 0;
    
    $_SESSION['cnt']++;
    echo($_SESSION['cnt']);

    echo('<a href="p2.php">Passa a pagina 2</a>');
?>