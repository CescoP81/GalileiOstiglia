<?php
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST');
header('Access-Control-Allow-Headers: Origin, Content-Type, X-Auth-Token');
header('Content-Type: application/json');

if(isset($_REQUEST['limit'])) $lim = $_REQUEST['limit']; else $lim = null;

require('libgenerale.php');

    $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
    $sql = "SELECT * 
            FROM temperatura 
            ORDER BY id DESC";
    if($lim != null)
        $sql .= " LIMIT $lim";
    //echo($sql);
    $resultSet = $db->query($sql);
    $db->close();


    $json = array();
    while($record = $resultSet->fetch_assoc()){
        array_push($json, $record);
    }

    echo(json_encode($json));    
?>