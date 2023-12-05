<?php 
/**
 * Gestione della tabella 'Dipendente' sul database, operazioni ammesse:
 * [] 'formNuovoDipendente' - Mostra il form di inserimento di un nuovo dipendente.
 * [] 'addNuovoDipendente' - Aggiunge i dati di un nuovo dipendente al database.
 * [] 'listaDipendente' - Visualizza la lista dei dipendenti presenti, con relativa città e reparto.
 * [] 'deleteDipendente' - Cancella un dipendente dal database.
 */
// include eventuali librerie utili alla UI.
require("../include/libGenerale.php");
// eseguo il test sulle variabili che posso ricevere tramite HTTP-REQUEST
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Sono nella sezione Dipendente. - Ver 1.0</div>');
    switch($sc){
        case "formNuovoDipendente":{
            break;
        }
        case "addNuovoDipendente":{
            break;
        }
        case "listaDipendente":{
            break;
        }
        case "deleteDipendente":{
            break;
        }
        default:{
            echo('<div class="alert alert-warning">Attenzione, scelta non valida.</div>');
            break;
        }
    }
require("../include/foot.php");
 ?>