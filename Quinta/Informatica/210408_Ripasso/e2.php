<?php
$db = new mysqli("localhost", "root", "", "scuola2021");

    // eseguo la query con SELECT innestate e recupero i dati con un unico passaggio.
    $sql = "SELECT mt.valore, ms.nome, ms.posizione ";
    $sql .= "FROM meteo_temperature AS mt, meteo_stazioni AS ms ";
    $sql .= "WHERE ms.id = mt.id_stazione AND mt.valore >= (SELECT AVG(mt.valore) FROM meteo_temperature AS mt)";

    $resultSet = $db->query($sql);
    $record = $resultSet->fetch_assoc();
    while($record){
        echo($record['valore']." ".$record['nome']." ".$record['posizione']."<br />");
        $record = $resultSet->fetch_assoc();
    }

    echo("<br /><br />");

    // Passaggio equivalente con due query.
    // Primo passaggio recupero la temperatura media e me la salvo in una variabile.
    $sql = "SELECT AVG(mt.valore) AS 'media' ";
    $sql .= "FROM meteo_temperature AS mt";
    $resultSet = $db->query($sql);
    $record = $resultSet->fetch_assoc();
    $media_temperature = $record['media'];
    echo("Media: ".$media_temperature."<br />");

    // costruisco la seconda query usando il valore sopra recuperato, come filtro nella clausola WHERE.
    $sql = "SELECT mt.valore, ms.nome, ms.posizione ";
    $sql .= "FROM meteo_temperature AS mt, meteo_stazioni AS ms ";
    $sql .= "WHERE ms.id = mt.id_stazione AND mt.valore >= '$media_temperature'";
    echo($sql."<br />");
    $resultSet = $db->query($sql);
    $record = $resultSet->fetch_assoc();
    while($record){
        echo($record['valore']." ".$record['nome']." ".$record['posizione']."<br />");
        $record = $resultSet->fetch_assoc();
    }
$db->close();
?>