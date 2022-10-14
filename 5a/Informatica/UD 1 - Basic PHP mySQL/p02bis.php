<?php
    require("../head.html");

    // aggancio al database ed interrogazione per avere tutti i record della tabella studenti.
    $db = new mysqli("localhost","root","","scuola2223");
    $sql = "SELECT * FROM studenti";
    $rs = $db->query($sql);
    
    require("required/showResultSetTable.php");


    $sql = "SELECT cognome,classe FROM studenti";
    $rs = $db->query($sql);
    
    require("required/showResultSetTable.php");
    $db->close();

    require("../foot.html");
?>