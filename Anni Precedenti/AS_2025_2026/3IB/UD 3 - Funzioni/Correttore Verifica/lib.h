// File contenente i prototipi opportunamente documentati
/**
 * Permette l'inserimento di un valore intero rispettando le condizioni del punto A
 * @param int Valore 1
 * @param int Valore 2
 * @return -1 pppure il numero inserito se rispetta i parametri.
 */
int inputNumber(int _p1, int _p2);

/**
 * Divisore maggiore comune a tutti e tre i valori passati.
 * @param int Valore 1
 * @param int Valore 2
 * @param int Valore 3
 * @return Divisore maggiore trovato.
 */
int getMaxDivider(int _v1, int _v2, int _v3);

/**
 * Ordina in modo crescente o decrescente tre variabili passate per riferimento.
 * @param int* Riferimento a Valore 1
 * @param int* Riferimento a Valore 2
 * @param int* Riferimento a Valore 3
 * @param int Tipo di ordinamento -> 0 decrescente; 1 crescete)
 */
void orderValues(int* _v1, int* _v2, int* _v3, int _ordine);

/**
 * Scambia il valore di due variabili passate per riferimento
 * @param int* Riferimento a Valore 1
 * @param int* Riferimento a Valore 2
 */
void swapValue(int* _x, int* _y);