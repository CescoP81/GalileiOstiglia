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
            // step 1. creo uno strem al database mysql
            $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

            // step 2. creo e eseguo la query sql per selezionare tutti i record
            // della tabella regione
            $sql = "SELECT * FROM regione";
            $resultSet = $db->query($sql);

            while($record = $resultSet->fetch_assoc()){
                echo($record['id']." ".$record['nome']."<br />");
            }

            break;
        }
    }
    // >> il tuo codice finisce qui.
    
// richiamo la footer per chiudere in modo corretto le pagine.
writeFooter();
?>