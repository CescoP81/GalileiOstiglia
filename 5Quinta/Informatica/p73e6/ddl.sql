/* tabelle di base */
create table p73e6_proprietario(
   id integer unsigned auto_increment,
   cognome varchar(20) not null,
   nome varchar(20) not null,
   via varchar(30),
   civico tinyint,
   citta varchar(30),
   telefono varchar(15),
   mail varchar(255) not null,

   primary key(id)
);

create table p73e6_zona(
   id integer unsigned auto_increment,
   nome varchar(20),
   primary key(id)
);

create table p73e6_tipologia(
   id integer unsigned auto_increment,
   nome varchar(20),
   primary key(id)
);

/* tabella degli immobili, dipende da Zona e Tipologia con le relative FK.*/
create table p73e6_immobile(
   id integer unsigned auto_increment,
   nome varchar(20),
   via varchar(30),
   civico tinyint,
   metratura integer,
   piano tinyint,
   locali tinyint,
   idZona integer unsigned,
   idTipologia integer unsigned,

   primary key(id),
   foreign key (idZona) references p73e6_zona(id),
   foreign key (idTipologia) references p73e6_tipologia(id)
)

/* tabella che associa immobile a proprietario,
   dipende da Proprietario e Immobile con le relative FK*/
create table p73e6_possiede(
   id integer unsigned auto_increment,
   data_acquisto date,
   idProprietario integer unsigned,
   idImmobile integer unsigned,

   primary key(id),
   foreign key (idProprietario) references p73e6_proprietario(id),
   foreign key (idImmobile) references p73e6_immobile(id)
)