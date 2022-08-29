INSERT INTO volontario(cognome, nome) VALUES('Rossi','Giorgio');
INSERT INTO volontario(cognome, nome) VALUES('Rossi','Marco');
INSERT INTO volontario(cognome, nome) VALUES('Bianchi','Filippo');
INSERT INTO volontario(cognome, nome) VALUES('Verdi','Anna');
INSERT INTO volontario(cognome, nome) VALUES('Verdi','Rosalba');
-- id    cognome     nome
--  1    Rossi       Giorgio
--  2    Rossi       Marco
--  3    Bianchi     Filippo
--  4    Verdi       Anna
--  5    Verdi       Rosalba

INSERT INTO cane(nome, razza, idVolontario) VALUES('Black', 'Alano', 1);
INSERT INTO cane(nome, razza, idVolontario) VALUES('Scheggia', 'Levriero', 3);
INSERT INTO cane(nome, razza, idVolontario) VALUES('Kira', 'Bassotto', 4);
INSERT INTO cane(nome, razza, idVolontario) VALUES('Sissi', 'Bassotto', 1);
INSERT INTO cane(nome, razza, idVolontario) VALUES('Artax', 'Pastore Tedesco', 3);

-- id    nome        razza             idVolontario
--  1    Black       Alano             1
--  2    Scheggia    Levriero          3
--  3    Kira        Bassotto          4
--  4    Sissi       Bassotto          1
--  5    Artax       Pastore Tedesco   3

INSERT INTO attivita(descrizione, data, esito, idCane) VALUES('Allenamento Salto', '2021/01/21', '1', 1)
INSERT INTO attivita(descrizione, data, esito, idCane) VALUES('Corsa mista', '2021/01/19', '1', 2)
INSERT INTO attivita(descrizione, data, esito, idCane) VALUES('Bagno', '2021/01/22', '1', 3)
INSERT INTO attivita(descrizione, data, esito, idCane) VALUES('Ricerca premio', '2021/01/19', '0', 5)
INSERT INTO attivita(descrizione, data, esito, idCane) VALUES('Tolettatura', '2021/01/24', '1', 5)

-- id    Descrizione          data        esito    idCane
--  1    Allenamento Salto    2021/01/21  1        1
--  2    Corsa mista          2021/01/19  1        2
--  3    Bagno                2021/01/22  1        3
--  4    Ricerca premio       2021/01/19  0        5
--  5    Tolettatura          2021/01/24  1        5