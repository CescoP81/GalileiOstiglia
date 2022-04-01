<?php
    require ("myGraph.php");

    $g = new myGraph(640, 480);
    $g->SetInternalMargins(150,50,100,50);
    
    $g->DrawBounds();
    $g->DrawInternalBounds();

    $valori = array(5,5,2,1,6,9);
    $g->SetValues($valori);
    $g->DrawPoints();
    /*$g->DrawPoint(1, 10);
    $g->DrawPoint(3, 10);
    $g->DrawPoint(5, 10);
    $g->DrawPoint(6, 10);
    $g->DrawPoint(9, 10);*/
    
    $g->Output();
?>