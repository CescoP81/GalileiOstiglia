<?php
/**
 * Gestione della tabella 'Citta' sul database, operazioni di gestione:
 * [] 'formNuovaCitta' - Visualizzazione form per inserimento nuova città.
 * [] 'addNuovaCitta' - Inserimento dati nuova città nel database.
 * [] 'listaCitta' - Visualizzazione delle città presenti nel database.
 * [] 'deleteCitta' - Cancellazione di una città dal database.
 */
require("../include/libGenerale.php");

require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Siamo nella sezione Città - Ver 1.0</div>');
require("../include/foot.php");
?>