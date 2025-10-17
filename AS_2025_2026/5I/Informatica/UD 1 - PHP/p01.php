<?php
    echo("<!DOCTYPE html>
        <html>
            <head><title>Prime prove di linguaggio PHP</title></head>
            <body>");
    // Dichiarazione di una variabile -> si usa il carattere $ seguito dal nome della variabile.
    $box = 12; //dichiara una variabile che contiene il valore intero 12;
    echo($box);
    echo("<br />");
    
    $box = "caspiterina";   // alla stessa variabile cambio contenuto con una stringa.
    echo($box);
    echo("<br />");

    $box = 13.45;           // inserisco un valore reale e la variabile si "adatta" automaticamente.
    echo($box);
    echo("<br />");

    $box = 11;              // torno ad inserire un intero e poi lo vado a dividere per due
    $box = $box / 2;        // la variabile diventa un float perchè viene creata la parte decimale.
    echo($box);
    echo("<br />");

    $box = 4;
    if($box >= 5){
        echo("Il valore in box è maggiore o uguale a 5.");
    }
    else{
        echo("Il valore è compreso tra 1 e 5.");
    }

    echo("<br >");
    for($i=1; $i<=10; $i++){    // esempio di ciclo for.
        echo($i." ");           // il carattere . concatena variabili e stringhe.
    }

    echo("<br />");
    $i=1;
    do{                         // esempio di ciclo do-while.
        echo($i." ");
        $i = $i + 1;
    }while($i<=10);
    
    echo("<br /><br />");
    // voglio realizzare in output una tabelline da 1 a 5
    echo("<table border=\"2\">");
    for($i=1; $i<=5; $i++){
        echo("<tr>");
        for($j=1; $j<=5; $j++){
            $ris = $i * $j;
            echo("<td>");
            echo($ris);
            echo("</td>");
        }
        echo("</tr>");
    }
    echo("</table>");

    echo("</body></html>");
?>