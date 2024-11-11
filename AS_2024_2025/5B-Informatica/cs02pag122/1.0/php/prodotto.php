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
            case "formNuovoProdotto":{
                // crea il form HTML/Bootstrap per l'inserimento dei dati di un prodotto.
                echo('
                    <form>
                        <div class="mb-3">
                            <label for="inputDescrizione" class="form-label">Descrizione Prodotto:</label>
                            <input type="text" class="form-control" id="inputDescrizione" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">Inserisci la descrizione del prodotto da inserire</div>
                        </div>
                        <button type="submit" class="btn btn-primary">Submit</button>
                    </form>
                ');
                break;
            }
        }
    // << end fo your code >>

// richiamo la funzione per la creazione della sezione finale delle pagine.
writeFooter();
?>