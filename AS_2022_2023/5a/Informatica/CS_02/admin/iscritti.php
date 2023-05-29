<?php
/* Pagina di gestione della tabella iscritti.*/
session_start();
$_SESSION['alogged'] = true;
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
        case "formNuovoIscritto":{
            echo("<form action=\"iscritti.php\" method=\"post\">
                <div class=\"mb-3\">
                    <label for=\"inputNome\" class=\"form-label\">Nome</label>
                    <input class=\"form-control\" name=\"nome\" type=\"text\" id=\"inputNome\" placeholder=\"Inserisci nome\" aria-label=\"default input example\">
                </div>
                <div class=\"mb-3\">
                    <label for=\"inputCognome\" class=\"form-label\">Cognome</label>
                    <input class=\"form-control\" name=\"cognome\" type=\"text\" id=\"inputCognome\" placeholder=\"Inserisci cognome\" aria-label=\"default input example\">
                </div>
                <div class=\"mb-3\">
                    <label for=\"inputMail\" class=\"form-label\">E-mail</label>
                    <input type=\"email\" name=\"mail\" class=\"form-control\" id=\"inputMail\" placeholder=\"name@example.com\">
                </div>
                <div class=\"mb-3\">
                    <label for=\"inputPassword\" class=\"form-label\">Password</label>
                    <input class=\"form-control\" name=\"password\" type=\"text\" id=\"inputPassword\">
                </div>
                <div class=\"mb-3\">
                    <label for=\"inputEta\" class=\"form-label\">Fascia d'et&agrave;</label>
                    <select class=\"form-selec\" name=\"fasciaEta\" id=\"inputEta\" aria-label=\"Fascia età\">
                        <option value=\"1\">Giovani</option>
                        <option value=\"2\">Adolescenti</option>
                        <option value=\"3\">Adulti</option>
                        <option value=\"4\">Anziani</option>
                    </select>
                </div>
                <input type=\"hidden\" name=\"scelta\" value=\"aggiungiIscritto\">
                <button type=\"submit\" class=\"btn btn-primary\">Submit</button>
            </form>");
            break;
        }
        case "aggiungiIscritto":{
            $n = $_REQUEST['nome'];
            $c = $_REQUEST['cognome'];
            $m = $_REQUEST['mail'];
            $p = md5($_REQUEST['password']);
            $fe = $_REQUEST['fasciaEta'];

            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "INSERT INTO cs02_iscritti(nome, cognome, mail, password, fasciaEta) VALUES('$n','$c','$m','$p',$fe)";
            echo($sql);
            if($db->query($sql)) echo("<div class=\"alert alert-success\">Iscritto aggiunto</div>");
            else echo("<div class=\"alert alert-danger\">Problema Inserimento.</div>");
            $db->close();
            break;
        }
        case "listaIscritti":{
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "SELECT cognome AS 'Cognome', nome AS 'Nome', mail AS 'eMail Address', password AS 'MD5 Password', fasciaEta AS 'Fascia Età' 
                FROM cs02_iscritti 
                ORDER BY cognome ASC";
            $rs = $db->query($sql);
            if($rs) showResultSetTable($rs, "Tabella Iscritti"); else echo("Problema...");

            $db->close();
            break;
        }
        case "cancellaIscritto":{
            break;
        }
        case "modificaIscritto":{
            break;
        }
        case "aggiornaIscritto":{
            break;
        }
        default:{
            break;
        }
    }
}
require("../include/foot.html");
?>