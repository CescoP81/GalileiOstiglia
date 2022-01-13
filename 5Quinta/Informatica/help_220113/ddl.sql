CREATE TABLE libri(
   id integer unsigned auto_increment,
   titolo varchar(50) not null,
   autore varchar(30) not null,
   prezzo float,

   primary key(id)
);

INSERT INTO libri(titolo, autore, prezzo) 
VALUES("L'isola perduta", "Erminio Rossi", 13.99);

INSERT INTO libri(titolo, autore, prezzo) 
VALUES("Fantasmi e spettri", "Anna Riciclo", 15.89);

INSERT INTO libri(titolo, autore, prezzo) 
VALUES("Pandemia", "Roberto Bianchi", 25.99);

INSERT INTO libri(titolo, autore, prezzo) 
VALUES("Trabocchetti e giochetti", null, 13.89);

-- QUERY DI ESEMPIO --
-- vedere tutti i libri ordinati per titolo
SELECT * 
FROM libri 
ORDER BY titolo ASC;

-- vedere tutti i libri ordinati per prezzo decrescente
SELECT *
FROM libri
ORDER BY prezzo DESC;

-- vedere titoli e prezzi dei libri ordinati per titolo
SELECT titolo, prezzo
FROM libri
ORDER BY titolo ASC;

-- vedere titolo e autore dei libri che hanno prezzo >= 15.00
SELECT titolo, autore
FROM libri
WHERE prezzo>=15.00
ORDER BY titolo ASC;