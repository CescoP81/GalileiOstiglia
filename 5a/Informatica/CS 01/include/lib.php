<?php
$mysql_host = "localhost";
$mysql_user = "root";
$mysql_password = "";
$mysql_db = "scuola2223";
/**
 * Funzione che crea la barra di navigazione dove viene richiamata.
 */
function adminNavBar(){
    echo("<nav class=\"navbar navbar-expand-lg bg-light\">
        <div class=\"container-fluid\">
            <ul class=\"navbar-nav me-auto mb-2 mb-lg-0\">
                <li class=\"nav-item\">
                    <a class=\"nav-link active\" aria-current=\"page\" href=\"index.php\">Home</a>
                </li>
                
                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                        Casa Editrice
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"casaEditrice.php?scelta=formNuovaEditrice\">Inserisci Nuova</a></li>
                        <li><a class=\"dropdown-item\" href=\"casaEditrice.php?scelta=listaEditrice\">Lista Case Editrici</a></li>
                    </ul>
                </li>
      
                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                        Fumetti
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"fumetto.php?scelta=formNuovoFumetto\">Nuovo Fumetto</a></li>
                        <li><a class=\"dropdown-item\" href=\"#\">Lista Fumetti</a></li>
                    </ul>
                </li>
            </ul>
            <form class=\"d-flex\" role=\"search\">
                <input class=\"form-control me-2\" type=\"search\" placeholder=\"Search\" aria-label=\"Search\">
                <button class=\"btn btn-outline-success\" type=\"submit\">Search</button>
            </form>
        </div>
    </nav>");
}
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