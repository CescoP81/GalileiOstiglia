Costruisci il modello di dati per la gestione delle informazioni riguardanti gli immobili e i loro proprietari; un immobile può essere intestato anche a più proprietari e naturalmente una persona può possedere uno o più immobili.
Gli immobili sono di diverse tipologie abitazioni, uffici e negozi; e sono posti in zone diverse della città.
La gestione deve poter ottenere:
- Le informazioni anagrafiche dei proprietari di un determinato immobile;
- l'elenco degli immobili con i relativi proprietari di una via prefissata della città,
- Le caratteristiche degli immobili di una certa tipologia con metratura, piano, numero locali.


#################
# VERSION CHART #
#################

Ver 2.0.0
- Modifica alla struttura tabella proprietario -> aggiunto il campo password per ASH MD5
- Aggiunta pagina cliente.php -> autentica un proprietario.
- Aggiunta nella registrazione nuovo proprietario il setup della password.
- Creazione PDF di riepilogo per proprietario con lista immobili e calcolo rendite annualità in corso.

Ver. 1.2.0
- Aggiunta tabella rendita_annuale.
- Aggiunta della pagina per la popolazione della rendita annuale.
- Calcolo rendita per singolo Proprietario su base annua o più anni.

Ver. 1.1.0
- Aggiunta stampa PDF Immobili di un determinato proprietario.

Ver. 1.0.0
- Sviluppo tabelle principali ed relativa gestione.
- Gestione Proprietari.
- Gestione Zone.
- Gestione Tipologie.
- Gestione Immobili.
- Gestione Associazione Proprietario <-> Immobile.


-----------------------
Riguardo la numerazione: https://it.wikipedia.org/wiki/Versione_(software)

Ver n1.n2.n3
n1 -> numero incrementale quando si aggiungono funzionalità che non sono retrocompatibili con la versione precedente del database.
n2 -> aggiunta di funzionalità lasciando inalterato il database.
n3 -> correzione di bug nella versione attualmente in uso.

Es.
Ver.  1.0.0 -> Versione base.
      1.1.0 -> E' stata aggiunta una fuzionalità mantenendo inalterato il DB.
      1.1.1 -> E' stato corretto uno o più bugfix.
      1.1.2 -> Sono stati corretti ulteriori bugfix.
      2.0.0 -> E' stata modificata la struttura del database, l'app sviluppata non è più compatibile con il DB precedente (ver 1.x.x).
      2.1.0 -> si riprende dall'aggiunta di funzionalità...