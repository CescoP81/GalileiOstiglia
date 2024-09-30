<?php
    echo('<!DOCTYPE HTML>
        <html>
            <head>
                <meta charset="UTF-8">
                <title>Prova di REQUEST HTTP</title>
            </head>
            <body>    
    ');
/*  Realizzare un script che riceve tramite REQUEST due chiavi chiamate
    'ValA' e 'ValB' con valori interi positivi maggiori di zero,
    lo script dopo aver verificato la validità dei valori visualizza
    la lista dei divisori comuni.
    es1. ValA=12 ValB=18 -> 1 2 3 6
    es2. ValA=-4 ValB=18 -> Valore/i errato/i
    es3. ValA=8 ValoreB=16 -> Chiave mancante o errata.
*/
    // test sulle chiavi che mi aspetto dalla richiesta HTTP.
    if(isset($_REQUEST['ValA'])) $va = $_REQUEST['ValA'];
    else $va = -1;

    if(isset($_REQUEST['ValB'])) $vb = $_REQUEST['ValB'];
    else $vb = -1;

    if(($va == -1) || ($vb == -1)){
        echo('Una o più chiavi mancanti.<br />');
    }
    else{
        // test sulla validità dei valori inseriti
        if(($va > 0) && ($vb > 0)){
            // sono nel caso in cui le chiavi esistano e i valori assegnati siano diversi da zero.
            // quindi eseguo l'algoritmo di calcolo dei divisori comuni.
            $min = 0;
            if($va < $vb)   $min = $va;
            else    $min = $vb;

            echo('Divisori comuni ai numeri '.$va.' e '.$vb.': ');
            for($i=1; $i<=$min; $i++){
                if(($va%$i == 0) && ($vb%$i == 0))
                    echo($i.' ');
            }
        }
        else{
            echo('Uno o entrambi i valori iniziali non sono maggiori di zero!<br />');
        }
    }

    echo('</body>
    </html>
    ');
?>