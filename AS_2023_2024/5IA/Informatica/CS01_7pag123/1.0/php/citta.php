<?php
/**
 * Gestione della tabella 'Citta' sul database, operazioni di gestione:
 * [] 'formNuovaCitta' - Visualizzazione form per inserimento nuova città.
 * [] 'addNuovaCitta' - Inserimento dati nuova città nel database.
 * [x] 'listaCitta' - Visualizzazione delle città presenti nel database.
 * [] 'deleteCitta' - Cancellazione di una città dal database.
 */
// include eventuali librerie utili alla UI.
 require("../include/libGenerale.php");
// eseguo il test sulle variabili che posso ricevere tramite HTTP-REQUEST
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Siamo nella sezione Città - Ver 1.0</div>');
    switch($sc){
        case "formNuovaCitta":{
            break;
        }
        case "addNuovaCitta":{
            break;
        }
        case "listaCitta":{
            $db = new mysqli("localhost", "root", "", "scuola2324");
            $sql = "SELECT * FROM citta";
            $rs = $db->query($sql);
            if($rs){
                echo('<table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Nome Città</th>
                        </tr>
                    </thead>
                ');
                echo('<tbody');
                while($record = $rs->fetch_assoc()){
                    echo('<tr>
                        <th scope="row">'.$record['id'].'</th>
                        <td>'.$record['nomeCitta'].'</td>
                        </tr>
                    ');
                }
                echo('</tbody>');
                echo('<caption>Lista città presenti a database');
                echo('</table>');
            }
            break;
        }
        case "deleteCitta":{
            break;
        }
        default:{
            echo('<div class="alert alert-warning">Attenzione, scelta non valida.</div>');
            break;
        }
    }
require("../include/foot.php");
?>