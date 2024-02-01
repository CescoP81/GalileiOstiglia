-- visualizzare tutti i reparti presenti nella città di Mantova
SELECT rep.nomeReparto
FROM Reparto AS rep, Citta AS c
WHERE c.nomeCitta = 'Mantova' AND c.id = rep.idCittaReparto

-- visualizzare tutti i reparti presenti nelle città di Mantova e Vicenza
SELECT rep.nomeReparto
FROM Reparto AS rep, Citta AS c
WHERE c.id = rep.idCittaReparto AND (c.nomeCitta = 'Mantova' OR c.nomeCitta = 'Vicenza')

-- visualizzare tutti i dipendenti che lavorano nella città di Mantova
SELECT d.nome, d.Cognome
FROM Citta AS c, Dipendente AS d, Reparto AS rep
WHERE d.idReparto = rep.id AND rep.idCittaReparto = c.id AND c.nomeCitta = 'Vicenza';

-- Query del 01/02/2024 esempi con funzioni di aggregazione.
