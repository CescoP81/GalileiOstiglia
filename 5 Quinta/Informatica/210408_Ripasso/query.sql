-- Visualizzare tutte le temperature con relativa stazione meteo.
SELECT mt.valore, ms.nome, ms.posizione
FROM meteo_temperature AS mt, meteo_stazioni AS ms
WHERE ms.id = mt.id_stazione

-- Visualizzare la media di tutte le temperature registrate.
SELECT AVG(mt.valore) AS 'Temperatura Media'
FROM meteo_temperature AS mt

-- Visualizzare tutte le temperature con relativa stazione meteo, che sono superiori o uguali alla media.
SELECT mt.valore, ms.nome, ms.posizione
FROM meteo_temperature AS mt, meteo_stazioni AS ms
WHERE ms.id = mt.id_stazione AND mt.valore >= (SELECT AVG(mt.valore) FROM meteo_temperature AS mt)

-- Visualizzare i dati della temperatura massima registrata.
SELECT mt.valore, ms.nome, ms.posizione
FROM meteo_temperature AS mt, meteo_stazioni AS ms
WHERE ms.id = mt.id_stazione AND mt.valore = (SELECT MAX(mt.valore) FROM meteo_temperature AS mt)

-- Visualizzare i dati della temperatura minima registrata.
SELECT mt.valore, ms.nome, ms.posizione
FROM meteo_temperature AS mt, meteo_stazioni AS ms
WHERE ms.id = mt.id_stazione AND mt.valore = (SELECT MIN(mt.valore) FROM meteo_temperature AS mt)