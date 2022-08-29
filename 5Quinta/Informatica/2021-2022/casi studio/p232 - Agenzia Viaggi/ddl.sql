/* DDL dell'esercizio di pagina 232 "Agenzia di viaggi".
*/
create table p232_organizzazione(
   cod integer unsigned auto_increment,
   nome varchar(30),
   telefono varchar(10),

   primary key(cod)
);

create table p232_nazione(
   cod integer unsigned auto_increment,
   denominazione varchar(30),
   documenti varchar(15),
   clima varchar(15),

   primary key(cod)
);

create table p232_cliente(
   cod integer unsigned auto_increment,
   cognome varchar(20),
   nome varchar(20),
   indirizzo varchar(30),
   telefono varchar(10),

   primary key(cod)
);

create table p232_pacchetto(
   cod integer unsigned auto_increment,
   descrizione varchar(30),
   modalita varchar(15),
   prezzo float,

   codOrganizzazione integer unsigned not null,
   codNazione integer unsigned not null,

   primary key(cod),
   foreign key (codOrganizzazione) references p232_organizzazione(cod),
   foreign key (codNazione) references p232_nazione(cod)
);

create table p232_acquisto(
   cod integer unsigned auto_increment,
   codPacchetto integer unsigned not null,
   codCliente integer unsigned not null,
   dataAcquisto date,

   primary key(cod),
   foreign key(codPacchetto) references p232_pacchetto(cod),
   foreign key(codCliente) references p232_cliente(cod)
);