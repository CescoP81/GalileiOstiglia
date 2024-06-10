-- Q1 Visualizzare tutte le marche di auto presenti a DB.
SELECT * FROM MarcaAutomobile;

-- Q2 Visualizzare tutte le auto presenti a DB
SELECT * FROM ModelloAutomobile;

-- Q2.1 Visualizzare come Q2 ma con la marca in chiaro
SELECT ModelloAutomobile.nome, 
        ModelloAutomobile.annoProduzione, 
        ModelloAutomobile.cilindrata, 
        MarcaAutomobile.nome
FROM ModelloAutomobile, MarcaAutomobile
WHERE ModelloAutomobile.idMarcaAutomobile = MarcaAutomobile.id;

-- Q2.2 Come Q2 ma con abbreviazioni (rename tabelle)
SELECT ModAut.nome, ModAut.annoProduzione AS 'Anno Produzione', ModAut.cilindrata, MarcAut.nome
FROM ModelloAutomobile AS ModAut, MarcaAutomobile AS MarcAut
WHERE ModAut.idMarcaAutomobile = MarcAut.id;

-- Come Q2.2 ma con filtro sulla marca
SELECT ModAut.nome, ModAut.annoProduzione AS 'Anno Produzione', ModAut.cilindrata, MarcAut.nome
FROM ModelloAutomobile AS ModAut, MarcaAutomobile AS MarcAut
WHERE ModAut.idMarcaAutomobile = MarcAut.id
    AND MarcAut.nome = "FIAT ITALIA"
ORDER BY ModAut.nome ASC;