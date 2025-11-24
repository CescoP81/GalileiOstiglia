<?php
/* Pagina dedicata alla gestione della tabella 'categoria' presente nel database.
Funzioni sviluppate:
- listaCategoria: Visualizza tutte le cateogirie prodotti presenti a database.
*/
require("../include/lib.php");
writeHeader();
    writeMainMenu();

    // case generale con le scelte da gestire per operare sul db e visualizzare i dati.
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

    switch($sc){
        case "listaCategoria":{
            // connessione al DB
            $db = new mysqli("localhost", "root", "", "5ics01");

            // recupero dei dati dal DB.
            $sql = "SELECT * FROM categoria";
            $rs = $db->query($sql); // rs contiene tutti i dati estrapolati dal db (più o meno come la fetch in JS per json)
            // chiusura stream al database
            $db->close();

            echo('<b>Lista delle categorie presenti a database: </b><br />');
            // creazione dei singoli record estratti come vettori chiave-valore, le chiavi sono
            // i nomi delle colonne nelle tabelle a database.
            while($record = $rs->fetch_assoc()){
                echo($record['id'].' - '.$record['nome'].' - '.$record['descrizione'].'<br />');
            }

            echo('<br />');
            while($record = $rs->fetch_assoc()){
                echo($record['id'].' - '.$record['nome'].' - '.$record['descrizione'].'<br />');
            }
            break;
        }
        default:{
            echo('Scelta non valida, utilizzare il menu predisposto...<br />');
            break;
        }
    }
writeFooter();
?>