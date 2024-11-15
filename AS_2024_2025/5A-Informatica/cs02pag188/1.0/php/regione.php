<?php
require('../include/lib.php');
// richiamo la header per generale il codice iniziale della pagina.
writeHeader();
writeMenu();

    // >> il tuo codice inizia qui.
    echo('<div class="alert alert-success">Sono nella sezione della REGIONE</div>');
    if(isset($_REQUEST['scelta']))
        $sc = $_REQUEST['scelta'];
    else 
        $sc = null;
    
    switch($sc){
        case "formRegione":{
            echo('Voglio inserire una nuova regione...');
            break;
        }
        case "listaRegioni":{
            echo('Voglio vedere le regioni presenti a database...');
            break;
        }
    }
    // >> il tuo codice finisce qui.
    
// richiamo la footer per chiudere in modo corretto le pagine.
writeFooter();
?>