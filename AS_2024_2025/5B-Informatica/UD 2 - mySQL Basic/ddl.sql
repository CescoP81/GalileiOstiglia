-- Questo file con linguaggio mySQL contiene SOLO
-- la definizione delle tabelle (cioè come si chiamano e quali campi sono presenti)

CREATE TABLE Artisti(
    id integer unsigned auto_increment,
    nome varchar(20) not null,
    cognome varchar(20) not null,
    nazione char(2),

    primary key(id)
)