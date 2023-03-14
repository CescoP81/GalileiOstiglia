/*CREATE TABLE cs02_iscritti(
    id integer unsigned auto_increment,
    nome varchar(20) not null,
    cognome varchar(20) not null,
    mail varchar(50) not null,
    password char(32),
    fasciaEta tinyint,

    primary key(id)
);*/
INSERT INTO cs02_iscritti(nome, cognome, mail, password, fasciaEta) VALUES ("Francesco","Pradella","fp@fp.it", MD5('guest'),3);
INSERT INTO cs02_iscritti(nome, cognome, mail, password, fasciaEta) VALUES ("Mario","Rossi","mr@mr.it", MD5('guest'),1);
INSERT INTO cs02_iscritti(nome, cognome, mail, password, fasciaEta) VALUES ("Anna","Verdi","av@av.it", MD5('guest'),1);
INSERT INTO cs02_iscritti(nome, cognome, mail, password, fasciaEta) VALUES ("Maria","Bianchi","mb@mb.it", MD5('guest'),4);
INSERT INTO cs02_iscritti(nome, cognome, mail, password, fasciaEta) VALUES ("Simone","Giudici","sg@sg.it", MD5('guest'),2);

/*CREATE TABLE cs02_spettacoli(
    id integer unsigned auto_increment,
    titolo varchar(50) not null,
    regia varchar(30) not null,
    attorePrincipale varchar(20),

    primary key(id)
);*/
INSERT INTO cs02_spettacoli(titolo, regia) VALUES("E.T.", "Stephen Spielberg");
INSERT INTO cs02_spettacoli(titolo, regia) VALUES("Il Pedone", "Giuseppe Giacobazzi");
INSERT INTO cs02_spettacoli(titolo, regia) VALUES("Il cosmo sul comò", "Aldio Giovanni e Giacomo");
INSERT INTO cs02_spettacoli(titolo, regia) VALUES("Bau", "Angelo Pintus");

/*CREATE TABLE cs02_stagioni(
    id integer unsigned auto_increment,
    descrizione varchar(255) not null,
    annualita varchar(10) not null,
    dataInizio date not null,
    dataFine date not null,

    primary key(id)
);*/
INSERT INTO cs02_stagioni(descrizione, annualita, dataInizio, dataFine) 
VALUES("Stagione omaggio a Monicelli", "2022-2023", "2022/09/01", "2023/05/31");

INSERT INTO cs02_stagioni(descrizione, annualita, dataInizio, dataFine) 
VALUES("40esimo in Teatro", "2021-2021", "2021/09/01", "2022/05/31");

INSERT INTO cs02_stagioni(descrizione, annualita, dataInizio, dataFine) 
VALUES("Un mondo di storie", "2020-2021", "2020/09/01", "2021/06/30");