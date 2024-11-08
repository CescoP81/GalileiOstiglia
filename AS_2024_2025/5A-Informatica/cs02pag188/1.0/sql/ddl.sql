-- QUESTO FILE CONTIENE LA SINTASSI MYSQL PER LA CREAZIONE DELLE TABELLE
CREATE TABLE regione(
    id integer unsigned auto_increment,
    nome varchar(25) not null,

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE prodotto(
    id integer unsigned auto_increment,
    descrizione varchar(30) not null,
    prezzoUnitario float not null,
    note varchar(255)

    primary key(id)
)ENGINE=InnoDB;