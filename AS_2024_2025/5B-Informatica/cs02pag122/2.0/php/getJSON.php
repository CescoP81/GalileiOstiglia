<?php
header('Content-Type: application/json');
require('../include/lib.php');
// require('libgenerale.php');

    $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
    $sql = "SELECT * FROM magazzino";
    $resultSet = $db->query($sql);

    $json = array();
    while($record = $resultSet->fetch_assoc()){
        array_push($json, $record);
    }

    echo(json_encode($json));

    $db->close();
?>