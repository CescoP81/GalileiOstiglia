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
------------------------------------------------------------
-- Visualizzare il numero di pagamenti totali effettuati.
SELECT COUNT(id)
FROM Pagamento;

-- Visualizzare il numero di pagamenti superiori o uguali a 1200
SELECT COUNT(id)
FROM Pagamento
WHERE importo>=1200;

-- Visualizzare l'importo minimo erogato.
SELECT MIN(importo)
FROM Pagamento;

-- Visualizzare l'importo massimo erogato.
SELECT MAX(importo)
FROM Pagamento;

-- Visualizzare la media degli importi erogati
SELECT AVG(importo)
FROM Pagamento;

-- Visualizzare la media degli importi del mese di gennaio
SELECT AVG(importo)
FROM Pagamento
WHERE data>='2024/01/01' AND data<='2024/01/31';

--Visualizzare per ogni dipendente il proprio pagamento
SELECT d.cognome, d.nome, p.data, p.importo
FROM Dipendente AS d, Pagamento AS p
WHERE d.id = p.idDipendente
ORDER by p.data DESC;

--Visualizzare il dipendente(cognome, nome)che ha percepito il pagamento minimo
SELECT d.cognome, d.nome, p.importo
FROM Dipendente AS d, Pagamento AS p
WHERE d.id = p.idDipendente
AND p.importo = (SELECT MIN(importo) FROM Pagamento); 

--Visualizzare i dipendenti(cognome, nome)che hanno percepito pagamenti superiori alla media generale
SELECT d.cognome, d.nome, p.importo
FROM Dipendente AS d, Pagamento AS p
WHERE d.id = p.idDipendente
AND p.importo > (SELECT AVG(importo) FROM Pagamento);

-- Visualizzare il totale degli importi erogati
SELECT SUM(importo)
FROM Pagamento;

-- Visualizzare il totale degli importi del dipendente 'Rossi Mario'
SELECT SUM(importo)
FROM Dipendente AS d, Pagamento AS p
WHERE d.id = p.idDipendente AND d.cognome = 'Rossi' AND d.nome = 'Mario';
-- WHERE d.id = p.idDipendente AND d.id=4;

-- Visualizzare il totale percepito da ogni singolo dipendente [UTILIZZO DEL RAGGRUPPAMENTO].
SELECT d.cognome, d.nome, SUM(importo) AS 'Totale Percepito'
FROM Dipendente AS d, Pagamento AS p 
WHERE d.id = p.idDipendente 
GROUP BY d.id;

-- Visualizzare il totale percepito da ogni singolo dipendente
-- nel solo mese di gennaio 2024 [UTILIZZO DEL RAGGRUPPAMENTO].
SELECT d.cognome, d.nome, SUM(importo) AS 'Totale Percepito'
FROM Dipendente AS d, Pagamento AS p 
WHERE d.id = p.idDipendente AND p.data>='2024/01/01' AND p.data<='2024/01/31'
GROUP BY d.id
HAVING SUM(importo) > 1200;

-- Visualizzare Cognome e Nome di ogni dipendente, la città di residenza
-- il reparto di impiego e la relativa città del reparto.
SELECT d.Cognome, d.Nome, c.NomeCitta, r.NomeReparto, c.NomeCitta 
FROM dipendente AS d, Citta AS c, Reparto as r 
WHERE d.idCittaResidenza=c.id AND d.idReparto=r.id AND r.idCittaReparto=c.id

-- quella sopra è ERRATA, bisogna rinominare due volte la tabella citta, come sotto:

SELECT d.Cognome, d.Nome, c.NomeCitta AS 'residenza',
         r.NomeReparto, c1.NomeCitta AS 'Citta Reparto' 
FROM dipendente AS d,
     Citta AS c, 
     Citta AS c1, 
     Reparto AS r 
WHERE d.idCittaResidenza=c.id AND d.idReparto=r.id AND r.idCittaReparto=c1.id
