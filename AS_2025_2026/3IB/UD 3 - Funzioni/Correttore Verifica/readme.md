## Testo della prova ##

Realizzare un programma che presentando un menu di scelta permetta di selezionare una delle seguenti operazioni, il programma deve essere ripetibile finché non viene inserita la scelta di uscita/termina programma:  

- A) int inputNumber(int, int): Prevede due parametri interi, ed esegue l'input di un numero da tastiera restituendolo al main, operando secondo il seguente schema:  
se i due parametri sono 0 accetta qualunque numero in input;  
se i due parametri sono diversi da zero con p1 < p2 accetta in input solo valori compresi tra p1 e p2 estremi compresi;  
se p1=0 e p2>0 allora accetta qualunque valore positivo purché inferiore a p2;  
tutti gli altri casi restituisce -1.  

- B) int getMaxDivider(int, int, int): vengono passati tre valori interi in ordine casuale, la funzione restituisce al main il divisore maggiore comune ai tre valori.  

- C) void orderValues(int, int, int, int): riceve tre valori in ordine casuale e come ultimo parametro un intero 0/1 (0 ordine decrescente; 1 ordine crescente). In base all'ordine impostato i tre valori vengono ordinati, quando la funzione trova due valori da scambiare chiama la funzione void swapValue(int, int) che esegue lo scambio di valore tra due variabili.  

- D) Termina programma: visualizza il totale delle scelte effettuate durante l’utilizzo del programma, quindi termina l’esecuzione.  

Creare gli opportuni file di libreria ed un main program per testare le funzioni, i prototipi vanno documentati.

Attenzione: come parametri ho indicato solamente il tipo di dato, se è passaggio per valore o riferimento lo devi decidere tu.