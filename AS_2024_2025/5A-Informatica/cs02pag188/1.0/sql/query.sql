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