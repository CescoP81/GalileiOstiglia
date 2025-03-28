<?php
require("GraficoGD.php");

    $im = new GraficoGD();
    $im->createTela();
    $im->createBorder();
    $im->disegnaLinea();
    $im->getPngImage();
?>