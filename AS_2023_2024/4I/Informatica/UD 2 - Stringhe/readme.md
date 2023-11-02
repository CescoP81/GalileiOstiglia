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
- [ ] input di una stringa.
- [ ] stampa di una stringa a video con funzione ricorsiva.
- [ ] Conteggio delle lettere maiuscole e minuscole in una stringa.
- [ ] Verifica se esistono doppie in una stringa 'otto', 'sette'.
- [ ] Prima lettera sempre maiuscola (se la stringa inizia con una minuscola, la trasforma in maiuscola).
- [ ] Per ogni lettera calcola e stampa il numero di occorrenze (quante volte ogni lettera compare).
- [ ] Crea stringa inversa. (st1 è l'originale, st2 è l'inversa).
- [ ] Verifica se due stringhe sono anagrammi (st2 è anagramma di st1, anagramma: parole diverse ma formate dalle stesse lettere)

Utilizzare le funzioni già esistenti nel file lib.c/lib.h, le nuove funzioni prima farne un test nel main e poi spostarle nel file libreria.
*/