### *ELENCO ESERCITAZIONI*

**p01.c**  
Esercitazione basilare per mostrare punti in comune tra il linguaggio C studiato ed il linguaggio PHP in studio quest'anno.

**p02.php**
Esercitazione incentrata sulla creazione e gestione dei vettori in PHP.

**p03.php e p03.html**
Esercitazione con form HTML e rispettiva pagina di scrip php. Il form presente nella pagina HTML ha come action la pagina php che viene richiamata alla pressione del bottone submit. La pagina php recupera i due dati dal vettore delle REQUEST e li utilizza per mostrare area e perimetro di un ipotetico rettangolo.

**p04.php**
Come esercizio precedente ma il form PHP è innestato nel codice PHP, quindi la pagina PHP genera il codice HTML per il form ed utilizza i dati nelle REQUEST una volta richiamata dalla pressione del button.

**p04_1.php**
Come esercizio precedente con l'aggiunta di una SELECT per dare possibilità di scelta se calcolare area o perimetro. La scelta viene gestita nel PHP con un semplice switch-case.

**p04_2.php**
Estensione dell'esercizio precedente mettendo però il codice html iniziale e finale in due file distinti chiamati head.php e foot.php, questi file vengono richiamati nel php generale grazie alla funzione require(). Scomposizione del codice in più file per sfruttare il riutilizzo anziche la ricopiatura ripetuta.

**p04_3.php**
Come esercizio precedente ma è stata inserita la sintassi BootStrap per l'utilizzo del framework che utilizzeremo per le interfacce delle web applications.

### **TRY YOURSEFL**
Utilizza il linguaggio PHP e la sintassi bootstrap per realizzare le seguenti pagine e verificare i contenuti fin qui visti.

**p05.php**
Realizza una pagina php che richiede tre valori, alla pressione del bottone di submit verifica se sono in ordine crescente oppure no.

**p06.php**
Realizza una pagina php che richiede un valore all'untente, alla pressione del bottone di submit: 1. genera un vettore di N (N inserito dall'utente) valori casuali compresi tra 10 e 25; 2. visualizza il vettore; determina quali valori nel vettori sono numeri primi.

**p07.php**
Realizza una pagina php che richiede un valore all'utente, alla pressione del bottone di submit genera una tabella HTML di tante righe e tante colonne quanto è il valore inserito e dove in ogni cella sia inserito il risultato (RIGA x COLONNA)