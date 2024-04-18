<?php
header ('Content-Type: image/png');
// definisco le dimensioni della tela, i margini per il grafico.
$width = 800;
$height = 600;
$mTop = 150;
$mLeft = 150;
$mBottom = 100;
$mRight = 50;

// definisco alcuni valori da graficare sull'asse delle y
$valori = array(5,3,8,4,2,10,20,3,5,7,8,1,2);

$img = imageCreate($width, $height); // alloca un tot di memoria e il riferimento è assegnato alla variabile img.

$white = imageColorAllocate($img, 255,255,255);
$black = imageColorAllocate($img, 0,0,0);
$red = imageColorAllocate($img, 255,0,0);
$green = imageColorAllocate($img, 0,255,0);
$blue = imageColorAllocate($img, 0,0,255);

    imageRectangle($img, $mLeft, $mTop, ($width-$mRight), ($height-$mBottom), $black);

// determino il valore massimo tra quelli presenti, così da avere un riferimento per la proporzione
$maxValore = $valori[0];
for($i=1; $i<count($valori); $i++){
    if($valori[$i] > $maxValore)
        $maxValore = $valori[$i];
}

// determino lo scostamento sull'asse X tra un valore e l'altro.
$deltaX = ($width-$mLeft-$mRight) / (count($valori)-1);

// grafico le linee tra i diversi punti
$x = $mLeft;
for($i=0; $i<count($valori)-1; $i++){
    $y1 = ($height-$mBottom) - (($height-$mTop-$mBottom) * $valori[$i] / $maxValore);
    $y2 = ($height-$mBottom) - (($height-$mTop-$mBottom) * $valori[$i+1] / $maxValore);

    imageLine($img, $x, $y1, $x+$deltaX, $y2, $blue);
    $x = $x + $deltaX;
}

// grafico i valori sottoforma di punti proporzionati alle dimensioni del grafico.
$x = $mLeft; // x dei punti
for($i=0; $i<count($valori); $i++){
    $y = ($height-$mBottom) - (($height-$mTop-$mBottom) * $valori[$i] / $maxValore);
    imageFilledEllipse($img, $x, $y, 10, 10, $red);
    $x = $x + $deltaX;
}

imagePNG($img);
?>