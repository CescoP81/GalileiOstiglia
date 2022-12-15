CREATE TABLE MS_MISURE(
    id integer unsigned auto_increment,
    dataMisura date
    tempoMisura time
    temperatura float,
    umidita float,
    luminosita float,
    
    primary key(id)
)