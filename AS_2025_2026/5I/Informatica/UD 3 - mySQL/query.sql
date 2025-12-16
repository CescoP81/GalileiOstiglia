-- file contente le query, cioè interrogazioni che estraggono dati da/lle tabella/lle
-- cancellano dati in una tabella, modificano dati in una tabella, modificano la struttura di una tabella.

SELECT * FROM nome_tabella;

SELECT * FROM nome_tabella
WHERE campo1=valore

SELECT * FROM nome_tabella
WHERE campo1=valore AND[OR] campo2=valore2

DELETE FROM nome_tabella
WHERE id=valore [al posto di ID indicare il campo primary key se diverso]

UPDATE nome_tabella
SET nome_campo = nuovo_valore
WHERE id=valore [al posto di ID indicare il campo primary key se diverso]