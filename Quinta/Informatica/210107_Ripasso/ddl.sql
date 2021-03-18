CREATE TABLE meteo_stazioni(
    id integer unsigned auto_increment,
    nome varchar(20) not null,
    posizione varchar(20) not null,
    anno_attivazione char(4) not null,
    primary key(id)
);

CREATE TABLE meteo_temperature(
    id integer unsigned auto_increment,
    valore float not null,
    id_stazione integer unsigned not null,

    primary key(id),
    foreign key (id_stazione) references meteo_stazioni(id)
);

-- POPOLAZIONE
meteo_stazioni
id  nome    posizione           Anno_attivazione
1   Meteo1  Via Bandiera        2009
2   Meteo2  Via Marconi         2010
3   Meteo3  Piazza Garibaldi    2016

meteo_temperature
id  valore  id_stazione -> meteo_stazioni(id)
1   20.4    1
2   25.0    2
3   13.5    2
