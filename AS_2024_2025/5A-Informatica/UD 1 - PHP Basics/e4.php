<?php 
/*
    Realizzare uno script PHP che riceve due valori interi nel vettore
    delle request con chiave 'Val' e 'Direzione'. 
    Se 'Direzione' vale 1 allora lo script comunica il numero primo successivo 
    al valore di 'Val'; se invece vale -1 allora comunica il precedente numero primo
    rispetto a 'Val' se esiste prima di arrivare a 0.
    */
$valore = $_REQUEST['Val'];
$direzione = $_REQUEST['Direzione'];

$cnt = 0;
$div = 1;

    if($direzione == 1){
        // cerco il numero primo successivo a quello inserito come valore
        do{
            $valore++;
            $cnt = 0;
            $i = 1;
            while($i <= $valore){
                if($valore%$i == 0)
                    $cnt++;
                $i++;
            }
        }while($cnt>2);
        echo("Il valore PRIMO successivo a quello inserito è: ".$valore);
    }
    if($direzione == -1){
        // cerco il numero primo precedente a quello inserito come valore
        do{
            $valore--;
            $cnt = 0;
            $i = 1;
            while($i <= $valore){
                if($valore%$i == 0)
                    $cnt++;
                $i++;
            }
        }while($cnt>2);
        echo("Il valore PRIMO precedente a quello inserito è: ".$valore);
    }

?>