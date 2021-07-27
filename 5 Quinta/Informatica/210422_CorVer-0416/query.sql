-- QUERY 1: 
SELECT a.* 
FROM v_autore AS a
ORDER BY a.cognome ASC;

-- QUERY 2:
SELECT l.titolo, l.n_pagine, l.prezzo , a.cognome, a.nome
FROM v_libro AS l, v_autore AS a 
WHERE l.id_autore = a.id;

-- QUERY 3:
SELECT vendita.data_vendita, libro.titolo, lettore.cognome_nome, libreria.nome 
FROM v_vendita AS vendita, v_libro AS libro, v_lettore AS lettore, v_libreria AS libreria
WHERE lettore.id=vendita.id_lettore AND vendita.id_libro=libro.id AND vendita.id_libreria=libreria.id;

-- QUERY 4:
SELECT lettore.cognome_nome, SUM(libro.prezzo) AS 'Spesa Totale'
FROM v_lettore AS lettore, v_libro AS libro, v_vendita AS vendita 
WHERE lettore.id=vendita.id_lettore AND vendita.id_libro=libro.id 
GROUP BY lettore.id;

-- QUERY 5:
SELECT vendita.data_vendita, libro.titolo, lettore.cognome_nome, libreria.nome 
FROM v_vendita AS vendita, v_libro AS libro, v_lettore AS lettore, v_libreria AS libreria
WHERE lettore.id=vendita.id_lettore AND vendita.id_libro=libro.id AND vendita.id_libreria=libreria.id AND vendita.data_vendita>'2016/01/01';

-- QUERY 6:
SELECT libro.titolo, libro.prezzo, libro.n_pagine 
FROM v_libro AS libro, v_libreria AS libreria, v_vendita AS vendita 
WHERE vendita.id_libro=libro.id AND vendita.id_libreria=libreria.id AND libreria.nome='Il Temperino';

-- QUERY 7:
SELECT libro.titolo, SUM(libro.prezzo) AS 'totale'
FROM v_libro AS libro, v_vendita AS vendita 
WHERE libro.id=vendita.id_libro 
GROUP BY libro.id
HAVING totale>=20 AND totale<=35

-- QUERY 8:
SELECT libro.titolo, autore.cognome, autore.nome 
FROM v_libro AS libro, v_autore AS autore 
WHERE libro.id_autore=autore.id AND 
    libro.prezzo>(SELECT AVG(libro.prezzo) FROM v_libro AS libro);
