-- definizione della tabella.
CREATE TABLE persone(
   id integer unsigned auto_increment,
   cognome varchar(30),
   nome varchar(30),
   primary key(id)
);

-- popolamento iniziale della tabella
INSERT INTO persone(cognome, nome) VALUES('Pradella','Francesco');
INSERT INTO persone(cognome, nome) VALUES('Rossi','Alice');
INSERT INTO persone(cognome, nome) VALUES('Verdi','Mario');
INSERT INTO persone(cognome, nome) VALUES('Bianchi','Sofia');

