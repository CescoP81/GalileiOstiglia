CREATE TABLE PRODOTTO(
    id integer unsigned auto_increment,
    descrizione varchar(25) not null,

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE MAGAZZINO(
    id integer unsigned auto_increment,
    nome varchar(20) not null,
    citta varchar(20) not null,
    provincia char(2) not null,

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE ACQUISTO(
    id integer unsigned auto_increment,
    idProdotto integer unsigned,
    idMagazzino integer unsigned,
    dataAcquisto date not null,
    quantitaAcquisto integer not null,
    prezzoAcquisto float not null,

    primary key(id),
    foreign key(idProdotto) references PRODOTTO(id),
    foreign key(idMagazzino) references MAGAZZINO(id)
)ENGINE=InnoDB;

CREATE TABLE ADMINS(
    id integer unsigned auto_increment,
    cognome varchar(20) not null,
    nome varchar(20) not null,
    mail varchar(200),
    password char(32)

    primary key(id, mail, password)
);

INSERT INTO admins(cognome, nome, mail, password)
VALUES ('Francesco', 'Pradella', 'f@p.it', MD5('12345678'));
INSERT INTO admins(cognome, nome, mail, password)
VALUES ('Luca', 'Cavallaro', 'l@c.it', MD5('01234567'));
INSERT INTO admins(cognome, nome, mail, password)
VALUES ('Tommaso', 'Rossi', 't@r.it', MD5('abcd1234'));

