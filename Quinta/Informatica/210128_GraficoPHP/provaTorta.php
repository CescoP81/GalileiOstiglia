<?php
header("Content-Type: image/png");

// DEFINISCO DELLE COSTANTI PER DELIMITARE TELA E GRAFICO
define("WIDTH", 300);               // definisco le dimensioni totali della tela su cui disegnare.
define("HEIGHT", 300);
// spazio del 'main program': tutte le istruzioni di disegno.
$im = imageCreate(WIDTH, HEIGHT);

$white = imageColorAllocate($im, 255,255,255);
$blue = imageColorAllocate($im, 0,0,255);
$red = imageColorAllocate($im, 255,0,0);
$green = imageColorAllocate($im, 0,255,0);
$black = imageColorAllocate($im, 0,0,0);
$gray = imageColorAllocate($im, 180,180,180);

// delimito l'area totale della tela.
imageRectangle($im, 0, 0, WIDTH-1, HEIGHT-1, $black);

    $xc = WIDTH/2;
    $yc = HEIGHT/2;
    $radius = (WIDTH-50)/2; // raggio della mia circonferenza.
    imageEllipse($im, $xc, $yc, $radius*2, $radius*2, $black);

    imageLine($im, $xc, $yc, $xc+$radius, $yc, $blue);

    imageLine($im, $xc, $yc, $xc+($radius*cos(deg2rad(220))), $yc-($radius*sin(deg2rad(220))), $red);



    // genero il codice finale dell'immagine formato PNG.
    imagepng($im);
    // dealloco la memoria riservata con la funzione di imageCreate ad inizio codice.
    imagedestroy($im);
?>