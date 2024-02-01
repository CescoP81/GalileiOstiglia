DROP TABLE IF EXISTS Dipendente;
DROP TABLE IF EXISTS Reparto;
DROP TABLE IF EXISTS Citta;

CREATE TABLE IF NOT EXISTS Citta(
    id integer unsigned auto_increment,
    nomeCitta varchar(20),

    primary key(id)
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS Reparto(
    id integer unsigned auto_increment,
    nomeReparto varchar(20),
    idCittaReparto integer unsigned,

    primary key(id),
    foreign key(idCittaReparto) references Citta(id)
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS Dipendente(
    id integer unsigned auto_increment,
    Cognome varchar(30),
    Nome varchar(30),
    idReparto integer unsigned,
    idCittaResidenza integer unsigned,

    primary key(id),
    foreign key(idReparto) references Reparto(id),
    foreign key(idCittaResidenza) references Citta(id)
) ENGINE=InnoDB;

-- aggiunta in data 1.02.24
CREATE TABLE IF NOT EXISTS Pagamento(
    id integer unsigned auto_increment,
    data date,
    causale varchar(255),
    importo float,
    idDipendente integer unsigned,

    primary key(id),
    foreign key(idDipendente) references Dipendente(id)
) ENGINE=InnoDB;