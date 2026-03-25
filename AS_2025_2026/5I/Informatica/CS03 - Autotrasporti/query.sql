SELECT c.cognome,
        c.nome s.descrizione,
        pp.nome,
        pa.nome 
FROM cliente as c,
        spedizione as s,
        provincia as pp,
        provincia as pa
WHERE c.id=s.idCliente 
        AND s.idProvinciaPartenza = pp.id
        AND s.idProvincaArrivo = pa.id