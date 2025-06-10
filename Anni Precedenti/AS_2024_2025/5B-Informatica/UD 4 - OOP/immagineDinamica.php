<?php
require("GraficoGD.php");

    // mi imposta le dimensioni a 640,480 di default.
    $im = new GraficoGD();
    $im->setNewDimensions(400,300);

    $im->createTela();
    $im->createBorder();
    //$im->disegnaLinea();
    $im->disegnaLineaXY(10,10, 100, 10);
    $im->disegnaLineaXY(100,140, 100, 240);
    $im->getPngImage();
?>