-- AGGIORNAMENTO DI UN RECORD DI UNA DETERMINATA TABELLA.
-- UPDATE Tabella
-- SET field1="", field2="", ...
-- WHERE id=..;
-- https://www.w3schools.com/mysql/mysql_update.asp

UPDATE citta
SET nomeCitta="Trento"
WHERE id=4;

-- ELIMINAZIONE DI UN RECORD SENZA FK.
-- https://www.w3schools.com/mysql/mysql_delete.asp
DELETE FROM citta
WHERE id=8;

-- USO del costrutto INNER JOIN
-- https://www.w3schools.com/mysql/mysql_join_inner.asp