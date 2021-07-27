<?php
session_start();

if($_SESSION['logged_in'] == true){
    //echo("<a href=\"forum.php\">Forum</a>");
    echo("SONO NEL FORUM..<br><br>");
    echo("<a href=\"forum.php\">Forum</a> | ");
    echo("<a href=\"login.php?scelta=logout\">Logout</a><br><br>");
    echo($_SESSION['id_utente']." ".$_SESSION['cognome']." ".$_SESSION['nome']);
}
else{
    echo("Utente non loggado eseguire il login.<br />");
    echo("<a href=\"login.html\">Login</a>");
}

?>