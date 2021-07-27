/*
STRUTTUTA DI UNA QUERY
SELECT tutto/campo/campi/tabella.campo
FROM tabella/tabelle
[WHERE filtri]
*/

--Q1: Visualizzare tutti i campi della tabella meteo_stazioni
SELECT *
FROM meteo_stazioni;

SELECT id, posizione, anno_attivazione, nome
FROM meteo_stazioni;

--Q2: Visualizzare il nome e la posizione delle stazioni meteo attivate nel 2002
SELECT nome, posizione
FROM meteo_stazioni
WHERE anno_attivazione='2002';

-- Q3: Visualizzare il nome e la posizione delle stazioni meteo attivate nel 2002 o nel 2012
SELECT nome, posizione
FROM meteo_stazioni
WHERE anno_attivazione='2002' OR anno_attivazione='2012';

-- Q3: Visualizzare valore e id_stazione di ogni temperatura rilevata.
SELECT valore, id_stazione
FROM meteo_temperature;

-- Q4: visualizzare valore, nome stazione e posizione stazione per ogni temperatura rilevata.
SELECT meteo_temperature.valore, meteo_stazioni.nome, meteo_stazioni.posizione
FROM meteo_temperature, meteo_stazioni;
WHERE meteo_stazioni.id=meteo_temperature.id_stazione;

SELECT meteo_temperature.valore, meteo_temperature.id_stazione, meteo_stazioni.id, meteo_stazioni.nome
FROM meteo_temperature, meteo_stazioni
WHERE meteo_stazioni.id=meteo_temperature.id_stazione;

-- Q5: Visualizzare valore e nome stazione di tutte le temperature registrate da centraline del 2008.
SELECT meteo_temperature.valore, meteo_stazioni.nome, meteo_stazioni.anno_attivazione
FROM meteo_temperature, meteo_stazioni
WHERE meteo_stazioni.id=meteo_temperature.id_stazione AND meteo_stazioni.anno_attivazione='2008';

-- Q6: visualizzare valore, nome stazione e posizione stazione di tutte le temperature superiori a 10.5 gradi.
SELECT meteo_temperature.valore, meteo_stazioni.nome, meteo_stazioni.posizione
FROM meteo_temperature, meteo_stazioni
WHERE meteo_stazioni.id=meteo_temperature.id_stazione AND meteo_temperature.valore>10.5;

-- Q7: visualizzare valore massimo e valore minimo misurato dalla stazione 'Meteo1'
-- USARE: MIN MAX o AVG per la media.
SELECT MIN(meteo_temperature.valore), MAX(meteo_temperature.valore), AVG(meteo_temperature.valore)
FROM meteo_stazioni, meteo_temperature
WHERE meteo_stazioni.id=meteo_temperature.id_stazione AND meteo_stazioni.nome='Meteo1';

-- Q8: visualizzare valore minimo, massimo e medio delle temperature.
SELECT MIN(valore), MAX(valore), AVG(valore)
FROM meteo_temperature;