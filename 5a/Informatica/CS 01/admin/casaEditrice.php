<?php
/*  Gestione della tabella cs01_casaEditrice
    Richiede i seguenti file dalla cartella include:
    - lib.php
    - head.html 
    - foot.html
*/
require("../include/lib.php");
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.html");
    adminNavBar();
    switch($sc){
        case "formNuovaEditrice":{
            echo("<form method=\"get\" action=\"casaEditrice.php\">
                    <div class=\"mb-3\">
                        <label for=\"inputNome\" class=\"form-label\">Nome Casa Editrice:</label>
                        <input type=\"text\" name=\"nomeE\" class=\"form-control\" id=\"inputNome\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputEmail\" class=\"form-label\">Indirizzo e-mail:</label>
                        <input type=\"email\" name=\"mailE\" class=\"form-control\" id=\"inputEmail\" aria-describedby=\"emailHelp\">
                        <!--<div id=\"emailHelp\" class=\"form-text\">We'll never share your email with anyone else.</div>-->
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputSito\" class=\"form-label\">Sito Web</label>
                        <input type=\"text\" name=\"sitoE\" class=\"form-control\" id=\"inputSito\" aria-describedby=\"emailHelp\">
                        <!--<div id=\"emailHelp\" class=\"form-text\">We'll never share your email with anyone else.</div>-->
                    </div>
                <input type=\"hidden\" name=\"scelta\" value=\"addEditrice\">
                <button type=\"submit\" class=\"btn btn-primary\">Inserisci</button>
            ");
            break;
        }
        case "addEditrice":{
            $nome = $_REQUEST['nomeE'];
            $mail = $_REQUEST['mailE'];
            $sito = $_REQUEST['sitoE'];

            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "INSERT INTO cs01_casaEditrice(nome, email, sitoWeb) VALUES('$nome','$mail','$sito')";
            if($db->query($sql))
                echo("<div class=\"alert alert-success\">Aggiunta nuova Casa Editrice</div>");
            else
                echo("<div class=\"alert alert-danger\">Problema in aggiunta nuova Casa Editrice</div>");
            $db->close();
            break;
        }
        case "listaEditrice":{
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "SELECT * FROM cs01_casaEditrice";
            $rs = $db->query($sql);
            showResultSetTable($rs,"Lista delle Case Editrici","casaEditrice.php");
            $db->close();
            break;
        }
        case "deleteRecord":{
            $idr = $_REQUEST['idRecord'];
            // step 1. verifico che nella tabella fumetti non ci siano chiavi esternet uguale all'id del record che voglio cancellare.
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "SELECT id FROM cs01_fumetto WHERE idCasaEditrice=$idr";
            $rs = $db->query($sql);
            if($rs->num_rows > 0){   // se la query mi restituisce una o più righe, non posso cancellare la casa editrice.
                echo("<div class=\"alert alert-danger\">Attenzione, ci sono fumetti con questa Casa Editrice.</div>");
            }
            else{
                $sql = "DELETE FROM cs01_casaEditrice WHERE id=$idr";
                if($db->query($sql))
                    echo("<div class=\"alert alert-success\">Cancellazione avvenuta.</div>");
                else
                    echo("<div class=\"alert alert-warning\">Problema in cancellazione.</div>");
            }
            $db->close();
            break;
        }
    }
require("../include/foot.html");
?>