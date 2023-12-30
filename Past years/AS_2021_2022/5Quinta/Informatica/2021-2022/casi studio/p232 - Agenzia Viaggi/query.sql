/* VEDERE TUTTI I CLIENTI IN ORDINE PER COGNOME */
SELECT * FROM p232_cliente
ORDER BY cognome ASC

/* VEDERE PER OGNI PACCHETTO NAZIONE E ORGANIZZAZIONE */
SELECT p.descrizione, p.modalita, p.prezzo, o.nome, n.denominazione
FROM p232_pacchetto AS p, p232_organizzazione AS o, p232_nazione AS n
p.codNazione = n.cod AND p.codOrganizzazione = o.cod

/* VEDERE TUTTI I PACCHETTI ACQUISTATI DA OGNI CLIENTE*/
SELECT c.cod, c.cognome, c.nome, p.descrizione, p.prezzo, a.dataAcquisto
FROM p232_cliente AS c, p232_pacchetto AS p, p232_acquisto AS a
WHERE p.cod = a.codPacchetto AND a.codCliente = c.cod
ORDER BY c.cod ASC;

/* VEDERE LA SPESA TOTALE PER OGNI CLIENTE */
SELECT c.cod, c.cognome, c.nome, SUM(p.prezzo) AS totale 
FROM p232_cliente AS c, p232_pacchetto AS p, p232_acquisto AS a
WHERE p.cod = a.codPacchetto AND a.codCliente = c.cod
GROUP BY c.cod

/* VEDERE LA SPESA TOTALE PER OGNI CLIENTE se SPESA TOTALE > 700 */
SELECT c.cod, c.cognome, c.nome, SUM(p.prezzo) AS totale 
FROM p232_cliente AS c, p232_pacchetto AS p, p232_acquisto AS a
WHERE p.cod = a.codPacchetto AND a.codCliente = c.cod
GROUP BY c.cod
HAVING totale>700;

/* VEDERE I PRIMI 3 CLIENTI ORDINATI PER SPESA TOTALE IN MODO DISCENDENTE */
SELECT c.cod, c.cognome, c.nome, SUM(p.prezzo) AS totale 
FROM p232_cliente AS c, p232_pacchetto AS p, p232_acquisto AS a
WHERE p.cod = a.codPacchetto AND a.codCliente = c.cod
GROUP BY c.cod
ORDER BY totale DESC
LIMIT 3

/* VEDERE TUTTI I PACCHETTI CON PREZZO COMRPESO TRA 300 E 700*/
SELECT p.descrizione, p.prezzo
FROM p232_pacchetto AS p 
   WHERE (p.prezzo BETWEEN 300 AND 700)
   /* WHERE p.prezzo >=300 AND p.prezzo<=700

/* VEDERE TUTTI I PACCHETTI CHE HANNO PREZZO SUPERIORE ALLA MEDIA GENERALE */
SELECT p.descrizione, p.prezzo
FROM p232_pacchetto AS p 
WHERE prezzo >= (
   SELECT AVG(p.prezzo)
   FROM p232_pacchetto AS p 
   )
/* errato usare solo WHERE con AVG 
WHERE prezzo >= AVG(p.prezzo);*/

