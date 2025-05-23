## Elenco esercitazioni sulle Liste

**e01.c**  
Esercitazione base per la creazione di una lista, il nodo semplice memorizza un valore numerico e il puntatore al nodo successivo. La creazione di nuovi nodi avviene nella MAIN insieme alla visualizzazione.

**e02.c**  
Esercizio pari al primo ma con definizione di funzioni per inserimento in testa e visualizzazione della lista.
- [x] pushTesta() inserisce un valore in un nodo aggiunto in testa alla lista.
- [x] vediLista() visualizza una lista ricevendo il puntatore alla testa come parametro.
- [x] pushTesta() Inserisce un nuovo nodo come testa della lista, riceve la testa e il valore da inserire come parametri.
- [x] contaNodi() Funziona che ritorna il numero di nodi presenti in una lista.
- [x] popTesta() Funzione che estrae un nodo dalla testa della lista e restituisce al main il valore estratto.
- [x] cercaValoreLista() Restituisce la prima posizione nella lista (il numero del nodo) in cui compare il valore ricercato e passato come parametro.
- [x] ricercaMinMaxLista(); ritorna il valore minimo o massimo della lista, dare la possibilità di scegliere se cercare il max o il min.
- [x] mediaValoriLista(); calcola e restituisce il valore medio della lista.
- [x] sostitusciValoreLista() sostitusce nella lista tutti i valori uguali ad un valore x passato come parametro, con un valore y passato come parametro.
- [x] pushCoda() Aggiunge un nodo in coda alla lista, se la lista è vuota allora crea il primo nodo.
- [x] popCoda() Estrae un valore dalla lista passata.

**e03.c**  
Creare un programma C che sfruttando i concetti di push e pop sulle liste esegua le seguenti operazioni:
- [ ] Crea una lista di 10 nodi con valori random compresi tra 1 e 15 estremi inclusi. (vedere srand e rand())
- [ ] Visualizza la lista creata a video. 
- [ ] Creare una seconda lista di 5 nodi con valori compresi tra 16 e 25, estremi inclusi. 
- [ ] Visualizzare la seconda lista. 
- [ ] Realizzare una lista unica contenente i valori della prima lista e successivamente i valori della seconda lista (concetto di merge).

**e04.c**
Realizzare un programma C che utilizzando liste e file permetta le seguenti operazioni, selezionabili da un menu:  
- [ ] Genera lista: genera una lista di 15 elementi con valori interi compresi tra 1 e 25.
- [ ] Vedi lista: Visualizza a video la lista creata.
- [ ] Media lista: calcola e restituisce la media dei valori presenti nella lista.
- [ ] Salva su file: salva tutti i valori presenti nella lista su un file.
- [ ] Carica da file: permette di caricare i valori presenti sul file in una nuova lista. Se la lista è già presente viene sostituita con quella presente nel file.

**e05.c**
Realizzare un programma C che gestisca una rubrica di contatti, ogni contatto è catalogato con nome, cognome, anno di nascita. Il programma deve permettere di inserire nuovi contatti, visualizzare i contatti presenti nella lista, ricercare un contatto per cognome, ricercare per anno di nascita, eseguire il backup dei contatti su file, ripristinare i contatti presenti da file.