<?php
// p04_1.php ? baseUtente=6 & altezzaUtente=8 & scelta=perimetro

/* check variabili */
if(isset($_REQUEST['baseUtente'])) $b=$_REQUEST['baseUtente']; else $b=0;
if(isset($_REQUEST['altezzaUtente'])) $h=$_REQUEST['altezzaUtente']; else $h=0;
if(isset($_REQUEST['scelta'])) $sc=$_REQUEST['scelta']; else $sc = null;

/* Apertura codice HTML per pagina valida */
require("head.php");

/* Creazione form html */
    echo("<form action=\"p04_1.php\">
            Base:
            <input type=\"text\" name=\"baseUtente\"><br />
            Altezza:
            <input type=\"text\" name=\"altezzaUtente\"><br />
            Scelta:<br />
            <select name=\"scelta\">
                <option value=\"area\">Area
                <option value=\"perimetro\">Perimetro
            </select><br />
            <input type=\"submit\" value=\"Calcola Valore\">        
        </form>");

/* controllo valori ed eventuali calcoli */
/*$b = $_REQUEST['baseUtente'];
$h = $_REQUEST['altezzaUtente']; Spostate in alto ad inizio pagina con controllo */

if($b<=0 || $h<=0)
    echo("Problema con i dati...");
else{
    switch($sc){
        case "area":{
            echo("Area= ".($b*$h)."<br />");
            break;
        }
        case "perimetro":{
            echo("Perimetro = ".(($b+$h)*2)."<br />");
            break;
        }
    }    
}

/* Chiusura della pagina html valida */
require("foot.php");
?>