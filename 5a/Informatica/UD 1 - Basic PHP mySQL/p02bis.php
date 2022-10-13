<?php
    require("../head.html");

    // aggancio al database ed interrogazione per avere tutti i record della tabella studenti.
    $db = new mysqli("localhost","root","","scuola2223");
    $sql = "SELECT cognome, nome FROM studenti";
    $rs = $db->query($sql);
    $db->close();

    require("required/showResultSetTable.php");

    require("../foot.html");
?>