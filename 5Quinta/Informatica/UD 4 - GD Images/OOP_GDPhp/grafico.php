<?php
    require ("myGraph.php");

    $g = new myGraph(640,480);
    $g->SetInternalMargins(50,50,100,100);
    
    $g->DrawBounds();
    $g->DrawInternalBounds();
    
    $g->Output();
?>