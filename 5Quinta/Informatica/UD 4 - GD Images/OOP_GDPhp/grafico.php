<?php
    require ("myGraph.php");

    $g = new myGraph(640, 480);
    $g->SetInternalMargins(70,60,150,50);
    
    $g->DrawBounds();
    $g->DrawInternalBounds();

    $valori = array(10,
                    40,
                    67, 
                    34,
                    99, 
                    110);
    $categorie = array("Luca",
                        "Anna",
                        "Marco",
                        "Roberta",
                        "Simone",
                        "Arianna");
    $g->SetValues($valori);
    $g->SetCategories($categorie);
    $g->DrawPoints();
    $g->DrawConnectionLines();
    $g->DrawValueLabels();
    $g->DrawReferenceLine();
    $g->WriteCategories(3);
    $g->SetTitles("Grafico di Prova della libreria GD", "Persone Coinvolte", "Km percorsi in settimana");
    $g->WriteTitles();
    $g->Output();

    /*$g->DrawPoint(1, 10);
    $g->DrawPoint(3, 10);
    $g->DrawPoint(5, 10);
    $g->DrawPoint(6, 10);
    $g->DrawPoint(9, 10);*/    
?>