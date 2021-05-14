<?php
if(isset($_REQUEST['scelta'])) $sc=$_REQUEST['scelta']; else $sc=null;

// inclusione di un file di libreria con funzioni sviluppate.
require("lib.php");

    require("../head.html");
        writeMainMenu();
    switch($sc){
        case "listaSpettacolo":{
            $db = new mysqli($dbhost, $dbuser, $dbpassword, $dbname);
            $sql = "SELECT s.id, s.titolo, s.compagnia, s.costo, g.titolo AS genere 
                FROM rf_genere AS g, rf_spettacolo AS s 
                WHERE g.id=s.id_genere";
            $resultSet = $db->query($sql);
            $db->close();

            createTable($resultSet, "Lista spettacoli disponibili.");
            break;
        }
        case "nuovoSpettacolo":{
            break;
        }
    }
require("../foot.html");
?>