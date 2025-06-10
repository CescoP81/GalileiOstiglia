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
                //echo('Contenuto della tabella Prodotto:<br />');
                // questo case deve aprire un flusso con mysql, quindi eseguire una query
                // per visualizzare il contenuto della tabella PRODOTTO, con o senza tabella bootstrap.
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
                $sql = "SELECT * FROM prodotto";
                $resultSet = $db->query($sql);

                /*while($record = $resultSet->fetch_assoc()){
                    echo($record['id'].' '.$record['descrizione'].'<br />');    
                }*/
                echo('<table class="table table-striped table-hover ">
                    <caption>Lista dei prodotti disponibili</caption>
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Descrizione</th>
                            <th scope="col">Gestione</th>
                        </tr>
                    </thead>
                    <tbody>                
                ');
                    while($record = $resultSet->fetch_assoc()){
                        echo('<tr>
                                <th scope="row">'.$record['id'].'</th>
                                <td>'.$record['descrizione'].'</td>
                                <td><a href="prodotto.php?scelta=deleteProdotto&idProdotto='.$record['id'].'">
                                        <button type="button" class="btn btn-primary">Cancella</button>
                                    </a>
                                </td>
                            </tr>
                        ');  
                    }
                echo('</tbody>
                </table>');

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
                    <form action="prodotto.php">
                        <div class="mb-3">
                            <label for="inputDescrizione" class="form-label">Descrizione Prodotto:</label>
                            <input type="text" name="descrizione" class="form-control form-control-sm" id="inputDescrizione" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">Inserisci la descrizione del prodotto da inserire</div>
                        </div>
                        <input type="hidden" name="scelta" value="aggiungiProdotto">
                        <button type="submit" class="btn btn-primary">Submit</button>
                    </form>
                ');
                break;
            }
            case "aggiungiProdotto":{
                /* Case richiamato dal form di inserimento nuovo prodotto, quindi
                    nel vettore $_REQUEST[] avrò la chiave 'descrizione' con contenuto il testo immesso
                    nella casella del form
                */
                $desc = $_REQUEST['descrizione'];
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

                $sql = "INSERT INTO prodotto(descrizione) VALUES('$desc')";
                if($db->query($sql)){
                    echo('<div class="alert alert-success">Nuovo prodotto aggiunto.</div>');
                }
                else{
                    echo('<div class="alert alert-warning">Problema in aggiunta nuovo prodotto.</div>');
                }
                $db->close();
                break;
            }
            case "deleteProdotto":{
                $idP = $_REQUEST['idProdotto'];
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

                $sql = "DELETE FROM prodotto WHERE id='$idP'";
                if($db->query($sql))
                    echo('<div class="alert alert-success">Prodotto Cancellato Correttamente.</div>');
                else
                    echo('<div class="alert alert-warning">Prodotto inesistente o errore in cancellazione.</div>');
                
                $db->close();
                break;
            }
        }
    // << end fo your code >>

// richiamo la funzione per la creazione della sezione finale delle pagine.
writeFooter();
?>