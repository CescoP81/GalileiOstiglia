<?php
$dbhost = "localhost";
$dbuser = "root";
$dbpassword ="";
$dbname = "scuola2021";

function writeMainMenu(){
    echo("<nav class=\"nav\">");
        echo("<a class=\"nav-link\" href=\"index.php\">Home</a>");
        echo("<a class=\"nav-link\" href=\"genere.php?scelta=nuovoGenere\">Nuovo Genere</a> ");
        echo("<a class=\"nav-link\" href=\"genere.php?scelta=listaGenere\">Lista Generi</a>");

        echo("<a class=\"nav-link\" href=\"spettacolo.php?scelta=nuovoSpettacolo\">Nuovo Spettacolo</a> ");
        echo("<a class=\"nav-link\" href=\"spettacolo.php?scelta=listaSpettacolo\">Lista Spettacoli</a>");

        echo("<a class=\"nav-link\" href=\"rassegna.php?scelta=nuovaRassegna\">Nuova Rassegna</a> ");
        echo("<a class=\"nav-link\" href=\"rassegna.php?scelta=listaRassegna\">Lista Rassegne</a>");
    echo("</nav>");
    return;
}

/**
 * Funzione che visualizza i risultati di una query sottoforma di tabella.
 * @param object $_rS ResultSet generato dalla query SQL.
 * @param string $_caption Caption della tabella.
 */
function createTable($_rS, $_caption="Default Dynamic Table"){
    if($_rS->num_rows > 0){
        $record = $_rS->fetch_assoc();
        $columns = array_keys($record);     // genero il vettore $columns con tutte le chiavi del vettore $record
        echo("<table class=\"table table-hover\">");
        echo("<caption>".$_caption."</caption>");
            echo("<thead  class=\"thead-dark\">");
            echo("<tr>");
                for($i=0; $i<count($columns); $i++)
                    echo("<th  scope=\"col\">".$columns[$i]."</td>");
            echo("</tr>");
            echo("</thead>");

            echo("<tbody>");
            while($record){
                echo("<tr>");
                for($i=0; $i<count($record); $i++)
                    echo("<td>".$record[$columns[$i]]."</td>"); // $record['id'] -- $record['titolo']
                echo("</tr>");
                $record = $_rS->fetch_assoc();
            }
            echo("</tbody>");
        echo("</table>");
    }
    return;
}
?>