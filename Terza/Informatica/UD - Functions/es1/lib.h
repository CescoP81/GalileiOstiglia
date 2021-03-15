/* Funzione di stampa di un valore intero passato come parametro.
@param int Intero da stampare.
@return void
*/
void printIntero(int _a);

/* Funzione che raddoppia il valore di un intero passato per riferimento.
@param int* Riferimento alla variabile da raddoppiare.
@return void*/
void doubleIntero(int* _a);

/* Funzione che restituisce il doppio di una variabile ricevuta per valore
@param int Variabile da raddoppiare
@return int Risultato dell'operazione di raddoppio.*/
int doubleIntero2(int _a);

/* Funzione che inizializza un vettore di interi con valori random tra 1 e 100 estremi compresi.
@param int[] Vettore da inizializzare.
@param int Dimensione del vettore.
@return void*/
void initVettore(int _v[], int _length);

/* Funzione che stampa un vettore ricevuto come parametro
@param int[] Vettore da stampare.
@param int Dimensione del vettore.
@return void;*/
void printVettore(int _v[], int _length);

/* Funzione che ricerca un valore in un vettore passato come parametro,
 restituisce 1 se lo trova, altrimenti 0.
 @param int[] Vettore con i valori
 @param int Dimensione del vettore.
 @param int valore da ricercare.
 @return int Booleano 1 valore trovato, 0 valore non trovato.*/
 int ricercaVettore(int _v[], int _length, int _src);

 /* Funzione che esegue il reverse di un vettore
 @param int[] Vettore di cui fare il reverse
 @param int Dimensione del vettore
 @return void */
 void reverseVettore(int _v[], int _length);