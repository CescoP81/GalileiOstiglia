## Elenco esercitazioni

**e01.c**
Introduzione alla scrittura e lettura di file binari con strutture.

**e02.c**
Realizzazione di un elenco di nominativi con salvataggio su file binario:  
- [x] Aggiunta nuovo nominativo.
- [x] Visualizzazione dei nominativi.
- [x] Ricerca per anno.

**e03.c**
Dato un file di binario, le cui righe rappresentano ciascuna i dati di una persona secondo il seguente formato:  
- cognome (max 30 car)  
- nome (max 30 car)  
- sesso (singolo car M/F)  
- anno di nascita intero  

scrivi un programma che permetta di inserire ripetutamente persone ad un file generale chiamato "contatti.dat', quando viene richiesto dall'utente, generare due file distinti maschi.dat e femmine.dat contenente i nominativi dei rispettivi sessi.  
Ogni volta i file maschi e femmine vengono generati da zero.  
Il file contatti viene gestito in aggiunta.

Utilizzare una struct e le funzioni fread e fwrite per la gestione dei file.

UPDATE:
[ ] Aggiungere opzione di modifica di un contatto nell'elenco generale.  
[x] Cancellazione di un contatto.