SELECT p.cognome, p.nome, i.nome AS 'Immobile', i.metratura, ra.prezzo_mq, (i.metratura*ra.prezzo_mq) AS 'Totale Valore'
FROM p73e6_proprietario AS p, 
   p73e6_possiede AS po, 
   p73e6_immobile AS i, 
   p73e6_rendita_annua AS ra 
WHERE p.id = po.idProprietario 
   AND po.idImmobile = i.id 
   AND i.idZona = ra.idZona
   AND i.idTipologia = ra.idTipologia