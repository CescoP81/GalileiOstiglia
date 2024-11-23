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
            case "listaMagazzino":{
                echo('Lista dei magazzini');
                $sql = "SELECT p.descrizione, m.nome, m.citta, m.provincia, a.dataAcquisto, a.quantita, a.prezzo 
                        FROM prodotto AS p, magazzino AS m, acquisto AS a 
                        WHERE p.id=a.idProdotto AND m.id=a.idMagazzino";
                break;
            }
            case "formNuovoAcquisto":{
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
                echo('
                    <form action="acquisto.php">
                        <div class="mb-3">
                            <label class="form-label">Prodotto</label>
                            <select class="form-select form-select-sm" name="idProdotto" aria-label="Default select example">');
                                $sql = "SELECT * FROM prodotto";
                                $resultSet = $db->query($sql);
                            
                                while($record = $resultSet->fetch_assoc()){
                                    echo('<option value='.$record['id'].'>'.$record['descrizione'].'</option>');
                                }
                                
                            echo('</select>
                            <div id="descrizioneHelp" class="form-text">Seleziona il prodotto</div>
                        </div>');

                        echo('<div class="mb-3">
                            <label class="form-label">Magazzino</label>');
                            $sql = "SELECT * FROM magazzino";
                            $resultSet = $db->query($sql);
                            echo('<select class="form-select form-select-sm" name="idMagazzino" aria-label="Default select example">');
                            while($record = $resultSet->fetch_assoc()){
                                echo('<option value='.$record['id'].'>'.$record['nome'].' - '
                                .$record['citta'].'('.$record['provincia'].')</option>');
                            }
                        echo('</select>
                            <div id="descrizioneHelp" class="form-text">Seleziona il Magazzino</div>
                        </div>
                        <div class="mb-3">
                            <label for="inputDataAcquisto" class="form-label">Data Acquisto:</label>
                            <input type="text" name="dataAcquisto" class="form-control form-control-sm" id="inputDataAcquisto" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">Inserisci la descrizione del prodotto da inserire</div>
                        </div>
                        <div class="mb-3">
                            <label for="inputQuantita" class="form-label">Quantità acquistata:</label>
                            <input type="text" name="quantita" class="form-control form-control-sm" id="inputQuantita" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">Inserisci la descrizione del prodotto da inserire</div>
                        </div>
                        <div class="mb-3">
                            <label for="inputPrezzo" class="form-label">Prezzo di acquisto:</label>
                            <input type="text" name="prezzo" class="form-control form-control-sm" id="inputPrezzo" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">Inserisci la descrizione del prodotto da inserire</div>
                        </div>
                        
                        <input type="hidden" name="scelta" value="aggiungiAcquisto">
                        <button type="submit" class="btn btn-primary btn-sm">Aggiunti un Acquisto</button>
                    </form> 
                ');
                
                break;
            }
            case "aggiungiAcquisto":{
                /* Case richiamato dal form di inserimento nuovo prodotto, quindi
                    nel vettore $_REQUEST[] avrò la chiave 'descrizione' con contenuto il testo immesso
                    nella casella del form
                */
                $idP = $_REQUEST['idProdotto'];
                $idM = $_REQUEST['idMagazzino'];
                $dataAcq = $_REQUEST['dataAcquisto'];
                $qtaAcq = $_REQUEST['quantita'];
                $prezzoAcq = $_REQUEST['prezzo'];
                
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

                $sql = "INSERT INTO acquisto(idProdotto, idMagazzino, dataAcquisto, quantitaAcquisto, prezzoAcquisto) 
                VALUES($idP, $idM, '$dataAcq', $qtaAcq, $prezzoAcq)";

                echo($sql);
                if($db->query($sql)){
                    echo('<div class="alert alert-success">Nuovo Acquisto aggiunto.</div>');
                }
                else{
                    echo('<div class="alert alert-warning">Problema in aggiunta nuovo acquisto.</div>');
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