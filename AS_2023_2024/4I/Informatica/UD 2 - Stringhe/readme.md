### *ELENCO ESERCITAZIONI*

**lib.h**   
Contiene i prototipi di tutte le funzioni sviluppate con relativo commento, testate e quindi inserite nel file lib.c come libreria generale. Questo file viene incluso nel file lib.c ad inizio codice.  

**lib.c**   
Contiene la definizione di tutte le funzioni sviluppate, ad inizio codice include le librerie necessarie (es. <stdio.h>) ed il file dei prototipi lib.h, eventuali commenti sono interni alle singole funzioni. Questo file viene incluso da inizio codice nei vari programmi p--.c dopo le librerie standard.

---

**p01.c**  
Esempio generale ed iniziale sull'input di una stringa e della relativa stampa, sia diretta sia char-by-char.

**p02.c**   
Creare un programma C che sfruttando la conoscenza delle stringhe permetta le seguenti funzioni:
- [x] Inizializzazione di una stringa vuota.
- [x] Inserimento di una stringa da tastiera.
- [x] Conteggio delle lettere della stringa.
- [x] Conteggio di una lettera inserita da tastiera.
- [x] Conteggio di quante vocali compaiono nella stringa.
- [x] Sostituzione di una lettera src con una lettera sostitutiva dst.
- [x] Visualizzazione di una stringa al contrario.
- [x] Verifica se una parola inserita è palindroma.

Ogni singolo punto è da realizzare con una specifica funzione, relativi parametri passati per valore/riferimento e con ritorno void o non-void.

**p03.c**   
Creare un programma C che soddisfi le seguenti richieste:
- [x] input di una stringa.
- [x] stampa di una stringa a video con funzione ricorsiva.
- [x] Conteggio delle lettere maiuscole e minuscole in una stringa.
- [x] Verifica se esistono doppie in una stringa 'otto', 'sette'.
- [x] Prima lettera sempre maiuscola (se la stringa inizia con una minuscola, la trasforma in maiuscola).
- [x] Per ogni lettera calcola e stampa il numero di occorrenze (quante volte ogni lettera compare).
- [x] Crea stringa inversa. (st1 è l'originale, st2 è l'inversa).
- [x] Verifica se due stringhe sono anagrammi (st2 è anagramma di st1, anagramma: parole diverse ma formate dalle stesse lettere)

Utilizzare le funzioni già esistenti nel file lib.c/lib.h, le nuove funzioni prima farne un test nel main e poi spostarle nel file libreria.
*/

**p04.c**  
Esempio di utilizzo di un vettore di stringhe, concettualmente è una matrice di caratteri dove ogni singola riga rappresenta una stringa.
Commentando il codice da riga 15 a riga 30 comprese, dopo averlo provato, sviluppare i seguenti punti:
- [ ] Acquisire 5 stringhe da tastiera.
- [ ] Stampare le 5 stringhe inserite come verifica.
- [ ] Per ogni stringa stampare la sua lunghezza.
- [ ] Determinare e stampare la stringa più lunga e la stringa più corta.
- [ ] Verificare se tra le parole sono presenti palindrome.
- [ ] Inserita una lettera da tastiera, determinare la parola che la contiene più volte.
- [ ] Modificare l'iniziale di ogni parola mettendola in maiuscolo.
- [ ] Visualizzare ogni parola al contrario.

**p06.c**
Creare un programma che genera una stringa casuale x5 volte rispettando il formato:  
	m, M, N, M - N, m, M, J  
	dove N indica un numero casuale tra 0 e 9;  
	dove m indica una lettera casuale tra 'a' e 'z';  
	dove M indica una lettera dell'alfabeto maiuscolo;  
	dove J indica un carattere jolly tra i seguenti:  
	- @;  
	- #;  
	- !;  
	- &;  
	- ?;   
	ESEMPIO:  
		a C 7 T - 2 s X #