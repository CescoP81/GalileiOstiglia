-- FILE CONTENENTE ALCUNE QUERY DI ESEMPIO CHE INTERESSINO UNA O PIU'
-- TABELLE CONTEMPORANEAMENTE.

-- Q1: Visualizzare tutti i prodotti presenti a DB.
SELECT *
FROM prodotto;

-- Q2: Visualizzare id, descrizione e note di tutti i prodotti.
SELECT id, descrizione, note
FROM prodotto;

-- Q3: come query sopra ma scambiando ordine degli attributi.
SELECT descrizione, prezzoUnitario, id
FROM prodotto;

-- Q4: Visualizza tutte le regioni presenti a DB
SELECT *
FROM regione;

-- Q5: visualizza tutti gli ufficio presenti a DB
SELECT *
FROM ufficio;

-- Q6: Come sopra ma sfrutto il concetto di JOIN e relazioni
-- per avere il nome della regione anziché il suo id.
SELECT ufficio.*, regione.nome
FROM ufficio, regione
WHERE ufficio.idRegione = regione.id;

-- Q7: Come sopra ma sfrutto il concetto di JOIN e relazioni
-- per avere il nome della regione anziché il suo id e elimino dalla
-- visuale le chiavi esterne e primary in regione.
SELECT u.id, u.citta, u.indirizzo, u.telefono, u.email, r.nome AS regione
FROM ufficio AS u, regione AS r
WHERE u.idRegione = r.id;