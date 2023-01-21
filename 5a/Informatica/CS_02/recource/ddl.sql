CREATE TABLE cs02_iscritti(
    id integer unsigned auto_increment,
    nome varchar(20) not null,
    cognome varchar(20) not null,
    mail varchar(50) not null,
    password char(32),

    primary key(id)
);

CREATE TABLE cs02_spettacoli(
    id integer unsigned auto_increment,
    titolo varchar(50) not null,
    regia varchar(30) not null,
    attorePrincipale varchar(20),
    durata integer unsigned,
    locandina varchar(100),

    primary key(id)
);

CREATE TABLE cs02_stagioni(
    id integer unsigned auto_increment,
    descrizione varchar(255) not null,
    annualita varchar(10) not null,
    dataInizio date not null,
    dataFine date not null,

    primary key(id)
);

CREATE TABLE cs02_palinsesto(
    id integer unsigned auto_increment,
    dataSpettacolo date not null,
    idSpettacolo integer unsigned,
    idStagione integer unsigned,

    primary key(id),
    foreign key(idSpettacolo) references cs02_spettacoli(id),
    foreign key(idStagione) references cs02_stagioni(id)
);

CREATE TABLE cs02_partecipa(
    id integer unsigned auto_increment,
    idIscritto integer unsigned,
    idPalinsesto integer unsigned,
    indiceGradimento tinyint,

    primary key(id),
    foreign key(idIscritto) references cs02_iscritti(id),
    foreign key(idPalinsesto) references cs02_palinsesto(id)
);