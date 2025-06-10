-- Questo file con linguaggio mySQL contiene SOLO
-- la definizione delle tabelle (cioè come si chiamano e quali campi sono presenti)

CREATE TABLE Artista(
    id integer unsigned auto_increment,
    nome varchar(20) not null,
    cognome varchar(20) not null,
    nazione char(2),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE Brano(
    id integer unsigned auto_increment,
    titolo varchar(20) not null,
    anno integer not null,
    genere varchar(15) not null,
    idArtista integer unsigned,

    primary key(id),
    foreign key(idArtista) references Artista(id)
)ENGINE=InnoDB;