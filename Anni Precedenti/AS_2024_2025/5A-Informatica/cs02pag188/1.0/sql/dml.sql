-- QUESTO FILE CONTIENE L'INSERIMENTO DELLE RIGHE INIZIALI NELLE RELATIVE TABELLE

INSERT INTO regione(nome) VALUES('Lombardia');
INSERT INTO regione(nome) VALUES('Veneto');
INSERT INTO regione(nome) VALUES('Piemonte');
INSERT INTO regione(nome) VALUES('Emilia Romagna');
INSERT INTO regione(nome) VALUES('Liguria');
INSERT INTO regione(nome) VALUES('Trentino Alto Adige');
INSERT INTO regione(nome) VALUES('Lazio');

INSERT INTO prodotto(descrizione, prezzoUnitario, note)
VALUES('Forchetta Carta', 9.55, 'Pacchi da 200');
INSERT INTO prodotto(descrizione, prezzoUnitario, note)
VALUES('Bicchiere 200ml', 7.55, 'Pacchi da 200');
INSERT INTO prodotto(descrizione, prezzoUnitario, note)
VALUES('Piatto Carta', 12.45, '');

INSERT INTO ufficio(citta, indirizzo, telefono, email, idRegione)
VALUES ('Mantova', 'via Risorgimento nr. 4', '0376-12345', '', 1),
('Ostiglia', 'via Collodi 24', '0386-12345', 'ufficio@sede.it', 1),
('Trento', 'via C. Colombo nr. 13', '0345-12345', '', 6),
('Ladispoli', 'via Verdi nr. 4', '', 'ladispoli@sede.it', 7),
('Genova', 'via Gramsci nr. 8', '', 'genova@sede.it', 10);

INSERT INTO ufficio(citta, indirizzo, telefono, email, idRegione)
VALUES ('Mantova', 'via Risorgimento nr. 4', '0376-12345', '', 1);

-- prodotti 1 2 5 6
-- ufficio 1 2 3 4 5
INSERT INTO vendita(dataVendita, quantita, idProdotto, idUfficio)
VALUES('2024-03-10', 3, 1, 2),
('2024-03-25', 10, 6, 5),
('2024-05-10', 20, 2, 3),
('2024-05-25', 15, 5, 4),
('2024-06-03', 50, 1, 2),
('2024-06-30', 75, 5, 4),
('2024-05-10', 30, 1, 5);

INSERT INTO vendita(dataVendita, quantita, idProdotto, idUfficio)
VALUES('2024-03-10', 3, 7, 6);