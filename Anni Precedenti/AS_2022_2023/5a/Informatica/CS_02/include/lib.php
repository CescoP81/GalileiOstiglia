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
            <!--<ul class=\"nav nav-tabs\">-->
            <ul class=\"navbar-nav me-auto mb-2 mb-lg-0\">
                <li class=\"nav-item\">
                    <a class=\"nav-link active\" aria-current=\"page\" href=\"index.php\">Home</a>
                </li>
                
                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/people-fill.svg\"> Iscritti
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"iscritti.php?scelta=formNuovoIscritto\"><img src=\"../../../../bsicon/person-add.svg\"> Nuovo Iscritto</a></li>
                        <li><a class=\"dropdown-item\" href=\"iscritti.php?scelta=listaIscritti\"><img src=\"../../../../bsicon/person-vcard.svg\"> Lista Iscritti</a></li>
                    </ul>
                </li>
      
                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/file-earmark-fill.svg\"> Spettacoli
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"spettacoli.php?scelta=#\"><img src=\"../../../../bsicon/file-earmark-plus.svg\"> Nuovo Spettacolo</a></li>
                        <li><a class=\"dropdown-item\" href=\"spettacoli.php?scelta=vediSpettacoli\"><img src=\"../../../../bsicon/list.svg\"> Lista Spettacoli</a></li>
                    </ul>
                </li>

                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/bookmark-fill.svg\"> Stagioni
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"stagioni.php\"><img src=\"../../../../bsicon/file-earmark-plus.svg\">  Nuova Stagione</a></li>
                        <li><a class=\"dropdown-item\" href=\"stagioni.php?scelta=vediStagioni\"><img src=\"../../../../bsicon/list.svg\"> Lista Stagioni</a></li>
                    </ul>
                </li>

                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/book-fill.svg\"> Palinsesto
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"palinsesto.php?scelta=formNuovoPalinsesto\"><img src=\"../../../../bsicon/file-earmark-plus.svg\"> Programma Spettacolo</a></li>
                        <li><a class=\"dropdown-item\" href=\"palinsesto.php?scelta=listaPalinsesto\"><img src=\"../../../../bsicon/list.svg\"> Vedi Spettacoli Programmati</a></li>
                    </ul>
                </li>

                <li class=\"nav-item\">
                    <a class=\"nav-link active\" aria-current=\"page\" href=\"index.php?scelta=logout\">Logout</a>
                </li>

            </ul>
            <!--<form class=\"d-flex\" role=\"search\">
                <input class=\"form-control me-2\" type=\"search\" placeholder=\"Search\" aria-label=\"Search\">
                <button class=\"btn btn-outline-success\" type=\"submit\">Search</button>
            </form>-->
        </div>
    </nav>");
}

/**
 * Funzione per la visualizzazione di record estratti da un database, sotto forma di tabella realizzata con BootStrap
 * @param Object $_rs Insieme dei risultati estratti con mysqli::query().
 * @param String $_caption Stringa da usare come caption della tabella.
 * @param String $_page Pagina da richiamare per modifica e cancellazione; passa deleteRecord/modificaRecord e idRecord
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
                        if($keys[$i] == "immagine"){
                            echo("<td>
                                <button type=\"button\" class=\"btn btn-primary\" data-bs-toggle=\"modal\" data-bs-target=\"#exampleModal\">
                                    Vedi la Copertina
                                </button>
                                <div class=\"modal\" id=\"exampleModal\" tabindex=\"-1\">
                                    <div class=\"modal-dialog\">
                                        <div class=\"modal-content\">
                                            <div class=\"modal-header\">
                                                <h5 class=\"modal-title\">Immagine di Copertina</h5>
                                                <button type=\"button\" class=\"btn-close\" data-bs-dismiss=\"modal\" aria-label=\"Close\"></button>
                                            </div>
                                            <div class=\"modal-body\">
                                                <p><img src=\"../images/".$record[$keys[$i]]."\" class=\"img-fluid rounded\" /></p>
                                            </div>
                                            <div class=\"modal-footer\">
                                                <button type=\"button\" class=\"btn btn-secondary\" data-bs-dismiss=\"modal\">Close</button>
                                            </div>
                                        </div>
                                    </div>
                                </div>                                                           
                            </td>");
                        }
                        else{
                            echo("<td>".$record[$keys[$i]]."</td>");
                        }
                    if(!is_null($_page)){
                        echo("<td><a href=\"$_page?scelta=deleteRecord&idRecord=".$record['id']."\">Cancello record ".$record['id']."</a></td>");
                        echo("<td><a href=\"$_page?scelta=modificaRecord&idRecord=".$record['id']."\">Modifica record ".$record['id']."</a></td>");
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

function associatoNavBar($id=null, $userName=null){
    echo("<nav class=\"navbar navbar-expand-lg bg-light\">
        <div class=\"container-fluid\">
            Associato: #$id - $userName | 
            <ul class=\"navbar-nav me-auto mb-2 mb-lg-0\">
                <li class=\"nav-item\">
                    <a class=\"nav-link active\" aria-current=\"page\" href=\"index.php\">Home</a>
                </li>
                <li class=\"nav-item\">
                    <a class=\"nav-link active\" aria-current=\"page\" href=\"associato.php\">Iscrizioni</a>
                </li>
                
                <!--
                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/people-fill.svg\"> Iscritti
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"iscritti.php?scelta=formNuovoIscritto\"><img src=\"../../../../bsicon/person-add.svg\"> Nuovo Iscritto</a></li>
                        <li><a class=\"dropdown-item\" href=\"iscritti.php?scelta=listaIscritti\"><img src=\"../../../../bsicon/person-vcard.svg\"> Lista Iscritti</a></li>
                    </ul>
                </li>
      
                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/file-earmark-fill.svg\"> Spettacoli
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"spettacoli.php?scelta=#\"><img src=\"../../../../bsicon/file-earmark-plus.svg\"> Nuovo Spettacolo</a></li>
                        <li><a class=\"dropdown-item\" href=\"spettacoli.php?scelta=vediSpettacoli\"><img src=\"../../../../bsicon/list.svg\"> Lista Spettacoli</a></li>
                    </ul>
                </li>

                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/bookmark-fill.svg\"> Stagioni
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"stagioni.php\"><img src=\"../../../../bsicon/file-earmark-plus.svg\">  Nuova Stagione</a></li>
                        <li><a class=\"dropdown-item\" href=\"stagioni.php?scelta=vediStagioni\"><img src=\"../../../../bsicon/list.svg\"> Lista Stagioni</a></li>
                    </ul>
                </li>

                <li class=\"nav-item dropdown\">
                    <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                    <img src=\"../../../../bsicon/book-fill.svg\"> Palinsesto
                    </a>
                    <ul class=\"dropdown-menu\">
                        <li><a class=\"dropdown-item\" href=\"palinsesto.php?scelta=formNuovoPalinsesto\"><img src=\"../../../../bsicon/file-earmark-plus.svg\"> Programma Spettacolo</a></li>
                        <li><a class=\"dropdown-item\" href=\"palinsesto.php?scelta=listaPalinsesto\"><img src=\"../../../../bsicon/list.svg\"> Vedi Spettacoli Programmati</a></li>
                    </ul>
                </li>-->

                <li class=\"nav-item\">
                    <a class=\"nav-link active\" aria-current=\"page\" href=\"index.php?scelta=logout\">Logout</a>
                </li>

            </ul>
        </div>
    </nav>");
}

?>