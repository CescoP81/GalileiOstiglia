-- QUESTO FILE CONTIENE LA SINTASSI MYSQL PER LA CREAZIONE DELLE TABELLE
CREATE TABLE regione(
    id integer unsigned auto_increment,
    nome varchar(25) not null,

    primary key(id)
)ENGINE=InnoDB;