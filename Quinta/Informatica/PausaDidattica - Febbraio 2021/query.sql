create table padre(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    primary key(id)
);

create table madre(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    primary key (id)
)

create table figlio(
    id integer unsigned auto_increment,
    nome varchar(20),
    id_padre integer unsigned,
    id_madre integer unsigned nut null,

    primary key(id),
    foreign key (id_padre) references padre(id),
    foreign key (id_madre) references madre(id)
);

insert into padre(cognome, nome) values("Rossi", "Gino");
insert into padre(cognome, nome) values("Bianchi", "Giorgio");

insert into madre (cognome, nome) VALUES ('Rossi','Gina');
insert into madre (cognome, nome) VALUES ('Verdi','Rosa');
insert into madre (cognome, nome) VALUES ('Bianchi','Luana');

insert into figlio(nome, id_padre, id_madre) values("Graziano", 2, 1);
insert into figlio(nome, id_padre, id_madre) values("Luca", 1, 2);
insert into figlio(nome, id_padre, id_madre) values("Annalisa", 1, 3);

q1. Selezionare tutti i padri presenti
SELECT cognome,nome FROM padre;

q2. Selezionare tutti i figli
select * from figlio;

q3. Selezionare tutti i figli e relativi cognomi.
SELECT f.nome, p.cognome
FROM figlio as f, padre as p
WHERE f.id_padre=p.id;

q4 Selezionare nome del figlio e cognome nome del padre
SELECT f.nome AS Figlio, p.nome AS Padre, p.cognome
FROM figlio AS f, padre AS p 
WHERE f.id_padre = p.id;

/* 25.02.2021 Proseguo Pausa Didattica */
create table donna(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    primary key (id)
)

insert into madre (cognome, nome) VALUES ('Rossi','Gina');
insert into madre (cognome, nome) VALUES ('Verdi','Rosa');
insert into madre (cognome, nome) VALUES ('Bianchi','Luana');

create table madre_di(
    id integer unsigned auto_increment,
    id_figlio integer unsigned,
    id_madre integer unsigned nut null,

    primary key(id),
    foreign key (id_figlio) references figlio(id),
    foreign key (id_madre) references donna(id)
);

INSERT INTO madre_di(id_figlio, id_madre) VALUES(1,1);
INSERT INTO madre_di(id_madre) VALUES(1);

/* QUERY POSSIBILI */
Selezionare Per ogni madre il nome del figlio ed i dati del padre
SELECT madre.cognome, madre.nome, figlio.nome, padre.cognome, padre.nome
FROM madre, padre, figlio
WHERE padre.id=figlio.id_padre AND figlio.id_madre=madre.id

SELECT m.cognome AS 'Cognome Madre', m.nome AS 'Nome Madre', f.nome AS 'Figlio', p.cognome AS 'Cognome Padre', p.nome AS 'Nome Padre'
FROM madre AS m, padre AS p, figlio AS f
WHERE p.id=f.id_padre AND f.id_madre=m.id
ORDER BY p.cognome, f.nome DESC