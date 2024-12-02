CREATE TABLE concessionaria(
    id integer unsigned auto_increment,
    marca varchar(20),
    modello varchar(15),
    nazionalita char(2),
    anno integer,
    kilometri integer unsigne,

    primary key(id)
);

INSERT INTO concessionaria(marca, modello, nazionalita, anno, kilometri)
VALUES  ('FIAT', 'Punto', 'IT', 2018, 15500),
        ('FIAT', 'Panda', 'IT', 2015, 25500),
        ('FIAT', 'Panda', 'IT', 2020, 5500),
        ('SKODA', 'Fabia', 'DE', 2019, 22000),
        ('SKODA', 'Rapid', 'FR', 2015, 123000),
        ('SEAT', 'Leon', 'IT', 2022, 10700),
        ('SEAT', 'Ibiza', 'SP', 2012, 187500),
        ('VOLKSWAGEN', 'Tiguan', 'IT', 2022, 40000),
        ('VOLKSWAGEN', 'Passat', 'IT', 2013, 250000),
        ('VOLKSWAGEN', 'T-Cross', 'DE', 2021, 43000),
        ('OPEL', 'Astra', 'IT', 2010, 400000),
        ('OPEL', 'Corsa', 'IT', 2014, 275000);