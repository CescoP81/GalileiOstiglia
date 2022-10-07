<?php
    header("Content-Type: application/json; charset=UTF-8");
    // connessione al database
    $db = new mysqli("localhost","root","","scuola2223");
    // creo la query da eseguire sul database
    $sql = "SELECT * FROM studenti";
    // eseguo la query sulla connessione aperta con il database.
    // la roisultante viene messa in $rs (result set)
    $rs = $db->query($sql);
    $nRecord = $rs->num_rows;

    // vediamo i dati se sono stati recuperati
    /*while($record = $rs->fetch_assoc()){
        echo($record['id']." ".$record['nome']." ".$record['cognome']." ".$record['classe']."<br />");
    }*/
    $cnt=1;
    echo("[");
    while($record = $rs->fetch_assoc()){
        echo(json_encode($record));
        if($cnt < $nRecord)
            echo(",");
        $cnt++;
    }
    echo("]");

    $db->close();

?>