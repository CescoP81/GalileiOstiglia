-- creazione della tabella utenti per salvataggio di una password in formato MD5
CREATE TABLE utente(
    id integer unsigned auto_increment,
    nome varchar(30),
    cognome varchar(30),
    mail varchar(30),
    passwd char(32),

    primary key(id)
);

INSERT INTO utente(nome, cognome, mail, passwd)
VALUES('Francesco', 'Pradella', 'fp@fp.it', MD5('abc123'));

INSERT INTO utente(nome, cognome, mail, passwd)
VALUES('Francesco', 'Gobbi', 'fg@fg.it', MD5('12345678'));