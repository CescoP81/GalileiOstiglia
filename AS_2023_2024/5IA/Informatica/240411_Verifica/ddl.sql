CREATE TABLE Citta(
    id integer unsigned auto_increment,
    nome varchar(15) not null,
    provincia char(2) not null,
    primary key(id)
)ENGINE=InnoDB;

CREATE TABLE Museo(
    id integer unsigned auto_increment,
    nome varchar(20) not null,
    telefono varchar(10) not null,
    email varchar(60) not null,
    idCitta integer unsigned,
    primary key(id),
    foreign key(idCitta) references Citta(id)
)ENGINE=InnoDB;

INSERT INTO Citta(nome, provincia) VALUES('Verona', 'VR');
INSERT INTO Citta(nome, provincia) VALUES('Rovigo', 'RO');
INSERT INTO Citta(nome, provincia) VALUES('Mantova', 'MN');
INSERT INTO Citta(nome, provincia) VALUES('Padova', 'PD');
INSERT INTO Citta(nome, provincia) VALUES('Trento', 'TN');