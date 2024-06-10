<?php
    header("Content-type: image/png");

    define("WIDTH", 640);
    define("HEIGHT", 480);
    
    // step 1 allocare la memoria per l'immagine.
    $im = imageCreate(WIDTH, HEIGHT); // alloca un'area di memoria pari a 640x480 pixel su cui disegnare.

    // step 2 allocare alcuni colori da utilizzare.
    $white = imageColorAllocate($im, 255,255,255);
    $black = imageColorAllocate($im, 0,0,0);
    $red = imageColorAllocate($im, 255,0,0);
    $green = imageColorAllocate($im, 0,255,0);
    $blue = imageColorAllocate($im, 0,0,255);

    // step 3 creo alcune figure.
    imageRectangle($im, 0, 0, WIDTH-1, HEIGHT-1, $black);

    imageLine($im, 10,10, 100, 100, $red);
    imageRectangle($im, 125, 10, 150, 50, $green);
    imageEllipse($im, 225, 100, 50, 50, $blue);
    imageEllipse($im, 280, 100, 30, 50, $blue);

    imageFilledRectangle($im, 125, 100, 150, 250, $green);
    imageFilledEllipse($im, 225, 200, 50, 50, $blue);

    imageFilledEllipse($im, 350, 100, 5, 5, $blue);

    imageString($im, 1, 100, 300, "Hello World", $red);
    // step 3 genero e restituisco il codice PNG
    imagePNG($im);

    // step 4 distruggo/libero l'area di memoria creata
    imageDestroy($im);
?>