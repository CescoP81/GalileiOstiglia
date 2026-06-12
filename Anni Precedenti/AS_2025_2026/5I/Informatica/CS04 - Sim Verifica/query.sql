-- Q1 Visualizza tutti gli autori in ordine crescente per cognome
SELECT *
FROM autore
ORDER BY cognome ASC;

-- Q2 Visualizza tutti i libri e realtivo autore(cognome, nome)
SELECT l.titolo, l.nPagine, l.prezzo, a.cognome, a.nome
FROM libro AS l, autore AS a
WHERE a.id = l.cod_autore;

-- Q2 bis
SELECT l.titolo, l.nPagine, l.prezzo, a.cognome, a.nome
FROM libro AS l
INNER JOIN autore AS a
ON l.cod_autore = a.id

-- Q3 Visualizza tutti gli acquisti data, titolo libro, dati del cognome_nome del lettore, libreria presenti adatabase.
SELECT v.dataVendita, le.cognome AS 'Lettore Cognome', le.nome AS 'Lettore Nome', li.titolo, li.prezzo, lib.nome, lib.indirizzo 
FROM vendita AS v, lettore AS le, libro AS li, libreria AS lib
WHERE v.idLettore = le.id
    AND v.idLibreria = lib.id
    AND v.idLibro = li.id;

-- Q4 Visualizzare quanto ha speso ogni lettore indicando nome cognome e totale
-- richiede l'uso di GROUP BY e nella clausola FROM bisogna indicare la tabella che collega lettore con libri cioè
-- vendita, altrimenti non riesco a rintraccia i libri acquistati da ogni singolo lettore.
SELECT le.cognome, le.nome, SUM(li.prezzo) AS 'Totale'
FROM lettore AS le, libro AS li, vendita AS ve
WHERE le.id=ve.idLettore AND ve.idLibro=li.id
GROUP BY le.id
ORDER BY Totale DESC;

-- Q5 Visualizzare tutti gli acquisti effettuati dopo il 1 gennaio 2016
SELECT li.titolo AS 'Titolo Libro', le.cognome AS 'Cognome Lettore', le.nome AS 'Nome lettore', lib.nome AS 'Libreria', ve.dataVendita AS 'Data di vendita'
FROM libro AS li, lettore AS le, libreria AS lib, vendita AS ve
WHERE ve.idLettore = le.id
    AND ve.idLibro = li.id
    AND ve.idLibreria = lib.id
    AND ve.dataVendita > '2016-01-01'
ORDER BY ve.dataVendita ASC;

-- Q6 Visualizzare tutti i libri acquistati nella libreria temperino
SELECT li.titolo
FROM libro AS li, vendita AS ve, libreria AS lib
WHERE li.id = ve.idLibro
    AND ve.idLibreria = lib.id
    AND lib.nome = 'La matita';
-- AND lib.id = 1 -> Errore, recupero la libreria per nome non per ID evitando di andare
-- a vedere l'id di una determinata libreria tra centinaia di librerie.

-- Q7 Visualizza tutti i libri la cui somma degli incassi è compresa tra 20 e 35.
SELECT li.titolo, SUM(li.prezzo) AS 'Totale'
FROM libro AS li, vendita AS ve
WHERE li.id = ve.idLibro
GROUP BY li.id
HAVING Totale >= 17.0 AND Totale <= 20.0
ORDER BY Totale ASC;
