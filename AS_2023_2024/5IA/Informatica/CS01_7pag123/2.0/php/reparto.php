<?php 
/**
 * Gestione della tabella reparto sul database, operazioni ammesse:
 * [x] 'formNuovoReparto' - Mostra il form di inserimento di un nuovo reparto.
 * [x] 'addNuovoReparto' - Aggiunge i dati di un nuovo reparto al database.
 * [x] 'listaReparto' - Visualizza la lista dei reparti presenti e relative città.
 * [] 'deleteReparto' - Cancella un reparto dal database.
 */
// include eventuali librerie utili alla UI.
require("../include/libGenerale.php");
// eseguo il test sulle variabili che posso ricevere tramite HTTP-REQUEST
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Sono nella sezione Reparto - Ver 2.0</div>');
    switch($sc){
        case "formNuovoReparto":{
            /* Visualizzo il form per l'inserimento di un nuovo reparto, arrivo in questo case cliccando il link nella navBar generale nella sezione Reparto.*/
            echo('<form action="reparto.php">
                <div class="mb-3">
                    <label for="nomeReparto" class="form-label">Nome Reparto:</label>
                    <input type="text" class="form-control" id="nomeReparto" name="nomeReparto" placeholder="Inserisci il nome di un reparto">
                </div>');
                
                /* la selezione della città viene fatta tramite una <SELECT name=""> creata con tutte le città presenti nel database,
                ogni <option ..> della select è composta da due parti <option value="..">Testo visualizzato.
                Nel value devo inserire l'id della città, mentre nella parte "testo visualizzato" inserirò il nome esatto della città.
                Righe dalla 39 alla 41 per creare la <SELECT> dinamicamente.
                */
                $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
                $sql = "SELECT * FROM Citta";
                $rs = $db->query($sql);
                $db->close();

                echo('<div class="mb-3">
                    <label for="idCitta" class="form-label">Città del reparto:</label>
                    <select class="form-select" id="idCitta" name="idCitta" aria-label="Default select example">');
                    while($record = $rs->fetch_assoc()){
                        echo('<option value="'.$record['id'].'">'.$record['nomeCitta'].'</option>');
                    }
                echo('</select>
                </div>');
            echo('
                <input type="hidden" name="scelta" value="addNuovoReparto">
                <button type="submit" class="btn btn-primary">Inserisci nel Database</button>
            </form>');
            break;
        }
        case "addNuovoReparto":{
            /* recupero i dati nome del reparto e id della città dall'indirizzo URL generato dalla pressione del bottone "Inserisci" nel form iniziale.
                Creo la query di INSERT e la eseguo per registrare i dati.
                NB: non viene datto alcun controllo che la città sia già presente o meno.
            */
            $nR = $_REQUEST['nomeReparto'];
            $iC = $_REQUEST['idCitta'];

            $sql = "INSERT INTO Reparto(nomeReparto, idCittaReparto) VALUES('$nR',$iC)";
            //echo($sql);
            //$db = new mysqli("localhost", "root", "", "scuola2324");
            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            if($db->query($sql)){
                echo('<div class="alert alert-success">Inserimento del nuovo reparto avvenuto con successo</div>');    
            }
            else{
                echo('<div class="alert alert-warning">Problema in inserimento nuovo reparto.</div>');
            }
            $db->close();
            break;
        }
        case "listaReparto":{
            /* Visualizzo con una tabella bootstrap tutti i reparti presenti a database, nella query mySQL eseguo una JOIN tra Reparto e Città così da non visualizzare
                gli ID delle città ma bensì i nomi.
                L'ultima colonna è dedicata alle operazioni di gestione, viene creato un link URL per la cancellazione indicando la scelta che sarà gestita nello switch-case
                e l'id del reparto che voglio cancellare.
            */
            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            $sql = "SELECT Reparto.id, Reparto.nomeReparto AS 'Reparto', Citta.nomeCitta AS 'Citta' 
                    FROM Reparto, Citta 
                    WHERE Reparto.idCittaReparto = Citta.id";
            $rs = $db->query($sql);
            

            echo('<table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Nome Reparto</th>
                            <th scope="col">Città Reparto</th>
                            <th scope="col">Dipendenti Presenti</th>
                            <th scope="col">Gestione</th>
                        </tr>
                    </thead>
                ');
                echo('<tbody');
                while($record = $rs->fetch_assoc()){
                    echo('<tr>
                        <th scope="row">'.$record['id'].'</th>
                        <td>'.$record['Reparto'].'</td>
                        <td>'.$record['Citta'].'</td>');

                        // conto quanti dipendenti sono presenti nel reparto.
                        $sql = "SELECT COUNT(d.id) AS recordTrovati 
                                FROM dipendente AS d 
                                WHERE d.idReparto=".$record['id'];
                        $rs2 = $db->query($sql);
                        $record2 = $rs2->fetch_assoc();
                        echo("<td>".$record2['recordTrovati']."</td>");                    
                    
                    echo('<td><a class="btn btn-danger" role="button" href="reparto.php?scelta=checkReparto&idReparto='.$record['id'].'">Cancella</a></td>
                        </tr>
                    ');
                }
                echo('</tbody>');
                echo('<caption>Lista reparti presenti a database');
            echo('</table>');
            $db->close();
            break;
        }
        case "checkReparto":{
            /* in questo case verifico se l'id del reparto selezionato compare oppure no
            nella tabella dipendente, se non compare allora eseguo una cancellazione diretta del reparto (l'id del reparto non è FK nella tabella dipendente),
            se invece compare(l'id del reparto compare almeno una volta come FK in dipendente) allora predispongo un bottone per dare all'utente la possibilità di confermare la cancellazione
            dei record associati anche nella tabella dipendente. L'operazione di cancellazione nella tabella dipendente 
            avviene nel case 'deleteReparto' che esegue la cancellazione PRIMA sulla tabella 'dipendente' e POI sulla tabella 'reparto', procedimento per garantine l'integrità referenziale del
            database.
            */
            $idR = $_REQUEST['idReparto'];
            echo("Sto controllando se il reparto scelto interessa uno o più dipendenti...<br />");

            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            $sql = "SELECT * FROM dipendente WHERE idReparto=$idR";
            $rs = $db->query($sql);

            echo("Record trovati: ".$rs->num_rows."<br />");
            if($rs->num_rows == 0){
                /* num_rows mi restituisce il numero di righe che soddisfano la query SELECT eseguita (cioè il numero di record)
                    se 0 nessun dipendente è associato al reparto che voglio cancellare.
                    quindi posso eseguire direttamente la cancellazione del reparto.
                */
                $sql = "DELETE FROM reparto WHERE id=$idR";
                if($db->query($sql))
                    echo('<div class="alert alert-success">Reparto cancellato con successo.</div>');
                else
                    echo('<div class="alert alert-warning">Problema in cancellazione.</div>');
            }
            else{
                // in questo caso l'id del reparto che voglio cancellare
                // interessa una o più righe nella tabella dipendente
                // quindi chiedo all'utente se cancellare anche i dipendenti.
                // echo('<a class="btn btn-danger" role="button" href="reparto.php?scelta=deleteReparto&idReparto='.$idR.'">Conferma cancellazione Reparto e Dipendenti associati</a>');
                echo('<div class="alert alert-warning">ATTENZIONE: Questo reparto interessa uno i più Dipendenti.<br />Procedere alla loro cancellazione quindi riprovare.</div>');
            }

            $db->close();
            break;
        }
        case "deleteReparto":{
            $idR = $_REQUEST['idReparto']; // id del reparto da cancellare.

            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            // cancello tutti i dipendenti che hanno FK uguale al reparto che voglio cancellare
            $sql = "DELETE FROM dipendente WHERE idReparto=$idR";
            $rs = $db->query($sql);
            echo("Dipendenti cancellati.<br />");

            // cancellati i dipendenti cancello il reparto selezionato.
            $sql = "DELETE FROM reparto WHERE id=$idR";
            if($db->query($sql))
                echo('<div class="alert alert-success">Reparto cancellato con successo.</div>');
            else
                echo('<div class="alert alert-warning">Problema in cancellazione</div>');
            $db->close();
            break;
        }
        default:{
            echo('<div class="alert alert-warning">Attenzione, scelta non valida.</div>');
            break;
        }
    }
require("../include/foot.php");
 ?>