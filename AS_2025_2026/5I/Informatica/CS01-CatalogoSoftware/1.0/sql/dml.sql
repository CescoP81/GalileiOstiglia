INSERT INTO produttore(nome, email, sitoweb, telefono)
VALUES('Acme s.r.l.', 'info@acmesrl.it', 'acmesrl.it', '555-789327');

INSERT INTO produttore(nome, email, sitoweb, telefono)
VALUES('Sitel s.r.l.', 'info@sitelsrl.it', 'sitel.com', '555-780087');

INSERT INTO produttore(nome, email, sitoweb, telefono)
VALUES('Rimor s.n.c.', 'info@rimor.it', 'rimor.it', '555-349932');

-- Popolazione della tabella 'categoria'
INSERT INTO categoria(nome, descrizione)
VALUES ('Progettazione CAD', 'Software per la progettazione 2D.'),
        ('Modellazione 3D', 'Software per la modellazione e stampa 3D'),
        ('Sicurezza e Privacy', 'Antivirus, Antispam, Firewall'),
        ('Sistemi Operativi', 'Sistemi operativi Microsoft e Linux Based'),
        ('Fotoritocco', 'Software di creazione, editing, stampa di fotografie');

-- Popolane della tabella 'prodotto'
INSERT INTO prodotto (nome, descrizione, prezzo, idProduttore, idCategoria)
VALUES  ('Autodesk Autocad', 'Software CAD', 185.50, 1, 1),
        ('Avast Antivirus', 'Software per controllo virus', 35.00, 2, 3),
        ('Solid Edge', 'Software CAD 2D/3D', 250.00, 1, 1),
        ('PhotoStitch', 'Software per foto fantastiche', 199.99, 3, 5),
        ('Linux Mint', 'Sistema operativo su base Debian', 0.0, 3, 4);