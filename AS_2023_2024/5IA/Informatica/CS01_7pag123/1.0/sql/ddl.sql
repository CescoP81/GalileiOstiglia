CREATE TABLE Citta(
    id integer unsigned auto_increment,
    nomeCitta varchar(20),

    primary key(id)
) ENGINE=InnoDB;

CREATE TABLE Reparto(
    id integer unsigned auto_increment,
    nomeReparto varchar(20),
    idCittaReparto integer unsigned,

    primary key(id),
    foreign key(idCittaReparto) references Citta(id)
) ENGINE=InnoDB;

CREATE TABLE Dipendente(
    id integer unsigned auto_increment,
    Cognome varchar(30),
    Nome varchar(30),
    idReparto integer unsigned,
    idCittaResidenza integer unsigned,

    primary key(id),
    foreign key(idReparto) references Reparto(id),
    foreign key(idCittaResidenza) references Citta(id)
) ENGINE=InnoDB;