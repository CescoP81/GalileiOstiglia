<?php
require('../include/lib.php');
// richiamo la header per generale il codice iniziale della pagina.
writeHeader();
writeMenu();

    // >> il tuo codice inizia qui.
    echo('<div class="alert alert-success">Sono nella sezione della REGIONE</div>');
    if(isset($_REQUEST['scelta']))
        $sc = $_REQUEST['scelta'];
    else 
        $sc = null;

    switch($sc){
        case "formRegione":{
            //echo('Voglio inserire una nuova regione...');
            echo('
                <form action="regione.php">
                    <div class="mb-3">
                        <label for="inputNomeRegione" class="form-label">Nome della Regione</label>
                        <input type="text" name="nomeRegione" class="form-control" id="inputNomeRegione" aria-describedby="emailHelp">
                    </div>
                    <input type="hidden" name="scelta" value="addNuovaRegione">
                    <button type="submit" class="btn btn-primary">Inserisci la Regione</button>
                </form>');
            break;
        }
        case "addNuovaRegione":{
            // case nel quale arrivo se viene premuto il bottone nel form di inserimento di una nuova regione
            $nomeR = $_REQUEST['nomeRegione'];
            $sql = "INSERT INTO regione(nome) VALUE('$nomeR')";

            echo($sql);
            $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
            if($db->query($sql))
                echo('<div class="alert alert-success">Nuova regione aggiunta!</div>');
            else
                echo('<div class="alert alert-danger">Problema in inserimento nuova regione!</div>');
            $db->close();
            break;
        }
        case "listaRegioni":{
            // step 1. creo uno strem al database mysql
            $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);

            // step 2. creo e eseguo la query sql per selezionare tutti i record
            // della tabella regione
            $sql = "SELECT * FROM regione";
            $resultSet = $db->query($sql);

            /*while($record = $resultSet->fetch_assoc()){
                echo($record['id']." ".$record['nome']."<br />");
            }*/
            // scrivo la parte statica di creazione di una tabella con BootS
            echo('
                <table class="table table-striped">
                    <thead>
                        <tr>
                            <th scope="col">#</th>
                            <th scope="col">Nome Regione</th>
                            <th scope="col">Gestisci</th>
                        </tr>
                    </thead>
                    <tbody>
            ');
            // le righe le genero dinamicamente con PHP e il ciclo while
            while($record = $resultSet->fetch_assoc()){
                echo('
                        <tr>
                            <th scope="row">'.$record['id'].'</th>
                            <td>'.$record['nome'].'</td>
                            <td><a class="btn btn-primary" href="regione.php?scelta=deleteRegione&idRegione='.$record['id'].'">Cancella</a>
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
        case "deleteRegione":{
            $idR = $_REQUEST['idRegione'];
            $sql = "DELETE FROM regione WHERE id=$idR";
            echo($sql);

            $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
            if($db->query($sql))
                echo('<div class="alert alert-success">Regione cancellata correttamente.</div>');
            else
                echo('<div class="alert alert-danger">Problema in cancellazione regione.</div>');
            $db->close();
            break;
        }
    }
    // >> il tuo codice finisce qui.
    
// richiamo la footer per chiudere in modo corretto le pagine.
writeFooter();
?>