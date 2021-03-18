<?php
    echo("<html><head><title>Report delle Temperature</title></head>");
    echo("<body>");

    $db = new mysqli("localhost","root","","scuola2021");
    $sql = "SELECT mt.valore, ms.nome AS stazione ";
    $sql .= "FROM meteo_temperature AS mt, meteo_stazioni AS ms ";
    $sql .= "WHERE mt.id_stazione = ms.id ORDER BY ms.id";

    $resultSet = $db->query($sql);
    $record = $resultSet->fetch_assoc();
    echo("<table border=\"1\">");
    echo("<tr>");
        echo("<th>#</th><th>Valore</th><th>Stazione Meteo</th>");
    echo("</tr>");
    $cnt = 1;
    while($record){
        echo("<tr><td>".$cnt."</td><td>".$record['valore']."</td><td>".$record['stazione']."</td></tr>");
        $record = $resultSet->fetch_assoc();
        $cnt++;
    }
    echo("</table>");
    echo("<br />");
    echo("<img src=\"multilinea_spezzata.php\" alt=\"Grafico multilinea delle temperature\" />");
    echo("<br /><br />");
    echo("Formato PDF: <a href=\"meteo_temperature_pdf.php\"><img src=\"../bsicons/printer.svg\" alt=\"Icona della stampante\" /></a>");


    echo("</body>");
    echo("</html>");
?>