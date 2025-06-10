<?php
class Oggetto{
    // L'insieme delle variabili private rappresenta lo stato dell'oggetto.
    private $var;
    
    // L'insieme delle funzioni di un oggetto che vengono chiamate METODI rappresenta
    // l'interfaccia con la quale si interagisce con l'oggetto stesso.
    
    /**
     * Costruttore base, esegue un set iniziale delle variabili dell'oggetto.
     */
    public function __construct(){
        echo('Costruttore OK e variabile azzerata.');
        $this->var = 0;
    }
    /**
     * Imposta la variabile var con il valore passato
     * @param int $_v Valore da impostare in var
     */
    public function setVar($_v){
        echo('Set: '.$_v);
        $this->var = $_v;
    }
    /**
     * Ritorna il valore della variabile var
     * @return int
     */
    public function getVar(){
        return($this->var);
    }
};

// -----------------------------
$o = new Oggetto();

echo('<br />O: '.$o->getVar().'<br />');
$o->setVar(19);
echo('<br />O: '.$o->getVar().'<br />');

echo('<br /><br />');

?>