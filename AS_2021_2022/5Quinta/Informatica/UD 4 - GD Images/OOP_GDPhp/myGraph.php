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
    private $categories = array();
    private $titles = array();
    
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
        if($n == 0)
            return(1);
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
     * Carica un vettore di stringhe da usare come categorie, label sotto all'asse X.
     * @param array $categorie Vettore delle categorie.
     */
    public function SetCategories($categorie){
        for($i=0; $i<count($categorie); $i++){
            array_push($this->categories, $categorie[$i]);
        }
    }
    /**
     * Carica i titoli del grafico, dell'asse x e dell'asse y
     * @param string $mainTitle Titolo generale del grafico.
     * @param string $xAxisTitle Titolo dell'asse X.
     * @param string $yAxisTitle Titolo dell'asse Y.
     */
    public function SetTitles($mainTitle, $xAxisTitle, $yAxisTitle){
            array_push($this->titles, $mainTitle);
            array_push($this->titles, $xAxisTitle);
            array_push($this->titles, $yAxisTitle);
    }

    /**
     * Disegna le linee di riferimento orizzontali e relativi valori a fianco dell'asse Y.
     */
    public function DrawReferenceLine(){
        $maxVal = $this->values[0];
        for($i=1; $i<count($this->values); $i++) // ricerco il valore massimo da graficare, mi servirà per la proporzione dei pixel.
            if($this->values[$i] > $maxVal) $maxVal = $this->values[$i];
        
        $spacers = 10;
        $deltaY = $this->graphHeight / $spacers;
        
        $yPunto = $this->totalHeight - $this->bottomMargin;
        for($i=0; $i<=$spacers; $i++){
            imageLine($this->im, $this->leftMargin-5, $yPunto, $this->totalWidth-$this->rightMargin, $yPunto, $this->colors['lightgray']);
            $yPunto = $yPunto - $deltaY;
        }

        $yPunto = $this->totalHeight - $this->bottomMargin;
        $referenceValue = 0;
        for($i=0; $i<=$spacers; $i++){
            //imageLine($this->im, $this->leftMargin, $yPunto, $this->totalWidth-$this->rightMargin, $yPunto, $this->colors['lightgray']);
            imageString($this->im, 5, $this->leftMargin-($this->numberOfDigits($referenceValue)*8)-10, $yPunto-8, round($referenceValue), $this->colors['lightgray']);
            $yPunto = $yPunto - $deltaY;
            $referenceValue += $maxVal / $spacers;
        }
    }
    
    /**
     * Scrive le categorie sotto all'asse delle X, se troppo lunghe è possibile troncarle passando il numero di caratteri.
     * @param int $trunk Numero di caratteri da visualizzare, lasciare vuoto per vedere la stringa completa.
     */
    public function WriteCategories($trunk=null){
        $deltaX = $this->graphWidth / (count($this->categories)-1);
        for($i=0; $i<count($this->categories); $i++){
            $category = null;
            if(!$trunk)
                $category = $this->categories[$i];
            else
                $category = substr($this->categories[$i], 0, $trunk);

            $xPunto = $this->leftMargin + ($deltaX*$i);
            $xPunto = $xPunto - (strlen($category)*4);
                        
            imageString($this->im, 5, $xPunto, $this->totalHeight-$this->bottomMargin+5, $category, $this->colors['black']);
        }
    }

    /**
     * Visualizza i titoli del grafico nelle rispettive posizioni.
     */
    public function WriteTitles(){
        $maxVal = $this->values[0];
        for($i=1; $i<count($this->values); $i++) // ricerco il valore massimo da graficare, mi servirà per la proporzione dei pixel.
            if($this->values[$i] > $maxVal) $maxVal = $this->values[$i];

        // main title
        imageString(
            $this->im,
            5,
            ($this->totalWidth/2)-(strlen($this->titles[0])*4),
            20,
            $this->titles[0],
            $this->colors['black']
        );

        // x axis title
        imageString(
            $this->im,
            5,
            //($this->totalWidth/2)-(strlen($this->titles[1])*4),
            $this->leftMargin + ($this->graphWidth/2 - strlen($this->titles[1])*4),
            $this->totalHeight-($this->bottomMargin/2),
            $this->titles[1],
            $this->colors['black']
        );

        // y axis title
        //imageString($this->im, 5, 0,0, $this->numberOfDigits($maxVal), $this->colors['black']);
        imageStringUp(
            $this->im,
            5,
            $this->leftMargin - ($this->numberOfDigits($maxVal)*8) - 10 - 22,
            $this->totalHeight/2 + (strlen($this->titles[2])*4),
            $this->titles[2],
            $this->colors['black']
        );
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