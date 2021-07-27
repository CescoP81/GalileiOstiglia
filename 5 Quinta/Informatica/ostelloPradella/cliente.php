<?php
/*  Pagina di gestione tabella docente
 Scelta:
 default: non visualizzo nulla.
 showCliente: visualizza tutti i clienti della tabella.
 formCliente: Visualizza il form per inserimento nuovo cliente.
 addCliente: Inserisce i dati del form nella tabella come nuovo record.
 deleteCliente: Cancella un record specifico dalla tabella ostello_cliente.
 */
session_start();
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

require('library.php');
include("../head.html");
//Richiamo la funzione menuOperativo() presente nel file library.php
if($_SESSION['autenticato'] == true){
    menuOperativo();
    switch($sc){
        case "showCliente":{
            $db = new mysqli("localhost","root","","scuola2021");
            $sql = "SELECT * FROM ostello_cliente";

            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            echo("<table class=\"table table-hover\">");
            echo("<caption>Lista delle camere</caption>");
            echo("<thead  class=\"thead-dark\">");
            echo("<tr>");
            echo("<th scope=\"col\">Id</th>");
            echo("<th scope=\"col\">Cognome</th>");
            echo("<th scope=\"col\">nome</th>");
            echo("<th scope=\"col\">Data Nascita</th>");
            echo("<th scope=\"col\">email</th>");
            echo("<th scope=\"col\">telefono</th>");
            echo("<th scope=\"col\">stato</th>");
            echo("<th scope=\"col\">provincia</th>");
            //echo("<th scope=\"col\">Options</th>");
            echo("</tr>");
            echo("</thead>");
            echo("<tbody>");
            while($record){
                echo("<tr>");
                echo("<td scope=\"row\">".$record['id']."</td>");
                echo("<td>".$record['cognome']."</td>");
                echo("<td>".$record['nome']."</td>");
                echo("<td>".$record['data_nascita']."</td>");
                echo("<td>".$record['email']."</td>");
                echo("<td>".$record['telefono']."</td>");
                echo("<td>".$record['stato_provenienza']."</td>");
                echo("<td>".$record['provincia_provenienza']."</td>");
                //echo("<td><a href=\"camera.php?scelta=deleteCamera&idCamera=".$record['id']."\"><img src=\"../bsicons/trash.svg\" alt=\"\" width=\"24\" height=\"24\" title=\"Bootstrap\" /></a></td>");
                echo("</tr>");
                $record = $resultSet->fetch_assoc();
            }
            echo("</tbody>");
            echo("</table>");
            $db->close();
            break;
        }
        case "formCliente":{
            // visualizza il form per inserimento dati da utente.
            echo("<form action=\"cliente.php\" method=\"get\">");
                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputCognome\">Cognome:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"cognome\" id=\"inputCognome\">");
                echo("</div>");

                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputNome\">Nome:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"nome\" id=\"inputNome\">");
                echo("</div>");

                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputEmail\">Indirizzo e-mail</label>");
                    echo("<input type=\"email\" class=\"form-control\" id=\"inputEmail\" name=\"email\" aria-describedby=\"emailHelp\">");
                    echo("<small id=\"emailHelp\" class=\"form-text text-muted\">Ad uso esclusivo di registrazione.</small>");
                echo("</div>");

                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputTelefono\">Telefono:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"telefono\" id=\"inputTelefono\">");
                echo("</div>");

                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputStato\">Stato provenienza:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"stato\" id=\"inputStato\">");
                echo("</div>");

                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputProvincia\">Provincia provenienza:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"provincia\" id=\"inputProvincia\">");
                echo("</div>");

                echo("<div class=\"form-group\">");
                    echo("<label for=\"inputDataNascita\">Data di nascita:</label>");
                    echo("<input class=\"form-control form-control-sm\" type=\"text\" name=\"data_nascita\" id=\"inputDataNascita\" placeholder=\"aaaa/mm/gg\">");
                echo("</div>");

                echo("<input type=\"hidden\" name=\"scelta\" value=\"addCliente\">");
                echo("<input type=\"submit\" class=\"btn btn-secondary\" value=\"Registra Cliente\">");
            echo("</form>");
            break;
        }
        case "addCliente":{
            // inserimento di una camera nel database.
            $cognome = $_REQUEST['cognome'];
            $nome = $_REQUEST['nome'];
            $email = $_REQUEST['email'];
            $telefono = $_REQUEST['telefono'];
            $stato = $_REQUEST['stato'];
            $provincia = $_REQUEST['provincia'];
            $data_nascita = $_REQUEST['data_nascita'];

            $sql = "INSERT INTO ostello_cliente(cognome, nome, email, telefono, stato_provenienza, provincia_provenienza, data_nascita) ";
            $sql .="VALUES('$cognome', '$nome', '$email', '$telefono', '$stato', '$provincia', '$data_nascita')";

            echo($sql."<br />");
            $db = new mysqli("localhost","root","","scuola2021");
            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Inserimento cliente avvenuto.</div>");
            else
                echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in inserimento.</div>");

            $db->close();
            break;
        }
        case "deleteCamera":{
            /*$idCamera = $_REQUEST['idCamera'];

            $db = new mysqli("localhost","root","","scuola2021");
            $sql = "DELETE FROM ostello_camera WHERE id=".$idCamera;

            if($db->query($sql))
                echo("<div class=\"alert alert-success\" role=\"aler\">Cancellazione avvenuta.</div>");
            else
                echo("<div class=\"alert alert-warning\" role=\"alert\">Problema in cancellazione.</div>");

            $db->close();
            //*/
            break;
        }
        default:{
            echo("<div class=\"alert alert-info\" role=\"alert\">Nessuna scelta effettuata...</div>");
            break;
        }
    }
}
else{
    echo("Utente Non Riconosciuto, eseguire il login<br />");
    echo("<a href=\"index.php\">Torna alla Home Page</a>");
}
include("../foot.html");
?>