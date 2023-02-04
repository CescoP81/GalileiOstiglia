<?php
/*  Pagina generale della parte amminsitrativa, effettua il login di un amministratore e visualizza dati riepilogativi della banca dati.
*/
session_start();
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
if(!isset($_SESSION['alogged'])) $_SESSION['alogged'] = false;

require("../include/lib.php");
require("../include/head.html");

if($sc == "logout"){
    $_SESSION['alogged'] = false;
    session_destroy();
}

if(!$_SESSION['alogged']){
    switch($sc){
        case "login":{
            if(($_REQUEST['username']=="admin") && ($_REQUEST['passwd']=="admin"))
                $_SESSION['alogged'] = true;
            break;
        }
        default:{
            echo("<form action=\"index.php\" method=\"post\">
                <div class=\"mb-3\">
                    <label for=\"inputUsername\" class=\"form-label\">Username</label>
                    <input class=\"form-control\" name=\"username\" type=\"text\" id=\"inputUsername\" placeholder=\"Inserisci User\" aria-label=\"default input example\">
                </div>
                <div class=\"mb-3\">
                    <label for=\"inputPassword\" class=\"form-label\">Password</label>
                    <input class=\"form-control\" name=\"passwd\" type=\"text\" id=\"inputPassword\">
                </div>
                <input type=\"hidden\" name=\"scelta\" value=\"login\">
                <button type=\"submit\" class=\"btn btn-primary\">Login</button>
            </form>");
        }
    }
}
if($_SESSION['alogged']){
    // Riepilogo dell'amministrazione.
    adminNavBar();
}
require("../include/foot.html");
?>