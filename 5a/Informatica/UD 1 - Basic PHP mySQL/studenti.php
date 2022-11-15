<?php
/* Questa pagina PHP esegue le seguenti operazioni sulla tabella 'studenti' creata
    con il codice SQL presente nel file p01.sql
    - Visualizzazione della tabella con formattazione Bootstrap
    - Visualizzazione del form per l'inserimento di un nuovo studente(record)
    - Aggiunta del nuovo record alla tabella 'studenti'

    Richiede:
        - File head.html e foot.html
        - File mylib.php posto nella sottocartella 'required'.
*/
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
    else $sc = null;
    require("include/mylib.php");
    require("../head.html");
    
    //echo("<a href=\"studenti.php?scelta=formStudente\">Nuovo Studente</a> ");
    //echo("<a href=\"studenti.php?scelta=showStudenti\">Visualizza studenti</a>");
    //echo("<br /><br />");

    echo("<nav class=\"navbar navbar-expand-lg bg-light\">
        <div class=\"container-fluid\">
            <!--<a class=\"navbar-brand\" href=\"#\">Navbar</a>
            <button class=\"navbar-toggler\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navbarNav\" aria-controls=\"navbarNav\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">
            <span class=\"navbar-toggler-icon\"></span>
            </button>-->
            <div class=\"collapse navbar-collapse\" id=\"navbarNav\">
                <ul class=\"navbar-nav\">
                    <li class=\"nav-item\">
                        <a class=\"nav-link active\" aria-current=\"page\" href=\"studenti.php?scelta=formStudente\">Nuovo Studente</a>
                    </li>
                    <li class=\"nav-item\">
                        <a class=\"nav-link active\" aria-current=\"page\" href=\"studenti.php?scelta=showStudenti\">Vedi Studenti</a>
                    </li>
                    <!--<li class=\"nav-item\">
                    <a class=\"nav-link\" href=\"#\">Pricing</a>
                    </li>
                    <li class=\"nav-item\">
                    <a class=\"nav-link disabled\">Disabled</a>
                    </li>-->
                </ul>
            </div>
        </div>
    </nav>");

    switch($sc){
        case "formStudente":{
            // per i componenti dei form, la guida è qui: https://getbootstrap.com/docs/5.2/forms/overview/
            //echo("DEVO MOSTRARE IL FORM PER I DATI DI UNO STUDENTE...");
            echo("<form action=\"studenti.php\">
                <div class=\"mb-3\">
                    <label for=\"exampleFormControlInput1\" class=\"form-label\">Cognome</label>
                    <input type=\"text\" name=\"cognomeS\" class=\"form-control\" id=\"exampleFormControlInput1\" placeholder=\"Cognome...\">
                </div>

                <div class=\"mb-3\">
                    <label for=\"exampleFormControlInput2\" class=\"form-label\">Nome</label>
                    <input type=\"text\" name=\"nomeS\" class=\"form-control\" id=\"exampleFormControlInput2\" placeholder=\"Nome...\">
                </div>

                <div class=\"mb-3\">
                    <label for=\"exampleFormControlInput3\" class=\"form-label\">Classe</label>
                    <input type=\"text\" name=\"classeS\" class=\"form-control\" id=\"exampleFormControlInput3\" placeholder=\"Classe...\">
                </div>

                <input type=\"hidden\" name=\"scelta\" value=\"addStudente\">
                <div class=\"col-auto\">
                    <button type=\"submit\" class=\"btn btn-primary mb-3\">Aggiungi Studente</button>
                </div>
            </form>");
            break;
        }
        case "addStudente":{
            echo("DEVO AGGIUNGERE UNO STUDENTE AL MIO DATABASE...");
            $nome = $_REQUEST['nomeS'];
            $cognome = $_REQUEST['cognomeS'];
            $classe = $_REQUEST['classeS'];

            $db = new mysqli("localhost","root","","scuola2223");
            $sql = "INSERT INTO studenti(nome, cognome, classe) 
                    VALUES('$nome','$cognome','$classe')";
            //echo($sql);
            if($db->query($sql))
                echo("<div class=\"alert alert-success\">Inserimento OK</div>");
            else
                echo("<div class=\"alert alert-danger\">Problemi in inserimento!</div>");
            $db->close();
            break;
        }
        case "showStudenti":{
            echo("DEVO MOSTRARE TUTTI GLI STUDENTI PRESENTI NELLA TABELLA SU DATABASE...");
            $db = new mysqli("localhost","root","","scuola2223");
            $sql = "SELECT * FROM studenti";
            $rs = $db->query($sql);
            $db->close();
            showResultSetTable($rs," tabella degli studenti", "studenti.php");
            break;
        }
        case "deleteStudente":{
            $idStudente = $_REQUEST['id_studente'];
            echo("Voglio cancellare lo studente con ID: ".$idStudente);
            $db = new mysqli("localhost","root","","scuola2223");
            $sql = "DELETE FROM studenti WHERE id=$idStudente";

            if($db->query($sql))    
                echo("<div class=\"alert alert-success\">Cancellazione OK</div>");
            else
                echo("<div class=\"alert alert-danger\">Problemi in cancellazione!</div>");
            $db->close();
            break;
        }
        case "modificaStudente":{
            $idStudente = $_REQUEST['id_studente'];
            $db = new mysqli("localhost","root","","scuola2223");
            $sql = "SELECT * FROM studenti WHERE id=$idStudente";
            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();
            $db->close();

            echo("<form action=\"studenti.php\">
                <div class=\"mb-3\">
                    <label for=\"exampleFormControlInput1\" class=\"form-label\">Cognome</label>
                    <input type=\"text\" name=\"cognomeS\" class=\"form-control\" value=\"".$record['cognome']."\" id=\"exampleFormControlInput1\" placeholder=\"Cognome...\">
                </div>

                <div class=\"mb-3\">
                    <label for=\"exampleFormControlInput2\" class=\"form-label\">Nome</label>
                    <input type=\"text\" name=\"nomeS\" class=\"form-control\" value=\"".$record['nome']."\" id=\"exampleFormControlInput2\" placeholder=\"Nome...\">
                </div>

                <div class=\"mb-3\">
                    <label for=\"exampleFormControlInput3\" class=\"form-label\">Classe</label>
                    <input type=\"text\" name=\"classeS\" class=\"form-control\" value=\"".$record['classe']."\" id=\"exampleFormControlInput3\" placeholder=\"Classe...\">
                </div>

                <input type=\"hidden\" name=\"idStudente\" value=\"".$record['id']."\">
                <input type=\"hidden\" name=\"scelta\" value=\"updateStudente\">
                <div class=\"col-auto\">
                    <button type=\"submit\" class=\"btn btn-primary mb-3\">Modifica Studente</button>
                </div>
            </form>");

            break;
        }
        case "updateStudente":{
            $c = $_REQUEST['cognomeS'];
            $n = $_REQUEST['nomeS'];
            $cl = $_REQUEST['classeS'];
            $idStudente = $_REQUEST['idStudente'];

            $db = new mysqli("localhost","root","","scuola2223");
            $sql = "UPDATE studenti SET cognome='$c', nome='$n', classe='$cl' WHERE id=$idStudente";
            if($db->query($sql))    
                echo("<div class=\"alert alert-success\">Modifica/Aggiornamento OK</div>");
            else
                echo("<div class=\"alert alert-danger\">Problemi in Modifica/Aggiornamento!</div>");
            $db->close();
            break;
        }
        default:{
            echo("Scelta non valida...");
            break;
        }
    }    
    require("../foot.html");
?>