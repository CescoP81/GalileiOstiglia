<?php
/*  Pagina di gestione tabella ostello_preotazione
 Scelta:
 default: non visualizzo nulla.
 
 */
session_start();
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

require('library.php');
include("../head.html");
//Richiamo la funzione menuOperativo() presente nel file library.php
if($_SESSION['autenticato'] == true){
    menuOperativo();
    switch($sc){
        case "showPrenotazione":{
            /*$db = new mysqli("localhost","root","","scuola2021");
            $sql = "SELECT * FROM ostello_camera";

            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            echo("<table class=\"table table-hover\">");
            echo("<caption>Lista delle camere</caption>");
            echo("<thead  class=\"thead-dark\">");
            echo("<tr>");
                echo("<th scope=\"col\">Id</th>");
                echo("<th scope=\"col\">Nr. Camera</th>");
                echo("<th scope=\"col\">Posti letto</th>");
                echo("<th scope=\"col\">Bagno in camera</th>");
                echo("<th scope=\"col\">Prezzo Giornaliero</th>");
                echo("<th scope=\"col\">Options</th>");
            echo("</tr>");
            echo("</thead>");
            echo("<tbody>");
            while($record){
                echo("<tr>");
                    echo("<td scope=\"row\">".$record['id']."</td>");
                    echo("<td>".$record['nr_camera']."</td>");
                    echo("<td>".$record['posti_letto']."</td>");
                    echo("<td>".$record['bagno_in_camera']."</td>");
                    echo("<td>".$record['prezzo_giornaliero']."</td>");
                    echo("<td><a href=\"camera.php?scelta=deleteCamera&idCamera=".$record['id']."\"><img src=\"../bsicons/trash.svg\" alt=\"\" width=\"24\" height=\"24\" title=\"Bootstrap\" /></a></td>");
                echo("</tr>");
                $record = $resultSet->fetch_assoc();
            }
            echo("</tbody>");
            echo("</table>");
            $db->close();*/
            break;
        }
        case "formPrenotazione":{
            // visualizza il form per inserimento dati da utente.
            echo("<form action=\"prenotazione.php\" method=\"get\">");
                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputDataInizio\">Data Inizio:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"data_inizio\" id=\"inputDataInizio\">");
                echo("</div>");
                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputDataFine\">Data Fine:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"data_fine\" id=\"inputDataFine\">");
                echo("</div>");
                
                $db = new mysqli("localhost","root","","scuola2021");
                $sql = "SELECT * FROM ostello_camera";
                $resultSet = $db->query($sql);
                echo("<div class=\"form-group\">");
                    echo("<label for=\"selectIdCamera\">Selezionare la camera:</label>");
                    echo("<select class=\"form-control\" id=\"selectIdCamera\" name=\"id_camera\">");
                    $record = $resultSet->fetch_assoc();
                    while($record){
                        echo("<option value=\"".$record['id']."\">".$record['nr_camera']." [".$record['posti_letto']." posto/i letto]</option>");
                        $record = $resultSet->fetch_assoc();
                    }
                    echo("</select>");
                echo("</div>");

                $sql = "SELECT * FROM ostello_cliente";
                $resultSet = $db->query($sql);
                echo("<div class=\"form-group\">");
                    echo("<label for=\"selectIdCliente\">Selezionare la camera:</label>");
                    echo("<select class=\"form-control\" id=\"selectIdCliente\" name=\"id_cliente\">");
                    $record = $resultSet->fetch_assoc();
                    while($record){
                        echo("<option value=\"".$record['id']."\">".$record['cognome']." ".$record['nome']." - ".$record['email']."</option>");
                        $record = $resultSet->fetch_assoc();
                    }
                    echo("</select>");
                echo("</div>");
                $db->close();

                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputIncasso\">Incasso:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"incasso\" id=\"inputIncasso\">");
                echo("</div>");
                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputRank\">Apprezzamento (1-5):</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"rank\" id=\"inputRank\">");
                echo("</div>");

                echo("<input type=\"hidden\" name=\"scelta\" value=\"addPrenotazione\">");
                echo("<input type=\"submit\" class=\"btn btn-secondary\" value=\"Aggiungi Prenotazione\">");
            echo("</form>");
            break;
        }
        case "addPrenotazione":{
            // inserimento di una camera nel database.
            $data_inizio = $_REQUEST['data_inizio'];
            $data_fine = $_REQUEST['data_fine'];
            $id_cliente = $_REQUEST['id_cliente'];
            $id_camera = $_REQUEST['id_camera'];
            $incasso = $_REQUEST['incasso'];
            $rank = $_REQUEST['rank'];

            $sql = "INSERT INTO ostello_prenotazione(data_inizio, data_fine, id_camera, id_cliente, incasso, rank_apprezzamento) ";
            $sql .="VALUES('$data_inizio', '$data_fine', $id_camera, $id_cliente, $incasso, $rank)";

            $db = new mysqli("localhost","root","","scuola2021");
            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Inserimento prenotazione avvenuto.</div>");
            else
                echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in inserimento.</div>");

            $db->close();
            break;
        }
        case "deleteCamera":{
            $idCamera = $_REQUEST['idCamera'];

            $db = new mysqli("localhost","root","","scuola2021");
            $sql = "DELETE FROM ostello_camera WHERE id=".$idCamera;

            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Cancellazione avvenuta.</div>");
            else
                echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in cancellazione.</div>");

            $db->close();
            //*/
            break;
        }
        default:{
            echo("<div class=\"alert alert-info\" role=\"alert\">Nessuna scelta effettuata...</div>");
            break;
        }
    }
}
else{
    echo("Utente Non Riconosciuto, eseguire il login<br />");
    echo("<a href=\"index.php\">Torna alla Home Page</a>");
}
include("../foot.html");
?>