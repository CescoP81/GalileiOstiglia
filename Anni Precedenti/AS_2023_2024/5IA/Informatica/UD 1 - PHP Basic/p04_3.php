<?php
// p04_1.php ? baseUtente=6 & altezzaUtente=8 & scelta=perimetro

/* check variabili */
if(isset($_REQUEST['baseUtente'])) $b=$_REQUEST['baseUtente']; else $b=0;
if(isset($_REQUEST['altezzaUtente'])) $h=$_REQUEST['altezzaUtente']; else $h=0;
if(isset($_REQUEST['scelta'])) $sc=$_REQUEST['scelta']; else $sc = null;

/* Apertura codice HTML per pagina valida */
require("head.php");

/* Creazione form html */
    echo("<div class=\"alert alert-success\" role=\"alert\">
        Form di prova con campi testuali e selection
    </div>");
    /* == vecchio form senza bootstrap ==
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
        </form>");*/
    
    // costruisco il nuovo form con gli elementi bootstrap
    echo("<form action=\"p04_3.php\">
        <div class=\"mb-3\">
            <label for=\"baseUtente\" class=\"form-label\">Base:</label>
            <input type=\"text\" class=\"form-control\" id=\"baseUtente\" name=\"baseUtente\" placeholder=\"Insert base value\">
        </div>

        <div class=\"mb-3\">
            <label for=\"altezzaUtente\" class=\"form-label\">Altezza:</label>
            <input type=\"text\" class=\"form-control\" id=\"altezzaUtente\" name=\"altezzaUtente\" placeholder=\"Insert height value\">
        </div>

        <div class=\"mb-3\">
            <label for=\"sceltaUtente\" class=\"form-label\">Determina:</label>
            <select class=\"form-select\" id=\"sceltaUtente\" name=\"scelta\" aria-label=\"Select the operation\">
                <option value=\"area\" selected>Area</option>
                <option value=\"perimetro\">Perimetro</option>
            </select>
        </div>

        <button type=\"submit\" class=\"btn btn-primary\">Calcola</button>
    </form>");

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