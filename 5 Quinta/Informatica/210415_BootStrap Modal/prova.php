<?php
require('lib_functions.php');
require('../head.html');

    // esempio di tabella dinamica derivante da risultato di una query.
    $db = new mysqli("localhost","root","","scuola2021");
    $sql = "SELECT  * FROM fumetto";
    $resultSet = $db->query($sql);
    if($resultSet->num_rows > 0)
        createTable($resultSet, "Tabella dei Libri");

    echo("<br /><br />");
    $sql = "SELECT l.id, l.titolo, l.prezzo, l.anno, a.cognome, a.nome ";
    $sql .= "FROM libro AS l, autore AS a ";
    $sql .= "WHERE l.id_autore=a.id";
    $resultSet = $db->query($sql);
    if($resultSet->num_rows > 0)
        createTable($resultSet);
// */

    // esempio di uso dei campi modals
    $db = new mysqli("localhost","root","","scuola2021");
    $sql = "SELECT * FROM fumetto";
    $resultSet = $db->query($sql);
    if($resultSet->num_rows > 0){
        echo("<table border=\"2\">");
        $record = $resultSet->fetch_assoc();
        while($record){
            echo("<tr><td>".$record['id']."</td><td>".$record['titolo']."</td>");
            echo("<td>");
                echo("<button type=\"button\" class=\"btn btn-primary\" data-toggle=\"modal\" data-target=\"#modal".$record['id']."\">");
                    echo("Details");
                echo("</button>");

                $modalText = "<b>ID:</b> ".$record['id']."<br />";
                $modalText .= "<b>Collana:</b> ".$record['collana']."<br />";
                $modalText .= "<b>Titolo:</b> ".$record['titolo']."<br />";
                $modalText .= "<b>Editore:</b> ".$record['editore']."<br />";
                $modalText .= "<b>Prezzo:</b> ".$record['prezzo']."<br />";
                $modalText .= "<b>Anno Pubblicazione:</b> ".$record['anno_pub']."<br />";
                
                // eseguo la creazione del modal con la funzione creata nella lib_functions.php
                createModal("modal".$record['id'], $record['titolo'], $modalText);

            echo("</td>");
            echo("</tr>");
            $record = $resultSet->fetch_assoc();
        }
        echo("</table>");  
    }
//*/

    $db->close();
    require('../foot.html');
?>