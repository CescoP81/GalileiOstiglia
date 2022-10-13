<?php
function showResultSetTable($_rs, $_caption=null){
    if($_rs->num_rows != 0){                            // controllo, se _rs è valido oppure vuoto.
        $record = $_rs->fetch_assoc();                  // estraggo il primo record 
        $keys = array_keys($record);                    // creo il record delle chiavi (nomi delle colonne)

        echo("<table class=\"table\">");
        echo("<caption>".$_caption."</caption>");
        echo("<thead>
            <tr>");
                for($i=0; $i<count($keys); $i++)        // ciclo per la stampa delle intestazioni della tabella
                    echo("<th>".$keys[$i]."</th>");
            echo("</tr>
        </thead>");
        echo("<tbody>");
            while($record){                             // ciclo per separare i vari record.
                echo("<tr>");
                    for($i=0; $i<count($keys); $i++)    // ciclo per la stampa dei campi di ogni singolo record.
                        echo("<td>".$record[$keys[$i]]."</td>");
                echo("</tr>");
                $record = $_rs->fetch_assoc();          // estraggo il record successivo
            }
        echo("</tbody>
        </table>");
    }
    else
        echo("<div class=\"alert alert-danger\">Table: ".$_caption."<br />Nessun risultato da mostrare</div>");
}
?>