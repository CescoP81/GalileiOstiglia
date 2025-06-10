<?php
/**
 * Pagina di esempio con passaggio di parametri tramite indirizzo HTTP (URL)
 * dove sfrutto le coppie chiave-valore ed il vettore REQUEST
 * 
 * http://...../p1.php?chiave1=4&chiave2=24
 * chiave1 e chiave2 sono i parametri passati tramire richiesta http, i cui valori sono
 * in questo caso specifico 4 e 24.
 * 
 * NOTA:
 * Anticamente esistevano solo due vettori $_GET[] $_POST[], dalla versione PHP 4.x o 5.x
 * sono stati mantenuti ma sono anche stati inglobati in un vettore più generale ovvero $_REQUEST[].
 */

    if(isset($_REQUEST['chiave1'])) $c1 = $_REQUEST['chiave1']; else $c1 = 0;
    //$c1 = $_REQUEST['chiave1'];
    if(isset($_REQUEST['chiave2'])) $c2 = $_REQUEST['chiave2']; else $c2 = 0;
    //$c2 = $_REQUEST['chiave2'];

    /* serie numeri da c1 a c2 estremi compresi */
    for($i=$c1; $i<=$c2; $i++){
        echo($i." ");
    }
    echo("<br />");
    /* serie dei numeri pari tra c1 e c2 estremi compresi */
    for($i=$c1; $i<= $c2; $i++){
        if($i%2 == 0)
            echo($i." ");
    }
    echo("<br />");
    /* serie dei numeri pari e dispari tra c1 e c2 estremi compresi, con i pari maggiorati
    rispetto ai dispari */
    for($i=$c1; $i<=$c2; $i++){
        if($i%2 == 0){
            echo('<font size="8">'.$i.'</font> ');
        }
        else{
            echo('<font size="4">'.$i.'</font> ');
        }
    }
?>