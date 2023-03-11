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

/* Visualizzare tutte le auto con tarda iniziale AC*/
SELECT *
FROM auto
WHERE targa LIKE "AC%";

/* Visualizz<re tutte le auto con targa contentente '12' */
SELECT *
FROM auto
WHERE targa LIKE "%12%";

/* Visualizzare i km percorsi da ogni auto in ordine decrescente */
SELECT a.targa, a.marca, a.modello, SUM(n.kmPercorsi) AS 'totale'
FROM auto AS a, noleggio AS n
WHERE a.id=n.idAuto
GROUP BY a.id
HAVING totale>0
ORDER BY totale DESC

/* Visualizzare le prime tre auto per km percorsi in ordine decrescente */
SELECT a.targa, a.marca, a.modello, SUM(n.kmPercorsi) AS 'totale'
FROM auto AS a, noleggio AS n
WHERE a.id=n.idAuto
GROUP BY a.id
HAVING totale>0
ORDER BY totale DESC
LIMIT 3

/* Visualizzare per ogni auto il numero di noleggi effettuati */
SELECT a.marca, a.modello, a.targa, COUNT(n.idAuto) AS 'Nr. Noleggi' 
FROM auto AS a, noleggio AS n 
WHERE a.id=n.idAuto
GROUP BY a.id

/*Determinare il km massimo e minimo percorsi tra tutti i noleggi*/
SELECT MIN(n.kmPercorsi), MAX(n.kmPercorsi)
FROM noleggio AS n

/* Determinare l'auto "marca, modello,targa" che ha effettuato il numero massimo di km*/
SELECT a.marca, a.modello, a.targa
FROM auto AS a, noleggio AS n
WHERE a.id = n.idAuto
    AND n.kmPercorsi =(SELECT MAX(n.kmPercorsi) FROM noleggio AS n) 

/*Visualizzare le auto che hanno effettuato almeno 2 noleggi*/
SELECT a.marca, a.modello, a.targa, COUNT(n.idAuto) AS 'Viaggi'
FROM auto AS a, noleggio AS n
WHERE a.id = n.idAuto
GROUP BY a.id
HAVING Viaggi>=2

/*Visualizzare il cliente che ha effettuato il noleggio più lungo(in km) e con che auto*/
SELECT c.cognome, c.nome, a.marca, a.modello, a.targa
FROM cliente AS c, auto AS a, noleggio AS n
WHERE a.id = n.idAuto AND c.id = n.idCliente
    AND n.kmPercorsi= (SELECT MAX(n.kmPercorsi) FROM noleggio AS n)

