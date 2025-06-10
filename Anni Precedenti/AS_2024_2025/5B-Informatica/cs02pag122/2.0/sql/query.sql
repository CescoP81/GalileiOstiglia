--Visualizzare tutti i magazzini ordinati per provincia
SELECT *
FROM magazzino
ORDER BY provincia asc; 

--Visualizzare tutti gli ordini presenti a DB
SELECT *
FROM acquisto
ORDER BY dataAcquisto;

--Visualizzare tutti gli ordini presenti a DB includendo i dati del prodotto e del relativo magazzino
SELECT p.descrizione, m.nome, m.citta, m.provincia, a.dataAcquisto, a.quantitaAcquisto, a.prezzoAcquisto
FROM prodotto as p, magazzino as m, acquisto as a
WHERE p.id = a.idProdotto and a.idMagazzino = m.id;

--SELECT * FROM table1 INNER JOIN table2 ON table1.id = table2.id;
SELECT p.descrizione as prodotto, m.nome as magazzino, m.citta, m.provincia, a.dataAcquisto as 'Data Acquisto', a.quantitaAcquisto, a.prezzoAcquisto
FROM acquisto as a
INNER JOIN prodotto as p on p.id = a.idProdotto
INNER JOIN magazzino as m on a.idMagazzino = m.id
ORDER BY a.dataAcquisto, a.prezzoAcquisto desc;

--Determinare il numero di prodotti presenti nel database
SELECT count(id)
FROM prodotto
--Determinare il prezzo minore dei prodotti presenti
SELECT min(prezzoAcquisto)
FROM acquisto;
--Detterminare il prezzo massimo di acquisto presente nel database
SELECT max(prezzoAcquisto)
FROM acquisto;
--Determinare il prezzo medio degli acquisti presenti nel database
SELECT avg(prezzoAcquisto)
FROM acquisto;
--
SELECT prezzoAcquisto
FROM acquisto
ORDER BY prezzoAcquisto desc
LIMIT 1;
--Visualizzare tutti gli acquisti con prezzo inferiore o uguale al prezzo di acquisto medio
SELECT acquisto.*
FROM acquisto
WHERE prezzoAcquisto <= (
    SELECT avg(prezzoAcquisto)FROM acquisto
    ); 
--Come query precedente ma visualizzando i dati del prodotto
SELECT p.descrizione as prodotto,m.nome as magazzino, a.dataAcquisto, a.quantitaAcquisto, a.prezzoAcquisto
FROM acquisto as a, prodotto as p, magazzino as m
WHERE a.prezzoAcquisto <=(SELECT avg(prezzoAcquisto) FROM acquisto)
AND p.id = a.idProdotto
AND a.idMagazzino = m.id;

--Visualizzare tutti gli ordini effettuati dal magazzino 'Mantova 1';
SELECT p.descrizione, a.dataAcquisto,a.prezzoAcquisto,a.quantitaAcquisto
FROM prodotto as p, acquisto as a, magazzino as m
WHERE p.id = a.idProdotto 
AND a.idMagazzino = m.id
AND m.nome = 'Mantova 1';

