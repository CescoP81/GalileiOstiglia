-- QUesto file contiene tutte le query sviluppate ed eseguibili
-- sulla banca dati in uso.

-- Q1: Visualizzare tutti gli artisti presenti nel database
SELECT * FROM Artista;
-- Q1.1
SELECT nome, cognome, nazione FROM Artista;
-- Q1.2
SELECT cognome,nome,nazione FROM Artista;

-- Q2: Visualizzare tutti i brani presenti.
SELECT * FROM Brano;
-- Q2.1
SELECT Brano.*, Artista.*
FROM Brano, Artista;
-- Q2.3
SELECT Brano.*, Artista.*
FROM Brano, Artista
WHERE Brano.idArtista = Artista.id;

-- Q3: Visualizzare tutti i brani e relativo autore, ordinando i risultati
-- per cognome dell'autore.
SELECT Brano.*, Artista.*
FROM Brano, Artista
WHERE Brano.idArtista = Artista.id
ORDER BY Artista.cognome;

-- Q3.2
SELECT Brano.*, Artista.*
FROM Brano
INNER JOIN Artista
ON Brano.idArtista = Artista.id
ORDER BY Artista.cognome;