<?php
/**
 * Script che utilizza i valori presenti nella chiavi 'base' e 'altezza' 
 * del vettore $_REQUEST[] al fine di calcolare area e perimetro di un
 * ipotetico rettangolo.
 */

 // verifica esistenza delle chiavi richieste. !!FONDAMENTALE!!
 if(isset($_REQUEST['base'])) $b = $_REQUEST['base'];
 else $b = -1;

 if(isset($_REQUEST['altezza'])) $h = $_REQUEST['altezza'];
 else $h = -1;

    // test sulle variabili b e h e conseguente calcolo e output dati
    if(($b != -1) && ($h != -1)){
        // ho valori validi sia per la base sia per l'altezza
        $area = $b * $h;
        $perimetro = ($b + $h) * 2;
        echo('Area pari a: '.$area.'<br />');
        echo('Perimetro pari a: '.$perimetro.'<br />');
    }
    else{
        echo('Valori mancanti o chiave errata.');
    }
?>