<?php
   if(isset($_REQUEST['w'])) $width = $_REQUEST['w']; else $width = 640;
   if(isset($_REQUEST['h'])) $height = $_REQUEST['h']; else $height = 480;

   // alloco un tot di memoria per una immagine 640x480 pixels
   $im = imageCreate($width, $height);

   // alloco alcuni colori utili alla mia immagine.
   $white = imageColorAllocate($im, 255, 255, 255);
   $green = imageColorAllocate($im, 0, 255, 0);
   $black = imageColorAllocate($im, 0, 0, 0);
   $red = imageColorAllocate($im, 255, 0, 0);
   $blue = imageColorAllocate($im, 0, 0, 255);
   
   // rettangolo per mostrare i confini dell'immagine.
   imageRectangle($im, 0, 0, $width-1, $height-1, $black);

   imageFilledRectangle($im, 20, 160, 120, 260, $blue);

   imageEllipse($im, 50, 300, 60, 120, $red);
   imageFilledEllipse($im, 150, 300, 60, 120, $red);

   imageString($im, 5, 20, 400, "Hello World....", $green);
   

   imageLine($im, 0, 0, 100, 100, $black);

   // pubblico l'immagine.
   imagePNG($im);
   // dealloco la memoria utilizzata.
   imageDestroy($im);
?>