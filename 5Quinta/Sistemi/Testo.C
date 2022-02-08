SELECT c.*, l.Nome, l.Prov, l.Cap 
FROM p62e1_Cliente AS c, p62e1_Localita AS l 
WHERE c.idLocalita=l.Id


SELECT c.*, l.Nome, l.Prov, l.Cap 
FROM p62e1_Cliente AS c
INNER JOIN p62e1_localita AS l
   ON c.idLocalita=l.id