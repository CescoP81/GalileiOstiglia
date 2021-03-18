1. creare il database 'scuola2021'
2. creare la tabella docenti
CREATE TABLE docente(
	id integer unsigned auto_increment,
    	cognome varchar(20),
    	nome varchar(20),
    	primary key(id)
);

CREATE TABLE studente(
	id integer unsigned auto_increment,
	cognome varchar(20),
	nome varchar(20),
	primary key(id)
);

INSERT INTO docente(cognome, nome) VALUES('Pradella','Francesco');
INSERT INTO docente(cognome, nome) VALUES('Bottoni', 'Alberto');

INSERT INTO studente(cognome, nome) VALUES('Bottura','Elia');
INSERT INTO studente(cognome, nome) VALUES('Bosi','Diego');

########### tbabella valutazione
CREATE TABLE valutazione(
	id integer unsigned auto_increment,
	id_docente integer unsigned,
	id_studente integer unsigned,
	data_voto date,
	materia varchar(20),
	voto float,
	
	foreign key(id_docente)	references docente(id),
	foreign key(id_studente) references studente(id),
	
	primary key(id)
)

INSERT INTO valutazione(id_docente, id_studente, data_voto, materia, voto)
VALUES(1, 1, '2020/11/13','Informatia',7.5);