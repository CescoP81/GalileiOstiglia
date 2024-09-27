<?php
/**
 * Script che riceve una chiave tramite HTTP REQUEST e 
 * ne utilizza il valore per visualizzare il contenuto.
 * VINCOLO:
 * la chiave deve chiamarsi 'val1'
 * 
 * http://.../e2.php senza nessuna coppia chiave valore ottengo un errore
 * http://.../e2.php?val1=23 -> viene creato il vettore $_REQUEST[]
 * dove ci sarà una chiave chiamata val1 e il cui contenuto sarà 23
 */
    if(isset($_REQUEST['val1']))
        $dato = $_REQUEST['val1'];
    else
        $dato = -1;

    echo('Valore presente nella chiave: '.$dato);
?>