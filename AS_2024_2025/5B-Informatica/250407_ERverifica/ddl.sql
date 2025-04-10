CREATE TABLE servizio(
    id integer unsigned auto_increment,
    descrizione varchar(50),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE consulente(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    recapito varchar(15)

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE provincia(
    id integer unsigned auto_increment,
    nome varchar(20),
    sigla char(2),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE cliente(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    indirizzo varchar(50),
    citta varchar(20),
    idConsulente integer unsigned,
    idProvincia integer unsigned,

    primary key(id),
    foreign key idConsulente references consulente(id),
    foreign key idProvincia references provincia(id)
)ENGINE=InnoDB;

CREATE TABLE fattura(
    id integer unsigned auto_increment,
    idServizio integer unsigned,
    idCliente integer unsigned,
    dataFattura date,
    importo float,

    primary key(id),
    foreign key idServizio references servizio(id),
    foreign key idCliente references cliente(id)
)ENGINE=InnoDB;