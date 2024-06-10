CREATE TABLE utenti(
    mail varchar(100) not null,
    password varchar(8) not null,
    nome varchar(20),
    cognome varchar(20),

    primary key(mail)
)

INSERT INTO utenti(mail, password, nome, cognome) VALUES('info@info.it', '12345678', 'Utente1','Utente1');
INSERT INTO utenti(mail, password, nome, cognome) VALUES('ipino@pino.it', '12345678', 'Pino','Pilotino');