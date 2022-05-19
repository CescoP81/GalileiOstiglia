INSERT INTO p232_organizzazione (nome, telefono)
VALUES('Viaggi liberi', '555-657689');

INSERT INTO p232_organizzazione (nome, telefono)
VALUES('Gironzolando', '555-657633');

INSERT INTO p232_organizzazione (nome, telefono)
VALUES('Il Solitario', '545-657689');

INSERT INTO p232_organizzazione (nome, telefono)
VALUES('La Barca Va', '555-688689');

/** ================================= */
INSERT INTO p232_nazione(denominazione, documenti, clima)
VALUES('Portogallo', 'Carta Identità', 'Mite');

INSERT INTO p232_nazione(denominazione, documenti, clima)
VALUES('Marocco', 'Passaporto', 'Caldo');

INSERT INTO p232_nazione(denominazione, documenti, clima)
VALUES('Brasile', 'Passaporto', 'Temperato');

INSERT INTO p232_nazione(denominazione, documenti, clima)
VALUES('Olanda', 'Carta Identità', 'Temperato');

/* =================================== */
INSERT INTO p232_cliente(cognome, nome, indirizzo, telefono)
VALUES('Rossi','Mario','via Schiappa, Quistello', '555-567890');

INSERT INTO p232_cliente(cognome, nome, indirizzo, telefono)
VALUES('Rossi','Arianna','via Moschino, Schivenoglia', '555-557890');

INSERT INTO p232_cliente(cognome, nome, indirizzo, telefono)
VALUES('Verdi','Alberto','via Castagne, Poggio Rusco', '555-545690');

INSERT INTO p232_cliente(cognome, nome, indirizzo, telefono)
VALUES('Bianchi','Annarita','via Tortellino, Ostiglia', '555-778890');

/* ====================================== */
INSERT INTO p232_pacchetto(descrizione, modalita, prezzo, codOrganizzazione, codNazione)
VALUES('Viaggio Avventura', 'Escursionismo', 350.50, 1, 1);

INSERT INTO p232_pacchetto(descrizione, modalita, prezzo, codOrganizzazione, codNazione)
VALUES('Relax in spiaggia', 'Villaggio vacanze', 500.00, 2, 2);

INSERT INTO p232_pacchetto(descrizione, modalita, prezzo, codOrganizzazione, codNazione)
VALUES('Colonne di Ercole', 'Visita guidata', 750.00, 3, 1);

INSERT INTO p232_pacchetto(descrizione, modalita, prezzo, codOrganizzazione, codNazione)
VALUES('Pesca snorkeling', 'Escursionismo', 250.50, 4, 4);

INSERT INTO p232_pacchetto(descrizione, modalita, prezzo, codOrganizzazione, codNazione)
VALUES('Caccia al Grillo', 'Escursionismo', 350.50, 3, 3);

/* ========================================== */
INSERT INTO p232_acquisto(codPacchetto, codCliente, dataAcquisto)
VALUES (1, 1, '2022/01/12');

INSERT INTO p232_acquisto(codPacchetto, codCliente, dataAcquisto)
VALUES (1, 3, '2022/01/16');

INSERT INTO p232_acquisto(codPacchetto, codCliente, dataAcquisto)
VALUES (3, 2, '2022/02/26');

INSERT INTO p232_acquisto(codPacchetto, codCliente, dataAcquisto)
VALUES (3, 4, '2022/04/25');

INSERT INTO p232_acquisto(codPacchetto, codCliente, dataAcquisto)
VALUES (2, 3, '2022/02/28');

INSERT INTO p232_acquisto(codPacchetto, codCliente, dataAcquisto)
VALUES (4, 4, '2022/05/15');

