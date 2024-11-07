<?php
/** Questa pagina sarà adibita alla gestione della tabella PRODOTTO */

if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

// includo la libreria con funzioni necessarie all'interfaccia.
require('../include/lib.php');
// richiamo la funzione per la creazione della sezione iniziale delle pagine
writeHeader();
writeMenu();

    // << your code start here >>
        switch($sc){
            case "listaProdotto":{
                echo('Contenuto della tabella Prodotto:<br />');
                // questo case deve aprire un flusso con mysql, quindi eseguire una query
                // per visualizzare il contenuto della tabella PRODOTTO, con o senza tabella bootstrap.
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
                $sql = "SELECT * FROM prodotto";
                $resultSet = $db->query($sql);

                while($record = $resultSet->fetch_assoc()){
                    echo($record['id'].' '.$record['descrizione'].'<br />');    
                }

                /* per poter veddere di nuovo i risultati devo ri-eseguire di nuovo la query 
                    e ri-creare di nuovo la resultSet
                echo('<br /><br />');
                $resultSet = $db->query($sql);
                while($record = $resultSet->fetch_assoc()){
                    echo($record['id'].' '.$record['descrizione'].'<br />');    
                }
                */
                $db->close();
                break;
            }
        }
    // << end fo your code >>

// richiamo la funzione per la creazione della sezione finale delle pagine.
writeFooter();
?>