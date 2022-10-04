-- codice sql per la creazione della prima tabella.

CREATE TABLE studenti(
    id INTEGER UNSIGNED AUTO_INCREMENT,
    nome VARCHAR(20),
    cognome VARCHAR(20),
    classe VARCHAR(3),

    PRIMARY KEY(id)
);

-- codice per inserire uno studente nella tabella creata
INSERT INTO studenti(nome, cognome, classe)
VALUES('Francesco', 'Pradella', '5I');

INSERT INTO studenti(nome, cognome, classe)
VALUES('Piero', 'Marcheselli', '5I');

INSERT INTO studenti(nome, cognome, classe)
VALUES('Denny', 'Pirani', '5I');

-- codice per eliminare un record
DELETE FROM studenti WHERE id=2;

-- codice per mostrare tutte le righe (interrogare un database)
SELECT * 
FROM studenti;

SELECT nome, cognome 
FROM studenti;

