-- Visualizzare tutti gli studenti in ordine di cognome.
SELECT *
FROM af_studente
ORDER BY cognome ASC;

-- Visualizza tutti gli studenti con nome Elisa
SELECT *
FROM af_studente
WHERE nome='Elisa' OR nome='elisa'
ORDER BY cognome ASC

-- VIsualizzare tutti gli studenti con lettera iniziale 'A'
SELECT *
FROM af_studente
WHERE nome LIKE 'A%'
ORDER BY cognome ASC

-- Visualizzare tutti gli studenti non ancora verificati.
SELECT *
FROM af_studente
where verificaStato = 0
ORDER BY cognome ASC

-- Visualizzare tutte le attività del turno 1 dell'evento attivo
SELECT a.*
FROM af_attivita AS a, af_evento AS e
WHERE e.id=a.idEvento AND a.turnoGiornata=1 AND e.isArchiviato=0

-- come precedente ma con INNER
SELECT a.*
FROM af_attivita AS a
INNER JOIN af_evento AS e
ON a.idEvento = e.id AND a.turnoGiornata=1

-- ERRORE DI SINTASSI OMETTENDO LA PAROLA JOIN
SELECT a.*
FROM af_attivita AS a
INNER af_evento AS e
ON a.idEvento = e.id AND a.turnoGiornata=1;
-- RESTITUISCE ERRORE.