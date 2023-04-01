CREATE TABLE marca_automezzo (
    id integer unsigned auto_increment,
    descrizione varchar(50),
    primary key(id)
);

INSERT INTO marca_automezzo(descrizione) 
VALUES ('Fiat'), ('Scania'), ('Volvo'), ('Mercedes');

CREATE TABLE provincia (
    id integer unsigned auto_increment,
    descrizione varchar(50),
    sigla char(2),
    primary key(id)
);

INSERT INTO provincia(descrizione, sigla) 
VALUES ('Mantova', 'MN'), ('Verona', 'VR'), ('Milano', 'MI'), 
('Bologna', 'BO'), ('Parma', 'PR'), ('Rovigo', 'RO');

CREATE TABLE mezzo (
    id integer unsigned auto_increment,
    descrizione varchar(50),
    idMarca integer unsigned,
    targa char(7),
    primary key(id),
    foreign key(idMarca) references marca_automezzo (id)
);

INSERT INTO mezzo (descrizione, idMarca, targa)
VALUES ('Ducato', '1', 'AB123AB'), ('Doblò', '1', 'AB234AB'), 
('AS750', '2', 'CB443SZ'), ('GC350', '3', 'BD543DS');

CREATE TABLE citta (
    id integer unsigned auto_increment,
    nome varchar(50),
    idProvincia integer unsigned,
    primary key(id),
    foreign key(idProvincia) references provincia(id)
);

INSERT INTO citta(nome, idProvincia) 
VALUES ('Borgocarbonara', '1'), ('Ostiglia', '1'), ('Pescantina', '2'), 
('Legnago', '2'), ('Arese', '3'), ('Milano', '3'), ('Porretta Terme', '4'),
('Rosolina Mare', '6'), ('Parma', 'PR'), ('Castelnovo Bariano', '6');

CREATE TABLE trasporto (
    id integer auto_increment,
    descrizioneMerce varchar(50),
    quintali int,
    data date,
    idMezzo integer unsigned,
    idCittaMittente integer unsigned,
    idCittaDestinatario integer unsigned,
    primary key(id),
    foreign key(idMezzo) references mezzo(id),
    foreign key(idCittaMittente) references citta(id),
    foreign key(idCittaDestinatario) references citta(id)
);

INSERT INTO trasporto (descrizioneMerce, quintali, data, idMezzo, idCittaMittente, idCittaDestinatario)
VALUES ('Scampi surgelati', '5', '2023/03/10', '1', '26', '22'), ('Acqua minerale', '2', '2023/03/25', '3', '24', '27'),
('Pistoni', '3', '2023/04/05', '4', '23', '19'), ('Pellet', '4', '2023/01/17', '4', '22', '20');

