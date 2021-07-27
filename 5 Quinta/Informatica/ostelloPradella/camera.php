<?php
/*  Pagina di gestione tabella ostello_camera
 Scelta:
 default: non visualizzo nulla.
 showcamera: visualizza tuttle camere della tabella.
 formCamera: Visualizza il form per inserimento nuova camera.
 addCamera: Inserisce i dati del form nella tabella come nuovo record.
 deleteCamera: Cancella un record specifico dalla tabella ostello_camera.
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
        case "showCamera":{
            $db = new mysqli("localhost","root","","scuola2021");
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
            $db->close();
            break;
        }
        case "formCamera":{
            // visualizza il form per inserimento dati da utente.
            echo("<form action=\"camera.php\" method=\"get\">");
                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputNrCamwera\">Numero camera:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"nr_camera\" id=\"inputNrCamera\">");
                echo("</div>");
                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputPostiLetto\">Posti letto:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"posti_letto\" id=\"inputPostiLetto\">");
                echo("</div>");
                echo("<label>Bagno in camera:</label>");
                echo("<div class=\"form-check\">");
                    echo("<input class=\"form-check-input\" type=\"radio\" name=\"bagno_in_camera\" id=\"inputBagno1\" value=\"1\" checked>");
                    echo("<label form-check-label for=\"inputBagno1\">Si:</label>");
                echo("</div>");
                echo("<div class=\"form-check\">");
                    echo("<input class=\"form-check-input\" type=\"radio\" name=\"bagno_in_camera\" id=\"inputBagno2\" value=\"0\">");
                    echo("<label form-check-label for=\"inputBagno2\">No:</label>");
                echo("</div>");
                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputPrezzo\">Prezzo giornaliero:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"prezzo_giornaliero\" id=\"inputPrezzo\">");
                echo("</div>");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"addCamera\">");
                echo("<input type=\"submit\" class=\"btn btn-secondary\" value=\"Aggiungi Camera\">");
            echo("</form>");
            break;
        }
        case "addCamera":{
            // inserimento di una camera nel database.
            $nr_camera = $_REQUEST['nr_camera'];
            $posti_letto = $_REQUEST['posti_letto'];
            $bagno = $_REQUEST['bagno_in_camera'];
            $prezzo = $_REQUEST['prezzo_giornaliero'];

            $sql = "INSERT INTO ostello_camera(nr_camera, posti_letto, bagno_in_camera, prezzo_giornaliero) VALUES('$nr_camera',$posti_letto,'$bagno',$prezzo)";

            $db = new mysqli("localhost","root","","scuola2021");
            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Inserimento camera avvenuto.</div>");
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