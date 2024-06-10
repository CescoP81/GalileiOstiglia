<?php
/**
 * Funzione per la visualizzazione di record estratti da un database, sotto forma di tabella realizzata con BootStrap
 * @param Object $_rs Insieme dei risultati estratti con mysqli::query().
 * @param String $_caption Stringa da usare come caption della tabella.
 * @param String $_page Pagina da richiamare per modifica e cancellazione.
 */
function showResultSetTable($_rs, $_caption=null, $_page=null){
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
                    if(!is_null($_page)){
                        echo("<td><a href=\"$_page?scelta=deleteStudente&id_studente=".$record['id']."\">Cancello record ".$record['id']."</a></td>");
                        echo("<td><a href=\"$_page?scelta=modificaStudente&id_studente=".$record['id']."\">Modifica record ".$record['id']."</a></td>");
                    }
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