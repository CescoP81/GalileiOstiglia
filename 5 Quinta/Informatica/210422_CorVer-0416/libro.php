<?php
// Variabili globali per aggancio al db con mysqli, da cambiare se diverse da quelle
// della macchina in uso.
$dbhost="localhost";
$dbuser="root";
$dbpassword="";
$dbname="scuola2021";
//--------------------------

if(isset($_REQUEST['scelta'])) $sc=$_REQUEST['scelta']; else $sc=null;

require('../head.html');

    // VISUALIZZAZIONE DEL MENU RICHIESTO
    echo("<a href=\"libro.php?scelta=nuovoLibro\">New Libro</a> | ");
    echo("<a href=\"libro.php?scelta=vediLibri\">Vedi Libri</a>");

    echo("<br /><br />");

    switch($sc){
        case "nuovoLibro":{
            // PRESENTA IL FORM DI INSERIMENTO DATI per un nuovo libro.
            echo("<form action=\"libro.php\" method=\"get\">");
            echo("<div class=\"form-group\">");
                echo("<label for=\"inputTitolo\">Titolo:</label>");
                echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"titolo\" id=\"inputTitolo\"><br/>");
                
                echo("<label for=\"inputNumeroPagine\">Nr. Pagine:</label>");
                echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"nr_pagine\" id=\"inputNumeroPagine\"><br/>");
            
                echo("<label for=\"inputPrezzo\">Prezzo:</label>");
                echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"prezzo\" id=\"inputPrezzo\"><br/>");
                  
                $db = new mysqli("localhost","root","","scuola2021");
                $sql = "SELECT * FROM v_autore";
                $resultSet = $db->query($sql);
                echo("<label for=\"selectAutore\">Autore</label>");
                echo("<select class=\"form-control\" id=\"selectAutore\" name=\"id_autore\">");
                    $record = $resultSet->fetch_assoc();
                    while($record){
                        echo("<option value=\"".$record['id']."\">".$record['cognome']." ".$record['nome']."</option>");
                        $record = $resultSet->fetch_assoc();
                    }
                echo("</select>");
                $db->close();
                echo("</div>");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"addLibro\">");
                echo("<input type=\"submit\" class=\"btn btn-secondary\" value=\"Aggiungi Libro\">");
            echo("</form>");
            break;
        }
        case "addLibro":{
            $titolo = $_REQUEST['titolo'];
            $n_pagine = $_REQUEST['nr_pagine'];
            $prezzo = $_REQUEST['prezzo'];
            $id_autore = $_REQUEST['id_autore'];

            $db = new mysqli($dbhost,$dbuser,$dbpassword,$dbname);
            $sql = "INSERT INTO v_libro(titolo, n_pagine, prezzo, id_autore) ";
            $sql .= "VALUES('$titolo', $n_pagine, $prezzo, $id_autore)";

            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Inserimento Libro avvenuto.</div>");
            else
                echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in inserimento.</div>");
            $db->close();
            break;
        }

        case "vediLibri":{
            if(isset($_REQUEST['order'])) $orderby=$_REQUEST['order']; else $orderby='id';
            $db = new mysqli($dbhost,$dbuser,$dbpassword,$dbname);
            $sql = "SELECT libro.id, libro.titolo, libro.n_pagine, libro.prezzo, autore.cognome, autore.nome ";
            $sql .= "FROM v_libro AS libro, v_autore AS autore ";
            $sql .= "WHERE libro.id_autore=autore.id ";
            $sql .= "ORDER BY $orderby";

            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            $columns = array_keys($record);     // genero il vettore $columns con tutte le chiavi del vettore $record
            echo("<table class=\"table table-hover\">");
                echo("<caption>Tabella Libri-Autori</caption>");
                echo("<thead  class=\"thead-dark\">");
                echo("<tr>");
                    for($i=0; $i<count($columns); $i++)
                        echo("<th  scope=\"col\"><a href=\"libro.php?scelta=vediLibri&order=".$columns[$i]."\">".$columns[$i]."</a></th>");
                echo("</tr>");
                echo("</thead>");

                echo("<tbody>");
                while($record){
                    echo("<tr>");
                    for($i=0; $i<count($record); $i++)
                        echo("<td>".$record[$columns[$i]]."</td>"); // $record['id'] -- $record['titolo']
                    echo("</tr>");
                    $record = $resultSet->fetch_assoc();
                }
                echo("</tbody>");
            echo("</table>");
            $db->close();
            break;
        }
        default:{
            break;
        }
    }
require('../foot.html');
?>