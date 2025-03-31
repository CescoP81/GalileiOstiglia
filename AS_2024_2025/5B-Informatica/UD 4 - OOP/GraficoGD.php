<?php
class GraficoGD{
    // insieme delle variabili dell'oggetto detto anche STATO dell'oggetto.
    private $width;
    private $heigth;
    private $tela;
    private $white;
    private $black;
    private $blue;

    function __construct(){
        $this->width = 640;
        $this->heigth = 480;
    }
    public function setNewDimensions($_w, $_h){
        $this->width = $_w;
        $this->heigth = $_h;
    }
    public function createTela(){
        // alloca la memoria necessaria per rappresentare 640pixel per 480pixel
        $this->tela = imageCreate($this->width, $this->heigth);

        // alloco alcuni colori. NB il primo colore allocato è il background dell'immagine.
        $this->white = imageColorAllocate($this->tela, 255,255,255);
        $this->black = imageColorAllocate($this->tela, 0,0,0);
        $this->blue = imageColorAllocate($this->tela, 0,0,255);
    }
    public function createBorder(){
        imageRectangle($this->tela, 0, 0, ($this->width)-1, ($this->heigth)-1, $this->black);
    }
    public function disegnaLinea(){
        imageLine($this->tela, 10,10, 550, 450, $this->blue);
    }
    public function disegnaLineaXY($x1, $y1, $x2, $y2){
        imageLine($this->tela, $x1, $y1, $x2, $y2, $this->blue);
    }
    public function getPngImage(){
        return(imagePNG($this->tela));
    }
}
?>