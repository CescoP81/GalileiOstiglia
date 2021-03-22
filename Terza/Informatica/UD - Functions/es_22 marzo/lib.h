/* Inizializza il vettore con valori random.
@param int[] Vettore da utilizzare.
@param int Dimensione del vettore.
@return void.*/
void initVettore(int _v[], int _length);

/* Stampa un vettore passato come parametro.
@param int[] Vettore da utilizzare.
@param int Dimensione del vettore.
@return void.*/
void stampaVet(int _v[], int _length);

/* Ricerca di un valore
@param int[] Vettore da utilizzare.
@param int Dimensione del vettore.
@param int Valore da ricercare.
@return int Numero di volte che compare il valore*/
int ricercaValore(int _v[], int _length, int _src);

/* RScambia due valori
@param int[] Vettore da utilizzare.
@param int Dimensione del vettore.
@param int Indice 1.
@param int Indice 2.
@return int booleano indica se l'operazione è andata a buon fine.*/
int swapValori(int _v[], int _length, int _index1, int _index2);

/* Confronta due vettori
@param int[] Vettore da utilizzare.
@param int[] Vettore da utilizzare.
@param int Dimensione del vettore.
@return int booleano indica se i due vettori sono identici.*/
int equalsVettori(int _v1[], int _v2[], int _length);

