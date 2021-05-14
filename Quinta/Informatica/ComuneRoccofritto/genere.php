<?php
if(isset($_REQUEST['scelta'])) $sc=$_REQUEST['scelta']; else $sc=null;

// inclusione di un file di libreria con funzioni sviluppate.
require("lib.php");

    require("../head.html");
        writeMainMenu();

        // switch-case con le opzione di gestione rf_genere
        switch($sc){
            case "listaGenere":{
                $db = new mysqli($dbhost, $dbuser, $dbpassword, $dbname);
                $sql = "SELECT * FROM rf_genere";
                $resultSet = $db->query($sql);
                $db->close();

                createTable($resultSet, "Elenco dei generi disponibili.");
                break;
            }
            case "nuovoGenere":{
                echo("<form action=\"genere.php\" method=\"get\">");
                    echo("<div class=\"form-group\">");
                    echo("<label for=\"inputTitoloGenere\">Titolo:</label><input class=\"form-control form-control-sm\" type=\"text\" name=\"titolo\" id=\"inputTitoloGenere\"><br/>");
                    echo("<label for=\"inputDescrizioneGenere\">Descrizione:</label><textarea class=\"form-control form-control-sm\" type=\"text\" name=\"descrizione\" id=\"inputDescrizioneGenere\"></textarea><br />");
                    echo("<input type=\"hidden\" name=\"scelta\" value=\"addGenere\">");
                    echo("<input type=\"submit\" class=\"btn btn-secondary\" value=\"Aggiungi Genere\">");
                echo("</form>");
                break;
            }
            case "addGenere":{
                $titolo = $_REQUEST['titolo'];
                $descrizione = $_REQUEST['descrizione'];
                $db = new mysqli($dbhost, $dbuser, $dbpassword, $dbname);
                $sql = "INSERT INTO rf_genere(titolo, descrizione) VALUE('$titolo', '$descrizione')";
                if($db->query($sql))
                    echo("<div class=\"alert alert-success\" role=\"aler\">Inserimento Corretto</div>");
                else
                    echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in inserimento.</div>");
                $db->close();
                break;
            }
        }
    require("../foot.html");
?>