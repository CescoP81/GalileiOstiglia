<?php
/* Last Update: Thu 06.12.2025

Pagina dedicata alla gestione della tabella 'produttore' presente nel database.
Funzioni sviluppate:
- listaProduttori -> Visualizza tutti i produttori presenti a database.
- formNuovoProduttore -> Visualizza il form per l'inserimento dei dati di una nuovo produttore.
- addNuovoProduttore -> Aggiunge alla tabella produttore nel DB il nuovo record.
*/
require("../include/lib.php");
writeHeader();
    writeMainMenu();

    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
    switch($sc){
        case "listaProduttori":{
            $db = new mysqli($db_host, $db_user, $db_password, $db_name);
            $sql = "SELECT * FROM produttore";
            $rs = $db->query($sql); 
            $db->close();

            echo('<table class="table table-striped table-hover">
                <thead>
                    <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Nome</th>
                    <th scope="col">e-mail</th>
                    <th scope="col">Sito Web</th>
                    <th scope="col">Telefono</th>
                    </tr>
                </thead>
                <tbody>
            ');
            while($record = $rs->fetch_assoc()){
                echo('<tr>
                    <th scope="row">'.$record['id'].'</th>'.
                    '<td>'.$record['nome'].'</td>'.
                    '<td>'.$record['email'].'</td>'.
                    '<td>'.$record['sitoWeb'].'</td>'.
                    '<td>'.$record['telefono'].'</td>'.
                    '</tr>
                ');
            }
            echo('</tbody>
                <caption>Elenco produttori</caption>    
                </table>');
            break;
        }
        case "formNuovoProduttore":{
            echo('<div class="alert alert-success">Aggiunta di un nuovo Produttore</div>');
            
            echo('<form action="produttore.php" method="get">
                <div class="mb-3">
                    <label for="inputNomeProduttore" class="form-label">Nome Produttore:</label>
                    <input type="text" name="nomeProduttore" class="form-control" id="inputNomeProduttore" placeholder="Nome nuova categoria">
                </div>
                <div class="mb-3">
                    <label for="inputEmailProduttore" class="form-label">E-mail Produttore:</label>
                    <input type="text" name="emailProduttore" class="form-control" id="inputEmailProduttore" placeholder="Nome nuova categoria">
                </div>
                <div class="mb-3">
                    <label for="inputSitoProduttore" class="form-label">Sito Web Produttore:</label>
                    <input type="text" name="sitoProduttore" class="form-control" id="inputSitoProduttore" placeholder="Nome nuova categoria">
                </div>
                <div class="mb-3">
                    <label for="inputTelefonoProduttore" class="form-label">Telefono Produttore:</label>
                    <input type="text" name="telefonoProduttore" class="form-control" id="inputTelefonoProduttore" placeholder="Nome nuova categoria">
                </div>

                <input type="hidden" name="scelta" value="addNuovoProduttore">
                <button type="submit" class="btn btn-primary">Inserisci</button>
            </form>');
            break;
        }
        case "addNuovoProduttore":{
            $nomeP = $_REQUEST['nomeProduttore'];
            $emailP = $_REQUEST['emailProduttore'];
            $sitoP = $_REQUEST['sitoProduttore'];
            $telefonoP = $_REQUEST['telefonoProduttore'];
            $sql = "INSERT INTO produttore(nome, email, sitoWeb, telefono) VALUES('$nomeP', '$emailP', '$sitoP', '$telefonoP')";
            
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