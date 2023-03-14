<?php
/*  Pagina front-end del sito dell'Associazione culturale, permette un riepilogo generale e mostra alcune informazioni generali.
*/
session_start();
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
if(!isset($_SESSION['ulogged'])){
    $_SESSION['ulogged'] = false;
    $_SESSION['associatoName'] = null;
    $_SESSION['idIscritto'] = null;
}

require("include/lib.php");
require("include/head.html");

if($sc == "logout"){
    $_SESSION['ulogged'] = false;
    session_destroy();
}

if(!$_SESSION['ulogged']){
    switch($sc){
        case "login":{
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $un = $_REQUEST['username'];
            $up = md5($_REQUEST['passwd']);
            $sql = "SELECT * FROM cs02_iscritti 
                    WHERE mail='$un' AND password='$up'";
            //echo($sql."<br >");
            if($rs = $db->query($sql)){
                echo($rs->num_rows);
                if($rs->num_rows > 0){ // è stato trovato un utente con le credenziali inserite.
                    $record = $rs->fetch_assoc();
                    $_SESSION['associatoName'] = $record['nome']." ".$record['cognome'];
                    $_SESSION['idIscritto'] = $record['id'];
                    $_SESSION['ulogged'] = true;
                }
            }
            $db->close();
            break;
        }
        default:{
            echo("<form action=\"index.php\" method=\"post\">
                <div class=\"mb-3\">
                    <label for=\"inputUsername\" class=\"form-label\">Your mail address:</label>
                    <input class=\"form-control\" name=\"username\" type=\"text\" id=\"inputUsername\" placeholder=\"Inserisci User\" aria-label=\"default input example\">
                </div>
                <div class=\"mb-3\">
                    <label for=\"inputPassword\" class=\"form-label\">Password:</label>
                    <input class=\"form-control\" name=\"passwd\" type=\"password\" id=\"inputPassword\">
                </div>
                <input type=\"hidden\" name=\"scelta\" value=\"login\">
                <button type=\"submit\" class=\"btn btn-primary\">Login</button>
            </form>");
        }
    }
}
if($_SESSION['ulogged']){
    // Riepilogo dell'amministrazione.
    //adminNavBar();
    associatonavBar($_SESSION['idIscritto'], $_SESSION['associatoName']);
    //echo("Associato loggato...");
}
require("include/foot.html");
?>