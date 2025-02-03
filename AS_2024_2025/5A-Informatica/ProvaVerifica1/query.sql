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