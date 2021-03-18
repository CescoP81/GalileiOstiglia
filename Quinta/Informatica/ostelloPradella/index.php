<?php
session_start();
if(isset($_SESSION['autenticato']) == false) $_SESSION['autenticato'] = false;
if(isset($_REQUEST['scelta']) == true) $sc = $_REQUEST['scelta'];
else $sc = null;

require('library.php');
// sezione di login o logout del mio utente
if($sc == "login"){
    //if($_REQUEST['utente']=="admin" && $_REQUEST['passwd']=="admin")
    //    $_SESSION['autenticato'] = true;
    $utente = $_REQUEST['utente'];
    $passwd = $_REQUEST['passwd'];

    $db = new mysqli("localhost","root","","scuola2021");
    $sql = "SELECT * FROM utente WHERE email='$utente' AND upassword='".md5($passwd)."'";
    $resultSet = $db->query($sql);
    if($resultSet->num_rows == 1){
        $record = $resultSet->fetch_assoc();
        $_SESSION['autenticato'] = true;
        $_SESSION['nome_utente'] = $record['cognome']." ".$record['nome'];
    }
    $_SESSION['autenticato'] = true;
    $db->close();
}
if($sc == "logout"){
    $_SESSION['autenticato'] = false;
    session_destroy();
}

include("../head.html");
    //Richiamo la funzione menuOperativo() presente nel file library.php
    if($_SESSION['autenticato'] == true){ // sono in presenza di un utente autenticato e valido, mostro il menu
        menuOperativo();
    }
    else{ // il mio utente non è autenticato, mostro il form di autentica.
        echo("<form action=\"index.php\" method=\"get\">");
            echo("Utente: <input type=\"text\" name=\"utente\">");
            echo("Password: <input type=\"password\" name=\"passwd\">");
            echo("<input type=\"hidden\" name=\"scelta\" value=\"login\">");
            echo("<input type=\"submit\" value=\"Login\">");
        echo("</form>");
    }
    echo("<div class=\"alert alert-info\" role=\"alert\">Home Page - Nessuna scelta effettuata</div>");
include("../foot.html");
?>