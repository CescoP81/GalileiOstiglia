-- Query 1: Selezionare tutti gli animali del volontario "Rossi Mario" 
SELECT a.nome
FROM animale AS a, volontario AS v 
WHERE a.idvolontario = v.id AND v.nome = 'Marco' AND v.cognome = 'Rossi';

SELECT a.nome, z.denominazione AS 'Zona', r.denominazione AS 'Razza'
FROM animale AS a, volontario AS v, Zona AS z, razza AS r
WHERE v.id = a.idvolontario AND v.nome = 'Marco' AND v.cognome = 'Rossi'
    AND a.idrazza = r.id
    AND a.idzona = z.id;

-- Query 2: Selezionare tutti gli animali della zona “Steppa e Savana” ordinandoli per nome.
SELECT a.nome, r.denominazione
FROM animale AS a, zona AS z, razza AS r
WHERE a.idzona = z.id AND z.denominazione = 'Steppa e Savana' 
    AND a.idRazza = r.id
ORDER BY a.nome;

-- Q3: Selezionare tutti i volontari che operano nella zona “Zona Asiatica” ordinandoli per cognome.
SELECT v.cognome, v.nome, v.statoServizio
FROM volontario AS v, animale AS a, zona AS z 
WHERE v.id = a.idVolontario AND a.idZona = z.id
    AND z.denominazione = 'Zona Asiatica'
ORDER BY v.cognome ASC; --DESC sarebbe dalla z-a

-- Q4: Selezionare tutte le zone e per ogni zona il numeri di animali presenti.
SELECT z.denominazione, COUNT(a.id) AS 'Animali presenti'
FROM zona AS z, animale AS a 
WHERE z.id = a.idZona
GROUP BY z.id;

-- Q5: Selezionare tutte le visite effettuate dal volontario “Verdi Bruno” includendo animale, data, referto,
--     costo.
SELECT a.nome, r.denominazione AS 'Razza', z.denominazione AS 'Zona', vi.dataVisita, vi.referto, vi.costo 
FROM animale AS a, zona AS z, visita AS vi, volontario AS vo, razza AS r
WHERE r.id = a.idRazza AND z.id = a.idZona AND a.id = vi.idAnimale
    AND a.idVolontario = vo.id AND vo.cognome = 'Verdi' AND vo.nome = 'Bruno';

-- Q6: Selezionare la spesa complessiva di ogni singolo volontario nell’anno 2023.
SELECT vo.cognome, vo.nome, SUM(vi.costo) AS 'Totale'
FROM volontario AS vo, animale AS a, visita AS vi 
WHERE vo.id = a.idVolontario AND a.id = vi.idAnimale
    AND vi.dataVisita>='2023-01-01' AND vi.dataVisita<='2023-12-31';
GROUP BY vo.id;

-- Q7: Selezionare per ogni animale il numero di visite effettuate e il costo totale.
SELECT a.nome, COUNT(vi.id) AS 'Numero visite', SUM(vi.costo) AS 'Costo totale'
FROM animale AS a, visita AS vi 
WHERE a.id = vi.idAnimale 
GROUP BY a.id;

-- Q8: Selezionare tutti gli animali che hanno un totale di spesa effettuata maggiore a 100€.
SELECT a.nome, r.denominazione AS 'Razza', SUM(vi.costo) AS 'Totale'
FROM animale AS a, razza AS r, visita AS vi 
WHERE a.id=v.idAnimale AND a.idRazza=r.id 
GROUP BY a.id 
HAVING totale>100;

-- QUERY SIMIL VERIFICA --

-- Q9: Visualizzare il costo medio delle visite presenti
SELECT AVG(costo)
FROM visita;

-- Q10: Selezionare tutte le visite indicando a che animale sono associate, che abbiano un costo
--     maggiore del costo medio delle visite presenti.
SELECT a.nome, vi.costo 
FROM animale AS a, visita AS vi 
WHERE a.id=vi.idAnimale 
    AND vi.costo > (SELECT AVG(visita.costo) FROM visita);