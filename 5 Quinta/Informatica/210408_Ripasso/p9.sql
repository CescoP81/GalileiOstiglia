CREATE TABLE p9_cliente(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    residenza varchar(20),
    paese varchar(20),
    cap varchar(8),
    provincia varchar(2),
    primary key(id)
);

INSERT INTO p9_cliente(cognome, nome, residenza, paese, cap, provincia)
VALUE('Rossi','Armando','via Gigli, 18', 'Serravalle', '46035', 'MN');

CREATE TABLE p9_ordine(
    id integer unsigned auto_increment,
    descrizione varchar(200),
    prezzo float,
    id_cliente integer unsigned,

    primary key(id),
    foreign key (id_cliente) references p9_cliente(id)
);

INSERT INTO p9_ordine(descrizione, prezzo, id_cliente)
VALUES ('Pomodori ciliegini', 12.50, 1);
INSERT INTO p9_ordine(descrizione, prezzo, id_cliente)
VALUES ('Banane', 8.00, 1);
INSERT INTO p9_ordine(descrizione, prezzo, id_cliente)
VALUES ('Kinder Fetta al latte', 20.50, 1);