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
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
                $sql = "SELECT * FROM magazzino";
                $resultSet = $db->query($sql);

                echo('<table class="table table-striped table-hover ">
                    <caption>Lista dei prodotti disponibili</caption>
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Nome</th>
                            <th scope="col">Città</th>
                            <th scope="col">Provincia</th>
                            <th scope="col">Gestione</th>
                        </tr>
                    </thead>
                    <tbody>                
                ');
                    while($record = $resultSet->fetch_assoc()){
                        echo('<tr>
                                <th scope="row">'.$record['id'].'</th>
                                <td>'.$record['nome'].'</td>
                                <td>'.$record['citta'].'</td>
                                <td>'.$record['provincia'].'</td>
                                <td><a href="magazzino.php?scelta=deleteMagazzino&idMagazzino='.$record['id'].'">
                                        <button type="button" class="btn btn-primary">Cancella</button>
                                    </a>
                                </td>
                            </tr>
                        ');  
                    }
                echo('</tbody>
                </table>');
                $db->close();                
                break;
            }
            case "formNuovoMagazzino":{
                echo('
                    <form action="magazzino.php">
                        <div class="mb-3">
                            <label for="inputNome" class="form-label">Nome del Magazzino:</label>
                            <input type="text" name="nomeMagazzino" class="form-control" id="inputNome" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">es. Mantova Hub 1</div>
                        </div>

                        <div class="mb-3">
                            <label for="inputCitta" class="form-label">Città del Magazzinoo:</label>
                            <input type="text" name="cittaMagazzino" class="form-control" id="inputCitta" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">es. Viadana</div>
                        </div>

                        <div class="mb-3">
                            <label for="inputProvincia" class="form-label">Provincia del Magazzino:</label>
                            <input type="text" name="provinciaMagazzino" class="form-control" id="inputProvincia" aria-describedby="descrizioneHelp">
                            <div id="descrizioneHelp" class="form-text">es. MN</div>
                        </div>

                        <input type="hidden" name="scelta" value="aggiungiMagazzino">
                        <button type="submit" class="btn btn-primary">Inserisci il nuovo Magazzino</button>
                    </form>
                ');
                
                break;
            }
            case "aggiungiMagazzino":{
                /* Case richiamato dal form di inserimento nuovo prodotto, quindi
                    nel vettore $_REQUEST[] avrò le chiavi relative ai 'name' messi alle caselle del form.
                */
                $nomeM = $_REQUEST['nomeMagazzino'];
                $cittaM = $_REQUEST['cittaMagazzino'];
                $provinciaM = $_REQUEST['provinciaMagazzino'];
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

                $sql = "INSERT INTO magazzino(nome, citta, provincia) VALUES('$nomeM', '$cittaM', '$provinciaM')";
                if($db->query($sql)){
                    echo('<div class="alert alert-success">Nuovo magazzino aggiunto.</div>');
                }
                else{
                    echo('<div class="alert alert-warning">Problema in aggiunta nuovo magazzino.</div>');
                }
                $db->close();
                break;
            }
            case "deleteMagazzino":{
                $idM = $_REQUEST['idMagazzino'];
                $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

                $sql = "DELETE FROM magazzino WHERE id='$idM'";
                if($db->query($sql))
                    echo('<div class="alert alert-success">Magazzino Cancellato Correttamente.</div>');
                else
                    echo('<div class="alert alert-warning">Magazzino inesistente o errore in cancellazione.</div>');
                
                $db->close();
                break;
            }
        }
    // << end fo your code >>

// richiamo la funzione per la creazione della sezione finale delle pagine.
writeFooter();
?>