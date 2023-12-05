<?php 
/**
 * Gestione della tabella reparto sul database, operazioni ammesse:
 * [] 'formNuovoReparto' - Mostra il form di inserimento di un nuovo reparto.
 * [] 'addNuovoReparto' - Aggiunge i dati di un nuovo reparto al database.
 * [] 'listaReparto' - Visualizza la lista dei reparti presenti e relative città.
 * [] 'deleteReparto' - Cancella un reparto dal database.
 */
require("../include/libGenerale.php");
require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Sono nella sezione Reparto - Ver 1.0</div>');
require("../include/foot.php");
 ?>