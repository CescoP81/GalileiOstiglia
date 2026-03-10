## ELENCO ESERCITAZIONI ## 

### suddivisione dei file e relativo contenuto ###
- **e#.c**: contengono il main program dell'esercitazione ed includono con il comando @include "libreria.c" il file di libereria.
- **libreria.c**: contiene le funzioni utili alle diverse esercitazioni, include le librerie di cui necessitano le funzioni ed include il file "libreria.h".
- **libreria.h**: contiene i prototipi delle funzioni, ognuno con relativo commento secondo la sintassi standard in cui viene indicato: tipo di ritorno della funzione, nome della funzione, tipo e nome dei parametri della funzione.

**e01.c**  
Introduzione alla programmazione con funzioni, concetto di prototipo (dichiarazione della funzione), definizione della funzione dopo il MAIN, commentatura del prototipo indicando descrizione generale e tipologia dei parametri e/o del valore di ritorno.
- [x] bool isPrimo(int _n)

**e02.c**
Come e01.c ma le funzioni sono state spostate in file di libreria separati, in particolare il file **mialib.h contiene solo** i prototipi delle funzioni mentre il file **mialib.c contiene solo** la definizione delle funzioni. Il file e02.c include mialib.c la quale a sua volta include mialib.h
- [x] bool isPrimo(int _n) Verifica se un numero passato come parametro per valore è primo oppure no.
- [x] bool idPerfect(int _n) Verifica se un numero passato come parametro per valore è perfetto oppure no (perfetto se la somma dei suoi divisori è uguale al suo doppio; 6 è perfetto).


