<?php 
/**
 * Gestione della tabella 'Dipendente' sul database, operazioni ammesse:
 * [x] 'formNuovoDipendente' - Mostra il form di inserimento di un nuovo dipendente.
 * [x] 'addNuovoDipendente' - Aggiunge i dati di un nuovo dipendente al database.
 * [x] 'listaDipendente' - Visualizza la lista dei dipendenti presenti, con relativa città e reparto.
 * [] 'deleteDipendente' - Cancella un dipendente dal database.
 */
// include eventuali librerie utili alla UI.
require("../include/libGenerale.php");
// eseguo il test sulle variabili che posso ricevere tramite HTTP-REQUEST
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Sono nella sezione Dipendente. - Ver 1.0</div>');
    switch($sc){
        case "formNuovoDipendente":{
            echo('<form action="dipendente.php">
                <div class="row">
                    <div class="col">
                        <div class="alert alert-success">1- Anagrafica Dipendente</div>
                        <div class="mb-3">
                            <label for="cognomeDipendente" class="form-label">Cognome Dipendente:</label>
                            <input type="text" class="form-control" id="cognomeDipendente" name="cognomeDipendente" placeholder="Inserisci il cognome di un dipendente">
                        </div>
                    
                        <div class="mb-3">
                            <label for="nomeDipendente" class="form-label">Nome Dipendente:</label>
                            <input type="text" class="form-control" id="nomeDipendente" name="nomeDipendente" placeholder="Inserisci il nome di un dipendente">
                        </div>
                    </div>');
                    echo('<div class="col">
                        <div class="alert alert-success">2- Residenza</div>');
                        // Select per selezionare la città di residenza.
                        //$db = new mysqli("localhost", "root", "", "scuola2324");
                        $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
                        $sql = "SELECT * FROM Citta";
                        $rs = $db->query($sql);
                        $db->close();

                        echo('<div class="mb-3">
                            <label for="idCitta" class="form-label">Città di residenza:</label>
                            <select class="form-select" id="idCitta" name="idCitta" aria-label="Città del reparto">');
                            while($record = $rs->fetch_assoc()){
                                echo('<option value="'.$record['id'].'">'.$record['nomeCitta'].'</option>');
                            }
                        echo('</select>
                        </div>');
                    echo("</div>");
                    echo('<div class="col">
                        <div class="alert alert-success">3- Dati del Reparto</div>');
                        // Select per selezionare il reparto di impiego.
                        $db = new mysqli("localhost", "root", "", "scuola2324");
                        $sql = "SELECT r.id, r.nomeReparto AS 'reparto', c.nomeCitta AS 'citta' 
                                FROM Reparto AS r, Citta as c 
                                WHERE r.idCittaReparto = c.id";
                        $rs = $db->query($sql);
                        //echo($sql);
                        $db->close();

                        echo('<div class="mb-3">
                            <label for="idReparto" class="form-label">Reparto di impiego:</label>
                            <select class="form-select" id="idReparto" name="idReparto" aria-label="Nome del reparto">');
                            while($record = $rs->fetch_assoc()){
                                echo('<option value="'.$record['id'].'">'.$record['reparto'].' - '.$record['citta'].'</option>');
                            }
                        echo('</select>
                        </div>');
                    echo("</div>");
                echo('<div class="col">
                        <input type="hidden" name="scelta" value="addNuovoDipendente">
                        <button type="submit" class="btn btn-primary">Inserisci nel Database</button>
                    </div>
            </form>');
            break;
        }
        case "addNuovoDipendente":{
            $c = $_REQUEST['cognomeDipendente'];
            $n = $_REQUEST['nomeDipendente'];
            $iC = $_REQUEST['idCitta'];
            $iR = $_REQUEST['idReparto'];
            $sql = "INSERT INTO Dipendente(cognome, nome, idReparto, idCittaResidenza) 
                    VALUES('$c', '$n', $iR, $iC)";
            //$db = new mysqli("localhost", "root", "", "scuola2324");
            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            if($db->query($sql)){
                echo('<div class="alert alert-success">Inserimento del nuovo dipendente avvenuto con successo</div>');    
            }
            else{
                echo('<div class="alert alert-warning">Problema in inserimento nuovo dipendente.</div>');
            }
            $db->close();
            break;
        }
        case "listaDipendente":{
            $sql = "select d.id, d.cognome, d.nome, c.nomeCitta, r.nomeReparto, c1.nomeCitta AS cittaReparto
                    FROM Dipendente AS d, Citta AS c, Reparto AS r, Citta AS c1 
                    WHERE d.idCittaResidenza=C.id AND d.idReparto=r.id AND r.idCittaReparto=c1.id";
            
            //$db = new mysqli("localhost", "root", "", "scuola2324");
            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            $rs = $db->query($sql);
            $db->close();

            echo('<table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Cognome</th>
                            <th scope="col">Nome</th>
                            <th scope="col">Città di Residenza</th>
                            <th scope="col">Reparto di Impiego</th>
                        </tr>
                    </thead>
                ');
                echo('<tbody');
                while($record = $rs->fetch_assoc()){
                    echo('<tr>
                        <th scope="row">'.$record['id'].'</th>
                        <td>'.$record['cognome'].'</td>
                        <td>'.$record['nome'].'</td>
                        <td>'.$record['nomeCitta'].'</td>
                        <td>'.$record['nomeReparto'].' di '.$record['cittaReparto'].'</td>
                        </tr>
                    ');
                }
                echo('</tbody>');
                echo('<caption>Lista dipendenti presenti a database');
            echo('</table>');
            break;
        }
        case "deleteDipendente":{
            break;
        }
        default:{
            echo('<div class="alert alert-warning">Attenzione, scelta non valida.</div>');
            break;
        }
    }
require("../include/foot.php");
 ?>