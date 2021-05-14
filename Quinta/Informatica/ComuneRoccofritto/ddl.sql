CREATE TABLE rf_genere(
    id integer unsigned auto_increment,
    titolo varchar(50) UNIQUE NOT NULL,
    descrizione text,
    primary key(id)
);

CREATE TABLE rf_spettacolo(
    id integer unsigned auto_increment,
    titolo varchar(50) NOT NULL,
    compagnia varchar(50) NOT NULL,
    descrizione text,
    costo float,
    id_genere integer unsigned,

    primary key(id),
    foreign key (id_genere) references rf_genere(id)
)

CREATE TABLE rf_rassegna(
    id integer unsigned auto_increment,
    titolo varchar(50) NOT NULL,
    descrizione text NOT NULL,
    data_inizio date NOT NULL,
    data_fine date NOT NULL,

    primary key(id)
)

CREATE TABLE rf_rassegna_spettacolo(
    id integer unsigned auto_increment,
    data_esecuzione date NOT NULL,
    id_rassegna integer unsigned,
    id_spettacolo integer unsigned,

    primary key(id),
    foreign key (id_rassegna) references rf_rassegna(id),
    foreign key (id_spettacolo) references rf_spettacolo(id)
)