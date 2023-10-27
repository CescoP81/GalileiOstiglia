/*  Il file denominato DML.sql contiene la popolazione iniziale delle singole tabelle,
    le istruzioni quindi di INSERT INTO, e a seguire le eventuali query di testing che
    vengono sviluppate per testare la banca dati.
*/
INSERT INTO Uomo(nome, cognome, paese, anni)
VALUES('Gino', 'Rossi', 'Ostiglia', 37);

INSERT INTO Uomo(nome, cognome, paese, anni)
VALUES('Anna', 'Verdi', 'Revere', 27);

INSERT INTO Uomo(nome, cognome, paese, anni)
VALUES('Mario', 'Bianchi', 'Quistello', 55);

INSERT INTO Uomo(nome, cognome, paese, anni)
VALUES('Maria', 'Rossi', 'Ostiglia', 41);

INSERT INTO Uomo(nome, cognome, paese, anni)
VALUES('Mirko', 'Bonavoglia', 'Governolo', 18);

-- INSERIMENTO RECORD TABELLA DONNA
INSERT INTO Donna(nome, cognome, paese, anni)
VALUES('Maria', 'Rossi', 'Ostiglia', 47);

INSERT INTO Donna(nome, cognome, paese, anni)
VALUES('Gina', 'Verdi', 'Poggio Rusco', 27);

INSERT INTO Donna(nome, cognome, paese, anni)
VALUES('Luisa', 'Bianchi', 'Nuvolato', 45);

INSERT INTO Donna(nome, cognome, paese, anni)
VALUES('Maria', 'Rossi', 'Ostiglia', 41);

INSERT INTO Donna(nome, cognome, paese, anni)
VALUES('Alessandra', 'Bentivoglio', 'Governolo', 28);


/* non dovrebbe eseguirla perchè mancante il valore del cognome */
INSERT INTO Uomo(nome, paese, anni)
VALUES('Rosario', 'Nuvolato', 33);

/* ESEMPIO DI QUERY */

Q: Visualizzare tutti i record con tutti i campi presenti nella tabella
SELECT *
FROM Uomo;

Q: Visualizza tutti i record con tutti i campi di uomini con cognome Rossi
SELECT *
FROM Uomo
WHERE cognome='Rossi';

Q: Visualizzare nome, paese e anni degli uomini con cognome 'Rossi'
SELECT nome, paese, anni
FROM Uomo
WHERE cognome='Rossi'

Q: Visualizzare tutti gli uomini presenti con tutti i campi, ordinandoli per cognome in ordine crescente.
SELECT *
FROM Uomo
ORDER BY cognome ASC;
/*  ASC -> ASCending -> Crescente [0->..; a->z; A->Z]
    DESC -> DESCending -> Decrescente [..->0; z->a; Z->A]
    */

Q: VIsualizzare tutti i campi di tutti gli uomini presenti con cognome Rossi ordinati per nome.
SELECT *
FROM Uomo
WHERE cognome='Rossi'
ORDER BY nome ASC;