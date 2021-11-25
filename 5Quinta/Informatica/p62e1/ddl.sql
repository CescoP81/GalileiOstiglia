CREATE TABLE p62e1_Localita(
   Id integer unsigned auto_increment not null,
   Cap char(5) not null,
   Nome varchar(30) not null,
   Prov char(2) not null,
   primary key(Id)
);

CREATE TABLE p62e1_Cliente(
   Id integer unsigned auto_increment not null,
   indirizzo varchar(50) not null,
   numTelefono varchar(10) not null,
   PartitaIva char(10),
   idAgente int,
   Fido int,
   idLocalita int unsigned,
   primary key(Id),
   foreign key (idLocalita) references p62e1_Localita(Id)
);

