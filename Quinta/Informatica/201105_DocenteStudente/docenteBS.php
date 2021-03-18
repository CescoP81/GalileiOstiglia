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

include("head.html");
    // creo il menu operativo della pagina.
    // utilizzo il blocco nav di base come specificato nella documentation.
    echo("<nav class=\"nav\">");
        echo("<a class=\"nav-link\" href=\"docente.php\">Home</a>");
        echo("<a class=\"nav-link\" href=\"docente.php?scelta=showDocente\">Visualizza Docenti</a> ");
        echo("<a class=\"nav-link\" href=\"docente.php?scelta=formDocente\">Nuovo Docente</a>");
    echo("</nav>");
    echo("<br />");

    switch($sc){
        case "showDocente":{
            $db = new mysqli("localhost","root","","scuola2021");
            $sql = "SELECT * FROM docente";

            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            echo("<table class=\"table table-hover\">");
                echo("<caption>Lista dei Docenti</caption>");
                echo("<thead  class=\"thead-dark\">");
                    echo("<tr>");
                        echo("<th scope=\"col\">Id</th>");
                        echo("<th scope=\"col\">Cognome</th>");
                        echo("<th scope=\"col\">Nome</th>");
                        echo("<th scope=\"col\">Options</th>");
                    echo("</tr>");
                echo("</thead>");
                echo("<tbody>");
                while($record){
                    echo("<tr>");
                        echo("<td scope=\"row\">".$record['id']."</td>");
                        echo("<td>".$record['cognome']."</td>");
                        echo("<td>".$record['nome']."</td>");
                        echo("<td><a href=\"docente.php?scelta=deleteDocente&idDocente=".$record['id']."\">Canc.</a></td>");
                    echo("</tr>");
                    $record = $resultSet->fetch_assoc();
                }
                echo("</tbody>");
            echo("</table>");
            $db->close();
            break;
        }
        case "formDocente":{
            // visualizza il form per inserimento dati da utente.
            echo("<form action=\"docente.php\" method=\"get\">");
                echo("<div class=\"form-group\">");
                echo("<label for=\"inputCognome\">Cognome:</label><input class=\"form-control form-control-sm\" type=\"text\" name=\"cognome\" id=\"inputCognome\"><br/>");
                echo("<label for=\"inputNome\">Nome:</label><input class=\"form-control form-control-sm\" type=\"text\" name=\"nome\" id=\"inputNome\"><br />");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"addDocente\">");
                echo("<input type=\"submit\" class=\"btn btn-secondary\" value=\"Aggiungi Docente\">");
            echo("</form>");
            break;
        }
        case "addDocente":{
            // inserimento di un docente nel database.
            $cognome = $_REQUEST['cognome'];
            $nome = $_REQUEST['nome'];

            $sql = "INSERT INTO docente(cognome,nome) VALUES('$cognome','$nome')";

            $db = new mysqli("localhost","root","","scuola2021");
            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Inserimento docente avvenuto.</div>");
            else
                echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in inserimento.</div>");

            $db->close();
            break;
        }
        case "deleteDocente":{
            $idDocente = $_REQUEST['idDocente'];

            $db = new mysqli("localhost","root","","scuola2021");
            $sql = "DELETE FROM docente WHERE id=".$idDocente;

            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Cancellazione avvenuta.</div>");
            else
                echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in cancellazione.</div>");

            $db->close();
            break;
        }
        default:{
            echo("<div class=\"alert alert-info\" role=\"alert\">Nessuna scelta effettuata...</div>");
            break;
        }
    }
include("foot.html");
?>