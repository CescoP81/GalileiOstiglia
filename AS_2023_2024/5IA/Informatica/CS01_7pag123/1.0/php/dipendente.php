<?php 
/**
 * Gestione della tabella 'Dipendente' sul database, operazioni ammesse:
 * [] 'formNuovoDipendente' - Mostra il form di inserimento di un nuovo dipendente.
 * [] 'addNuovoDipendente' - Aggiunge i dati di un nuovo dipendente al database.
 * [] 'listaDipendente' - Visualizza la lista dei dipendenti presenti, con relativa città e reparto.
 * [] 'deleteDipendente' - Cancella un dipendente dal database.
 */
require("../include/libGenerale.php");
require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Sono nella sezione Dipendente. - Ver 1.0</div>');
require("../include/foot.php");
 ?>