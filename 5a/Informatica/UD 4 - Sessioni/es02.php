<?php
/*  - esempio di base sulla creazione di una variabile di sessione, modifica e richiamo di tale variabile.
    - Recupero dati da database e salvataggio in una sessione.
*/
session_start();
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

$host = "localhost";
$user = "root";
$passwd = "";
$db_name = "scuola2223";

if(!$_SESSION['loggato']){  // non sono un utente loggato sul sito, quindi mostro form per login
    if($sc == "login"){
        echo("Eseguo il login...");
        $db = new mysqli($host,$user,$passwd,$db_name);
        $query // da finire
    }
    else{
        echo("<form action=\"es02.php\" method=\"get\">
            E-mail: <input type=\"text\" name=\"mail\"><br />
            Password: <input type=\"password\" name=\"passwd\"><br />
            <input type=\"hidden\" name=\"scelta\" value=\"login\">
            <input type=\"submit\" value=\"Try Login\">
            </form>");
    }
}

if($_SESSION['loggato']){

}
?>