CREATE TABLE Razza(
    id integer unsigned auto_increment,
    denominazione varchar(30) not null,
    paeseOrigine varchar(20) not null,

    primary key (id)
)ENGINE=InnoDB;

CREATE TABLE Zona(
    id integer unsigned auto_increment,
    denominazione varchar(30) not null,

    primary key (id) 
)ENGINE=InnoDB;

CREATE TABLE Volontariato(
    id integer unsigned auto_increment,
    Cognome varchar(20) not null,
    Nome varchar(20) not null,
    statoServizio char(2) not null,

    primary key (id)
)ENGINE=InnoDB;

CREATE TABLE Animale(
    id integer unsigned auto_increment,
    Nome varchar(20) not null,
    idRazza integer unsigned,
    idZona integer unsigned, 
    idVolontariato integer unsigned,

    primary key (id),
    foreign key (idRazza) references Razza(id),
    foreign key (idZona) references Zona(id),
    foreign key (idVolontariato) references Volontariato(id)
)ENGINE=InnoDB;

CREATE TABLE Visita(
    id integer unsigned auto_increment,
    dataVisita date not null,
    referto varchar(50) not null,
    costo float not null,
    idAnimale integer unsigned,

    primary key(id),
    foreign key (idAnimale) references Animale(id)
)ENGINE=InnoDB;