-- questo file contiene il codice mySQL per la creazione del table set iniziale.
CREATE TABLE PRODUTTORE
(
    id integer unsigned auto_increment,
    nome varchar(50) not null,
    email varchar(100) not null,
    sitoWeb varchar(100),
    telefono varchar(15),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE CATEGORIA
(
    id integer unsigned auto_increment,
    nome varchar(50) not null,
    descrizione varchar(255),

    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE PRODOTTO
(
    id integer unsigned auto_increment,
    nome varchar(50) not null,
    descrizione varchar(255),
    prezzo float not null,
    idProduttore integer unsigned not null,
    idCategoria integer unsigned not null,

    primary key(id),
    foreign key (idProduttore) references PRODUTTORE(id),
    foreign key (idCategoria) references CATEGORIA(id)
)ENGINE= InnoDB;