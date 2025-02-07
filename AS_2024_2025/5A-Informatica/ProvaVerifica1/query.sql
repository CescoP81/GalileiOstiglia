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