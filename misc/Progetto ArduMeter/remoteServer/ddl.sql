CREATE TABLE IF NOT EXISTS Temperatura(
    id integer auto_increment,
    datamisura date,
    ora varchar(8),
    temperatura float,
    umidita float,
    
    primary key(id)
) ENGINE=InnoDB;