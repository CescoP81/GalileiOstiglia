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
    primary key (idSpecieFlora, idParco)
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

insert into tipoFlora(tipologia) values('alberi');
insert into tipoFlora(tipologia) values('arbusti');
insert into tipoFlora(tipologia) values('piante erbacee');

insert into parco(parco, regione) values('Colli Euganei', 'Veneto');
insert into parco(parco, regione) values('Dolomiti Bellunesi', 'Veneto');
insert into parco(parco, regione) values('Dolomiti D\'Ampezzo', 'Veneto');
insert into parco(parco, regione) values('Lessinia', 'Veneto');

insert into parco(parco, regione) values('Adamello', 'Lombardia');
insert into parco(parco, regione) values('Adda Nord', 'Lombardia');
insert into parco(parco, regione) values('Adda Sud', 'Lombardia');
insert into parco(parco, regione) values('Parco del Mincio', 'Lombardia');

insert into ordineFauna (ordine) values('mammiferi');
insert into ordineFauna (ordine) values('rettili');
insert into ordineFauna (ordine) values('uccelli');

insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (1, 'quercia', 'primavera', 'frutto ghianda');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (1, 'faggio', 'autunno', 'nc');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (1, 'acacia', 'primavera', 'pianta con spine');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (2, 'lavanda', 'primavera', 'utile per profumi');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (2, 'rosmarino', 'primavera', 'spezia da cucina');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (2, 'rododendro', 'autunno', 'bacche velenose');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (3, 'fragola di bosco', 'primavera', 'frutti piccoli');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (3, 'margherita', 'primavera', 'nc');
insert into specieFlora(idTipoFlora, specie, fioritura, altreCaratteristiche) values (3, 'primula', 'estate', 'nc');

insert into specieFauna(idOrdine, specie, anniAdulto, nEsemplariRischio) values (1, 'scoiattolo', 3, 15);
insert into specieFauna(idOrdine, specie, anniAdulto, nEsemplariRischio) values (1, 'volpe', 6, 30);
insert into specieFauna(idOrdine, specie, anniAdulto, nEsemplariRischio) values (1, 'orso', 4, 25);
insert into specieFauna(idOrdine, specie, anniAdulto, nEsemplariRischio) values (2, 'vipera', 1, 50);
insert into specieFauna(idOrdine, specie, anniAdulto, nEsemplariRischio) values (3, 'falco', 3, 30);
insert into specieFauna(idOrdine, specie, anniAdulto, nEsemplariRischio) values (3, 'aquila', 3, 10);

insert into parcoFlora(idSpecieFlora, idParco) values(1, 2);
insert into parcoFlora(idSpecieFlora, idParco) values(1, 4);
insert into parcoFlora(idSpecieFlora, idParco) values(1, 7);
insert into parcoFlora(idSpecieFlora, idParco) values(2, 3);
insert into parcoFlora(idSpecieFlora, idParco) values(2, 5);
insert into parcoFlora(idSpecieFlora, idParco) values(2, 7);
insert into parcoFlora(idSpecieFlora, idParco) values(5, 1);
insert into parcoFlora(idSpecieFlora, idParco) values(5, 2);
insert into parcoFlora(idSpecieFlora, idParco) values(5, 4);
insert into parcoFlora(idSpecieFlora, idParco) values(5, 5);
insert into parcoFlora(idSpecieFlora, idParco) values(8, 5);
insert into parcoFlora(idSpecieFlora, idParco) values(8, 6);
insert into parcoFlora(idSpecieFlora, idParco) values(8, 7);