<?php
    require ("myGraph.php");

    $g = new myGraph(640, 480);
    $g->SetInternalMargins(150,50,100,50);
    
    $g->DrawBounds();
    $g->DrawInternalBounds();

    $valori = array(10,50,110,90,43,26,88);
    $g->SetValues($valori);
    $g->DrawPoints();
    $g->DrawConnectionLines();
    $g->DrawValueLabels();
    
    $g->Output();

    /*$g->DrawPoint(1, 10);
    $g->DrawPoint(3, 10);
    $g->DrawPoint(5, 10);
    $g->DrawPoint(6, 10);
    $g->DrawPoint(9, 10);*/
    
    
?>