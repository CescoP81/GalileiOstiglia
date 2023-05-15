-- seleziona tutte le località in ordine alfabetico per nome.
SELECT *
FROM p62e1_Localita
ORDER BY Nome ASC;

-- Seleziona tutte le località con CAP uguale a 46020
SELECT *
FROM p62e1_Localita
WHERE Cap='46020'
ORDER BY Nome ASC;

-- Seleziona tutti i clienti mostrando il paese di residenza.
SELECT p62e1_Cliente.*, p62e1_Localita.Nome
FROM p62e1_Cliente, p62e1_Localita
WHERE p62e1_Cliente.idLocalita=p62e1_Localita.Id;

-- Selezionare tutti i clienti con fido >=1500
