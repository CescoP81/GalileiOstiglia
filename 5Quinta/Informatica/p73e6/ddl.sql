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

/*
   Aggiunto in un secondo momento la tabella rendita_annua permette di assegnare
   ad ogni immobile in ogni zona una specifica rendita (prezzo al mq) per un determinato
   anno. In questo modo possiamo comunicare anno per anno, ad un ipotetico cliente
   dell'agenzia quanto rendono i suoi immobili.
*/
create table p73e6_rendita_annua(
   id integer unsigned auto_increment,
   anno integer unsigned not null,
   prezzo_mq float,
   idZona integer unsigned,
   idTipologia integer unsigned,
   
   primary key (id),
   foreign key (idZona) references p73e6_zona(id),
   foreign key (idTipologia) references p73e6_tipologia(id)
)