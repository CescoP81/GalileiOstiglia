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