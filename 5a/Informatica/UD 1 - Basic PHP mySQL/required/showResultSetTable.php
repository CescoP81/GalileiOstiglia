<?php
// !! richiede OBBLIGATORIAMENTE che la risultante della query sia messa in $rs !!
// -------------------------------------------------------------------------------

$record = $rs->fetch_assoc();                   // estraggo il primo record 
$keys = array_keys($record);                    // creo il record delle chiavi (nomi delle colonne)

echo("<table class=\"table\">");
echo("<caption>Tabella Studenti</caption>");
echo("<thead>
    <tr>");
        for($i=0; $i<count($keys); $i++)        // ciclo per la stampa delle intestazioni della tabella
            echo("<th>".$keys[$i]."</th>");
    echo("</tr>
</thead>");
echo("<tbody>");
while($record){
    echo("<tr>");
        for($i=0; $i<count($keys); $i++)        // ciclo per la stampa dei campi di ogni singolo record.
            echo("<td>".$record[$keys[$i]]."</td>");
    echo("</tr>");
    $record = $rs->fetch_assoc();               // estraggo il record successivo
}
echo("</tbody>
</table>");
?>