<?php
if(isset($_REQUEST['scelta'])) $sc=$_REQUEST['scelta']; else $sc=null;

// inclusione di un file di libreria con funzioni sviluppate.
require("lib.php");

    require("../head.html");
        writeMainMenu();

        // switch-case con le opzione di gestione rf_genere
        switch($sc){
            case "listaRassegna":{
                $db = new mysqli($dbhost, $dbuser, $dbpassword, $dbname);
                $sql = "SELECT * FROM rf_rassegna";
                
                $sql = "SELECT r.titolo AS 'Titolo', r.data_inizio AS 'Inizia', r.data_fine AS 'Termina', COUNT(rs.id) AS 'Numero Spettacoli' 
                    FROM rf_rassegna AS r, rf_rassegna_spettacolo AS rs 
                    WHERE r.id=rs.id_rassegna 
                    GROUP BY r.id";


                $resultSet = $db->query($sql);
                $db->close();

                createTable($resultSet, "Elenco rassegne disponibili.");
                break;
            }
            case "nuovaRassegna":{
                echo("<form action=\"genere.php\" method=\"get\">");
                    echo("<div class=\"form-group\">");
                    echo("<label for=\"inputTitoloRassegna\">Titolo:</label><input class=\"form-control form-control-sm\" type=\"text\" name=\"titolo\" id=\"inputTitoloGenere\"><br/>");
                    echo("<label for=\"inputDescrizioneGenere\">Descrizione:</label><textarea class=\"form-control form-control-sm\" type=\"text\" name=\"descrizione\" id=\"inputDescrizioneGenere\"></textarea><br />");
                    echo("<label for=\"inputDataInizio\">Data Inizio:</label><input class=\"form-control form-control-sm\" type=\"text\" name=\"data_inizio\" id=\"inputDataInizio\"><br/>");
                    echo("<label for=\"inputDataFine\">Data Fine:</label><input class=\"form-control form-control-sm\" type=\"text\" name=\"data_fine\" id=\"inputDataFine\"><br/>");
                    
                    echo("<input type=\"hidden\" name=\"scelta\" value=\"addRassegna\">");
                    echo("<input type=\"submit\" class=\"btn btn-secondary\" value=\"Aggiungi Rassegna\">");
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