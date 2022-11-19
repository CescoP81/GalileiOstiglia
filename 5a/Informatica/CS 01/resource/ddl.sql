CREATE TABLE cs01_casaEditrice(
    id integer unsigned auto_increment,
    nome varchar(100) not null,
    email varchar(100),
    sitoWeb varchar(100),

    primary key(id)
);

CREATE TABLE cs01_fumetto(
    id integer unsigned auto_increment,
    titolo varchar(100) not null,
    numero varchar(4) not null,
    dataUscita date,
    prezzo float not null,
    immagine varchar(100),
    idCasaEditrice integer unsigned,

    primary key(id),
    foreign key (idCasaEditrice) references cs01_casaEditrice(id)
);