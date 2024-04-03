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
Creare un file di testo "parole.txt" contenente alcune parole di lunghezza non superiore a 15 caratteri, divise da un "invio" (andata a capo). **L'ultima parola non ha l'invio finale.** Il programma apre in lettura il file e determina:
- [x] Numero di parole presenti.
- [x] Lunghezza media delle parole.
- [x] Stampa a video delle eventuali parole palindrome.

**p06.c**
Realizzare un file "valori.txt" con all'interno 20 valori casuali interi compresi tra 10 e 25, i valori devono essere scritti a mano nel file. Realizzare quindi un programma che aperto il file in lettura:
- [x] Visualizza a video tutti i valori presenti nel file.
- [x] Determina e comunica a video il valore maggiore e minore.
- [x] Determina la media dei valori presenti.
- [x] Visualizza a video tutti i valori superiori alla media e in una riga successiva tutti i valori inferiori alla media.
- [x] Richiede da tastiera un valore compreso tra 10 e 25 quindi salva in un secondo file "numeri2.txt" solo i valori maggiori o uguali al valore inserito, presenti nel file iniziale.

---

File binari, post pcto, con strutture.
- [x] Definizione di struttura e dichiarazione ed utilizzo.
- [x] Scrittura di strutture con fwrite.
- [x] Lettura di strutture con fread.
- [x] Gestione rubrica telefonica, elenco prodotti, catalogo dischi.
- [ ] Vettore di strutture [forse].

**p07.c**
Esempio di definizione della struttura e relativa dichiarazione come variabile o come puntatore, esempio di input.  

**p08.c**
Esempio di scrittura di una struttura su file binario con funzione fwrite.

**p09.c**
Esempio di lettura di strutture su file binario con funzione fread. Riutilizzo sempre il puntatore p dopo aver scritto la struttura sul file.

**p10.c**
Applicazione sviluppata in C per la catalogazione di una collezione privata di Dischi.
Ogni disco è identificato dalle seguenti informazioni:
- Artista -> Cognome e Nome  
- Titolo  
- Anno  
- Giri -> 45 o 33  
L'applicazione deve permettere le seguenti funzionalità utilizzando come archivio il file binario 'discografia.dat':
    - [x] Aggiunta di un nuovo Disco alla collezione.
    - [x] Visualizzazione dei Disco della collezione.
    - [x] Ricerca di un Disco basata su Cognome Artista.
    - [x] Ricerca di un Disco basata su Anno o intervallo anni.
    - [x] Modifica dei dati di un Disco.
    - [x] Cancellazione di un Disco dall'elenco discografico.

NB: il MAIN PROGRAM prevede un menu, uno switch case e la chiamata di una FUNZIONE per ogni punto da sviluppare.
