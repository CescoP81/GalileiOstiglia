-- definizione delle tabelle.
CREATE TABLE p8_cliente(
    id integer unsigned auto_increment,
    nominativo varchar (30),
    prov_residenza char(2),
    primary key(id)
);

-- Corrieri es: TNT, DHL, BRT, POSTENL...
CREATE TABLE p8_corriere(
    id integer unsigned auto_increment,
    denominazione varchar(20),
    primary key(id)
);

CREATE TABLE p8_spedizione(
    id integer unsigned auto_increment,
    id_cliente integer unsigned not null,
    id_corriere integer unsigned,
    data_spedizione date,
    partenza varchar(20) not null,
    destinazione varchar(20) not null,

    primary key(id),
    foreign key (id_cliente) references p8_cliente(id),
    foreign key (id_corriere) references p8_corriere(id)
);

-------------------------------------
-- popolazione iniziale delle tabelle
INSERT INTO p8_cliente(nominativo, prov_residenza) VALUES ('Pradella Francesco', 'MN'); -- id 1
INSERT INTO p8_cliente(nominativo, prov_residenza) VALUES ('CEM s.p.a.', 'MN');         -- id 2
INSERT INTO p8_cliente(nominativo, prov_residenza) VALUES ('Bottoni Alberto', 'RO');    -- id 3
INSERT INTO p8_cliente(nominativo, prov_residenza) VALUES ('Tosano Market', 'VR');      -- id 4

INSERT INTO p8_corriere(denominazione) VALUES ('BRT');  -- id 1
INSERT INTO p8_corriere(denominazione) VALUES ('SDA');  -- id 2
INSERT INTO p8_corriere(denominazione) VALUES ('DHL');  -- id 3
INSERT INTO p8_corriere(denominazione) VALUES ('UPS');  -- id 4
INSERT INTO p8_corriere(denominazione) VALUES ('GLS');  -- id 5

INSERT INTO p8_spedizione (id_cliente, id_corriere, data_spedizione, partenza, destinazione)
VALUES (1, 2, '2021/03/24', 'Mantova (MN)', 'Solferino (MN)');
INSERT INTO p8_spedizione (id_cliente, id_corriere, data_spedizione, partenza, destinazione)
VALUES (2, 4, '2021/02/24', 'Quistello (MN)', 'Cascina (PI)');
INSERT INTO p8_spedizione (id_cliente, id_corriere, data_spedizione, partenza, destinazione)
VALUES (3, 2, '2021/02/28', 'Ostiglia (MN)', 'Trento (TN)');

INSERT INTO p8_spedizione (id_cliente, id_corriere, data_spedizione, partenza, destinazione)
VALUES (4, null, null, 'Legnago (VR)', 'Mantova (MN)');
INSERT INTO p8_spedizione (id_cliente, id_corriere, data_spedizione, partenza, destinazione)
VALUES (3, null, null, 'Ostiglia (MN)', 'Bologna (BO)');
INSERT INTO p8_spedizione (id_cliente, partenza, destinazione)
VALUES (4, 'Legnago (VR)', 'Brescia (BS)');