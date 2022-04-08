<?php
/**
 * Classe sviluppata per la realizzazione di un grafico a linea spezata stile "Excel"
 */
class myGraph{
    private $totalWidth;
    private $totalHeight;
    private $leftMargin;
    private $topMargin;
    private $rightMargin;
    private $bottomMargin;
    private $graphWidth;
    private $graphHeight;

    private $im;
    private $colors;
    private $values = array();
    
    /**
     * Costruttore della classe
     * @param int $w Larghezza in pixel dell'immagine.
     * @param int $h Altezza in pixel dell'immagine.
     */
    function __construct($w, $h){
        $this->totalWidth = $w;
        $this->totalHeight = $h;

        $this->SetInternalMargins( 10, 10, 10, 10);

        $this->im = imageCreate($this->totalWidth, $this->totalHeight);
        $this->colors = array(
            "white" => imageColorAllocate($this->im, 255,255,255),
            "black" => imageColorAllocate($this->im, 0,0,0),
            "lightgray" => imageColorAllocate($this->im, 200,200,200),
            "blue" => imageColorAllocate($this->im, 0,0,255),
            "red" => imageColorAllocate($this->im, 200,0,0),
        );
    }    
    /**
     * Funzione per modificare i margini interni di default.
     * @param int $lm Pixel margine sinistro.
     * @param int $tm Pixel margine superiore.
     * @param int $rm Pixel margine destro.
     * @param int $bm Pixel margine inferiore.
     */
    public function SetInternalMargins($lm, $tm, $rm, $bm){
        $this->leftMargin = $lm;
        $this->topMargin = $tm;
        $this->rightMargin = $rm;
        $this->bottomMargin = $bm;

        $this->graphWidth = $this->totalWidth - $this->leftMargin - $this->rightMargin;
        $this->graphHeight = $this->totalHeight - $this->topMargin - $this->bottomMargin;
    }
    /**
     * Disegna un rettangolo per delimitare i confini dell'immagine.
     */
    public function DrawBounds(){
        imageRectangle($this->im, 0, 0, $this->totalWidth-1, $this->totalHeight-1, $this->colors['black']);
    }
    /**
     * Disegna un rettangolo per delimitare i confini dell'area del grafico.
     */
    public function DrawInternalBounds(){
        imageRectangle($this->im, $this->leftMargin, $this->topMargin, $this->leftMargin+$this->graphWidth, $this->topMargin+$this->graphHeight, $this->colors['lightgray']);
    }

    public function DrawPoint($val, $maxVal){
        // calcolo i pixel in proporzione
        // $maxVal:$graphHeight = $val:$pixel --> $pixel= $val*$graphHeight/$maxVal
        $pixel = $val * $this->graphHeight / $maxVal;
        $yPunto = $this->totalHeight - $this->bottomMargin - $pixel;
        $xPunto = $this->leftMargin + ($this->graphWidth/2);

        imageFilledEllipse($this->im, $xPunto, $yPunto, 10, 10, $this->colors['blue']);
    }
    /**
     * Disegna i punti all'interno dell'area designata come grafico, il primo ed ultimo punto cadono sui bordi sinistro e destro.
     */
    public function DrawPoints(){
        $maxVal = $this->values[0];
        for($i=1; $i<count($this->values); $i++) // ricerco il valore massimo da graficare, mi servirà per la proporzione dei pixel.
            if($this->values[$i] > $maxVal) $maxVal = $this->values[$i];
        
        $deltaX = $this->graphWidth / (count($this->values)-1);
        $xPunto = $this->leftMargin;
        for($i=0; $i<count($this->values); $i++){
            $pixel = $this->values[$i] * $this->graphHeight / $maxVal;
            //echo($this->values[$i]." ".$pixel."<br >");
            $yPunto = $this->totalHeight - $this->bottomMargin - $pixel;
            imageFilledEllipse($this->im, $xPunto, $yPunto, 8, 8, $this->colors['blue']);

            $xPunto = $xPunto + $deltaX;
        }        
    }
    /**
     * Disegna le linee tra un punto ed il successivo.
     */
    public function DrawConnectionLines(){
        $maxVal = $this->values[0];
        for($i=1; $i<count($this->values); $i++)
            if($this->values[$i] > $maxVal) $maxVal = $this->values[$i];
        
        $deltaX = $this->graphWidth / (count($this->values)-1);
        $xPunto = $this->leftMargin;
        for($i=0; $i<count($this->values)-1; $i++){
            $pixel = $this->values[$i] * $this->graphHeight / $maxVal;
            $pixel2 = $this->values[$i+1] * $this->graphHeight / $maxVal;
            //echo($this->values[$i]." ".$pixel."<br >");
            $yPunto = $this->totalHeight - $this->bottomMargin - $pixel;
            $yPunto2 = $this->totalHeight - $this->bottomMargin - $pixel2;
            //imageFilledEllipse($this->im, $xPunto, $yPunto, 10, 10, $this->colors['blue']);
            imageLine($this->im, $xPunto, $yPunto, $xPunto+$deltaX, $yPunto2, $this->colors['blue']);
           
            $xPunto = $xPunto + $deltaX;
        }
    }
    /**
     * Restituisce il numero di cifre che compongono un numero intero.
     * @param int $n Numero d esaminare.
     * @return int Numero di cifre che lo compongono.
     */
    private function numberOfDigits($n){
        $cnt = 0;
        while($n>0){
            $cnt++;
            $n = (int)($n/10);
        }
        return($cnt);
    }
    /**
     * Scrive i valori al di sopra del rispettivi punti.
     */
    function DrawValueLabels(){
        $maxVal = $this->values[0];
        for($i=1; $i<count($this->values); $i++)
            if($this->values[$i] > $maxVal) $maxVal = $this->values[$i];
        $deltaX = $this->graphWidth / (count($this->values)-1);

        $xPunto = $this->leftMargin;
        for($i=0; $i<count($this->values); $i++){
            $pixel = $this->values[$i] * $this->graphHeight / $maxVal;
            $yPunto = $this->totalHeight - $this->bottomMargin - $pixel;

            //imageRectangle($this->im, $xPunto-15, $yPunto-15, $xPunto+10, $yPunto-3, $this->colors['black']);
            ImageString($this->im,5,$xPunto-($this->numberOfDigits($this->values[$i])*4), $yPunto-20, $this->values[$i], $this->colors['red']);
            $xPunto = $xPunto + $deltaX;            
        }
    }
    /**
     * Carica un vettore di valori passato come parametro.
     * @param array $valori Vettore dei valori.
     */
    public function SetValues($valori){
        for($i=0; $i<count($valori); $i++){
            array_push($this->values, $valori[$i]);
        }
    }

    /**
     * Output del codice PNG realtivo all'immagine creata.
     */
    public function Output(){
        header("Content-type: image/png");
        imagePNG($this->im);
        imageDestroy($this->im);
    }   
}
?>