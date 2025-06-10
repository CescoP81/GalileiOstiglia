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
SELECT ufficio.*, regione.nome AS Regione
FROM ufficio, regione
WHERE ufficio.idRegione = regione.id;

-- Q7: Come sopra ma sfrutto il concetto di JOIN e relazioni
-- per avere il nome della regione anziché il suo id e elimino dalla
-- visuale le chiavi esterne e primary in regione.
SELECT u.id, u.citta, u.indirizzo, u.telefono, u.email, r.nome AS regione
FROM ufficio AS u, regione AS r
WHERE u.idRegione = r.id;

-- Come Q6 ma utilizzando la sintassi INNER JOIN anziche le clausole WHERE.
SELECT ufficio.*, regione.nome AS Regione
FROM ufficio
INNER JOIN regione ON ufficio.idRegione=regione.id

-- Q8 visualizzare tutti i prodotti ordinandoli per prezzo
-- ORDER BY ... ASC (di default)-> Ascendente dal piccolo al grande.
-- ORDER BY ... DESC -> Discendente dal grande al piccolo.
SELECT *
FROM prodotto
ORDER BY prezzoUnitario ASC;

-- Q9 Determinare il prezzo massimo tra i prodotti presenti
-- operatore MAX restituisce il valore massimo sulla colonna scelta.
SELECT MAX(prezzoUnitario)
FROM prodotto;

-- Q10 Determinare il prezzo minimo tra i prodotti presenti
-- operatore MIN restituisce il valore minimo sulla colonna scelta.
SELECT MIN(prezzoUnitario)
FROM prodotto;

-- Q11 Determinare il prezzo medio tra i prodotti presenti
-- operatore AVG restituisce il valore medio sulla colonna scelta.
SELECT AVG(prezzoUnitario)
FROM prodotto;

-- Q12 Calcolare la somma totale dei prezzi tra tutti i prodotti
SELECT SUM(prezzoUnitario)
FROM prodotto;

-- Q13 Determinare quanti prodotti sono inseriti nel database
SELECT COUNT(id)
FROM prodotto;

-- Q14 Visualizzare tutti i prodotti che hanno un prezzoUnitario
-- inferiore di un prezzo scelto ( es. 6€).
SELECT *
FROM prodotto
WHERE prezzoUnitario < 6;

-- Q15 Visualizza tutti i prodotti che hanno un prezzoUnitario
-- inferiore alla media dei prezzi.
SELECT *
FROM prodotto
WHERE prezzoUnitario < ( SELECT AVG(prezzoUnitario)
                            FROM prodotto);

-- Q16 Visualizzare tutte le vendite effettuate
SELECT * 
FROM vendita;

-- Q16 advanced
SELECT v.dataVendita, v.quantita, p.descrizione AS Prodotto, u.citta AS 'Città ufficio'
FROM vendita AS v, prodotto AS p, ufficio AS u
WHERE u.id=v.idUfficio AND v.idProdotto=p.id;