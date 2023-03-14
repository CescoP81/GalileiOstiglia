<?php
/*  Pagina di gestione lato associato con login specifico iscritto e possibilità di iscrizione ad uno specifico spettacolo.
*/
session_start();
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
if(!isset($_SESSION['ulogged'])){
    $_SESSION['ulogged'] = false;
    $_SESSION['associatoName'] = null;
}

require("include/lib.php");
require("include/head.html");

if(!$_SESSION['ulogged']){
    echo("Form per l'autentica come amministratore...");
    // funzione che crea il form
}
else{
    associatonavBar($_SESSION['idIscritto'], $_SESSION['associatoName']);
    switch($sc){
        /*
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
        */
        default:{
            // mostro le iscrizioni effettuate.
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "SELECT spe.titolo AS 'Titolo Spettacolo', spe.regia AS 'Regia di', pal.dataSpettacolo AS 'Data programmata'  
                    FROM cs02_iscritti AS isc, cs02_partecipa AS par, cs02_spettacoli AS spe, cs02_palinsesto as pal   
                    WHERE par.idIscritto=isc.id AND 
                        par.idPalinsesto=pal.id AND
                        pal.idSpettacolo=spe.id AND
                        isc.id=".$_SESSION['idIscritto'];
            //echo($sql);
            $rs = $db->query($sql); 
            if($rs)
                showResultSetTable($rs, "Iscrizioni personali");
            $db->close();
            break;
        }
    }
}
require("include/foot.html");
?>