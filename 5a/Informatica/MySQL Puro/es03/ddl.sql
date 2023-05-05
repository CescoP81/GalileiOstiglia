create table tipoFlora(
    id integer unsigned auto_increment,
    tipologia varchar(20),

    primary key(id)
);

create table parco(
    id integer unsigned auto_increment,
    parco varchar(20),
    regione varchar(20),
    primary key(id)
);

create table ordineFauna(
    id integer unsigned auto_increment,
    ordine varchar(20),
    primary key(id)
);

create table specieFlora(
    id integer unsigned auto_increment,
    idTipoFlora integer unsigned,
    specie varchar(20),
    fioritura varchar(20),
    altreCaratteristiche varchar(20),

    foreign key (idTipoFlora) references tipoFlora(id),
    primary key (id)
);

create table parcoFlora(
    idSpecieFlora integer unsigned,
    idParco integer unsigned,

    foreign key (idSpecieFlora) references specieFlora(id),
    foreign key (idParco) references parco(id),
    primary key(idSpecieFlora, idParco)
);

create table specieFauna(
    id integer unsigned auto_increment,
    idOrdine integer unsigned,
    specie varchar(20),
    anniAdulto tinyint,
    nEsemplariRischio tinyint,

    foreign key (idOrdine) references ordineFauna(id),
    primary key (id)
);

create table esemplareFauna(
    id integer unsigned auto_increment,
    idParco integer unsigned,
    idSpecie integer unsigned,
    nome varchar(20),
    dataNascita date,
    sesso char(1),
    salute varchar(20),

    foreign key (idParco) references parco(id),
    foreign key (idSpecie) references specieFauna(id),
    primary key (id, idParco)
)