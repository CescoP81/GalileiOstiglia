<?php
// gestione della tabella cs01_fumetto
require("../include/lib.php");
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.html");
    adminNavBar();
    switch($sc){
        case "formNuovoFumetto":{
            echo("<form method=\"get\" action=\"casaEditrice.php\">
                    <div class=\"mb-3\">
                        <label for=\"inputTitolo\" class=\"form-label\">Titolo:</label>
                        <input type=\"text\" name=\"titoloF\" class=\"form-control\" id=\"inputTitolo\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputNumero\" class=\"form-label\">Numero:</label>
                        <input type=\"text\" name=\"numeroF\" class=\"form-control\" id=\"inputNumero\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputData\" class=\"form-label\">Data Uscita:</label>
                        <input type=\"text\" name=\"dataF\" class=\"form-control\" id=\"inputData\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputPrezzo\" class=\"form-label\">Prezzo:</label>
                        <input type=\"text\" name=\"dataF\" class=\"form-control\" id=\"inputPrezzo\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>");
                    // devo dare la possibilità di scegliere la casa editrice.
                    $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
                    $sql = "SELECT * FROM cs01_casaEditrice";
                    $resultSet = $db->query($sql);
                    echo("<div class=\"mb-3\">");
                        echo("<label for=\"inputPrezzo\" class=\"form-label\">Casa Editrice:</label>");
                        echo("<select name=\"idEditrice\" class=\"form-select\" aria-label=\"Default select example\">");
                        while($record = $resultSet->fetch_assoc()){
                            echo("<option value=\"".$record['id']."\">".$record['nome']."</option>");
                        }
                        echo("</select>");
                    echo("</div>");
                    $db->close();
            echo("<input type=\"hidden\" name=\"scelta\" value=\"addFumetto\">
                <button type=\"submit\" class=\"btn btn-primary\">Inserisci Nuovo Fumetto</button>
            ");
            break;
        }
    }
require("../include/foot.html");
?>