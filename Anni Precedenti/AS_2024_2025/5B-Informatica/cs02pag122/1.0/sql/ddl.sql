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