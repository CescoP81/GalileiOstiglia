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
    public function __construct($_n, $_d){
        $this->numeratore = $_n;
        if($_d == 0)
            $this->denominatore = 1;
        else
            $this->denominatore = $_d;
    }
    /**
     * Imposta il numeratore con un valore specificato.
     * @param int $_n Nuovo numeratore.
     */
    public function setNumeratore($_n){
        $this->numeratore = $_n;
    }
    /**
     * Imposta il denominatore con un valore specificato.
     * @param int $_d Nuovo denominatore.
     */
    public function setDenominatore($_d){
        if($_d == 0)
            $this->denominatore = 1;
        else
            $this->denominatore = $_d;
    }

    /**
     * Restituisce il valore corrente del numeratore.
     * @return int Numeratore corrente.
     */
    public function getNumeratore(){
        return($this->numeratore);
    }
    /**
     * Restituisce il valore del denominatore.
     * @return int Denominatore corrente.
     */
    public function getDenominatore(){
        return($this->denominatore);
    }
    /** 
     * Stampa la frazione come n / d
     * @return void
     */
    public function stampaFrazione(){
        echo($this->numeratore . "/" . $this->denominatore);
    }

    /**
     * Restituisce il valore decimale della frazione con masismo 4 decimali.
     * @return float Valore decimale della frazione.
     */
    public function getDecimale(){
        $x = $this->numeratore / $this->denominatore;
        $x = round($x, 4);
        return($x);
    }
}
?>