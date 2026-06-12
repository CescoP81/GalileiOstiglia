<?php
/*  Last Update: Thu 27.11.2025

Pagina dedicata alla gestione della tabella 'categoria' presente nel database.
Funzioni sviluppate:
- listaCategoria -> Visualizza tutte le cateogirie prodotti presenti a database.
- formNuovaCategoria -> Visualizza il form per l'inserimento dei dati di una nuova categoria.
- addNuovaCategoria -> Aggiunge alla tabella categoria nel DB il nuovo record.
*/
require("../include/lib.php");
writeHeader();
    writeMainMenu();

    /*  La scelta tramite HTTP REQUEST può arrivare in due modi:
        1. Tramite un link creato manualmente (es la menu bar nella funzione writeMainMenu nel file lib.php)
        2. Tramite il campo hidden con name=scelta presente in un form
        
        Se la scelta non viene passata in uno dei due modi precedenti allora non viene creata nel vettore
        REQUEST quindi la isset restituisce un false e si esce dall'IF passando per l'else, la variabile
        $sc viene impostata a null e nello switch-case che segue farà eseguire il caso di default.
        
        Se la scelta è invece passata e viene creata la chiave nel vettore REQUEST la isset restituisce un true
        e nella variabile $sc viene messo il contenuto della chiave nel vettore REQUEST. Se il contenuto è uguale
        ad uno dei case, allora quel particolare case viene eseguito.
    */
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

    switch($sc){
        case "listaCategoria":{
            // connessione al DB
            //$db = new mysqli("localhost", "root", "", "5ics01"); utilizzo le variabili globali nella lib.php
            $db = new mysqli($db_host, $db_user, $db_password, $db_name);
            // recupero dei dati dal DB.
            $sql = "SELECT * FROM categoria";
            $rs = $db->query($sql); // rs contiene tutti i dati estrapolati dal db (più o meno come la fetch in JS per json)
            // chiusura stream al database
            $db->close();

            /*echo('<b>Lista delle categorie presenti a database: </b><br />');
            // creazione dei singoli record estratti come vettori chiave-valore, le chiavi sono
            // i nomi delle colonne nelle tabelle a database.
            while($record = $rs->fetch_assoc()){
                echo($record['id'].' - '.$record['nome'].' - '.$record['descrizione'].'<br />');
            }*/

            echo('<table class="table table-striped table-hover">
                <thead>
                    <tr>
                    <th scope="col">ID</th>
                    <th scope="col">Nome</th>
                    <th scope="col">Descrizione</th>
                    </tr>
                </thead>
                <tbody>
            ');
            while($record = $rs->fetch_assoc()){
                echo('<tr>
                    <th scope="row">'.$record['id'].'</th>'.
                    '<td>'.$record['nome'].'</td>'.
                    '<td>'.$record['descrizione'].'</td>
                    </tr>
                ');
            }
            echo('</tbody>
                <caption>Elenco categorie prodotti</caption>
                </table>');
            break;
        }
        case "formNuovaCategoria":{
            /*  Visualizzo il form per l'inserimento di una nuova categoria, nome e descrizione.
                Il tasto submit alla fine del form richiama la pagina inserita nell'action passando tramite indirizzo
                http i due campi del form ed anche il campo nascosto (hidden) chiamato scelta con una stringa
                utile per selezionare il case che esegue effettivamente l'inserimento dei dati nel db.
            */
            echo('<div class="alert alert-success">Aggiunta di una nuova Categoria Prodotti</div>');
            
            echo('<form action="categoria.php" method="get">
                <div class="mb-3">
                    <label for="inputNomeCategoria" class="form-label">Nome Categoria:</label>
                    <input type="text" name="nomeCategoria" class="form-control" id="inputNomeCategoria" placeholder="Nome nuova categoria">
                </div>
                <div class="mb-3">
                    <label for="inputDescrizioneCategoria" class="form-label">Descrizione Categoria:</label>
                    <textarea name="descrizioneCategoria" class="form-control" id="inputDescrizioneCategoria" placeholder="Descrizione della nuova categoria" rows="3"></textarea>
                </div>
                <input type="hidden" name="scelta" value="addNuovaCategoria">
                <button type="submit" class="btn btn-primary">Inserisci</button>
            </form>');
            break;
        }
        case "addNuovaCategoria":{
// http://scuola.local/AS_2025_2026/5I/Informatica/CS01-CatalogoSoftware/1.0/php/categoria.php?nomeCategoria=Ufficio&descrizioneCategoria=Software+per+ufficio.&scelta=addNuovaCategoria

            /* in questo case arrivo solo dopo aver premuto il bottone nel form, quindi devo recuperare
                dal vettore REQUEST i valori delle chiavi 'nomeCategoria' e 'descrizioneCategoria', successivamente
                creo la query di inserimento 'INSERT INTO...' e una volta collegato al DB eseguo la query.
            */
            $nomeC = $_REQUEST['nomeCategoria'];
            $descrizioneC = $_REQUEST['descrizioneCategoria'];
            $sql = "INSERT INTO categoria(nome, descrizione) VALUES('$nomeC','$descrizioneC')";

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