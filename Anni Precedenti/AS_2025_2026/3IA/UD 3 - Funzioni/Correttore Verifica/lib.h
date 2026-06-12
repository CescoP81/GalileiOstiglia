/**
 * Inserimento controllato di un valore da tastiera, compreso tra i valori x e y e divisibile per z
 * @param int Estremo inferiore del range
 * @param int Estremo superiore del range
 * @param int Divisore per verificare se il numero è multiplo di z.
 * @return Numero inserito valido
 */
int inputNumeroFiltrato(int _x, int _y, int _z);

/**
 * Determina l'n-simo numero primo dopo il valore x inserito.
 * @param int Numero di riferimento da cui partire la ricerca.
 * @param int L'n-esimo numero da restituire.
 * @return Numero primo trovato.
 */
int trovamiPrimo(int _x, int _n);

/**
 * Determina se un numero passato è primo oppure no
 * @param int Numero da verificare
 * @return 1 è primo, 0 non è primo.
 */
int isPrimo(int _x);

/**
 * Funzione che ordina in modo crescente tre valori ricevuti per riferimento
 * @param int* Riferimento al primo valore.
 * @param int* Riferimento al secondo valore.
 * @param int* Riferimento al terzo valore
 */
void ordinaTreValori(int* _x, int* _y, int* _z);

/**
 * Funzione che calcola area rettangolo se valori sono diversi oppure perimetro quadrato se sono uguali
 * @param int Misura primo lato.
 * @param int Misura secondo lato.
 * @return Valore calcolato oppure -1 se una delle due misure è zero.
 */
int determinaFigura(int _x, int _y);