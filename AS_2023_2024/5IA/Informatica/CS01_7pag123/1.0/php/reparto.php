<?php 
/**
 * Gestione della tabella reparto sul database, operazioni ammesse:
 * [] 'formNuovoReparto' - Mostra il form di inserimento di un nuovo reparto.
 * [] 'addNuovoReparto' - Aggiunge i dati di un nuovo reparto al database.
 * [] 'listaReparto' - Visualizza la lista dei reparti presenti e relative città.
 * [] 'deleteReparto' - Cancella un reparto dal database.
 */
// include eventuali librerie utili alla UI.
require("../include/libGenerale.php");
// eseguo il test sulle variabili che posso ricevere tramite HTTP-REQUEST
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Sono nella sezione Reparto - Ver 1.0</div>');
    switch($sc){
        case "formNuovoReparto":{
            break;
        }
        case "addNuovoReparto":{
            break;
        }
        case "listaRepartoa":{
            break;
        }
        case "deleteReparto":{
            break;
        }
        default:{
            echo('<div class="alert alert-warning">Attenzione, scelta non valida.</div>');
            break;
        }
    }
require("../include/foot.php");
 ?>