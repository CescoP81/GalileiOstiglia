-- Contiene le INSERT iniziali per popolare il database e poter
-- eseguire alcune query di controllo.

INSERT INTO Artista(nome, cognome, nazione)
VALUES('Riccardo', 'Cocciante', 'IT');

INSERT INTO Artista(nome, cognome, nazione)
VALUES('Laura', 'Pausini', 'IT');

INSERT INTO Artista(nome, cognome, nazione)
VALUES('David', 'Bowie', 'UK');

-- inserimento righe iniziali nella tabella brani

INSERT INTO Brano(titolo, anno, genere, idArtista)
VALUES('Canzone 1', 2007, 'Pop', 1);
INSERT INTO Brano(titolo, anno, genere, idArtista)
VALUES('Canzone 2', 2010, 'Pop', 1);
INSERT INTO Brano(titolo, anno, genere, idArtista)
VALUES('Canzone 3', 2023, 'Pop', 1);

INSERT INTO Brano(titolo, anno, genere, idArtista)
VALUES('Canzone 4', 2011, 'Rock', 3);
INSERT INTO Brano(titolo, anno, genere, idArtista)
VALUES('Canzone 5', 2020, 'Rock', 3);

-- Questa query non rispettando l'integrità referenziale non viene inserita a DB.
-- INSERT INTO Brano(titolo, anno, genere, idArtista)
-- VALUES('Canzone 6', 2020, 'Rock', 5);