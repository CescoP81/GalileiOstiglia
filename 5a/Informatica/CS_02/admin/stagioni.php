<?php
/* Gestione delle stagioni teatrali e del palinsesto*/
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
        case "formNuovaStagione":{
            break;
        }
        case "vediStagioni":{
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "SELECT annualita, descrizione, dataInizio, dataFine FROM cs02_stagioni ORDER BY annualita DESC";
            $rs = $db->query($sql);
            if($rs) showResultSetTable($rs, "Tabella Stagioni Teatrali"); else echo("Problema...");

            $db->close();
            break;
        }
        case "cancellaStagione":{
            break;
        }
        case "modificaStagione":{
            break;
        }
        case "aggiornaStagione":{
            break;
        }
        default:{
            break;
        }
    }
}
require("../include/foot.html");
?>