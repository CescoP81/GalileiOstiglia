-- Q1: visualizzare tutti i clienti presenti a sistema.
SELECT * 
FROM p8_cliente;

-- Q2: visualizzare tutti i clienti della provincia di Mantova.
SELECT * 
FROM p8_cliente
where prov_residenza='MN';

-- Q3: visualizza tutte le spedizioni del cliente Pradella Francesco
SELECT c.nominativo, s.*
FROM p8_spedizione AS s, p8_cliente AS c
WHERE s.id_cliente=c.id AND c.nominativo='Bottoni Alberto';

-- Q4: visualizzare il numero di spedizioni non concluse per il cliente 'Tosano Market'
SELECT s.*
FROM p8_spedizione AS s, p8_cliente AS c 
WHERE s.id_cliente=c.id AND c.nominativo='Tosano Market' AND s.id_corriere is null;

-- Q5: visualizzare tutti i clienti serviti dal corriere 'SDA'
SELECT COUNT(cl.id) AS 'Totale Clienti Serviti'
FROM p8_corriere AS co, p8_spedizione AS sp, p8_cliente as cl
WHERE sp.id_corriere=co.id AND sp.id_cliente=cl.id AND co.denominazione='SDA'

-- Q6: Visualizzare tutte le spedizioni per ogni corriere.
SELECT co.denominazione, COUNT(cl.id) AS 'Totale Spedizioni'
FROM p8_corriere AS co, p8_spedizione AS sp, p8_cliente as cl
WHERE sp.id_corriere=co.id AND sp.id_cliente=cl.id
GROUP BY co.denominazione
