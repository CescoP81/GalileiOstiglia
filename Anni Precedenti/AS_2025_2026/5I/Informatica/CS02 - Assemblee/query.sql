-- 1 Visualizzare tutti gli studenti in ordine di cognome.
SELECT *
FROM af_studente
ORDER BY cognome ASC;

-- 2 Visualizza tutti gli studenti con nome Elisa
SELECT *
FROM af_studente
WHERE nome='Elisa' OR nome='elisa'
ORDER BY cognome ASC

-- 3 VIsualizzare tutti gli studenti con lettera iniziale 'A'
SELECT *
FROM af_studente
WHERE nome LIKE 'A%'
ORDER BY cognome ASC

-- 4 Visualizzare tutti gli studenti non ancora verificati.
SELECT *
FROM af_studente
where verificaStato = 0
ORDER BY cognome ASC

-- 5 Visualizzare tutte le attività del turno 1 dell'evento attivo
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

-- 6 visualizzare per ogni studente il numero di attività a cui è iscritto.
SELECT s.nome, s.cognome, COUNT(i.id) AS iscrizioni
FROM af_studente AS s, af_iscrizione AS i
WHERE s.id=i.idStudente
GROUP BY s.id

-- 7 Visualizzare per ogni attività il numero di iscrizioni ricevute
SELECT a.titolo, a.turnoGiornata, a.orarioInizio, a.orarioFine, COUNT(i.id) AS iscrizioni
FROM af_attivita AS a, af_iscrizione AS i
WHERE a.id=i.idAttivita 
GROUP BY a.id

-- 8 Visualizzare tutti gli studenti iscritti all'evento con id=1
SELECT DISTINCT s.cognome, s.nome, s.classe 
FROM af_studente AS s, af_iscrizione AS i, af_attivita AS a, af_evento AS e
WHERE s.id = i.idStudente AND
    i.idAttivita = a.id AND
    a.idEvento = e.id AND
    e.id = 1
ORDER BY s.cognome 

-- 9 Visualizzare le 5 attività con relativo numero di iscrizioni, più gettonate.
SELECT a.titolo, a.turnoGiornata, COUNT(i.id) as 'iscrizioni' 
FROM af_attivita AS a, af_iscrizione AS i 
WHERE a.id=i.idAttivita
GROUP BY a.id
ORDER BY iscrizioni DESC
LIMIT 10;

-- 10 Visualizzare le 5 attività con relativo numero di iscrizioni, che nessuno si c@@a.
SELECT a.titolo, a.turnoGiornata, COUNT(i.id) as 'iscrizioni' 
FROM af_attivita AS a, af_iscrizione AS i 
WHERE a.id=i.idAttivita
GROUP BY a.id
ORDER BY iscrizioni ASC
LIMIT 5;

-- 11 Visualizzare a quali attività si sono iscritti gli studenti di una determinata classe.
SELECT s.cognome, s.nome, s.classe, a.titolo, a.turnoGiornata
FROM af_attivita AS a, af_iscrizione AS i, af_studente AS s 
WHERE a.id = i.idAttivita AND s.id = i.idStudente AND (s.classe='5L' OR s.classe='4U')

-- 12 Contare e visualizzare il totale iscrizioni raggruppate per attività del solo turno 1.

-- 13 Determinare e visualizzare tutte le attività (titolo e turno) che hanno raggiunto almeno 15 iscritti.

-- 14 Determinare il numero medio di iscrizioni tra tutte le attivita.

-- 15 Determinare e visualizzare tutti gli studenti REGISTRATI ma non ISCRITTI
-- aggiungendo le colonne della tab di destra, si nota come vengano lasciate
-- a NULL dove non trova corrispondenza.
SELECT DISTINCT s.nome, s.cognome, s.classe, i.idAttivita, i.dataIscrizione
FROM af_studente AS s
LEFT JOIN af_iscrizione AS i
ON s.id=i.idStudente
