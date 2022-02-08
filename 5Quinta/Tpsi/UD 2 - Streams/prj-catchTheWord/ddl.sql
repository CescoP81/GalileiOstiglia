CREATE TABLE tpsi_parola(
   id integer unsigned auto_increment not null,
   testo varchar(25),
   lingua char(2),
   primary key(id)
);

CREATE TABLE tpsi_punteggio(
   id integer unsigned auto_increment not null,
   email varchar(100),
   punteggio integer unsigned,
   idParola integer unsigned,
   primary key id,
   foreign key (idParola) references tpsi_parola(id)
);

INSERT INTO tpsi_parola(testo, lingua) VALUES('BANANA', 'IT');
INSERT INTO tpsi_parola(testo, lingua) VALUES('LIBRO', 'IT');
INSERT INTO tpsi_parola(testo, lingua) VALUES('ALABASTRO', 'IT');
INSERT INTO tpsi_parola(testo, lingua) VALUES('GIORNALE', 'IT');
INSERT INTO tpsi_parola(testo, lingua) VALUES('FENICOTTERO', 'IT');
INSERT INTO tpsi_parola(testo, lingua) VALUES('ANANAS', 'IT');

INSERT INTO tpsi_parola(testo, lingua) VALUES('MAINBOARD', 'EN');
INSERT INTO tpsi_parola(testo, lingua) VALUES('BOOK', 'EN');
INSERT INTO tpsi_parola(testo, lingua) VALUES('RAILROAD', 'EN');
INSERT INTO tpsi_parola(testo, lingua) VALUES('PHILADELPHIA', 'EN');
INSERT INTO tpsi_parola(testo, lingua) VALUES('OFFSHORE', 'EN');
INSERT INTO tpsi_parola(testo, lingua) VALUES('AIRPLANE', 'EN');