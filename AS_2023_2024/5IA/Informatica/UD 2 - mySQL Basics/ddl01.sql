/*  Il file denominato DDL.sql contiene la creazione delle tabelle,
    quindi solamente le istruzioni di CREATE TABLE.
    I nomi delle tabelle, il nome e tipo dei singoli attributi DEVE rispecchiare
    quanto schematizzato nel file er.drawio o comunque nel diagramma E.R. realizzato (con altro programma, su carta, etc...).
*/
CREATE TABLE Uomo(
    id integer unsigned auto_increment,
    nome varchar(39) NOT NULL,
    cognome varchar(15) NOT NULL,
    paese varchar(15),
    anni TINYINT,

    PRIMARY KEY(id)
);