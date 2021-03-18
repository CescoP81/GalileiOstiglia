CREATE TABLE dipendente(
    id integer unsigned auto_increment,
    cognome varchar(20),
    nome varchar(20),
    primary key(id)
);

CREATE TABLE stipendio(
    id integer unsigned auto_increment,
    data_accredito date,
    cifra float,
    id_dipendente integer unsigned,

    primary key(id),
    foreign key (id_dipendente) references dipendente(id)
);

INSERT INTO dipendente (cognome, nome) VALUES('Bianchi', 'Franco');
INSERT INTO dipendente (cognome, nome) VALUES('Rossi', 'Giacomo');
INSERT INTO dipendente (cognome, nome) VALUES('Verdi', 'Annalisa');

INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/01/23', 1250.00, 1);
INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/02/23', 1250.00, 1);
INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/03/23', 1250.00, 1);

INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/01/23', 1500.00, 2);
INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/02/23', 1500.00, 2);

INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/01/23', 850.00, 3);
INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/02/23', 850.00, 3);
INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/03/23', 900.00, 3);
INSERT INTO stipendio (data_accredito, cifra, id_dipendente)
VALUES('2021/04/23', 925.00, 3);

SELECT SUM(cifra) AS Totale FROM stipendio WHERE id_dipendente=1

Q: Visualizzare Cognome, Nome e il totale stipendi di ogni singolo dipendente.
SELECT d.cognome, d.nome, SUM(s.cifra) AS totale 
FROM dipendente AS d, stipendio AS s 
WHERE s.id_dipendente=d.id
GROUP BY d.id HAVING totale >=3500
ORDER BY totale DESC

/* PASSO IN PHP */
$sql = "SELECT * FROM dipendente ORDER BY id";
$resultSet = $db->query($sql);
$record = $resultSet->fetch_assoc();
while($record){
    echo($record['id']." ".$record['cognome']." ".$record['nome']."<br />");

    $sql = "SELECT SUM(s.cifra) AS totale FROM stipendio AS s WHERE s.id_dipendente='$record['id']";
    $resultSet2 = $db->query($sql);
    $record2 = $resultSet2->fetch_assoc();
    echo("Totale Stipendi: ".$record2['totale']);

    $record = $resultSet->fetch_assoc();
}
