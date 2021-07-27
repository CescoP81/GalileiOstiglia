<?php
/*  Pagina di gestione tabella docente
    Scelta:
        default: non visualizzo nulla.
        showDocente: visualizza tutti i docenti della tabella.
        formDocente: Visualizza il form per inserimento nuovo docente.
        addDocente: Inserisce i dati del form nella tabella come nuovo record.
        deleteDocente: Cancella un record specifico dalla tabella docente.
*/
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

    // creo il menu operativo della pagina.
    echo("<a href=\"docente.php\">Home</a> | ");
    echo("<a href=\"docente.php?scelta=showDocente\">Visualizza Docenti</a> | ");
    echo("<a href=\"docente.php?scelta=formDocente\">Nuovo Docente</a> ");
    echo("<br /><br />");

    switch($sc){
        case "showDocente":{
            $db = new mysqli("localhost","root","","scuola2021");
            $sql = "SELECT * FROM docente";

            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            while($record){
                echo($record['id']." ".$record['cognome']." ".$record['nome']." | ");
                echo("<a href=\"docente.php?scelta=deleteDocente&idDocente=".$record['id']."\">Canc.</a>");
                echo("<br />");
                $record = $resultSet->fetch_assoc();
            }
            $db->close();
            break;
        }
        case "formDocente":{
            // visualizza il form per inserimento dati da utente.
            echo("<form action=\"docente.php\" method=\"get\">");
                echo("Cognome:<br /><input type=\"text\" name=\"cognome\"><br/>");
                echo("Nome:<br /><input type=\"text\" name=\"nome\"><br />");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"addDocente\">");
                echo("<input type=\"submit\" value=\"Aggiungi Docente\">");
            echo("</form>");
            break;
        }
        case "addDocente":{
            // inserimento di un docente nel database.
            $cognome = $_REQUEST['cognome'];
            $nome = $_REQUEST['nome'];

            $sql = "INSERT INTO docente(cognome,nome) VALUES('$cognome','$nome')";

            $db = new mysqli("localhost","root","","scuola2021");
            if($db->query($sql)) echo("Inserimento docente avvenuto.");
            else echo("Problema in inserimento.");

            $db->close();
            break;
        }
        case "deleteDocente":{
            $idDocente = $_REQUEST['idDocente'];

            $db = new mysqli("localhost","root","","scuola2021");
            $sql = "DELETE FROM docente WHERE id=".$idDocente;

            if($db->query($sql)) echo("Cancellazione avvenuta.");
            else echo("Problema in cancellazione.");

            $db->close();
            break;
        }
        default:{
            echo("Nessuna scelta effettuata...");
            break;
        }
    }
?>