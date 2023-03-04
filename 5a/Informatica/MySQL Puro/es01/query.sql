/* lista delle query eseguite sul database */

/* Visualizzare tutte le auto presenti */
SELECT *
FROM auto;

/* Visualizza marca e modello di tutte le auto */
SELECT marca, modello
FROM auto;

/* Vesualizza marca e modello di tutte le auto, ordinandole per marca. */
SELECT marca, modello
FROM auto
ORDER BY marca ASC

/* Vesualizza marca e modello di tutte le auto, ordinandole per marca, modello */
SELECT marca, modello
FROM auto
ORDER BY marca, modello ASC

/* 1. Visualizzare tutte le auto ordinate per numero di targa */
SELECT *
FROM auto
ORDER BY targa ASC

/* 3. Visualizzare tutti i noleggi effettuati nel mese di febbraio 2023 */
SELECT *
FROM noleggio
WHERE dataNoleggio>="2023/02/01" AND dataNoleggio<="2023/02/28"

/* 3bis */
SELECT n.dataNoleggio, n.dataResa, n.dataResaEffettiva, n.kmPercorsi,
         c.cognome, c.nome, 
         a.marca, a.modello
FROM noleggio AS n, 
    auto AS a, 
    cliente AS c
WHERE a.id=n.idAuto 
    AND n.idCliente=c.id 
    AND n.dataNoleggio>="2023/02/01" AND n.dataNoleggio<="2023/02/28";

/* 3Tris: come primma ma ordinando per kilometraggio */
SELECT n.dataNoleggio, n.dataResa, n.dataResaEffettiva, n.kmPercorsi,
         c.cognome, c.nome, 
         a.marca, a.modello
FROM noleggio AS n, 
    auto AS a, 
    cliente AS c
WHERE a.id=n.idAuto 
    AND n.idCliente=c.id 
    AND n.dataNoleggio>="2023/02/01" AND n.dataNoleggio<="2023/02/28"
ORDER BY n.kmPercorsi ASC;

/* 4. */
SELECT n.dataNoleggio, n.dataResa, n.dataResaEffettiva, n.kmPercorsi,
         c.cognome, c.nome, 
         a.marca, a.modello
FROM noleggio AS n, 
    auto AS a, 
    cliente AS c
WHERE a.id=n.idAuto 
    AND n.idCliente=c.id
    AND c.cognome="Rossi" AND c.nome="Giuseppe";

/* 5. */
SELECT n.dataNoleggio, n.dataResa, n.dataResaEffettiva, n.kmPercorsi,
         c.cognome, c.nome, 
         a.marca, a.modello
FROM noleggio AS n, 
    auto AS a, 
    cliente AS c
WHERE a.id=n.idAuto 
    AND n.idCliente=c.id
    AND a.targa="AB034LJ";

/* Visualizzare per ogni auto i kmPercorsi totali */
SELECT SUM(n.kmPercorsi) AS 'Totale', a.marca, a.modello
FROM noleggio AS n, auto AS a
WHERE n.idAuto=a.id 
GROUP BY a.id
    HAVING totale>0;

/* Visualizza i kmPercorsi mediamente nei noleggi*/
SELECT AVG(kmPercorsi)
FROM noleggio;

/* Visualizzare tutti i noleggi che hanno kmPercorsi superiori alla media */
SELECT n.dataNoleggio, n.kmPercorsi,
        a.marca, a.modello,
        c.nome, c.cognome
FROM noleggio AS n,
        auto AS a,
        cliente AS c
WHERE c.id=n.idCliente AND n.idAuto=a.id
    AND n.kmPercorsi >= (SELECT AVG(kmPercorsi) FROM noleggio);
