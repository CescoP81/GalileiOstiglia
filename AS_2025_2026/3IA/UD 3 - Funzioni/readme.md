## ELENCO ESERCITAZIONI ## 

### suddivisione dei file e relativo contenuto ###
- **e#.c**: contengono il main program dell'esercitazione ed includono con il comando @include "libreria.c" il file di libereria.
- **libreria.c**: contiene le funzioni utili alle diverse esercitazioni, include le librerie di cui necessitano le funzioni ed include il file "libreria.h".
- **libreria.h**: contiene i prototipi delle funzioni, ognuno con relativo commento secondo la sintassi standard in cui viene indicato: tipo di ritorno della funzione, nome della funzione, tipo e nome dei parametri della funzione.

**mialib.h - mialib.c**
- [x] bool isPrimo(int _n) - Check whether a number is prime or not.
- [x] bool isPerfect(int _n) - Verifica se un numero è perfetto oppure no.
- [x] bool isTernaPitagorica(int _n1, int _n2, int _n3) - Verifica terna pitagorica, se n1^2+n2^2 = n3^2.
- [x] int inputValoreRange(int _min, int _max) - Inserimento controllato di un valore intero tra min e max estremi compresi.
- [x] int randomValoreRange(int _min, int _max) - Genera un valore random compreso tra due valori interi min e max, estremi compresi.
- [x] int nextPrimo(int _val) - Restituisce il successivo numero primo di un valore passato come parametro.
- [x] int prevPrimo(int _val) - Restituisce il primo precedente ad un valore passato come parametro
- [x] void visualizzaPrimi(int _val, int _n) - Visualizza a video N numeri casuali primi (compresi tra 1 e 999) successivi ad un valore di riferimento

**e01.c**  
Introduzione alla programmazione con funzioni, concetto di prototipo (dichiarazione della funzione), definizione della funzione dopo il MAIN, commentatura del prototipo indicando descrizione generale e tipologia dei parametri e/o del valore di ritorno.
- [x] bool isPrimo(int _n)

**e02.c**
Come e01.c ma le funzioni sono state spostate in file di libreria separati, in particolare il file **mialib.h contiene solo** i prototipi delle funzioni mentre il file **mialib.c contiene solo** la definizione delle funzioni. Il file e02.c include mialib.c la quale a sua volta include mialib.h  
L'esercizio esegue una chiamata come test per le seguenti funzioni:
- [x] bool isPrimo(int _n).
- [x] bool idPerfect(int _n).
- [x] bool isTernaPitagorica(int _n1, int _n2, int _n3).
- [x] int inputValoreRange(int _min, int _max).
- [x] int randomValoreRange(int _min, int _max).


