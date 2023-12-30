-- Q1 Visualizzare tutti i cani presenti.
SELECT id, nome, razza
FROM cane;

-- Q2 Visualizzare tutti i cani associati al volontario “Rossi Marco”.
SELECT c.id, c.nome, c.razza
FROM cane AS c, volontario AS v
WHERE c.idVolontario=v.id AND v.cognome="Rossi" AND v.nome="Marco";

-- Q3 Visualizzare tutte le attività eseguite.
SELECT a.id, a.descrizione, a.data, a.esito
FROM attivita AS a;

SELECT a.id, a.descrizione, a.data, a.esito, c.nome, c.razza
FROM attivita AS a, cane AS c
WHERE a.idCane = c.id;

-- Q4 Visualizzare tutti i cani e le attività dove il cane è di razza “Maremmano”
SELECT c.id, c.nome, a.descrizione, a.data, a.esito
FROM cane AS c, attivita AS a
WHERE a.idCane=c.id AND c.razza="Maremmano";

-- Q5 Visualizzare tutte le attività prestate dal volontario “Bianchi Filippo”
SELECT a.id, a.descrizione, a.data, a.esito, c.nome, c.razza
FROM attivita AS a, cane AS c, volontario AS v
WHERE v.id=c.idVolontario AND c.id=a.idCane AND v.cognome="Bianchi" AND v.nome="Filippo";

-- Q6 Visualizzare tutte le attività, specificando anche il cane, con esito positivo.
SELECT a.id, a.descrizione, a.data, a.esito, c.nome, c.razza
FROM attivita AS a, cane AS c
WHERE a.idCane=c.id AND a.esito=1;

-- Q7 Visualizzare tutti i volontari con cane di razza “Bassotto”
SELECT v.id, v.cognome, v.nome
FROM volontario AS v, cane AS c 
WHERE v.id=c.idVolontario AND c.razza="Bassotto";

-- Q8 Visualizzare tutte le attività compreso volontario e cane, svolte in data “2021/01/19”
SELECT a.id, a.descrizione, a.data, a.esito, v.cognome, v.nome, c.nome, c.cognome
FROM attivita AS a, cane AS c, volontario AS v 
WHERE c.idVolontario=v.id AND a.idCane=c.id AND a.data="2021/01/19";