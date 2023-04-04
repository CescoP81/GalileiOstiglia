-- 1) Visualizzare tutti i mezzi con relativa marca_automezzo
SELECT m.descrizione,m.targa,ma.descrizione 
FROM mezzo AS m, marca_automezzo AS ma
WHERE m.idMarca=ma.id;

-- 2) Visualizzare per ogni trasporto il mezzo utilizzato e la città di partenza
SELECT c.nome AS 'Partenza', m.descrizione AS 'Mezzo', t.descrizioneMerce,t.data, t.quintali
FROM trasporto AS t, mezzo AS m, citta AS c
WHERE t.idCittaMittente=c.id AND t.idMezzo=m.id;

-- 2 bis)
SELECT c.nome AS 'Partenza', c1.nome AS 'Destinazione',m.descrizione AS 'Mezzo', t.descrizioneMerce,t.data, t.quintali
FROM trasporto AS t, mezzo AS m, citta AS c, citta AS c1
WHERE t.idCittaMittente=c.id AND t.idMezzo=m.id AND t.idCittaDestinatario=c1.id;

-- 3) Visualizzare tutti i trasporti effettuati con mezzi FIAT ordinandoli per quantità
SELECT t.descrizioneMerce, t.data,t.quintali,m.targa, m.descrizione
FROM  trasporto AS t, mezzo AS m, marca_automezzo AS ma
WHERE t.idMezzo=m.id AND m.idMarca=ma.id AND ma.descrizione = 'FIAT';

--4) Visualizzare tuttu i trasporti con relativo mezzo effettuati nei primi tre mesi del 2023
SELECT t.descrizioneMerce , t.data ,t.quintali , m.descrizione ,m.targa
FROM trasporto AS t, mezzo AS m
WHERE m.id=t.idMezzo AND t.data >= '2023/01/01' AND t.data <= '2023/03/31';

--5) Visualizzare il trasporto e il mezzo che ha il valore massimo di quantità.
SELECT t.descrizioneMerce, t.quintali, t.data, m.descrizione, m.targa, ma.descrizione
FROM trasporto AS t, mezzo AS m, marca_automezzo AS ma
WHERE t.idMezzo=m.id AND m.idMarca=ma.id AND t.quintali=(
    SELECT max(quintali) FROM trasporto);

--6) Visualizzare il numero di trasporti effettuato da ogni mezzo.
SELECT count(t.id), m.descrizione, m.targa
FROM trasporto AS t, mezzo AS m
WHERE m.id=t.idMezzo
GROUP BY m.id

--7) Visualizzare il totale dei quantali trasportati in ogni città nel mese di Marzo.
SELECT SUM(t.quintali) AS 'totale', c.nome
FROM trasporto as t, citta as c
WHERE c.id=t.idCittaDestinatario AND t.data>='2023-01-01' AND t.data<='2023-12-31' 
GROUP BY c.id
HAVING totale>=3 AND totale<=4
ORDER BY totale ASC;
-- WHERE c.id=t.idCittaDestinatario AND t.data BETWEEN '2023-03-01' AND '2023-03-31'

--8) Visualizzare tutti i trasporti (quintali, data, mezzo) che hanno provincia_mittente e provincia_destinatario diverse.

--9) Visualizzare tutti i percorsi di 5 tappe.

--9-bis) Visualizzare il percorso più lungo. 