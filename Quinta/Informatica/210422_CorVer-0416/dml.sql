-- POPOLAMENTO INIZIALE DELLE TABELLE DEL DATABASE.
---------------------------------------------------

INSERT INTO v_autore (cognome, nome, anno_nascita) VALUES('Calvino', 'Italo', 1934);
INSERT INTO v_autore (cognome, nome, anno_nascita) VALUES('King', 'Stephen', 1954);
INSERT INTO v_autore (cognome, nome, anno_nascita) VALUES('Brown', 'Dan', 1966);

INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(1, 'Il sentiero dei nidi di ragno', 180, 12.50);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(2, 'Misery non deve morire', 380, 22.00);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(2, 'IT', 523, 18.00);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(3, 'Il Codice Da Vinci', 364, 25.50);
INSERT INTO v_libro(id_autore, titolo, n_pagine, prezzo) VALUES(3, 'Inferno', 487, 20.50);

INSERT INTO v_lettore(cognome_nome, mail) VALUES('Rossi Giorgio', 'giorgior@gmail.com');
INSERT INTO v_lettore(cognome_nome, mail) VALUES('Bianchi Sara', 'sarab@gmail.com');
INSERT INTO v_lettore(cognome_nome, mail) VALUES('Verdi Rita', '');

INSERT INTO v_libreria(nome, indirizzo) VALUES('Il Temperino', 'Quistello');
INSERT INTO v_libreria(nome, indirizzo) VALUES('Il Nautilus', 'Mantova');
INSERT INTO v_libreria(nome, indirizzo) VALUES('La Rizzoli', 'Bologna');

INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2020/04/20', 1, 1, 1);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2020/05/22', 2, 3, 2);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2021/03/15', 3, 2, 3);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2021/04/16', 3, 1, 1);
INSERT INTO v_vendita(data_vendita, id_lettore, id_libro, id_libreria) 
VALUES('2015/12/23', 1, 3, 3);