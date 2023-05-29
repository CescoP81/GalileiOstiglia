<?php
    header("Content-Type: application/json; charset=UTF-8");
    $db = new mysqli("localhost", "root","","scuola2223");
    $query = "SELECT * FROM marca_automezzo ORDER BY descrizione ASC";
    $rs = $db->query($query);
    $json = Array();

    while($row = $rs->fetch_assoc()){
        array_push($json, $row);
    }

    echo(json_encode($json));
    $db->close();
?>