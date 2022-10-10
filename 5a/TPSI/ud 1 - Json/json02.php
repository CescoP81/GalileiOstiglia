<?php
    header("Content-Type: application/json; charset=UTF-8");
    // connessione al database
    $db = new mysqli("localhost","root","","scuola2223");
    // creo la query da eseguire sul database
    $sql = "SELECT * FROM studenti";
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