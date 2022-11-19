CREATE TABLE casa_discografica(
    id integer unsigned auto_increment,
    descrizione varchar(100) not null,
    stato varchar(2) not null,

    primary key(id);
)

CREATE TABLE album(
    id integer unsigned auto_increment,
    autore varchar(30),
    anno_uscita char(4),
    idCasaDiscrografica integer unsigned,

    primary key(id),
    foreign key(idCasaDiscrografica) references casa_discografica(id)
)