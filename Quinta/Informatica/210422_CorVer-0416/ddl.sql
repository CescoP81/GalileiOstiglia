-- CREAZIONE DELLE TABELLE DEL DATABASE
---------------------------------------
CREATE TABLE v_autore(
    id integer unsigned auto_increment,
    cognome varchar(30) not null,
    nome varchar(30) not null,
    anno_nascita char(4),
    
    primary key(id)
);
-- ###########################
CREATE TABLE v_libro(
    id integer unsigned auto_increment,
    id_autore integer unsigned,
    titolo varchar(20) not null,
    n_pagine integer,
    prezzo float,

    primary key(id),
    foreign key (id_autore) references v_autore(id)
);
-- ###########################
CREATE TABLE v_lettore(
    id integer unsigned auto_increment,
    cognome_nome varchar(50) not null,
    mail varchar(50),

    primary key(id)
);
-- ###########################
CREATE TABLE v_libreria(
    id integer unsigned auto_increment,
    nome varchar(30) not null,
    indirizzo varchar(50),

    primary key(id)
);
-- ###########################
CREATE TABLE v_vendita(
    id integer unsigned auto_increment,
    data_vendita date,
    id_lettore integer unsigned,
    id_libro integer unsigned,
    id_libreria integer unsigned,

    primary key(id),
    foreign key (id_lettore) references v_lettore(id),
    foreign key (id_libro) references v_libro(id),
    foreign key (id_libreria) references v_libreria(id)
);