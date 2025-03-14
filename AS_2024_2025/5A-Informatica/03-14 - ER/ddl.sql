-- PRIMO CASO CON DUE TABELLE PARTENZA E ARRIVO
create table partenza(
    id integer unsigned auto_increment,
    nomeCitta varchar(30),
    nomeStazione varchar(30),
    primary key(id)
)ENGINE = InnoDB;

create table arrivo(
    id integer unsigned auto_increment,
    nomeCitta varchar(30),
    nomeStazione varchar(30),
    primary key(id)
)ENGINE = InnoDB;

create table viaggio(
    id integer unsigned auto_increment,
    dataViaggio date
    oraViaggio time
    idPartenza integer unsigned,
    idArrivo integer unsigned,

    primary key(id),
    foreign key idPartenza references partenza(id),
    foreign key idArrivo references arrivo(id)
)ENGINE = InnoDB;


-- SECONDA VERSIONE CON TABELLA UNICA STAZIONI UTILIZZATA
-- SIA COME PARTENZA CHE COME ARRIVO
create table stazione(
    id integer unsigned auto_increment,
    nomeCitta varchar(30),
    nomeStazione varchar(30),
    primary key(id)
)ENGINE = InnoDB;

create table viaggio(
    id integer unsigned auto_increment,
    dataViaggio date
    oraViaggio time
    idPartenza integer unsigned,
    idArrivo integer unsigned,

    primary key(id),
    foreign key idPartenza references stazione(id),
    foreign key idArrivo references stazione(id)
)ENGINE = InnoDB;