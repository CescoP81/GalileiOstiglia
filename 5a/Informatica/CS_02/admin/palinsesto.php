<?php
/*Pagina di creazione e gestione dei palinsesti (elenco degli spettacoli che vengono realizzati durante una determinata stagione) */
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
        case "formNuovoPalinsesto":{
            echo("<form action=\"palinsesto.php\" method=\"post\">
                <div class=\"row\">
                    <div class=\"col\">
                        <div class=\"mb-3\">
                            <label for=\"inputData\" class=\"form-label\">Data</label>
                            <input class=\"form-control\" name=\"dataSpettacolo\" type=\"date\" id=\"inputData\" placeholder=\"Inserisci nome\" aria-label=\"default input example\">
                        </div>
                    </div>
                    <div class=\"col\">
                        <div class=\"mb-3\">
                            <label for=\"inputStagione\" class=\"form-label\">Stagione</label>
                            <select class=\"form-selec\" name=\"idStagione\" id=\"inputStagione\" aria-label=\"Stagione\">");
                                $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
                                $sql = "SELECT id, annualita, dataInizio, dataFine FROM cs02_stagioni ORDER BY annualita DESC";
                                $rs = $db->query($sql);
                                $db->close();
                                while($record = $rs->fetch_assoc()){
                                    echo("<option value=\"".$record['id']."\">".$record['annualita']." - dal ".$record['dataInizio']." al ".$record['dataFine']."</option>");
                                }
                            echo("</select>
                        </div>
                    </div>
                    <div class=\"col\">
                        <div class=\"mb-3\">
                            <label for=\"inputSpettacolo\" class=\"form-label\">Spettacolo</label>
                            <select class=\"form-selec\" name=\"idSpettacolo\" id=\"inputSpettacolo\" aria-label=\"Spettacolo\">");
                                $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
                                $sql = "SELECT id, titolo, regia FROM cs02_spettacoli ORDER BY titolo ASC";
                                $rs = $db->query($sql);
                                $db->close();
                                while($record = $rs->fetch_assoc()){
                                    echo("<option value=\"".$record['id']."\">".$record['titolo']." - di ".$record['regia']."</option>");
                                }
                            echo("</select>
                        </div>
                    </div>
                </div>
                <input type=\"hidden\" name=\"scelta\" value=\"aggiungiPalinsesto\">
                <button type=\"submit\" class=\"btn btn-primary\">Programma Spettacolo</button>
            </form>");
            break;
        }
        case "aggiungiPalinsesto":{
            $d = $_REQUEST['dataSpettacolo'];
            $idSt = $_REQUEST['idStagione'];
            $idSp = $_REQUEST['idSpettacolo'];
            $sql = "INSERT INTO cs02_palinsesto(dataSpettacolo, idSpettacolo, idStagione) VALUES('$d',$idSp, $idSt)";
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            if($db->query($sql)) echo("<div class=\"alert alert-success\">Spettacolo programmato</div>");
            else echo("<div class=\"alert alert-danger\">Problema Inserimento.</div>");
            break;
        }
        case "listaPalinsesto":{
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            //$sql = "SELECT id, dataSpettacolo, idSpettacolo, idStagione FROM cs02_palinsesto ORDER BY dataSpettacolo DESC";
            $sql = "SELECT p.id, p.dataSpettacolo AS 'Data Spettacolo', sp.titolo , sp.regia 
                FROM cs02_palinsesto AS p, cs02_spettacoli AS sp, cs02_stagioni AS st
                WHERE p.idSpettacolo=sp.id AND p.idStagione=st.id
                ORDER BY p.dataSpettacolo ASC";
            $rs = $db->query($sql);
            if($rs) showResultSetTable($rs, "Palinsesto di stagione"); else echo("Problema...");

            $db->close();
            break;
        }
        default:{
            break;
        }
    }
}
require("../include/foot.html");
?>