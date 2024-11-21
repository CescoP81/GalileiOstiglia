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
                
                break;
            }
            case "formNuovoMagazzino":{
                echo('Form nuovo magazzino');
                
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