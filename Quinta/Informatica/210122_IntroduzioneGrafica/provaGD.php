<?php
header("Content-Type: image/jpeg");

// definisco le dimensioni della mia tela
$larghezza = 400;
$altezza = 300;

// assegno il riferimento alla memoria
// allocata alla variabile $im.
$im = imagecreate($larghezza, $altezza);

// alloco alcuni colori di base per poter poi disegnare.
$white = imageColorAllocate($im,255,255,255);
$red = imageColorAllocate($im,255,0,0);
$green = imageColorAllocate($im,0,255,0);
$blue = imageColorAllocate($im,0,0,255);
$black = imageColorAllocate($im,0,0,0);

// disegno una linea di colore rosso.
imageLine($im, 10,10, 100, 100, $red);

// disegno un rettangolo di colore verde
imageRectangle($im, 110,10, 150,60, $green);
// disegno una ellisse di colore blu
imageEllipse($im, 100,200, 50, 75, $blue);
//imageFill($im,100,200, $red);

// disegno un cerchio
imageEllipse($im, 140,200, 50, 50, $blue);
//imageFilledEllipse($im, 165,200, 50, 50, $blue);
imageFill($im, 120,200, $red);

//disegno un rettangolo grande quanto l'intera tela.
imageRectangle($im,0,0,$larghezza-1,$altezza-1, $black);

// genero il sorgente jpeg.
imagejpeg($im);

// dealloco la memoria precedentemente allocata con la imagecreate.
imagedestroy($im);
?>