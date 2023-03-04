INSERT INTO auto(targa, marca, modello)
VALUES('AB123CD', 'FIAT', 'Panda 1.2 GPL');

INSERT INTO auto(targa, marca, modello)
VALUES('AC123CF', 'FIAT', 'Punto 2.0 TDI');

INSERT INTO auto(targa, marca, modello)
VALUES('AC123CG', 'FIAT', 'Doblò 1.8 TDI');

INSERT INTO auto(targa, marca, modello)
VALUES('AB034LJ', 'FIAT', 'Bravo 2.0 Benzina');

INSERT INTO auto(targa, marca, modello)
VALUES('GF233ER', 'VOLKSWAGEN', 'Passat 2.0 TDI');

INSERT INTO auto(targa, marca, modello)
VALUES('GF233ET', 'VOLKSWAGEN', 'Polo 1.6 TDI');

INSERT INTO auto(targa, marca, modello)
VALUES('CD090AC', 'VOLKSWAGEN', 'Touran 2.0 TDI');

INSERT INTO auto(targa, marca, modello)
VALUES('GF213EA', 'VOLKSWAGEN', 'ID.3');

/* ------------------------------------------ */

INSERT INTO cliente(cognome, nome, indirizzo, telefono, cartaCredito)
VALUES('Rossi','Giuseppe','','','1111222233334444');

INSERT INTO cliente(cognome, nome, indirizzo, telefono, cartaCredito)
VALUES('Rossi','Luigia','','','1111222233334444');

INSERT INTO cliente(cognome, nome, indirizzo, telefono, cartaCredito)
VALUES('Verdi','Alberta','via America 4b, Ostiglia','','1111222233334444');

INSERT INTO cliente(cognome, nome, indirizzo, telefono, cartaCredito)
VALUES('Verdi','Maria','via Sistri 1, Quistello','','1111222233334444');

INSERT INTO cliente(cognome, nome, indirizzo, telefono, cartaCredito)
VALUES('Orlandi','Simone','via Ronchi 16, Sustinente','','1111222233334444');

/* ------------------------------------------ */

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa, dataResaEffettiva, kmPercorsi) 
VALUES('2023/01/25', 1, 1, '2023/01/30', '2023/01/31', 250);

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa, dataResaEffettiva, kmPercorsi) 
VALUES('2023/02/03', 1, 1, '2023/02/05', '2023/02/05', 100);

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa, dataResaEffettiva, kmPercorsi) 
VALUES('2023/02/03', 3, 2, '2023/02/05', '2023/02/08', 300);

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa, dataResaEffettiva, kmPercorsi) 
VALUES('2023/02/15', 3, 3, '2023/02/25', '2023/02/28', 575);

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa, dataResaEffettiva, kmPercorsi) 
VALUES('2023/03/01', 4, 5, '2023/02/05', '2023/02/08', 125);

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa, dataResaEffettiva, kmPercorsi) 
VALUES('2023/03/11', 7, 5, '2023/03/15', '2023/03/18', 230);

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa) 
VALUES('2023/03/11', 6, 3, '2023/03/15');

INSERT INTO noleggio(dataNoleggio, idAuto, idCliente, dataResa) 
VALUES('2023/03/22', 2, 4, '2023/03/25');