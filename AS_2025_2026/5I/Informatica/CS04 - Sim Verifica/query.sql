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