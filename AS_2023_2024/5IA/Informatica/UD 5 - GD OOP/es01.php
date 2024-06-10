<?php
    header ('Content-Type: image/png');

    require("graphic.php");

    $i = new Grafico(800, 600);
    $v = array(1,2,3,4,5,6,7,8,9,10);
    // 1- carico il vettore di valori da graficare.    
    $i->loadSerie($v);
    // 2- inizializzo il grafico.
    $i->InitGrafico();
    // 3- grafico i punti
    $i->deployPoint();
    // 4- grafico le linee

    // 5- Grafico le etichette degli assi.

    // 6- Grafico la legenda laterale destra.
    
    // ritorno il codice PNG dell'immagine creata.
    $i->DeployGrafico();
?>