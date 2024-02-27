CREATE TABLE Utente(
    id integer unsigned auto_increment,
    email varchar(255),
    passwd char(32),
    nome varchar(30),
    cognome varchar(30),

    primary key(id)
);