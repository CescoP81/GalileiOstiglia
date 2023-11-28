CREATE TABLE MarcaAutomobile(
    id integer unsigned auto_increment,
    nome varchar(20),
    nazionalita char(2),
    sitoWeb varchar(200),

    primary key(id)
)

CREATE TABLE ModelloAutomobile(
    id integer unsigned auto_increment,
    nome varchar(20),
    annoProduzione char(4),
    cilindrata char(3),
    idMarcaAutomobile integer unsigned,

    primary key(id),
    foreign key(idMarcaAutomobile) references MarcaAutomobile(id)
)