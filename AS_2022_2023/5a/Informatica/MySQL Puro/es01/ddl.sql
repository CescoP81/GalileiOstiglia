CREATE TABLE auto(
    id integer unsigned auto_increment,
    targa char(7) not null,
    marca varchar(15) not null,
    modello varchar(25) not null,

    primary key(id)
);

CREATE TABLE cliente(
    id integer unsigned auto_increment,
    cognome varchar(20) not null,
    nome varchar(20) not null,
    indirizzo varchar(50),
    telefono varchar(10),
    cartaCredito varchar(16) not null,

    primary key(id)
);

CREATE TABLE noleggio(
    id integer unsigned auto_increment,
    dataNoleggio date not null,
    
    idAuto integer unsigned,
    idCliente integer unsigned,

    dataResa date not null,
    dataResaEffettiva date,
    kmPercorsi integer unsigned,

    primary key(id),
    foreign key (idAuto) references auto(id),
    foreign key (idCliente) references cliente(id)
);