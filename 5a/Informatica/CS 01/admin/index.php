<?php
// pagina iniziale della sezione amministrazione.
require("../include/lib.php");

// costruisco la struttura della pagina includendo il file head.html per la parte iniziale
// che comprende le chiamate al CSS di bootstrap.
require("../include/head.html");
    adminNavBar();
    echo("Riepilogo generico o altre informazioni...");

require("../include/foot.html");
?>