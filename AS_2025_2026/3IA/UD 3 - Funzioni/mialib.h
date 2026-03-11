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