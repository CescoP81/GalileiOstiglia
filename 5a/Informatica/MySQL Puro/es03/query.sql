-- vedere tutte le specie di flora, ordinate per tipoflora
SELECT s.specie ,t.tipologia, s.fioritura , s.altreCaratteristiche 
FROM specieFlora As s, tipoflora AS t
WHERE s.idTipoFlora = t.id
ORDER BY t.tipologia ASC

-- visualizzare tutti i parchi, in cui sono presenti arbusti
SELECT p.parco , p.regione
FROM parco AS p, parcoFlora AS pf , specieFlora as s , tipoflora as t
WHERE s.idTipoFlora = t.id 
AND pf.idSpecieFlora = s.id 
AND pf.idParco = p.id
AND t.tipologia = 'arbusti'

-- contare il numero di specie flora associate a piante erbacee
SELECT COUNT(sf.id)
FROM specieFlora AS sf
INNER JOIN tipoFlora AS tf ON sf.idTipoFlora = tf.id
WHERE 
tf.tipologia = 'piante erbacee';

-- numero di parchi che hanno del rosmarino (Marcheselli production @Marcheselli)
SELECT COUNT(p.id) as 'numero parchi'
FROM specieFlora AS s , parcoFlora as pf , parco as p
WHERE s.id = pf.idSpecieFlora AND pf.idParco = p.id
AND s.specie = 'rosmarino'

-- numero di parchi che hanno del rosmarino (versione INNER JOIN)
SELECT COUNT(p.id) AS 'numero parchi'
FROM specieFlora AS s 
-- INNER JOIN [tabella] AS [alias tabella] ON [condizione join]
INNER JOIN parcoFlora AS pf ON s.id = pf.idSpecieFlora
INNER JOIN parco AS p ON pf.idParco = p.id
WHERE
s.specie = 'rosmarino';

select * from specieFlora as s
INNER JOIN parcoFlora AS pf ON s.id = pf.idSpecieFlora