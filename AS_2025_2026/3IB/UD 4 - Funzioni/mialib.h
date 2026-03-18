/* QUESTO FILE CONTIENE SOLAMENTE I PROTOTIPI DELLE FUNZIONI */

/**
 * Funzione che visualizza i divisori di un numero passato come parametro.
 * @param int Numero da analizzare.
 */
void vediDivisori(int _n);

/**
 * Richiede l'inserimento di un valore intero e lo restituisce al main program.
 * @return Valore intero inserito dall'utente.
 */
int getIntegerValue();

/**
 * Richiede l'inserimento di un valore intero compreso in un range di valori e lo restituisce al main.
 * @param int Valore minimo ammesso.
 * @param int Valore massimo ammesso.
 * @return Valore intero inserito dall'utente.
 */
int getIntegerValueInterval(int _min, int _max);

/**
 * Restituisce un numero random compreso tra 1 e 999
 * @return Valore random generato.
 */
int getRandomValue();

/**
 * Restitusce un numero random compreso in un range di valori.
 * @param int Valore minimo ammesso.
 * @param int Valore massimo ammesso.
 * @return Valore random generato nell'intervallo min<->max
 */
int getRandomValueInterval(int _min, int _max);

/**
 * Verifica se un numero è primo oppure no
 * @param int Numero da verificare
 * @return True/False se è primo oppure no.
 */
bool isPrimo(int _num);