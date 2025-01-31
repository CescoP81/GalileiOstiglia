INSERT INTO Razza(denominazione, paeseOrigine)
VALUES('mammifero', 'Senegal'),
('rettile', 'Australia'),
('volatile', 'Italia');

INSERT INTO Zona(denominazione)
VALUES ('tropicale'),
('marina'),
('foresta pluviale'),
('zona asiatica');

INSERT INTO Volontariato(Cognome, Nome, statoServizio)
VALUES ('Rossi', 'Mario', 'SN'),
('Bing', 'Qi Ling', 'JR'),
('Elkadiri', 'Aziz', 'SN');

INSERT INTO Animale(Nome, idRazza, idZona, idVolontariato)
VALUES ('jeppino', 2, 3, 2),
('gianfranco', 3, 1, 3),
('david' , 1, 4, 1);

INSERT INTO visita(dataVisita, referto, costo, idAnimale)
VALUES ('2025-2-14', 'deceduto', 104.69, 2),
('2025-4-21', 'in salute', 420.12, 1),
('2023-12-25', 'normale', 32.99, 3);
