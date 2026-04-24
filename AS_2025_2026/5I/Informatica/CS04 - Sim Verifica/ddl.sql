CREATE TABLE autore(
    id integer unsigned auto_increment,
    cognome varchar(30),
    nome varchar(30),
    annoNascita char(4),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE lettore(
    id integer unsigned auto_increment,
    cognome varchar(30),
    nome varchar(30),
    mail varchar(50),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE libreria(
    id integer unsigned auto_increment,
    nome varchar(30),
    indirizzo varchar(50),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE libro(
    id integer unsigned auto_increment,
    cod_autore integer unsigned,
    titolo varchar(20),
    nPagine integer unsigned,
    prezzo float,

    primary key(id),
    foreign key (cod_autore) references autore(id)
)ENGINE=InnoDB;

CREATE TABLE vendita(
    id integer unsigned auto_increment,
    dataVendita date,
    idLettore integer unsigned,
    idLibro integer unsigned,
    idLibreria integer unsigned,

    primary key(id),
    foreign key(idLettore) references lettore(id),
    foreign key(idLibro) references libro(id),
    foreign key(idLibreria) references libreria(id)
)ENGINE=InnoDB;