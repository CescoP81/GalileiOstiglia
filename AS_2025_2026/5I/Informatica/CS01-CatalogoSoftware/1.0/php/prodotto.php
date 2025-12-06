<?php
/* Last Update: Thu 06.12.2025

Pagina dedicata alla gestione della tabella 'produttore' presente nel database.
Funzioni sviluppate:
- listaProdotti -> Visualizza tutti i prodotti presenti a database, richiamando il relativo produttore e categoria.
- formNuovoProdotto -> Visualizza il form per l'inserimento dei dati di un nuovo prodotto.
- addNuovoProdotto -> Aggiunge alla tabella prodotto nel DB il nuovo record.
*/
require("../include/lib.php");
writeHeader();
    writeMainMenu();

    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
    switch($sc){
        case "listaProdotti":{
            // in questo caso la query da eseguire non è su singola tabella, ma richiama le
            // tabelle referenziate tramite Foreign Key (Chiavi Esterne).
            // Vista la presenza di più attributi 'nome' che andrebbero a generare la stessa chiave nel
            // vettore $record, dobbiamo rinominare almeno due 'nome' utilizzando l'operatore mysql AS.
            $db = new mysqli($db_host, $db_user, $db_password, $db_name);
            $sql = "SELECT prodotto.id, prodotto.nome, prodotto.descrizione, prodotto.prezzo, categoria.nome AS categoria, produttore.nome AS produttore 
                    FROM prodotto, categoria, produttore 
                    WHERE prodotto.idCategoria = categoria.id AND prodotto.idProduttore = produttore.id";            
            $rs = $db->query($sql); 
            $db->close();

            echo('<table class="table table-striped table-hover">
                <thead>
                    <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Prodotto</th>
                    <th scope="col">Descrizione</th>
                    <th scope="col">Prezzo</th>
                    <th scope="col">Categoria</th>
                    <th scope="col">Produttore</th>
                    </tr>
                </thead>
                <tbody>
            ');
            while($record = $rs->fetch_assoc()){
                echo('<tr>
                    <th scope="row">'.$record['id'].'</th>'.
                    '<td>'.$record['nome'].'</td>'.
                    '<td>'.$record['descrizione'].'</td>'.
                    '<td>'.$record['prezzo'].'</td>'.
                    '<td>'.$record['categoria'].'</td>'.
                    '<td>'.$record['produttore'].'</td>'.
                    '</tr>
                ');
            }
            echo('</tbody>
                <caption>Elenco prodotti a catalogo</caption>
                </table>');
            break;
        }
        case "formNuovoProdotto":{
            echo('<div class="alert alert-success">Aggiunta di un nuovo Produttore</div>');
            
            echo('<form action="prodotto.php" method="get">
                <div class="mb-3">
                    <label for="inputNomProdotto" class="form-label">Nome Prodotto:</label>
                    <input type="text" name="nomeProdotto" class="form-control" id="inputNomeProdutto" placeholder="Nome nuova categoria">
                </div>
                <div class="mb-3">
                    <label for="inputDiscrzioneProdotto" class="form-label">Descrizione Prodotto:</label>
                    <input type="text" name="descrizioneProdotto" class="form-control" id="inputDiscrzioneProdotto" placeholder="Nome nuova categoria">
                </div>
                <div class="mb-3">
                    <label for="inputPrezzoProdotto" class="form-label">Prezzo Prodotto:</label>
                    <input type="text" name="prezzoProdotto" class="form-control" id="inputPrezzoProdotto" placeholder="Nome nuova categoria">
                </div>');

                // costruisco dinamicamente la select dei produttori, prendendo i dati dal DB con i produttori
                // esistenti e creando quindi tante options quanti sono i produttori estratti.
                // nel campo valure metto l'id (chiave primaria) estratto da produttori, mentre il testo
                // visualizzato per quella specifica option è il nome del produttore.
                $db = new mysqli($db_host, $db_user, $db_password, $db_name);
                $sql = "SELECT * FROM produttore";
                $rs = $db->query($sql);

                echo('<div class="mb-3">
                        <label for="inputPrezzoProdotto" class="form-label">Produttore:</label>');
                echo('<select class="form-select" name="codProduttore" aria-label="Default select example">');
                    while($record = $rs->fetch_assoc()){
                        echo('<option value="'.$record['id'].'">'.$record['nome'].'</option>');
                    }
                echo('</select>
                </div>');

                // creo dinamicamente la select per la categoria del prodotto
                $sql = "SELECT * FROM categoria";
                $rs = $db->query($sql);
                echo('<div class="mb-3">
                        <label for="inputCategoriaProdotto" class="form-label">Categoria:</label>');
                echo('<select class="form-select" name="codCategoria" aria-label="Default select example">');
                    while($record = $rs->fetch_assoc()){
                        echo('<option value="'.$record['id'].'">'.$record['nome'].'</option>');
                    }
                echo('</select>
                </div>');
                $db->close();

            echo('<input type="hidden" name="scelta" value="addNuovoProdotto">
                <button type="submit" class="btn btn-primary">Inserisci</button>
            </form>');
            break;
        }
        case "addNuovoProdotto":{
            $nomeP = $_REQUEST['nomeProdotto'];
            $descrizioneP = $_REQUEST['descrizioneProdotto'];
            $prezzoP = $_REQUEST['prezzoProdotto'];
            $codiceProduttore = $_REQUEST['codProduttore'];
            $codiceCategoria = $_REQUEST['codCategoria'];

            $sql = "INSERT INTO prodotto(nome, descrizione, prezzo, idProduttore, idCategoria) 
                    VALUES('$nomeP', '$descrizioneP', $prezzoP, '$codiceProduttore', '$codiceCategoria')";
            
            //echo($sql);
            
            $db = new mysqli($db_host, $db_user, $db_password, $db_name);
            if($db->query($sql))
                echo('<div class="alert alert-success">Inserimento avvenuto con successo</div>');
            else
                echo('<div class="alert alert-danger">Problema in inserimento</div>');
            $db->close();
            
            break;
        }
        default:{
            echo('Scelta non valida, utilizzare il menu predisposto...<br />');
            break;
        }
    }
writeFooter();
?>