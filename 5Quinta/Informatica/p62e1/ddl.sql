CREATE TABLE p62e1_Localita(
   Id integer unsigned auto_increment not null,
   cap char(5) not null,
   nome varchar(30) not null,
   prov char(2) not null,
   primary key(Id)
);

CREATE TABLE p62e1_Cliente(
   Id integer unsigned auto_increment not null,
   ragioneSociale varchar(30),
   indirizzo varchar(50) not null,
   numTelefono varchar(10) not null,
   partitaIva char(10),
   idAgente int,
   fido int,
   idLocalita int unsigned,
   primary key(Id),
   foreign key (idLocalita) references p62e1_Localita(Id)
);

