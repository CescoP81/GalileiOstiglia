<?php
require('../include/lib.php');
// richiamo la header per generale il codice iniziale della pagina.
writeHeader();
writeMenu();

    // >> il tuo codice inizia qui.
    echo('<div class="alert alert-success">Sono nella sezione del PRODOTTO</div>');
    if(isset($_REQUEST['scelta']))
        $sc = $_REQUEST['scelta'];
    else 
        $sc = null;

    switch($sc){
        case "formProdotto":{
            //echo('Voglio inserire un nuovo prodotto...');
            echo('
                <form action="prodotto.php">
                    <div class="mb-3">
                        <label for="inputDescrizione" class="form-label">Descrizione:</label>
                        <input type="text" name="descrizioneProdotto" class="form-control" id="inputDescrizione" aria-describedby="">
                    </div>
                    <div class="mb-3">
                        <label for="inputPrezzo" class="form-label">Prezzo unitario:</label>
                        <input type="text" name="prezzoProdotto" class="form-control" id="inputPrezzo" aria-describedby="">
                    </div>
                    <div class="mb-3">
                        <label for="inputNote" class="form-label">Note:</label>
                        <input type="text" name="noteProdotto" class="form-control" id="inputNote" aria-describedby="">
                    </div>
                    <input type="hidden" name="scelta" value="addNuovoProdotto">
                    <button type="submit" class="btn btn-primary">Inserisci il Prodotto</button>
                </form>');
            break;
        }
        case "addNuovoProdotto":{
            // case nel quale arrivo se viene premuto il bottone nel form di inserimento di un nuovo prodotto
            $descrizioneP = $_REQUEST['descrizioneProdotto'];
            $prezzoP = $_REQUEST['prezzoProdotto'];
            $noteP = $_REQUEST['noteProdotto'];

            $sql = "INSERT INTO prodotto(descrizione, prezzoUnitario, note) VALUE('$descrizioneP', '$prezzoP', '$noteP')";

            //echo($sql);
            $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
            if($db->query($sql))
                echo('<div class="alert alert-success">Nuovo prodotto aggiunto!</div>');
            else
                echo('<div class="alert alert-danger">Problema in inserimento nuovo prodotto!</div>');
            $db->close();
            break;
        }
        case "listaProdotti":{
            // step 1. creo uno strem al database mysql
            $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

            // step 2. creo e eseguo la query sql per selezionare tutti i record
            // della tabella regione
            $sql = "SELECT * FROM prodotto";
            $resultSet = $db->query($sql);

            // scrivo la parte statica di creazione di una tabella con BootS
            echo('
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Descrizione</th>
                            <th scope="col">Prezzo Unitario</th>
                            <th scope="col">Note</th>
                            <th scope="col">Gestione</th>
                        </tr>
                    </thead>
                    <tbody>
            ');
            // le righe le genero dinamicamente con PHP e il ciclo while
            while($record = $resultSet->fetch_assoc()){
                echo('
                        <tr>
                            <th scope="row">'.$record['id'].'</th>
                            <td>'.$record['descrizione'].'</td>
                            <td>'.$record['prezzoUnitario'].'</td>
                            <td>'.$record['note'].'</td>
                            <td><a class="btn btn-primary" href="prodotto.php?scelta=deleteProdotto&idProdotto='.$record['id'].'">Cancella</a>
                        </tr>
                ');
            }
            // scriv la parte statica di chiusura della tabella con BootS.
            echo('
                    </tbody>
                </table>
            ');
            break;
        }
        case "deleteProdotto":{
            $idP = $_REQUEST['idProdotto'];
            $sql = "DELETE FROM prodotto WHERE id=$idP";
            echo($sql);

            $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
            if($db->query($sql))
                echo('<div class="alert alert-success">Prodotto cancellato correttamente.</div>');
            else
                echo('<div class="alert alert-danger">Problema in cancellazione prodotto.</div>');
            $db->close();
            break;
        }
    }
    // >> il tuo codice finisce qui.
    
// richiamo la footer per chiudere in modo corretto le pagine.
writeFooter();
?>