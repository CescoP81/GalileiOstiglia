<?php
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

// includo la libreria con funzioni necessarie all'interfaccia.
require('../include/lib.php');
// richiamo la funzione per la creazione della sezione iniziale delle pagine
writeHeader();
writeMenu();

    // << your code start here >>
        switch($sc){
            case "listaProdotto":{
                
                break;
            }
        }
    // << end fo your code >>

// richiamo la funzione per la creazione della sezione finale delle pagine.
writeFooter();
?>