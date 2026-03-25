/*  Contiene solo i prototipi delle funzione che vado a sviluppare
    per la mia libreria personale */

/**
 * Check whether a number is prime or not.
 * @param int Number to test.
 * @return boolean true/false.
 */
bool isPrimo(int _n);
/**
 * Verifica se un numero è perfetto oppure no
 * @param int Numero da verificare
 * @return boolean true/false
 */
bool isPerfect(int _n);
/**
 * Verifica terna pitagorica, se n1^2+n2^2 = n3^2
 * @param int _n1 Primo valore
 * @param int _n2 Secondo valore
 * @param int _n3 Terzo valore
 * @return boolean true/false
 */
bool isTernaPitagorica(int _n1, int _n2, int _n3);

/**
 * Inserimento controllato di un valore intero tra min e max estremi compresi
 * @param int Valore minimo accettato
 * @param int Valore massimo accettato
 * @return Valore inserito dall'utente valido e nel range min-max
 */
int inputValoreRange(int _min, int _max);

/**
 * Genera un valore random compreso tra due valori interi min e max, estremi compresi
 * @param int Valore minimo accettato
 * @param int Valore massimo accettato
 * @return Valore random generato compreso nel range min-max
 */
int randomValoreRange(int _min, int _max);

/**
 * Restituisce il successivo numero primo di un valore passato come parametro.
 * @param int Valore di riferimento.
 * @return Successivo numero primo.
 */
int nextPrimo(int _val);

/**
 * Versione very short proposta dal Prof. Bottoni, livello PRO.
 * @param int Valore di riferimento.
 * @return Successivo numero primo.
 */
int nextPrimo3(int _val);

/**
 * Restituisce il primo precedente ad un valore passato come parametro
 * @param int Valore di riferimento
 * @return Valore primo precedente al valore di riferimento.
 */
int prevPrimo(int _val);

/**
 * Visualizza a video N numeri casuali primi (compresi tra 1 e 999) successivi ad un valore di riferimento
 * @param int Valore di riferimento.
 * @param int Numero di valori da visualizzare.
 */
void visualizzaPrimi(int _val, int _n);

/**
 * Funzione che riceve una variabile per riferimento, ne raddoppia il valore contenuto.
 * @param int* Riferimento(indirizzo in memoria) alla variabile originale.
 */
void raddoppiaValore(int* _n);

/**
 * Funzione che riceve base e altezza di un rettangolo, calcola Area e Perimetro "restituendoli" al main
 * @param int Valore della base.
 * @param int Valore dell'altezza.
 * @param int* Riferimento alla variabile in cui mettere l'area.
 * @param int* Riferimento alla variabile in cui mettere il perimetro.
 */
void calcolaAreaPerimetro(int _base, int _altezza, int* _area, int* _perimetro);

/**
 * Funzione che in modo RICORSIVO suddivide un numero intero in singole cifre
 * @param int Valore da cui ricavare la cifra con peso minore. (unità)
 */
void estraiCifra(int _num);

/**
 * Funzione che in modo RICORSIVO esegue la conversione di un numero intero decimale in formato binario
 * operando per divisioni successive.
 * @param int Numero di cui calcolare il resto della divisone per 2 (operatore modulo - %)
 */
void convertiBinario(int _n);

/**
 * Funzione che scambia il contenuto di due variabili, se il primo è maggiore del secondo.
 * @param int* Riferimento alla prima variabile.
 * @param int* Riferimento alla seconda variabile
 * @return True/False in caso lo scambio avvenga oppure no.
 */
bool scambiaValori(int* _a, int* _b);