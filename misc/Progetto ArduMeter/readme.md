## Progetto realizzato dalla 5IA A.S. 2023/24 ##

Il progetto consiste in due parti realizzate da due gruppi di studenti, suddividendo così il lavoro di progettazione e realizzazione:   
- Gruppo 1: Sviluppo hardware basato su scheda Arduino UNO R3 con annessa Keyestudio Ethernet Shield Wired 5100 e sensore di temperatura Keyestudio DHT11. Il programma caricato nella Board legge i valori temperatura e umidità con cadenza orara e tramite la Ethernet Shield e una chiamata HTTP invia i dati ad un server remoto con supporto PHP/MySQL per il salvataggio di tale dati in un database.

- Gruppo 2: Sviluppo della pagina PHP e relativa API per permettere l'inserimento di dati temperatura e umidità nel database MySQL, e la visualizzazione in formato tabellare con framework Bootstrap.

## Change Log. ##
- 1.0
    - Lettura temperatura e umidità con cadenza oraria.
    - Salvataggio informazioni su server remoto PHP/MySQL.
    - Visualizzazione con tabella Bootstrap dei dati letti. 