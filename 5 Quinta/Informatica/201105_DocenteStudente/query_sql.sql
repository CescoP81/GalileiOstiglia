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
// CREIAMO LA TABELLA VALUTAZIONE CHE
// COLLEGA DOCENTE A STUDENTE

CREATE TABLE valutazione(
	id integer unsigned auto_increment,
	id_docente integer unsigned,
	id_studente integer unsigned,
	data_voto date,
	materia varchar(20),
	voto float,
	
	primary key(id)
)
modificare la tabella in questo modo:
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

docente
1 Pradella Francesco

studente
4 Bottura Elia

Valutazione
id	id_docente	id_studente	data_voto	materia		voto
1	1			4			2020/11/13	Informatica	7.5

INSERT INTO valutazione(id_docente, id_studente, data_voto, materia, voto)
VALUES(1, 1, '2020/11/13','Informatia',7.5);

###########################
Interrogazione della tabella valutazione.
SELECT * FROM valutazione;

SELECT v.id, d.cognome, d.nome, s.cognome, s.nome, v.data_voto, v.materia, v.voto
FROM valutazione AS v, docente AS d, studente AS s
WHERE d.id=v.id_docente AND v.id_studente=s.id
