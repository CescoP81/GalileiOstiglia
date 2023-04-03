<?php
    if(isset($_REQUEST['idMarca'])) $idMarca = $_REQUEST['idMarca']; else $idMarca = null;

    header("Content-Type: application/json; charset=UTF-8");
    $db = new mysqli("localhost", "root","","scuola2223");
    $query = "SELECT * FROM mezzo
                WHERE idMarca=$idMarca
                ORDER BY descrizione ASC";
    $rs = $db->query($query);
    $json = Array();
    //echo($query);
    //echo($rs->num_rows);
    while($row = $rs->fetch_assoc()){
        //echo($row['id']." ".$row['descrizione']."<br />");
        array_push($json, $row);
    }
    
    echo(json_encode($json));
    $db->close();
?>