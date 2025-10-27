## Elenco esercitazioni  

## boot01.html  
Primo esempio di caricamento del framework Bootstrap, le librerie CSS sono caricate nel tag &lt;head&gt; mentre la parte di script è alla fine del &lt;body&gt;

## boot01.php  
Stessa struttura della pagina precedente ma il codice HTML è restituito al browser tramite funzioni di echo().

## boot02.php
Esempio di utilizzo dei form Bootstrap per l'acquisizione di valori base e altezza di un ipotetico rettangolo per il calcolo di area e perimetro. I valori sono passati tramite indirizzo HTTP REQUEST.

## boot03.php
Stesso codice del boot02 con la variante che le righe iniziali e finali in HTML sono spostate nel file *lib.php* in cui sono state create le funzioni *writeStart()* e *writeEnd()*

## lib.php
File di libreria nel quale il codice è raccolto in diverse funzioni che verranno poi richiamate dalle varie pagine che con la funzione *require()* includeranno il file *lib.php*.