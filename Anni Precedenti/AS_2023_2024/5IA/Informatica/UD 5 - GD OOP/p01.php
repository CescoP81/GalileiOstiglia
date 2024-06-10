<?php
header ('Content-Type: image/png');
    
    $img = imageCreate(800, 600); // alloca un tot di memoria e il riferimento è assegnato alla variabile img.

    $white = imageColorAllocate($img, 255,255,255);
    $black = imageColorAllocate($img, 0,0,0);
    $red = imageColorAllocate($img, 255,0,0);
    $green = imageColorAllocate($img, 0,255,0);
    $blue = imageColorAllocate($img, 0,0,255);

    imageLine($img, 100, 100, 250, 250, $blue);
    imageLine($img, 100, 120, 250, 270, $red);

    imageRectangle($img, 400, 100, 500, 150, $blue);
    imageFilledRectangle($img, 550, 100, 650, 150, $blue);

    imageEllipse($img, 450, 250, 100, 100, $green);
    imageFilledEllipse($img, 600, 250, 100, 100, $green);

    imageEllipse($img, 450, 400, 100, 50, $green);
    imageFilledEllipse($img, 600, 400, 100, 50, $green);

    $str = "Hello world from PNG";
    imageString($img, 6, 400, 500, $str, $red);
    ImageStringUp($img, 6, 700, 500, $str, $red);

    imagePNG($img);
?>