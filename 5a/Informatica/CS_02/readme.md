# Pag. 188 nr. 2  
Vendite di prodotti   
Un’azienda opera in diverse regioni del Paese, in ognuna delle quali ha molti uffici di rappresentanza. Ciascuno di questi uffici può vendere più di un prodotto tra quelli offerti dall’azienda. Si vuole costruire un database per controllare la distribuzione regionale delle vendite. Descrivi l’analisi del problema individuando entità, attributi e associazioni; disegna il modello E/R e deriva le tabelle.

## Funzionalità minime richieste da sviluppare in PHP/mySQL:
Lato amministrazione
- [ ] aggiornare l’archivio dei prodotti;
- [ ] elencare il numero di pezzi venduti e il relativo incasso raggruppati per prodotto;
- [ ] elencare le quantità vendute dei prodotti raggruppate per data;
- [ ] elencare i prodotti che non sono mai stati venduti;
- [ ] determinare il valore totale delle vendite suddiviso per ufficio di rappresentanza;
- [ ] determinare le quantità vendute di prodotti [ricerca determinato prodotto], elencando i risultati in modo ordinato per ufficio di rappresentanza;
- [ ] elencare le vendite di un dato ufficio in un intervallo di date scelto parametricamente(data inizio-data fine).
   
Lato Ufficio:
- [ ] aggiornare l’archivio delle vendite;
- [ ] elencare il numero di pezzi venduti e il relativo incasso raggruppati per prodotto;

## Funzionalità aggiuntive di progetto   
Lato amministrazione:   
- [ ] ...   
- [ ] ...   
   
Lato iscritto:
- [ ] ...   
- [ ] ...   
   
   
   
# Pag. 189 nr. 4    
Iscritti a un’associAzione culturale e spettacoli teatrali   
Gli iscritti a un’associazione culturale partecipano a spettacoli teatrali proposti annualmente dall’associazione e, dopo ogni rappresentazione, indicano il livello di gradimento dello spettacolo teatrale da 1-minimo gradimento a 5-massimo gradimento. La partecipazione di un iscritto a un evento è controllata con la presenza di un livello di gradimento. Gli iscritti che non partecipano a un dato spettacolo non forniscono alcuna indicazione.    Nell’anagrafica degli iscritti è registrata anche la fascia d’età con valori da 1-giovani fino a 4-anziani. Si vuole organizzare un database per registrare le partecipazioni agli spettacoli e controllare partecipazione e livello di gradimento per gli spettacoli proposti. Descrivi l’analisi del problema con entità, attributi e associazioni; disegna il modello E/R e deriva le tabelle.   

## Funzionalità minime richieste da sviluppare in PHP/mySQL:   
Lato amministrazione:   
- [ ] aggiornare l’archivio degli iscritti;   
- [ ] ottenere, a fine stagione, il conteggio delle partecipazioni di ogni iscritto, ordinato per iscritto;   
- [ ] individuare gli iscritti che non hanno partecipato a nessuno spettacolo;   
- [ ] ottenere la lista degli iscritti che hanno partecipato a tutti gli spettacoli;   
- [ ] ottenere il gradimento medio di tutti gli spettacoli;   

Lato iscritto:   
- [ ] Visualizzare il programma dell'annualità e relative schede spettacolo.   
- [ ] permettere l’inserimento e la modifica delle partecipazioni a spettacoli.   
- [ ] Specificare indice di gradimento di uno spettacolo visto.   
   
## Funzionalità aggiuntive di progetto   
Lato amministrazione:   
- [ ] ...   
- [ ] ...   
   
Lato iscritto:
- [ ] ...   
- [ ] ...   

## Project Timeline
- [x] 14.01.23 Presentazione tracce.
- [x] 21.01.23 Definizione ER Database - DDL.sql e DML.sql
- [x] 28.01.23 Definizione funzionalità aggiuntive
    - [x] Inizio programmazione parte amministrativa
- [x] 31.01.23 Visione concetto di sessione ed utilizzo (login utente).
- [ ] 04.02.23 Inizio programmazione parte front-end (iscritto o agenzia di vendita)
- [ ] 11.02.23 Check preventivo per rilascio versione finale.
- [ ] 18.02.23 Chiusura lavori e rubric di valutazione.



