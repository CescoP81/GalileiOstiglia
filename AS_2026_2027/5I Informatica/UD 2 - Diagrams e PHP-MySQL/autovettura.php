<!-- 
    filename: autovettura.php
    date: 18.11.26 21:30
    Description: file PHP per la gestione della tabella autovettura
    - Visualizza le autovetture presenti.
    - Visualizza il form per l'inserimento di una nuova autovettura.
    - Inserisce i dati nella tabella mySQL.
-->
<!DOCTYPE html>
<html>
    <head>
        <title>Rivendita Auto Usate</title>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.13.1/font/bootstrap-icons.min.css">
    </head>
    <body>
        <div class="container mt-3">
            <!-- Creo la navbar con le opzioni generali -->
            <nav class="navbar navbar-expand-lg bg-body-tertiary">
                <div class="container-fluid">
                    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                        <span class="navbar-toggler-icon"></span>
                    </button>
                    <div class="collapse navbar-collapse" id="navbarSupportedContent">
                        <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                            <li class="nav-item">
                                <a class="nav-link active" aria-current="page" href="autovettura.php?scelta=vediCatalogo">Vedi Catalogo</a>
                            </li>
                            <li class="nav-item">
                                <a class="nav-link" href="autovettura.php?scelta=formNuovaAutovettura">Nuova Autovettura</a>
                            </li>
                        </ul>
                    </div>
                </div>
            </nav>

            <?php
                if(isset($_GET['scelta'])) $sc = $_GET['scelta']; else $sc = null;
                switch($sc){
                    case "vediCatalogo":{
                        // caso in cui devo visualizzare il catalogo, cioè tutte le auto nella tabella mySQL.

                        // mi collego al database e estraggo tutte le righe con una select di base.
                        $db = new mysqli("localhost","root","","5i_as2627");
                        
                        // preparo la query mySQL da eseguire
                        $sql = "SELECT * FROM autovettura";

                        // eseguo la query e ricevo la risposta in una variabile 'resultSet' -> analoga alla promise usata nei JSON
                        // se la query va a buon fine, resultSet contiene un vettore con tutti i record estratti dalla query.
                        $resultSet = $db->query($sql);
                        $db->close();
                        ?>
                        <!-- preparo l'intestazione della tabella -->
                        <table class="table">
                            <thead>
                                <tr>
                                <th scope="col">id</th>
                                <th scope="col">Marca</th>
                                <th scope="col">Modello</th>
                                <th scope="col">Anno Immatricolazione</th>
                                <th scope="col">Provincia</th>
                                <th scope="col">Uniproprietario</th>
                                <th scope="col">Kilometraggio</th>
                                <th scope="col">Gestione</th>
                                </tr>
                            </thead>
                            <tbody>
                                <?php
                                // estraggo un record alla volta dalla resultSet e ne vado a stampare i valori richiamando le 'chiavi' -> 'colonne della tabella mysql'
                                while($record = $resultSet->fetch_assoc()){
                                        echo('<tr>
                                            <th scope="row">'.$record['id'].'</th>
                                            <td>'.$record['marca'].'</td>
                                            <td>'.$record['modello'].'</td>
                                            <td>'.$record['annoImmatricolazione'].'</td>
                                            <td>'.$record['provincia'].'</td>
                                            <td>'.$record['uniproprietario'].'</td>
                                            <td>'.$record['kilometraggio'].'</td>
                                            <td><a class="btn btn-danger btn-lg" href="autovettura.php?scelta=cancellaRecord&idRecord='.$record['id'].'">Cancella</a></td>
                                            <td><a class="btn btn-danger btn-lg" href="autovettura.php?scelta=cancellaRecord&idRecord='.$record['id'].'"><i class="bi bi-apple"></i></a></td>
                                        </tr>');
                                }
                                ?>
                            </tbody>
                        </table>
                        <?php
                        break;
                    }
                    case "formNuovaAutovettura":{
                        /* utilizzando le classi Bootstrap 5.3.8 creo tutto il form con:
                            - caselle di testo (form control)
                            - radio button (form-check)
                            - input nascosco (<input type type="hidden"...>)
                            - bottone submit a fine del form.
                            Per il layour ho deciso di fare una riga (class="row") a 3 colonne(class="col")
                            ed una riga finale a singola colonna con testo allineato al centro (class="col text-center")

                            !ATTENZIONE!
                            tutto deve essere incluso in un tag <form ...> l'attributo action specifica la pagina da richiamare quando viene
                            premuto il buttone submit
                        */
                        ?>
                        <form action="autovettura.php" method="get">
                            <div class="row">
                                <div class="col">
                                    <div class="form-group">
                                        <div class="mb-3">
                                        <label for="inputMarca" class="form-label">Marca Autovettura</label>
                                        <input class="form-control" type="text" id="inputMarca" name="inputMarca" placeholder="Marca autovettura" aria-label="Input marca autovettura">
                                        </div>
                                        <div class="mb-3">
                                        <label for="inputModello" class="form-label">Modello Autovettura</label>
                                        <input class="form-control" type="text" id="inputModello" name="inputModello" placeholder="Modello autovettura" aria-label="Input modello autovettura">
                                        </div>   
                                    </div>
                                </div>

                                <div class="col">
                                    <div class="form-group">
                                        <div class="form-group">
                                            <div class="mb-3">
                                            <label for="inputAnno" class="form-label">Anno Immatricolazione</label>
                                            <input class="form-control" type="text" id="inputAnno" name="inputAnno" placeholder="Anno Immatricolazione" aria-label="Input anno immatricolazione">
                                            </div>
                                            <div class="mb-3">
                                            <label for="inputProvincia" class="form-label">Provincia</label>
                                            <input class="form-control" type="text" id="inputProvincia" name="inputProvincia" placeholder="Provincia" aria-label="Input provincia">
                                            </div>   
                                        </div>
                                    </div>
                                </div>

                                <div class="col">
                                    <div class="form-group">
                                        <div class="form-group">
                                            <div class="mb-3">
                                                <label for="inputAnno" class="form-label">Nr. Proprietari</label>
                                                <div class="form-check">
                                                    <input class="form-check-input" type="radio" name="inputUnip" id="inputUnipTrue" value="1" checked>
                                                    <label class="form-check-label" for="inputUnipTrue">
                                                        Uniproprietario
                                                    </label>
                                                </div>
                                                <div class="form-check">
                                                    <input class="form-check-input" type="radio" name="inputUnip" id="inputUnipFalse" value="0">
                                                    <label class="form-check-label" for="inputUnipFalse">
                                                        Auto Seconda mano
                                                    </label>
                                                </div>
                                            </div>
                                            <div class="mb-3">
                                            <label for="inputKilometraggio" class="form-label">Kilometri Percorsi</label>
                                            <input class="form-control" type="text" id="inputKilometri" name="inputKilometri" placeholder="Kilometri percorso" aria-label="Input Kilometri">
                                            </div>   
                                        </div>
                                    </div>
                                </div>
                            </div> <!-- chiude la prima riga a tre colonne -->
                            <div class="row">
                                <div class="col text-center">
                                    <input type="hidden" name="scelta" value="aggiungiAutovettura">
                                    <button type="submit" class="btn btn-primary">Aggiungi Dati Auto</button>
                                </div>
                            </div> <!-- chiude la seconda riga a colonna singola -->
                        </form>
                        <?php
                        break;
                    }
                    case "aggiungiAutovettura":{
                        // recupero dal vettore $_GET i valori che l'untente ha inserito nei campi di testo
                        $marca = $_GET['inputMarca'];
                        $modello = $_GET['inputModello'];
                        $annoImm = $_GET['inputAnno'];
                        $prov = $_GET['inputProvincia'];
                        $uniprop = $_GET['inputUnip'];
                        $kilometri = $_GET['inputKilometri'];

                        // mi collego al database
                        $db = new mysqli("localhost", "root", "", "5i_as2627");
                        // preparo lo statement da eseguire; preferibile alla semplice query per evitare SQL injections.
                        // reference ufficiale: https://www.php.net/manual/en/mysqli.quickstart.prepared-statements.php
                        $stmt = $db->prepare("INSERT INTO autovettura(marca, modello, annoImmatricolazione, provincia, uniproprietario, kilometraggio) VALUES(?,?,?,?,?,?)");
                        // eseguo il bind 'associo' il tipo di dato da inserire alla variabile che lo contiene 
                        $stmt->bind_param("ssssii", $marca, $modello, $annoImm, $prov, $uniprop, $kilometri);
                        
                        // eseguo lo statement -> ritorna true se va a buon fine altrmenti un false.
                        if($stmt->execute())
                            echo('<div class="alert alert-success text-center"><h3>Autovettura inserita correttamente</h3></div>');
                        else
                            echo('<div class="alert alert-warning text-center"><h3>ERRORE in aggiunta autovettura</h3></div>');
                        $db->close();
                        break;
                    }
                    case "cancellaRecord":{
                        // recupero l'id del record da cancellare dalla http requesto
                        $idR = $_REQUEST['idRecord'];

                        // mi collego al database
                        $db = new mysqli("localhost","root","","5i_as2627");
                        $sql = "DELETE FROM autovettura WHERE id=$idR";

                        if($db->query($sql))
                            echo('<div class="alert alert-success text-center"><h3>Cancellazione avvenuta...</h3></div>');
                        else
                            echo('<div class="alert alert-warning text-center"><h3>Ops, qualquadra non cosa...</h3></div>');

                        $db->close();
                        break;
                    }
                }
            ?>
        </div>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>
    </body>
</html>