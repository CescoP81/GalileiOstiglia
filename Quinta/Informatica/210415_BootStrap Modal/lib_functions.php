<?php
/**
 * Funzione che visualizza i risultati di una query sottoforma di tabella.
 * @param object $_rS ResultSet generato dalla query SQL.
 * @param string $_caption Caption della tabella.
 */
function createTable($_rS, $_caption="Default Dynamic Table"){
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
    return;
}

/**
 * Funzione che visualizza i risultati di una query sottoforma di tabella.
 * @param string $_modalId Id che compare nel bottone associato.
 * @param string $_modalTitle Il titolo del modal.
 * @param string $_modalBody Il testo del body del modal.
 */
function createModal($_modalId, $_modalTitle, $_modalBody){
    echo("<div class=\"modal fade\" id=\"".$_modalId."\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"exampleModalLabel\" aria-hidden=\"true\">");
        echo("<div class=\"modal-dialog\" role=\"document\">");
            echo("<div class=\"modal-content\">");
                echo("<div class=\"modal-header\">");
                    echo("<h5 class=\modal-title\" id=\"exampleModalLabel\">".strtoupper($_modalTitle)."</h5>");
                    echo("<button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-label=\"Close\">");
                        echo("<span aria-hidden=\"true\">&times;</span>");
                    echo("</button>");
                echo("</div>");

                echo("<div class=\"modal-body\">");
                    echo($_modalBody);
                echo("</div>");

                /*echo("<div class=\"modal-footer\">");
                    echo("<button type=\"button\" class=\"btn btn-secondary\" data-dismiss=\"modal\">Close</button>");
                    echo("<button type=\"button\" class=\"btn btn-primary\">Save changes</button>");
                echo("</div>");*/
            echo("</div>");
        echo("</div>");
    echo("</div>");
    return; 
}
?>