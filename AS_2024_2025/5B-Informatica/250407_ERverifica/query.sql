-- SELECT -> che cosa selezionare e se da più tabelle usare la formula tab.campo
-- FROM elenco tabelle con eventuale rename con 'AS'
-- WHERE filtri, se la query interessa più tabelle avrete tab1.pk = tab2.fk

-- SE nella select avete funzioni come SUM, AVG, MIN, MAX, COUNT e nella where avete più tabelle.
-- dopo WHERE usare GROUP BY
-- se dovete usare un filtro per esempio su SUM non usate la WHERE ma HAVING
-- ESEMPIO
SELECT cliente.nome, cliente.cognome, SUM(f.importo) AS totale
FROM cliente AS c, fattura AS f
WHERE c.id=f.idCliente
GROUP BY c.id;
-- se voglio importi superiori a un certo tot, aggiungo clausola HAVING basata sul campo calcolato con la SUM
-- HAVING totale > 10000;

-- Voglio visualizzare i primi 5 clienti con spesa massima.
SELECT cliente.nome, cliente.cognome, SUM(f.importo) AS totale
FROM cliente AS c, fattura AS f
WHERE c.id=f.idCliente
GROUP BY c.id
ORDER BY totale DESC
LIMIT 5;

-- Ipotizziamo di inserire il cliente Rossi Maria
INSERT INTO cliente(cognome, nome, indirizzo, citta, idProvincia, idConsulente)
VALUE('Rossi','Maria','Via Cantone 18','Ostiglia', 1, 2);
-- Ipotizziamo che invece di Rossi MARIA fosse Rossi Mario
UPDATE TABLE cliente
SET nome='Mario'
WHERE id=[id del record da modificare];