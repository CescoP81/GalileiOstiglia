<?php
require("include/lib.php"); // carico il file di libreria con varie funzioni.
require("include/head.php");
    // richiamo la funzione presente in /include/lib.php per scrivere il codice della navbar.
    scriviNavBar();

    echo('<div class="alert alert-success">Ti trovi nella Home del progetto.</div>');
    // eventuale corpo della pagina iniziale index.php [Home] deve essere inserito qui di seguito.

require("include/foot.php");
?>