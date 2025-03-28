<?php
class GraficoGD{
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
    public function createTela(){
        $this->tela = imageCreate($this->width, $this->heigth);
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
    public function getPngImage(){
        return(imagePNG($this->tela));
    }
}
?>