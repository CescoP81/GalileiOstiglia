<?php
/*  Author: Pradella Francesco
    Start Date: 12/03/2021
    Last Modify Date: 12/03/2021
    Description: Pagina di gestione tabelle Progetto6_pag285
*/
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;
$host = "localhost";
$user = "root";
$password = "";
$dbname = "scuola2021";

require("../head.html");
    echo("<nav class=\"navbar navbar-expand-lg navbar-light bg-light\">");
        echo("<div class=\collapse navbar-collapse\" id=\"navbarNav\">");
        echo("<ul class=\"navbar-nav\">");
            echo("<li class=\"nav-item\">");
                echo("<a class=\"nav-link\" href=\"p6.php?scelta=cliente\">Cliente</a>");
            echo("</li>");
            echo("<li class=\"nav-item\">");
            echo("<a class=\"nav-link\" href=\"p6.php?scelta=nazione\">Nazione</a>");
            echo("</li>");
            echo("<li class=\"nav-item\">");
            echo("<a class=\"nav-link\" href=\"p6.php?scelta=organizzazione\">Organizzazione</a>");
            echo("</li>");
            echo("<li class=\"nav-item\">");
            echo("<a class=\"nav-link\" href=\"p6.php?scelta=servizio\">Servizio</a>");
            echo("</li>");
        echo("</ul>");
        echo("</div>");
    echo("</nav>");

    switch($sc){
        case "cliente":{
            $db = new mysqli($host, $user, $password, $dbname);
            $sql = "SELECT * FROM p6_cliente";
            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            echo("<table class=\"table\">");
            echo("<caption>Lista Tabella Cliente</caption>");
            echo("<thead><tr><th scope=\"col\">#</th><th scope=\"col\">Nome</th></tr></thead>");
            echo("<tbody>");
                while($record){
                    echo("<tr><th scope=\"row\">".$record['id']."</th><td>".$record['nome']."</td></tr>");
                    $record = $resultSet->fetch_assoc();
            }
            echo("</tbody>");
            echo("</table>");
            $db->close();
            break;
        }
        case "nazione":{
            $db = new mysqli($host, $user, $password, $dbname);
            $sql = "SELECT * FROM p6_nazione";
            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            echo("<table class=\"table\">");
            echo("<caption>Lista Tabella Nazione</caption>");
            echo("<thead><tr><th scope=\"col\">#</th><th scope=\"col\">Nome</th></tr></thead>");
            echo("<tbody>");
                while($record){
                    echo("<tr><th scope=\"row\">".$record['id']."</th><td>".$record['nome']."</td></tr>");
                    $record = $resultSet->fetch_assoc();
            }
            echo("</tbody>");
            echo("</table>");
            $db->close();
            break;
        }
        case "organizzazione":{
            $db = new mysqli($host, $user, $password, $dbname);
            $sql = "SELECT * FROM p6_organizzazione";
            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            echo("<table class=\"table\">");
            echo("<caption>Lista Tabella Organizzazione</caption>");
            echo("<thead><tr><th scope=\"col\">#</th><th scope=\"col\">Nome</th></tr></thead>");
            echo("<tbody>");
                while($record){
                    echo("<tr><th scope=\"row\">".$record['id']."</th><td>".$record['nome']."</td></tr>");
                    $record = $resultSet->fetch_assoc();
            }
            echo("</tbody>");
            echo("</table>");
            $db->close();
            break;
        }
        case "servizio":{
            $db = new mysqli($host, $user, $password, $dbname);
            $sql = "SELECT s.id, s.nome, s.prezzo, o.nome AS organizzazione, n.nome AS nazione ";
            $sql .= "FROM p6_servizio AS s, p6_organizzazione AS o, p6_nazione as n ";
            $sql .= "WHERE o.id=s.id_organizzazione AND s.id_nazione=n.id";
            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            echo("<table class=\"table\">");
            echo("<caption>Lista Tabella Servizio</caption>");
            echo("<thead><tr><th scope=\"col\">#</th><th scope=\"col\">Nome</th><th scope=\"col\">Prezzo</th><th scope=\"col\">Organizzazione</th><th scope=\"col\">Nazione</th></tr></thead>");
            echo("<tbody>");
                while($record){
                    echo("<tr><th scope=\"row\">".$record['id']."</th><td>".$record['nome']."</td><td>".$record['prezzo']."</td><td>".$record['organizzazione']."</td><td>".$record['nazione']."</td></tr>");
                    $record = $resultSet->fetch_assoc();
            }
            echo("</tbody>");
            echo("</table>");
            $db->close();
            break;
        }
    }

require("../foot.html");
?>