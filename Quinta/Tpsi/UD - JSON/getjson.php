<?php
    $db = new mysqli("localhost","root","","scuola2021");
    $sql = "SELECT * FROM meteo_stazioni WHERE id=1";
    $resultSet = $db->query($sql);
    $db->close();

    $record = $resultSet->fetch_assoc();
    echo(json_encode($record));
    
    /*echo("[");
        while($record = $resultSet->fetch_assoc()){
            echo(json_encode($record));
        }
    echo("]");*/
?>