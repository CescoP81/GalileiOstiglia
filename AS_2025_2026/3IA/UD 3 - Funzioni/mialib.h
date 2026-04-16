/*  Contiene solo i prototipi delle funzione che vado a sviluppare
    per la mia libreria personale */

/**
 * [IT] Verifica se un numero è primo oppure no.
 * [EN] Check whether a number is prime or not.
 * @param int Number to test.
 * @return boolean true/false.
 */
bool isPrimo(int _n);
/**
 * [IT] Verifica se un numero è perfetto oppure no
 * [EN] Check whether a number is perfect or not.
 * @param int Number to test
 * @return boolean true/false
 */
bool isPerfect(int _n);
/**
 * [IT] Verifica terna pitagorica, se n1^2+n2^2 = n3^2
 * [EN] Check if three values are a Pythagorean triple.
 * @param int _n1 First values
 * @param int _n2 Second value
 * @param int _n3 Third value
 * @return boolean true/false
 */
bool isTernaPitagorica(int _n1, int _n2, int _n3);

/**
 * [IT] Inserimento controllato di un valore intero tra min e max estremi compresi.
 * [EN] Controller input of an integer value between min and max bounds.
 * @param int Min value accepted
 * @param int Max value accepted
 * @return Return the allowed number insered
 */
int inputValoreRange(int _min, int _max);

/**
 * [IT] Genera un valore random compreso tra due valori interi min e max, estremi compresi.
 * [EN] Generate a random value between min and max values, extremes included.
 * @param int Min value accepted.
 * @param int Max value accepted.
 * @return Return the random value generated.
 */
int randomValoreRange(int _min, int _max);

/**
 * [IT] Restituisce il successivo numero primo di un valore passato come parametro.
 * 
 * [EN] Return the next prime number following a passed value.
 * @param int Reference passed value.
 * @return The next prime value after the reference passed.
 */
int nextPrimo(int _val);

/**
 * Versione very short proposta dal Prof. Bottoni, livello PRO.
 * @param int Valore di riferimento.
 * @return Successivo numero primo.
 */
int nextPrimo3(int _val);

/**
 * [IT] Restituisce il primo precedente ad un valore passato come parametro
 * [EN] Return the previous prime number following a passed value.
 * @param int Reference passed value.
 * @return The previous prime value after the reference passed.
 */
int prevPrimo(int _val);

/**
 * [IT] Visualizza a video N numeri casuali primi (compresi tra 1 e 999) successivi ad un valore di riferimento
 * [EN] Show N prime random values (between 1 and 999) following the reference value passed.
 * @param int Reference passed value.
 * @param int Number of values to generate and show.
 */
void visualizzaPrimi(int _val, int _n);

/**
 * [IT] Funzione che riceve una variabile per riferimento, ne raddoppia il valore contenuto.
 * [EN] Function that receive a reference to a variable and double the original content.
 * @param int* Reference (the memory address) of the original variable.
 */
void raddoppiaValore(int* _n);

/**
 * [IT] Funzione che riceve base e altezza di un rettangolo, calcola Area e Perimetro "restituendoli" al main.
 * [EN] coming soon...
 * @param int Valore della base.
 * @param int Valore dell'altezza.
 * @param int* Riferimento alla variabile in cui mettere l'area.
 * @param int* Riferimento alla variabile in cui mettere il perimetro.
 */
void calcolaAreaPerimetro(int _base, int _altezza, int* _area, int* _perimetro);

/**
 * [IT] Funzione che in modo RICORSIVO suddivide un numero intero in singole cifre
 * @param int Valore da cui ricavare la cifra con peso minore. (unità)
 */
void estraiCifra(int _num);

/**
 * [IT] Funzione che in modo RICORSIVO esegue la conversione di un numero intero decimale in formato binario
 * operando per divisioni successive.
 * [EN] coming soon...
 * @param int Numero di cui calcolare il resto della divisone per 2 (operatore modulo - %)
 */
void convertiBinario(int _n);

/**
 * [IT] Funzione che scambia il contenuto di due variabili, se il primo è maggiore del secondo.
 * [EN] coming soon...
 * @param int* Riferimento alla prima variabile.
 * @param int* Riferimento alla seconda variabile
 * @return True/False in caso lo scambio avvenga oppure no.
 */
bool scambiaValori(int* _a, int* _b);