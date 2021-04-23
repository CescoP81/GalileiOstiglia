CREATE TABLE v_autore(
    id integer unsigned auto_increment,
    cognome varchar(30) not null,
    nome varchar(30) not null,
    anno_nascita char(4),
    
    primary key(id)
);

INSERT INTO v_autore (cognome, nome, anno_nascita) VALUES('Calvino', 'Italo', 1934);
INSERT INTO v_autore (cognome, nome, anno_nascita) VALUES('King', 'Stephen', 1954);
INSERT INTO v_autore (cognome, nome, anno_nascita) VALUES('Brown', 'Dan', 1966);

-- ###########################
CREATE TABLE v_libro(
    id integer unsigned auto_increment,
    id_autore integer unsigned,
    titolo varchar(20) not null,
    n_pagine integer,
    prezzo float,

    primary key(id),
    foreign key (id_autore) references v_autore(id)
);

INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(1, 'Il sentiero dei nidi di ragno', 180, 12.50);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(2, 'Misery non deve morire', 380, 22.00);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(2, 'IT', 523, 18.00);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(3, 'Il Codice Da Vinci', 364, 25.50);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(3, 'Inferno', 487, 20.50);

-- ###########################
CREATE TABLE v_lettore(
    id integer unsigned auto_increment,
    cognome_nome varchar(50) not null,
    mail varchar(50),

    primary key(id)
);

INSERT INTO v_lettore(cognome_nome, mail) VALUES('Rossi Giorgio', 'giorgior@gmail.com');
INSERT INTO v_lettore(cognome_nome, mail) VALUES('Bianchi Sara', 'sarab@gmail.com');
INSERT INTO v_lettore(cognome_nome, mail) VALUES('Verdi Rita', '');

-- ###########################
CREATE TABLE v_libreria(
    id integer unsigned auto_increment,
    nome varchar(30) not null,
    indirizzo varchar(50),

    primary key(id)
);

INSERT INTO v_libreria(nome, indirizzo) VALUES('Il Temperino', 'Quistello');
INSERT INTO v_libreria(nome, indirizzo) VALUES('Il Nautilus', 'Mantova');
INSERT INTO v_libreria(nome, indirizzo) VALUES('La Rizzoli', 'Bologna');

-- ###########################
CREATE TABLE v_vendita(
    id integer unsigned auto_increment,
    data_vendita date,
    id_lettore integer unsigned,
    id_libro integer unsigned,
    id_libreria integer unsigned,

    primary key(id),
    foreign key (id_lettore) references v_lettore(id),
    foreign key (id_libro) references v_libro(id),
    foreign key (id_libreria) references v_libreria(id)
);

INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2020/04/20', 1, 1, 1);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2020/05/22', 2, 3, 2);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2021/03/15', 3, 2, 3);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2021/04/16', 3, 1, 1);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2015/12/23', 1, 3, 3);