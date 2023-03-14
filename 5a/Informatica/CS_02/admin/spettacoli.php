<?php
/* Gestione della tabella spettacoli */
session_start();
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/lib.php");
require("../include/head.html");

if(!$_SESSION['alogged']){
    echo("Form per l'autentica come amministratore...");
    // funzione che crea il form
}
else{
    adminNavBar();
    switch($sc){
        case "formSpettacolo":{
            break;
        }
        case "vediSpettacoli":{
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "SELECT id, titolo, regia, attorePrincipale, durata FROM cs02_spettacoli ORDER BY id DESC";
            $rs = $db->query($sql);
            if($rs) showResultSetTable($rs, "Tabella Spettacoli Disponibili"); else echo("Problema...");

            $db->close();
            break;
        }
        case "cancellaSpettacolo":{
            break;
        }
        case "modificaSpettacolo":{
            break;
        }
        case "aggiornaSpettacolo":{
            break;
        }
        default:{
            break;
        }
    }
}
require("../include/foot.html");
?>
