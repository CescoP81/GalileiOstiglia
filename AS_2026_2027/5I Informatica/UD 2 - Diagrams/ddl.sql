CREATE TABLE IF NOT EXISTS autovettura(
    id integer unsigned auto_increment,
    marca varchar(20),
    modello varchar(20),
    annoImmatricolazione char(4),
    provincia char(2),
    uniproprietario boolean,
    kilometraggio integer unsigned,

    primary key(id)
);