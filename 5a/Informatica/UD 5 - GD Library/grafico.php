<?php
/*  Esempio di sviluppo di un grafico dati in PHP partendo da equivalenti grafici realizzati con LibreOffice Calc.
    Il codice che segue realizza un grafico a linea spezzata ipotizzando di dover graficare le temperature medie
    dei dodici mesi dell'anno.
    Il grafico prevede le etichette sugli assi X e Y, legende sugli assi X e Y, un titolo generale del grafico.
    E' possibile con le impostazioni iniziali definire quanto spazio bianco vi è attorno all'area del grafico.
*/
header("Content-type: image/png");

// Vettori contenenti i valori e le etichette da graficare.
$values = Array(8,12,16,20,25,28,33,32,27,14,13,10);
$labels = Array('Gen','Feb','Mar','Apr','Mag','Giu','Lug','Ago','Set','Ott','Nov','Dic');

/*### DATI INIZIALI PER LA CREAZIONE DEL GRAFICO ###
- Dimensioni dell'area grafica.
- Margini attorno al grafico.
- Allocazione colori.
- Calcolo di dimensioni relative utili alle proporzioni di graficazione. */
$width = 640;           // larghezza totale dell'area immagine.
$height = 480;          // altezza totale dell'area immagine.

$marginTop = 30;        // margine superiore al grafico.
$marginLeft = 150;      // margine sinistro al grafico.
$marginBottom = 130;     // margine inferiore al grafico.
$marginRight = 50;      // margine destro al grafico.

$availableHeight = $height - $marginTop - $marginBottom;        // calcolo dell'altezza massima del grafico, necessario per le proporzioni.
$numberOfValues = count($values);                               // determino quanti elementi devo graficare.
$maxValue = $values[0];                                         // determino il valore massimo presente nel vettore.
for($i=1; $i<$numberOfValues; $i++)
    if($values[$i] > $maxValue)
        $maxValue = $values[$i];

/* ### CREAZIONE DELLA TELA GRAFICA E ALLOCAZIONE DI ALCUNI COLORI */
$im = imageCreate($width, $height);                             // creo l'area grafica.
$white = imageColorAllocate($im, 255,255,255);                  // alloco i colori necessari, il primo è il background dell'area grafica.
$black = imageColorAllocate($im, 0,0,0);
$gray = imageColorAllocate($im, 200,200,200);
$red = imageColorAllocate($im, 200,0,0);
$green = imageColorAllocate($im, 0,200,0);
$blue = imageColorAllocate($im, 0,0,200);

// disegno il perimetro della png.
imageRectangle($im, 0, 0, $width-1, $height-1, $black);

// disegno il perimetro del grafico.
imageRectangle($im, $marginLeft, $marginTop, $width-$marginRight, $height-$marginBottom, $gray);

// grafico le tacche sull'asse x del grafico.
$dx = ($width-$marginLeft-$marginRight)/($numberOfValues-1);
$x = $marginLeft;
for($i = 0; $i<$numberOfValues; $i++){
    imageLine($im, $x, $height-$marginBottom-5, $x, $height-$marginBottom+5, $gray);
    $x = $x + $dx;
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
}

/* Grafico le linee tra i punti, il ciclo che si muove sul vettore dei valori deve fermarsi sul penultimo valore,
    perchè una linea parte dal punti i e arriva al punto i+1. */
$x = $marginLeft;
for($i = 0; $i<$numberOfValues-1; $i++){
    $y1 = $availableHeight*$values[$i]/$maxValue;
    $y2 = $availableHeight*$values[$i+1]/$maxValue;

    imageLine($im, $x, $height-$marginBottom-$y1, $x+$dx, $height-$marginBottom-$y2, $green);
    $x = $x + $dx;
}

/* Visualizzo le stringhe come didascalie dell'asse x. */
$x = $marginLeft;
for($i = 0; $i<$numberOfValues; $i++){
    imageString($im, 4, $x-12, $height-$marginBottom+10, $labels[$i], $black);
    $x = $x + $dx;
}

imagePNG($im);
imageDestroy($im);
?>