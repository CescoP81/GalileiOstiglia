<?php
    // funzione echo() per la stampa di messaggi, stringhe da restituire al browser.
    echo("<HTML>
        <HEAD><TITLE>Prove di PHP</TITLE></HEAD>
        <BODY>
    ");

    echo("Hello World to 5IA...<br /><br />");

    // esempio di ciclo while per stampa di 10 numeri random, da notare la sintassi praticamente identica al conosciuto C/C++.
    $cnt = 1;
    while($cnt <= 10){
        $nRandom = rand(10, 45);
        if($nRandom%2 == 0)
            echo($nRandom. " è pari<br />");           // l'operatore '.', punto, serve per concatenare variabili e stringhe.
        else
            echo($nRandom. " è dispari<br />");
        
        $cnt++;
    }

    echo("<br /><br />");

    // esempio di come si può modificare velocemente il contenuto di una variabile da numero intero a stringa, senza casting o altro.
    $cnt = "MA che bello il PHP...";
    echo($cnt);

    echo("</BODY>
        </HTML>
    ");
?>