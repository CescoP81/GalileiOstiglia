public class Robot {
    private
        int a;
        int b;
    
    /**
     * Costruttore dell'oggetto, generalmente inizializza le variabili interne
     * dette "Stato dell'oggetto" ad un valore iniziale di default.
     * Il costruttore viene richiamato ogni volta che si invoca l'operatore 'new Object'.
     */
    public Robot(){
        a = 0;
        b = 0;
    }

    /**
     * Metodo che inizializza lo stato dell'oggeto con i valori passati come parametri.
     * @param _a Valore della variabile A
     * @param _b Valore della variabile B
     */
    public void setValues(int _a, int _b){
        a = _a;
        b = _b;
    }

    public int getValueA(){
        return(a);
    }
    public int getValueB(){
        return(b);
    }

    /**
     * Metodo che restiuisce la somma dei due valori presenti nell'oggetto.
     * @return Somma dei valori A e B.
     */
    public int getSommaValues(){
        return(a+b);
    }    
}
