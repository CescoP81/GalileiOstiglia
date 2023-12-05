<?php
/**
 * Gestione della tabella 'Citta' sul database, operazioni di gestione:
 * [] 'formNuovaCitta' - Visualizzazione form per inserimento nuova città.
 * [] 'addNuovaCitta' - Inserimento dati nuova città nel database.
 * [] 'listaCitta' - Visualizzazione delle città presenti nel database.
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
    }
require("../include/foot.php");
?>