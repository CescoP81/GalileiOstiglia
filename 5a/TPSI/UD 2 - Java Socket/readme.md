### LISTA DELLE ESERCITAZIONI ###

*** EchoServer.java ***   
Esempio di base per la creazione di un ServerSocket in Java. Il socket si mette in ascolto, acquisisce un singolo carattere dal client e lo rimanda al client aggiungendo il carattere '?'. L'esempio verifica la creazione di un ServerSocket, e lo scambio di un messaggio con un client.

*** EchoServer2.java ***   
Come esercizio precedente sfrutta la creazione di un ServerSocket ma grazie all'utilizzo di un BufferedReader il socket accetta dal client stringhe composte da più parole, ogni volta la stringa inserita viene rimandata dal ServerSocket come verifica. Se si inserisce la stringa particolare "ciao!" il ServerSocket termina il suo ciclo di ascolto ripetuto e chiude la connessione.