<?php
/*
    Creare la pagina PAGAMENTO.php che esegue le seguenti operazioni:
    1 -> Visualizza la lista dei dipendenti presenti con il tasto "Stampa Pagamenti" a fianco
    di ogni dipendente (come il tasto cancella nelle precedenti tabelle)

    2 -> Selezionato un dipendente crea il PDF contenente tutti i pagamenti attribuiti al dipendente.
*/
// include eventuali librerie utili alla UI.
require("../include/libGenerale.php");
// eseguo il test sulle variabili che posso ricevere tramite HTTP-REQUEST
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.php");
    scriviNavBar();
    echo('<div class="alert alert-primary">Sono nella sezione Pagamento - Ver 2.0</div>');

    switch($sc){
        case "listaPagamenti":{
            // in questo case visualizzo la lista dei dipendenti con un bottone
            // per ogni dipendente per creare il suo pdf.
            $sql = "select d.id, d.cognome, d.nome, c.nomeCitta, r.nomeReparto, c1.nomeCitta AS cittaReparto
                    FROM Dipendente AS d, Citta AS c, Reparto AS r, Citta AS c1 
                    WHERE d.idCittaResidenza=C.id AND d.idReparto=r.id AND r.idCittaReparto=c1.id";
            
            //$db = new mysqli("localhost", "root", "", "scuola2324");
            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            $rs = $db->query($sql);
            
            echo('<table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Cognome</th>
                            <th scope="col">Nome</th>
                            <th scope="col">Città di Residenza</th>
                            <th scope="col">Reparto di Impiego</th>
                            <th scope="col">Pagamenti Presenti</th>
                            <th scope="col">Gestione</th>
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
                        <td>'.$record['nomeReparto'].' di '.$record['cittaReparto'].'</td>');

                        // eseguo conteggio pagamenti associati al dipendente.
                        $sql = "SELECT COUNT(p.id) AS recordTrovati 
                                FROM pagamento AS p 
                                WHERE idDipendente=".$record['id'];
                        $rs2 = $db->query($sql);
                        $record2 = $rs2->fetch_assoc();
                        echo('<td>'.$record2['recordTrovati'].'</td>');

                        echo('<td>
                            <a class="btn btn-success" role="button" target="new" href="creaPdfPagamento.php?idDipendente='.$record['id'].'">
                            Stampa Cedolino</a>
                            </td>
                        </tr>
                    ');
                }
                echo('</tbody>');
                echo('<caption>Lista dipendenti presenti a database');
            echo('</table>');
            $db->close();
            break;
        }
        /*case "creaPdfPagamento":{
            // interrogazione del database e creazione della tabella
            // con i pagamenti specifici del dipendente scelto.
            $idD = $_REQUEST['idDipendente'];
            echo("Voglio il cedolino del dipendente con id: $idD");
            break;
        }*/
    }
require("../include/foot.php");
?>