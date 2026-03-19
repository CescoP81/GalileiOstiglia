-- ISTRUZIONIO mySQL PER LA CREAZIONE DEL TABLE SET
create table cliente(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    email varchar(50),

    primary key(id)
)ENGINE=InnoDB;

create table provincia(
    id integer unsigned auto_increment,
    nome varchar(30),

    primary key(id)
)ENGINE=InnoDB;

create table spedizione(
    id integer unsigned auto_increment,
    descrizoneMerce varchar(255),
    idCliente integer unsigned,
    idProvinciaPartenza integer unsigned,
    idProvinciaArrivo integer unsigned,

    primary key(id),
    foreign key (idCliente) references cliente(id),
    foreign key (idProvinciaPartenza) references provincia(id),
    foreign key (idProvinciaArrivo) references provincia(id)
)ENGINE=InnoDB;

create table tracking(
    id integer unsigned auto_increment,
    dataTappa date
    idSpedizione integer unsigned,
    idProvincia integer unsigned,

    foreign key (idSpedizione) references spedizione(id),
    foreign key (idProvincia) references provincia(id)
)ENGINE=InnoDB;