CREATE TABLE volontario(
   id integer unsigned auto_increment,
   cognome varchar(20),
   nome varchar(20),

   primary key (id);
);

CREATE TABLE cane(
   id integer unsigned auto_increment,
   nome varchar(20),
   razza varchar(20),
   idVolontario integer unsigned,

   primary key(id),
   foreign key (idVolontario) references volontario(id)
)

CREATE TABLE attivita(
   id integer unsigned auto_increment,
   descrizione varchar(50),
   data date,
   esito boolean,
   idCane integer unsigned,

   primary key(id),
   foreign key (idCane) references cane(id)
)