<?php
    echo("<HTML>
    <HEAD><TITLE>Prove con i Vettori</TITLE></HEAD>
    <BODY>
    ");

    // http://scuola.localhost/AS_2023_2024/5I%20-%20Informatica/UD%201%20-%20PHP%20Basic/p03.php?numeroUtente=34
    $base = $_REQUEST['baseUtente'];
    $altezza = $_REQUEST['altezzaUtente'];

    echo("Ho un rettangolo di base: ".$base." e altezza: ".$altezza."<br />");
    echo("Area: ". ($base*$altezza)." <br />");
    echo("Perimetro: ".(($base+$altezza)*2)."<br />");

    echo("<br /><a href=\"p03.html\">Torna al modulo</a>");

    echo("</BODY>
        </HTML>
    ");
?>