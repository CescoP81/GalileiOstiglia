<?php
    require("required/mylib.php");
    require("../head.html");

    // aggancio al database ed interrogazione per avere tutti i record della tabella studenti.
    $db = new mysqli("localhost","root","","scuola2223");
    $sql = "SELECT * FROM studenti";
    $rs54 = $db->query($sql);
    $db->close();

    showResultSetTable($rs54, "Lista degli Studenti presenti");

    require("../foot.html");
?>