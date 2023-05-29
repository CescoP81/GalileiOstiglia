<?php
if(isset($_REQUEST['classe'])) $classe = $_REQUEST['classe']; else $classe = null;

if(isset($_REQUEST['annoMinimo'])) $amin = $_REQUEST['annoMinimo']; else $amin = null;
if(isset($_REQUEST['annoMassimo'])) $amax = $_REQUEST['annoMassimo']; else $amax = null;

    header("Content-Type: application/json; charset=UTF-8");
    // connessione al database
    $db = new mysqli("localhost","root","","scuola2223");
    // creo la query da eseguire sul database
    $sql = "SELECT * 
            FROM studenti
            WHERE 1=1 ";

    if($classe != null)
        $sql .= " AND classe='$classe'";
    if($amin!=0 && $amax!=0)
        $sql .= " AND anno_nascita>=$amin AND anno_nascita<=amax";

    // eseguo la query sulla connessione aperta con il database.
    // la roisultante viene messa in $rs (result set)
    $rs = $db->query($sql);
    
    $risultati = Array();
    while($record = $rs->fetch_assoc()){
        array_push($risultati, $record);
    }
    echo(json_encode($risultati));

    $db->close();
?>