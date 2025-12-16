-- Questo file denominato DDL.sql contiene le istruzioni necessarie alla creazione
-- del set ti dabelle che compongono il database.
-- E' il primo file da realizzare partendo da un diagramma ER.

CREATE TABLE 'nome_tabella'(
    id integer unsigned auto_increment,
    campo1 varchar(10) not null,
    campo2 char(8) not null,
    campo3 text,

    primary key(id)
);

CREATE TABLE 'nome_tabella'(
    id integer unsigned auto_increment,
    campo1 varchar(10) not null,
    idEsterno integer unsigned,

    primary key(id)
    foreign key (idEsterno) references nome_tabella(id)
)