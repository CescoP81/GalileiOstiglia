<?php
header("Content-Type: image/png");

// DEFINISCO DELLE COSTANTI PER DELIMITARE TELA E GRAFICO
define("WIDTH", 450);               // definisco le dimensioni totali della tela su cui disegnare.
define("HEIGHT", 300);

$im = imageCreate(WIDTH, HEIGHT);

$white = imageColorAllocate($im, 255,255,255);
$black = imageColorAllocate($im, 0,0,0);

    $colors = Array();
    for($i=1; $i<=10; $i++)
        array_push($colors, imageColorAllocate($im, rand(0,255), rand(0,255), rand(0,255)));
    //array_push($colors, imageColorAllocate($im, rand(0,255), rand(0,255), rand(0,255)));
    //array_push($colors, imageColorAllocate($im, rand(0,255), rand(0,255), rand(0,255)));

    imageRectangle($im, 0, 0, WIDTH-1, HEIGHT-1, $black);

    $y = 10;
    for($i=0; $i<count($colors); $i++){
        imageFilledRectangle($im, 10, $y, 400, $y+5, $colors[$i]);
        $y = $y + 20;
    }

   // genero il codice finale dell'immagine formato PNG.
   imagepng($im);
   // dealloco la memoria riservata con la funzione di imageCreate ad inizio codice.
   imagedestroy($im);
?>