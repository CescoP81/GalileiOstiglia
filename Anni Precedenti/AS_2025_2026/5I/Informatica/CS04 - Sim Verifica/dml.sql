INSERT INTO autore(cognome, nome, annoNascita)
VALUES ('Calvino', 'Italo', '1905'),
('Rossi', 'Alberto', '1954'),
('Verdi', 'Bruno', '1983'),
('Bianchi', 'Maria', '1966');

INSERT INTO lettore(cognome, nome, mail)
VALUES('Aldrighi','Lucia','lucia@aldrighi.it'),
('Marusti','Simone','simone@marusti.it'),
('Brambilla','Mario','mario@brambilla.it'),
('Siliprandi','Antonio','antonio@soliprandi.it');

INSERT INTO libreria(nome, indirizzo)
VALUES('Il Temperino','Quistello MN'),
('La matita', 'Ostiglia MN'),
('Quadretto rosso', 'Nogara VR'),
('Pennarello verde', 'Melara RO');

INSERT INTO libro(cod_autore, titolo, nPagine, prezzo)
VALUES(1, 'Cime tempestose', 145, 15.99),
(1, 'Barone rampante', 210, 17.99),
(3, 'Lo squalo', 225, 9.99),
(4, 'I Goonies', 160, 19.99),
(4, 'Tremors', 350, 25.50);

INSERT INTO vendita(dataVendita, idLettore, idLibro, idLibreria)
VALUES('2026/01/12', 2, 3, 3),
('2026/01/13', 3, 4, 4),
('2026/02/09', 4, 2, 2),
('2026/02/19', 1, 1, 1);