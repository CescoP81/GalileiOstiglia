/* Codice SQL relativo alla banca dati dell'esercizio "Le attività sportive studentesche" proposto
a pagina 229 del libro di testo.
*/

create table p229_istituto(
   cod integer unsigned auto_increment,
   denominazione varchar(30),
   indirizzo varchar(30),
   telefono varchar(10),

   primary key(cod)
);

create table p229_studente(
   cod integer unsigned auto_increment,
   cognome varchar(20),
   nome varchar(20),
   dataNascita date,
   classe varchar(3),
   codIstituto integer unsigned,

   primary key(cod),
   foreign key(codIstituto) references p229_istituto(cod)
);

create table p229_manifestazione(
   cod integer unsigned auto_increment,
   descrizione varchar(50),
   luogo varchar(30),
   dataInizio date,
   primary key(cod)
);


create table p229_professore(
   cod integer unsigned auto_increment,
   cognome varchar(20),
   nome varchar(20),
   codIstituto integer unsigned,
   codManifestazione integer unsigned,

   primary key(cod),
   foreign key(codIstituto) references p229_istituto(cod),
   foreign key(codManifestazione) references p229_manifestazione(cod)
);

create table p229_partecipa(
   cod integer unsigned auto_increment,
   codStudente integer unsigned,
   codManifestazione integer unsigned,
   dataIscrizione date,

   primary key(cod),
   foreign key(codStudente) references p229_studente(cod),
   foreign key(codManifestazione) references p229_manifestazione(cod),
   unique(codStudente, codManifestazione)
) 