<?php
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST');
header('Access-Control-Allow-Headers: Origin, Content-Type, X-Auth-Token');

header('Content-Type: application/json');

require('libgenerale.php');

    $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
    $sql = "SELECT * FROM concessionaria ORDER BY id DESC";
    $resultSet = $db->query($sql);
    $db->close();


    $json = array();
    while($record = $resultSet->fetch_assoc()){
        array_push($json, $record);
    }

    echo(json_encode($json));    
?>