<?php
$host = "localhost";
$user = "root";
$password = "";
$db_name = "scuola2223";

$db = new mysqli($host, $user, $password, $db_name);

$sql = "CREATE TABLE IF NOT EXISTS prova_pdf(
    id integer unsigned auto_increment, 
    postazione integer unsigned, 
    mmPioggia integer unsigned, 
    primary key(id))";
    
    if($db->query($sql)) echo("Table OK<br />");
    else echo("Problem Table<br />");

    $postazione = 0;
    $mmPioggia = 0;
    for($i=0; $i<=50; $i++){
        $postazione = 1 + rand()%3;
        $mmPioggia = rand()%50;

        $sql = "INSERT INTO prova_pdf(postazione, mmPioggia) VALUES($postazione, $mmPioggia)";
        if($db->query($sql))
            echo($sql." -> Row OK.<br />");
        else
            echo($sql." -> Row Issue.<br />");
    }
    $db->close();
?>