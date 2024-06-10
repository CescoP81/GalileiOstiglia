<?php
require("head.php");
    echo("<div class=\"container\">");

    // -- FORM PER INSERIMENTO NUOVO VINO
    echo("<div class=\"alert alert-primary\"><h3>Form inserimento nuovo Vino</h3></div>");
        echo("<form action=\"#\">
            <div class=\"mb-3\">
                <label for=\"nomeVino\" class=\"form-label\">Nome:</label>
                <input type=\"text\" class=\"form-control\" id=\"nomeVino\" name=\"nomeVino\" placeholder=\"Insert a name\">
            </div>
            <div class=\"mb-3\">
                <label for=\"regioneVino\" class=\"form-label\">Regione:</label>
                <input type=\"text\" class=\"form-control\" id=\"regioneVino\" name=\"regioneVino\" placeholder=\"Insert a Region\">
            </div>
            <div class=\"mb-3\">
                <label for=\"gradoAlcolico\" class=\"form-label\">Grado Alcolico:</label>
                <input type=\"text\" class=\"form-control\" id=\"gradoAlcolico\" name=\"gradoAlcolico\" placeholder=\"alcohol level\">
            </div>
            <div class=\"mb-3\">
                <label for=\"portataConsigliata\" class=\"form-label\">Piatto Consigliato:</label>
                <input type=\"text\" class=\"form-control\" id=\"portataConsigliata\" name=\"portataConsigliata\" placeholder=\"Suggested dish\">
            </div>
            <div class=\"mb-3\">
                <label for=\"prezzoVino\" class=\"form-label\">Prezzo:</label>
                <input type=\"text\" class=\"form-control\" id=\"prezzoVino\" name=\"prezzoVino\" placeholder=\"Price\">
            </div>
            <input type=\"hidden\" name=\"scelta\" value=\"addVino\">
            <button type=\"submit\" class=\"btn btn-primary\">Inserisci nuovo record</button>
        </form>");
    // -- FINE FORM

    echo("</div>");
require("foot.php");
?>
