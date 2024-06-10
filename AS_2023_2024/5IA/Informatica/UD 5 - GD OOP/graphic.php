<?php
class Grafico{
    private $img = null;
    private $width = 0;
    private $height = 0;
    private $colors;
    private $valueSerie = array();
    /**
     * Costruisce un oggetto grafico. Se non specificate le dimensione di default sono 640x480 pixels.
     * @param Dimensione X.
     * @param Dimensione Y.
     * @return void
     */
    function __construct($_w=640, $_h=480){
        $this->width = $_w;
        $this->height = $_h;

        $this->img = imageCreate($this->width, $this->height);
        $this->colors = array(
            "white" => imagecolorallocate($this->img, 255,255,255),
            "black" => imagecolorallocate($this->img, 0,0,0),
            "red" => imagecolorallocate($this->img, 255,0,0),
            "blue" => imagecolorallocate($this->img, 0,0,255),
            "green" => imagecolorallocate($this->img, 0,255,0)
        );
        /*
        array_push($this->colors, imageColorAllocate($this->img, 255,255,255));     //[0] -> White
        array_push($this->colors, imageColorAllocate($this->img, 200,0,0));         //[1] -> Red
        // */
    }
    /**
     * Inizializza l'area grafica con background bianco ed una linea rossa da 1px sui lati.
     * @return void
     */
    function InitGrafico(){
        imageRectangle($this->img, 0,0, $this->width-1, $this->height-1, $this->colors['red']);
        imageLine($this->img, 10, 10, 200, 200, $this->colors['blue']);
    }

    function loadSerie($_s){
        for($i=0; $i<count($_s); $i++)
            array_push($this->valueSerie, $_s[$i]);
    }

    function deployPoint(){
        $x=10;
        for($i=0; $i<count($this->valueSerie); $i++){
            imageString($this->img, 4, $x, 20, $this->valueSerie[$i], $this->colors['black']);
            $x = $x + 40;
        }
    }
    /**
     * Crea il codice PNG dell'immagine creata.
     * @return void
     */
    function DeployGrafico(){
        imagepng($this->img);
    }
}
?>