<?php
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
    else $sc = null;
    require("required/mylib.php");
    require("../head.html");

    echo("<a href=\"studenti.php?scelta=formStudente\">Nuovo Studente</a> ");
    echo("<a href=\"studenti.php?scelta=showStudenti\">Visualizza studenti</a>");
    echo("<br /><br />");

    switch($sc){
        case "formStudente":{
            echo("DEVO MOSTRARE IL FORM PER I DATI DI UNO STUDENTE...");
            echo("<form action=\"studenti.php\">
                <b>Cognome:</b><input type=\"text\" name=\"nomeS\"><br />
                <b>Nome:</b><input type=\"text\" name=\"cognomeS\"><br />
                <b>Classe:</b><input type=\"text\" name=\"classeS\"><br />

                <input type=\"hidden\" name=\"scelta\" value=\"addStudente\">

                <input type=\"submit\" value=\"Aggiungi nuovo Studente\">
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
            showResultSetTable($rs," tabella degli studenti");
            break;
        }
        default:{
            echo("Scelta non valida...");
            break;
        }
    }    
    require("../foot.html");
?>