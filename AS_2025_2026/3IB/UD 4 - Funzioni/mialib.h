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

/**
 * Restituisce il successivo numero primo rispetto ad un valore passato come parametro.
 * @param int Valore di riferimento
 * @return Valore primo successivo al valore di riferimento.
 */
int nextPrimo(int _num);

/**
 * Restituisce il precedente numero primo rispetto ad un valore passato come parametro.
 * @param int Valore di riferimento
 * @return Valore primo precedente al valore di riferimento
 */
int prevPrimo(int _num);

/**
 * Visualizza N numeri primi successivi ad un valore passato come parametro generati in modo casuale
 * tra 1 e 999.
 * @param int Valore di riferimento.
 * @param int Numero di valori da generare
 */
void generaPrimi(int _num, int _n);

/**
 * Visualizza i divisori primi di un numero passato come parametro, restituisce 
 * il numero di divisori trovati.
 * @param int Numero di riferimento.
 * @return Numero di divisori primi identificati e stamapti.
 */
//--- divisoriPrimi(---);