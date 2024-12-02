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
VALUES ('Mantova', 'via Risorgimento nr. 4', '0376-12345', '', 1),