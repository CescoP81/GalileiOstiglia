<?php
/**
 * Classe Studente di prova per mostrare l'uso di metodi, attributi pubblici e privati.
 * @version 1.0.0
 * @author Francesco pradella
 * @license GPL
 * @link http://www.github.com/cescop81
 */
class Studente{
    private $nome;
    private $cognome;
    private $eta;

    /**
     * Costrutture dell'oggetto.
     * @param string $_n Nome
     * @param string $_c Cognome
     * @param integer $_e Età
     * @return void
     */
    public function __construct($_n, $_c, $_e){
            $this->nome = $_n;
            $this->cognome = $_c;
            $this->eta = $_e;
    }
    /**
     * Ritorna il nome dello studente
     * @return string Nome dello studente
     */
    public function getNome(){
        return($this->nome);
    }
    /**
     * Ritorna il cognome dello studente
     * @return string cognome dello studente
     */
    public function getCognome(){
        return($this->cognome);
    }
    /**
     * Ritorna l'età dello studente
     * @return integer Età della persona.
     */
    public function getEta(){
        return($this->eta);
    }
}

/**
 * Seconda classe di prova
 */
class Insegnante{
    private $nome;
    /**
     * Costrutture della classe
     * @param string $n Nome da inserire nell'oggetto.
     */
    public function __construct($n){
        $this->nome = _n;
    }
}
?>