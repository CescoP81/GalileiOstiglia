<?php
/**
 * Classe Frazione per la memorizzazione e gestione di una frazione numeratore/denominatore.
 * @version 1.0.0
 * @author Francesco pradella
 * @license GPL
 * @link http://www.github.com/cescop81
 * @package GalileiOstiglia\5a\TPSI\UD4_OOP
 */
class Frazione{
    private $numeratore;
    private $denominatore;

    /**
     * Costruttore della classe.
     * @param int $_n Valore da attribuire al numeratore.
     * @param int $_d Valore da attribuire al denominatore.
     */
    public function __contruct($_n=1, $_d=1){
        $this->numeratore = $_n;
        $this->denominatore = $_d;
    }

    public function setNumeratore($_n){
    }

    public function setDenominatore($_d){
    }
}
?>