<?php
session_start();
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;

if($_SESSION['loggato']){
    echo('Utente: '.$_SESSION['cognome']." ".$_SESSION['nome'].'<br />');
    echo('<a href="index.php">Torna alla Home</a><br />');
}
else{
    echo('Utente non loggato, tornare alla Home Page<br /><a href="index.php">Home</a>');
}

?>