<?php
    // a ggancio al database su cui risiedono le tabelle
    $db = new mysqli("localhost","root","","scuola2021");

    // preparo la stringa SQL da eseguire (può essere SELECT o INSERT o altro)
    $sql = "SELECT * FROM docente";

    //$sql = "SELECT docente.nome, studente.nome FROM docente, studente WHERE docente.id=studente.id_docente";

    // eseguo una request al motore sql tramite interfaccia php.
    $resultSet = $db->query($sql);

    // scompongo tutti i risultati ottenuto in singoli record,
    // per ogni record ho come indici i nomi delle colonne della tabella.
    // USO UN WHILE perchè non conosco a priori il numero di record estratti.
    $record = $resultSet->fetch_assoc();
    while($record){
        echo($record['id']." ".$record['cognome']." ".$record['nome']."<br />");
        $record = $resultSet->fetch_assoc();
    }
    echo("<br><br>");

    // visualizzo i risultati della query con una tabella.
    $resultSet = $db->query($sql);
    $record = $resultSet->fetch_assoc();
    echo("<table border=\"1\">");
        echo("<thead>");
            echo("<th>ID</th><th>Cognome</th><th>Nome</th>");
        echo("</thead>");
        while($record){
            echo("<tr>");
                echo("<td>".$record['id']."</td><td>".$record['cognome']."</td><td>".$record['nome']."</td>");
            echo("</tr>");
            $record = $resultSet->fetch_assoc();
        }
    echo("</table>");

    echo("<br><br>");

    // visualizzo i risultati della query con una tabella.
    $sql = "SELECT studente.id AS StudenteID, studente.nome, studente.cognome FROM studente";
    $resultSet = $db->query($sql);
    $record = $resultSet->fetch_assoc();
    echo("<table border=\"1\">");
        echo("<thead>");
            echo("<th>ID</th><th>Cognome</th><th>Nome</th>");
        echo("</thead>");
        while($record){
            echo("<tr>");
                echo("<td>".$record['StudenteID']."</td><td>".$record['cognome']."</td><td>".$record['nome']."</td>");
            echo("</tr>");
            $record = $resultSet->fetch_assoc();
        }
    echo("</table>");
    // chiudo lo stream al database.
    $db->close();
?>