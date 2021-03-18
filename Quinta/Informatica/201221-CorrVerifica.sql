-- Correzione Verifica del 11.12.2020
-- Traccia Nr. 1
-------------------------------------

-- Query 1: creazione delle tabelle.
create table autore(
	id integer unsigned auto_increment,
	cognome varchar(20),
	nome varchar(20),
	provincia char(2),
	anni tinyint,
	sesso char(1),
	primary key(id)
);

create table libro(
	id integer unsigned auto_increment,
	titolo varchar(30),
	genere varchar(15),
	prezzo float,
	anno char(4),
	id_autore integer unsigned,
	
	primary key(id),
	foreign key (id_autore) references autore(id)
)

-- Query 2
INSERT INTO autore(cognome, nome, provincia, anni, sesso)
VALUE('Pradella','Francesco','MN',39,'M');
INSERT INTO autore(cognome, nome, provincia, anni, sesso)
VALUE('Rossi','Alberto','VR',28,'M');
INSERT INTO autore(cognome, nome, provincia, anni, sesso)
VALUE('Verdi','Gina','TO',16,'F');

INSERT INTO libro(titolo, genere, prezzo, anno, id_autore)
VALUE('Prati verdi','Racconto',9.99, 2008, 1);
INSERT INTO libro(titolo, genere, prezzo, anno, id_autore)
VALUE('Margherite Impazzite','Racconto',19.99, 2018, 1);

INSERT INTO libro(titolo, genere, prezzo, anno, id_autore)
VALUE('Ali al vento','Romanzo',12.50, 2012, 3);
INSERT INTO libro(titolo, genere, prezzo, anno, id_autore)
VALUE('Rose di maggio','Storiografia',15.75, 2019, 3);

-- query 3: selezionare cognome, nome e provincia di tutti gli autori.
SELECT cognome, nome, provincia
FROM autore;

-- query 4: selezionare tutti gli autori maschi maggiorenni
SELECT *
FROM autore
WHERE sesso='M' AND anni>=18;

-- query 5: Selezionare tutti i libri di genere Racconto
SELECT *
FROM libro
WHERE genere='Racconto';

-- query 6: Inserire l'autore Verdi Giacomo della provincia di Napoli di 47 anni.
INSERT INTO autore(cognome, nome, provincia, anni, sesso)
VALUE('Verdi','Giacomo','NA',47,'M');

-- query 7: Selezionare tutti i libri pubblicati dopo il 2008 da autori minorenni.
SELECT libro.titolo, libro.genere, libro.prezzo
FROM libro, autore
WHERE autore.id=libro.id_autore AND autore.anni<18 AND libro.anno>2008

--query 8: Selezionare tutti i libri visualizzando inoltre cognome e nome dell'autore
SELECT libro.titolo, libro.genere, autore.cognome, autore.nome
FROM libro, autore
WHERE autore.id=libro.id_autore;

-- query 9: Selezionare tutti i libri con prezzo compreso tra 5.50 e 20.00
SELECT *
FROM libro
WHERE prezzo>=5.50 AND prezzo <=20.00

-- query 10: Calcolare il prezzo medio tra i prezzi di tutti i libri
SELECT AVG(prezzo)
FROM libro

