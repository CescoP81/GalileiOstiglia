<?php
    echo("Sono nella pagina PHP...ora dovrei fare qualcosa!?<br /><br />");
    $_base = $_REQUEST['base'];
    $_altezza = $_REQUEST['altezza'];

    // step 2 -> disegno il rettangolo
    for($i=1; $i<=$_altezza; $i++){
        for($j=1; $j<=$_base; $j++){
            echo("* ");    
        }
        echo("<br />");
    }
    echo("<br /><br />");
    
    // step 3 -> calcolo e comunicazione dei risultati
    $area = $_base * $_altezza;
    $perimetro = ($_base + $_altezza) * 2;
    echo("Area: ".$area."<br />");
    echo("Perimetro: ".$perimetro."<br />");
?>