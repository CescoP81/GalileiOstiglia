/* CREAZIONE TABELLE PRINCIPALI */
CREATE TABLE p6_organizzazione(
    id integer unsigned auto_increment,
    nome varchar(30) not null,
    primary key(id)
);

CREATE TABLE p6_nazione(
    id integer unsigned auto_increment,
    nome varchar(30) not null,
    primary key(id)
);

CREATE TABLE p6_cliente(
    id integer unsigned auto_increment,
    nome varchar(30) not null,
    primary key(id)
);

/* CREAZIONE TABELLE DI RELAZIONE */
CREATE TABLE p6_servizio(
    id integer unsigned auto_increment,
    nome varchar(30) not null,
    prezzo float,
    id_organizzazione integer unsigned not null,
    id_nazione integer unsigned not null,

    primary key(id),
    foreign key(id_organizzazione) references p6_organizzazione(id),
    foreign key(id_nazione) references p6_nazione(id)
);

CREATE TABLE p6_servizio_cliente(
    id integer unsigned auto_increment,
    id_servizio integer unsigned not null,
    id_cliente integer unsigned not null,

    primary key(id),
    foreign key(id_servizio) references p6_servizio(id),
    foreign key(id_cliente) references p6_cliente(id)
);

/* POPOLAMENTO INIZIALE DELLE TABELLE PRINCIPALI */
INSERT INTO p6_organizzazione(nome) VALUES('Albero Rosso srl');     /*1*/
INSERT INTO p6_organizzazione(nome) VALUES('Spago Spaghetto spa');  /*2*/
INSERT INTO p6_organizzazione(nome) VALUES('Il Filodoro snc');      /*3*/

INSERT INTO p6_nazione(nome) VALUES('Italy');                       /*1*/
INSERT INTO p6_nazione(nome) VALUES('France');                      /*2*/
INSERT INTO p6_nazione(nome) VALUES('Spain');                       /*3*/
INSERT INTO p6_nazione(nome) VALUES('Hungary');                     /*4*/

INSERT INTO p6_cliente(nome) VALUES('Rossi Giorgio');               /*1*/
INSERT INTO p6_cliente(nome) VALUES('Bianchi Armando');             /*2*/
INSERT INTO p6_cliente(nome) VALUES('Malavicina Luisa');            /*3*/
INSERT INTO p6_cliente(nome) VALUES('Tarocco Alberta');             /*4*/
/* POPOLAMENTO INIZIALE DELLE TABELLE DI RELAZIONE */
INSERT INTO p6_servizio(nome, prezzo, id_organizzazione, id_nazione) VALUES('Trasporto Navetta', 1250.50, 3, 1);    /*1*/
INSERT INTO p6_servizio(nome, prezzo, id_organizzazione, id_nazione) VALUES('Mail Boxes Etc', 800.00, 1, 2);        /*2*/
INSERT INTO p6_servizio(nome, prezzo, id_organizzazione, id_nazione) VALUES('Mail Boxes Etc', 750.00, 1, 3);        /*3*/
INSERT INTO p6_servizio(nome, prezzo, id_organizzazione, id_nazione) VALUES('Mail Boxes Etc', 1000.00, 1, 4);       /*4*/
INSERT INTO p6_servizio(nome, prezzo, id_organizzazione, id_nazione) VALUES('Web Hosting', 425.00, 2, 4);           /*5*/

INSERT INTO p6_servizio_cliente(id_servizio, id_cliente) VALUES(1, 1);  /*1*/
INSERT INTO p6_servizio_cliente(id_servizio, id_cliente) VALUES(2, 3);  /*2*/
INSERT INTO p6_servizio_cliente(id_servizio, id_cliente) VALUES(4, 4);  /*3*/
INSERT INTO p6_servizio_cliente(id_servizio, id_cliente) VALUES(1, 2);  /*4*/
INSERT INTO p6_servizio_cliente(id_servizio, id_cliente) VALUES(5, 2);  /*5*/