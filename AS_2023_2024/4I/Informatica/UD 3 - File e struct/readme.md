File di testo pre pcto:
- [ ] Apertura file di testo .txt in modo W-R-A.
- [ ] Scrittura con funzione fprintf, fputc, fputs.
- [ ] lettura da file con funzioni fscanf, fgetc, fgets.

**p01.c**
Esercizio di esempio per la scrittura di singole parole su file. Il programma legge delle parole in input e le scrive su un file di testo finché non viene inserita la parola "fine".

**p02.c**
Esercizio di esempio per la lettura di parole da un file.
Utilizzo la funzione fscanf(..) la quale si comporta come la scanf() quindi termina la lettura di una parola quando incontra il carattere ' ' spazio, oppure '\n' andata a capo.

**p03.c**
Esempio di lettura di valori da file, utilizzanod %d nella fscanf così come farei a video e da tastiera.
NB: Il file DEVE contenere solo numeri interi con %d e in virgola si %f.

**p04.c**
Programma che richiede parole all'utente ed in caso siano di un numero di caratteri dispari allora le salva in un file denominato 'parole.txt' separandole da uno spazio. L'inserimento termina con la parola chiave "fine". Il programma deve comunicare all'utente quante parole sono inserite nel file, la lunghezza più corta e quella più lunga.

**p05.c**
Creare un file di testo "parole.txt" contenente alcune parole di lunghezza non superiore a 15 caratteri, divise da un "invio" (andata a capo). L'ultima parola non ha l'invio finale. Il programma apre in lettura il file e determina:
- [x] Numero di parole presenti.
- [x] Lunghezza media delle parole.
- [x] Stampa a video delle eventuali parole palindrome.

**p06.c**
Realizzare un file "valori.txt" con all'interno 20 valori casuali interi compresi tra 10 e 25, i valori devono essere scritti a mano nel file. Realizzare quindi un programma che aperto il file in lettura:
- [ ] Visualizza a video tutti i valori presenti nel file.
- [ ] Determina e comunica a video il valore maggiore e minore.
- [ ] Determina la media dei valori presenti.
- [ ] Visualizza a video tutti i valori superiori alla media e in una riga successiva tutti i valori inferiori alla media.
- [ ] Richiede da tastiera un valore compreso tra 10 e 25 quindi salva in un secondo file "numeri2.txt" solo i valori maggiori o uguali al valore inserito, presenti nel file iniziale.

---

File binari, post pcto, con strutture.
- [x] Definizione di struttura e dichiarazione ed utilizzo.
- [x] Scrittura di strutture con fwrite.
- [ ] Lettura di strutture con fread.
- [ ] Gestione rubrica telefonica, elenco prodotti, catalogo dischi.
- [ ] Vettore di strutture [forse].

**p07.c**
Esempio di definizione della struttura e relativa dichiarazione come variabile o come puntatore, esempio di input.
