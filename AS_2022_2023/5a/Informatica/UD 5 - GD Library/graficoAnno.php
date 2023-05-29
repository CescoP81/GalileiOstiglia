<?php
if(isset($_REQUEST['rifAnno'])) $anno = $_REQUEST['rifAnno'];
else $anno = Date("Y"); // -> mi restituisci l'anno corrente.
/*
    $record = [anno][2022], [gen][12], ...
*/
header("Content-type: image/png");

// recupero i dati dal database.
$db = new mysqli("localhost","root","","scuola2223");
$sql = "SELECT gen, feb, mar, apr, mag, giu FROM datigrafico WHERE anno='$anno'";
$rs = $db->query($sql);
$db->close();

$fattibile = true;          // fattibile lo uso come flag, vale true se la query mi ha estratto almeno un record, altrimenti vale false.
if($rs->num_rows == 0)      // in base allo stato di 'fattibile' poi determino se fare il grafico o il messaggio di errore.
    $fattibile = false;

    // RECUPERATI VALORI E ETICHETTE (VALUES, LABELS) COSTRUISCO IL GRAFICO.
    /*### DATI INIZIALI PER LA CREAZIONE DEL GRAFICO ###
    - Dimensioni dell'area grafica.
    - Margini attorno al grafico.
    - Allocazione colori.
    - Calcolo di dimensioni relative utili alle proporzioni di graficazione. */
    $width = 640;           // larghezza totale dell'area immagine.
    $height = 480;          // altezza totale dell'area immagine.

    $marginTop = 50;        // margine superiore al grafico.
    $marginLeft = 150;      // margine sinistro al grafico.
    $marginBottom = 130;     // margine inferiore al grafico.
    $marginRight = 70;      // margine destro al grafico.

    /* ### CREAZIONE DELLA TELA GRAFICA E ALLOCAZIONE DI ALCUNI COLORI */
    $im = imageCreate($width, $height);                             // creo l'area grafica.
    $white = imageColorAllocate($im, 255,255,255);                  // alloco i colori necessari, il primo è il background dell'area grafica.
    $black = imageColorAllocate($im, 0,0,0);
    $gray = imageColorAllocate($im, 200,200,200);
    $red = imageColorAllocate($im, 200,0,0);
    $green = imageColorAllocate($im, 0,200,0);
    $blue = imageColorAllocate($im, 0,0,200);

if($fattibile){
    $record = $rs->fetch_assoc();

    // recupero e creo un vettore labels con i nomi delle colonne che compongono un record.
    $labels = array_keys($record);
    $values = Array();
    for($i=0; $i<count($labels); $i++){
        //echo($record[$labels[$i]]."<br />");
        array_push($values, $record[$labels[$i]]);
    }    

    $availableHeight = $height - $marginTop - $marginBottom;        // calcolo dell'altezza massima del grafico, necessario per le proporzioni.
    $numberOfValues = count($values);                               // determino quanti elementi devo graficare.
    $maxValue = $values[0];                                         // determino il valore massimo presente nel vettore.
    for($i=1; $i<$numberOfValues; $i++)
        if($values[$i] > $maxValue)
            $maxValue = $values[$i];
    $maxValue += 5;    

    // disegno il perimetro della png.
    imageRectangle($im, 0, 0, $width-1, $height-1, $black);

    // disegno il perimetro del grafico.
    imageRectangle($im, $marginLeft, $marginTop, $width-$marginRight, $height-$marginBottom, $blue);

    // grafico le tacche sull'asse x del grafico.
    $dx = ($width-$marginLeft-$marginRight)/($numberOfValues-1);
    $x = $marginLeft;
    for($i = 0; $i<$numberOfValues; $i++){
        imageLine($im, $x, $height-$marginBottom-5, $x, $height-$marginBottom+5, $red);
        $x = $x + $dx;
    }
    // */

    /* grafico le linee orizzontali di riferimento */
    $dy =   $availableHeight / 9;   // lo spazio tra una linea e l'altra, la prima linea coincide con l'asse y e l'ultima con il bordo dell'area grafico.
    $y = $height-$marginBottom;
    for($i = 1; $i<=10; $i++){
        if($y < $marginTop) $y = $marginTop;
        imageLine($im, $marginLeft-5, $y, $marginLeft+5, $y, $red);
        $y = $y - $dy;
    }

    /* visualizzo le etichette valori di riferimento a fianco dell'asse y */
    $dy =   $availableHeight / 9;
    $y = $height-$marginBottom;
    $value = 0;
    for($i = 1; $i<=10; $i++){
        if($y < $marginTop) $y = $marginTop;
        $numberOfDigits = strlen((string)round($value));
        imageString($im, 3, $marginLeft-($numberOfDigits*8)-10, $y-7, round($value), $black);
        $y = $y - $dy;
        $value = $value + ($maxValue/10);
    }

    /*  grafico i punti all'interno del grafico.
        la coordinata Y del punto la devo determinare come proporzione del valore massimo presente nel vettore con il valore massimo di altezza disponibile.
        $availableHeight:$maxValue = $y:$values[$i] -> $y = $availableHeight*$values[$i]/$maxValue
        Devo poi individuarla all'interno dell'area grafica sapendo che l'asse Y è invertito rispetto al normale.
    */
    $x = $marginLeft;
    for($i = 0; $i<$numberOfValues; $i++){
        $y = $availableHeight*$values[$i]/$maxValue;

        imageFilledEllipse($im, $x, $height-$marginBottom-$y, 10,10, $green);
        $x = $x + $dx;
    }//*/

    /* Grafico le linee tra i punti, il ciclo che si muove sul vettore dei valori deve fermarsi sul penultimo valore,
        perchè una linea parte dal punti i e arriva al punto i+1. */
        $x = $marginLeft;
    for($i = 0; $i<$numberOfValues-1; $i++){
        $y1 = $availableHeight*$values[$i]/$maxValue;
        $y2 = $availableHeight*$values[$i+1]/$maxValue;

        imageLine($im, $x, $height-$marginBottom-$y1, $x+$dx, $height-$marginBottom-$y2, $green);
        $x = $x + $dx;
    }//*/

    /* Visualizzo le stringhe come didascalie dell'asse x. */
    $x = $marginLeft;
    for($i = 0; $i<$numberOfValues; $i++){
        imageString($im, 4, $x-12, $height-$marginBottom+10, $labels[$i], $black);
        $x = $x + $dx;
    }// */
}
else{
    $str = "ALERT - ERRORE NEI DATI O DATI INESISTENTI".
    imageRectangle($im, 0, 0, $width-1, $height-1, $black);
    imageString($im, 5, ($width/2)-(strlen($str)*8)/2, ($height/2), $str, $red);
}
imagePNG($im);
imageDestroy($im);
?>