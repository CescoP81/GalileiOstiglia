<?php
header("Content-Type: image/png");

// DEFINISCO DELLE COSTANTI PER DELIMITARE TELA E GRAFICO
define("WIDTH", 450);               // definisco le dimensioni totali della tela su cui disegnare.
define("HEIGHT", 300);

define("MTOP", 50);                 // definisco i margini attorno al mio grafico.
define("MLEFT", 50);
define("MBOTTOM", 50);
define("MRIGHT", 100);

$GWIDTH = WIDTH - MLEFT - MRIGHT;   // calcolo quanta larghezza ho per il grafico.
$GHEIGHT = HEIGHT - MTOP - MBOTTOM; // calcolo quanta altezza ho per il grafico.

// Spazio relativo alla definizione di funzioni
/**
 * Funzione che ricevuta una X nel grafico aggiunge il margine impostato.
 * @param int $xcoord coordinata x da posizionare nel grafico
 * @return int ritorna il valore tenendo conto dele margine sinistro.
 */
function getGX($xcoord){
    return(MLEFT + $xcoord);
}

/**
 * Funzione che ricevuto un valore da graficare ne calcola i pixel proporzionali rispetto
 * alla dimensione Y del grafico, restituisce il valore in pixel assoluto tenendo conto dei margini.
 * @param int $value Il valore da rappresentare.
 * @param int $max_value il valore massimo da rappresentare, indispensabile per la proporzionalità.
 * @return int Il valore assoluto in pixel tenendo conto dei margini e del ribaltamento della Y.
 */
function getGY($value, $max_value){
    // max_value:GHEIGHT = value : ?    -> ? value*GHEIGHT/max_value
    global $GHEIGHT;    // carico la variabile globale ovvero esterna alla funzione.

    $ycoord = $value * $GHEIGHT / $max_value;
    return(HEIGHT - MBOTTOM - $ycoord);
}
//----
//---- FINE SPAZIO FUNZIONI ----
//----

// spazio del 'main program': tutte le istruzioni di disegno.
    $im = imageCreate(WIDTH, HEIGHT);

    $white = imageColorAllocate($im, 255,255,255);
    $blue = imageColorAllocate($im, 0,0,255);
    $red = imageColorAllocate($im, 255,0,0);
    $green = imageColorAllocate($im, 0,255,0);
    $black = imageColorAllocate($im, 0,0,0);
    $gray = imageColorAllocate($im, 180,180,180);

    $colors = Array();
    array_push($colors, imageColorAllocate($im, rand(0,255), rand(0,255), rand(0,255)));
    array_push($colors, imageColorAllocate($im, rand(0,255), rand(0,255), rand(0,255)));
    array_push($colors, imageColorAllocate($im, rand(0,255), rand(0,255), rand(0,255)));
    array_push($colors, imageColorAllocate($im, rand(0,255), rand(0,255), rand(0,255)));

    $series = Array();
    array_push($series, "Meteo 1");
    array_push($series, "Meteo 2");
    array_push($series, "Meteo 3");

    // delimito l'area totale della tela.
    imageRectangle($im, 0, 0, WIDTH-1, HEIGHT-1, $black);
   
    // delimito l'area utile del grafico.
    imageRectangle($im, MLEFT, MTOP, WIDTH-MRIGHT-1, HEIGHT-MBOTTOM-1, $black);

    // per verificare se riusciamo a disegnare nell'area grafica proviamo a disegnare
    // un punto con valore 8 su un asse che accetta massimo valore 10
    // imageFilledEllipse($im, getGX(200), getGY(2,10), 10, 10, $blue);

    // preparo un vettore con N elmenti da grafica.
    $valori = Array();
    $db = new mysqli("localhost","root","","scuola2021");
        $sql = "SELECT valore FROM meteo_temperature WHERE id_stazione=1";
        $resultSet = $db->query($sql);
        
        $valori[0] = Array();
        $record = $resultSet->fetch_assoc();
        while($record){
            array_push($valori[0], $record['valore']);
            $record = $resultSet->fetch_assoc();
        }

        $sql = "SELECT valore FROM meteo_temperature WHERE id_stazione=2";
        $resultSet = $db->query($sql);
        $valori[1] = Array();
        $record = $resultSet->fetch_assoc();
        while($record){
            array_push($valori[1], $record['valore']);
            $record = $resultSet->fetch_assoc();
        }

        $sql = "SELECT valore FROM meteo_temperature WHERE id_stazione=3";
        $resultSet = $db->query($sql);
        $valori[2] = Array();
        $record = $resultSet->fetch_assoc();
        while($record){
            array_push($valori[2], $record['valore']);
            $record = $resultSet->fetch_assoc();
        }

    $db->close();
    /*
    for($i = 1; $i<=rand(10,20); $i++){
        array_push($valori, rand(0,100));
    }*/
    /*echo("<br/><br/>");
    for($i=0; $i<count($valori); $i++){
        echo($i." : ".count($valori[$i])."<br />");
    }
    echo("<br/><br/>");*/

    // ricerco il massimo valore da rappresentare
    $vmax = $valori[0][0];
    $n_max_val = 0;
    for($i=0; $i<count($valori); $i++){
        if(count($valori[$i]) > $n_max_val)
            $n_max_val = count($valori[$i]);

        for($j=0; $j<count($valori[$i]); $j++)
            if($valori[$i][$j] > $vmax)
                $vmax = $valori[$i][$j];
    }
    $vmax = $vmax + ($vmax*0.10);
    //echo($n_max_val);
    // calcolo ogni quanti x pixel cade un punto -> dimensione asse x fratto numero dei valori-1.
    $xoffset = $GWIDTH / ($n_max_val-1);

    // disegno le linee verticali in corrisponza dei punti del grafico.
    $x = $xoffset;
    for($i=1; $i<=$n_max_val-2; $i++){
        imageLine($im, getGx($x), HEIGHT-MBOTTOM+5, getGx($x), MTOP, $gray);
        $x += $xoffset;
    }

    // disegno le linee orizzontali per suddividere l'area del grafico.
    $settori = 10;
    $yoffset = $GHEIGHT / $settori;
    $y = $yoffset;
    for($i=1; $i<$settori; $i++){
        imageLine($im, MLEFT-5, MTOP+$y, WIDTH-MRIGHT, MTOP+$y, $gray);
        $y += $yoffset;
    }

    // stringhe asse x
    /*$x = 0;
    for($i=0; $i<count($valori); $i++){
        imageString($im, 3, MLEFT+$x-10, HEIGHT-MBOTTOM+5, $valori[$i], $red);
        $x += $xoffset;
    }*/

    // stringhe asse y
    imageString($im, 3, 5,5, $vmax." ".($vmax/($settori+1)), $blue);

    $yoffset = $GHEIGHT / $settori;
    $y = HEIGHT-MBOTTOM;
    $yval = 0;
    for($i=1; $i<=$settori+1; $i++){
        imageString($im, 3, MLEFT-35, $y-8, round($yval), $red);
        $y -= $yoffset;
        $yval = $yval + ($vmax/($settori));
    }
    

    // disegno i punti sul grafico proporzionati al valore massimo da rappresentare.
    for($i=0; $i<count($valori); $i++){
        $x = 0;
        for($j=0; $j<count($valori[$i]); $j++){
            imageFilledEllipse($im, getGX($x), getGY($valori[$i][$j], $vmax), 10, 10, $colors[$i]);
            $x = $x + $xoffset;
        }
    }

    // disegno le linee di collegamento.
    
    for($i=0; $i<count($valori); $i++){
        $x = 0;
        for($j=0; $j<count($valori[$i])-1; $j++){
            imageLine($im, getGX($x), getGY($valori[$i][$j], $vmax), getGX($x+$xoffset), getGY($valori[$i][$j+1], $vmax), $colors[$i]);
            $x = $x + $xoffset;
        }
    }
    $y = MTOP+25;
    for($i=0; $i<count($series); $i++){
        imageString($im,4, MLEFT+$GWIDTH+20, $y, $series[$i], $colors[$i]);
        $y = $y + 15;
    }
    // genero il codice finale dell'immagine formato PNG.
    imagepng($im);
    // dealloco la memoria riservata con la funzione di imageCreate ad inizio codice.
    imagedestroy($im);
?>