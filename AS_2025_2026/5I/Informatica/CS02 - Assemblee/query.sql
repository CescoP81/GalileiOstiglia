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
-- SELECT a.*
-- FROM af_attivita AS a
-- INNER af_evento AS e
-- ON a.idEvento = e.id AND a.turnoGiornata=1;
-- RESTITUISCE ERRORE.

-- visualizzare per ogni studente il numero di attività a cui è iscritto.
SELECT s.nome, s.cognome, COUNT(i.id) AS iscrizioni
FROM af_studente AS s, af_iscrizione AS i
WHERE s.id=i.idStudente
GROUP BY s.id

-- Visualizzare per ogni attività il numero di iscrizioni ricevute
SELECT a.titolo, a.turnoGiornata, a.orarioInizio, a.orarioFine, COUNT(i.id) AS iscrizioni
FROM af_attivita AS a, af_iscrizione AS i
WHERE a.id=i.idAttivita 
GROUP BY a.id

-- Visualizzare tutti gli studenti iscritti all'evento con id=1
SELECT DISTINCT s.cognome, s.nome, s.classe 
FROM af_studente AS s, af_iscrizione AS i, af_attivita AS a, af_evento AS e
WHERE s.id = i.idStudente AND
    i.idAttivita = a.id AND
    a.idEvento = e.id AND
    e.id = 1
ORDER BY s.cognome