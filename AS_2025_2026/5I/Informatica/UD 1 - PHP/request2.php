<?php
/* questo codice è inserito nella pagina/file: request2.php
    NON richiede altri file ne PHP ne HTML
*/

echo('<!DOCTYPE html>
    <html>
        <head>
            <title>Passaggio dati da FORM a PHP su singola pagina.</title>
        </head>
        <body>
');
/*  eseguo un test sul vettore delle REQUEST e verifico che ci sia la chiave 'scelta', se esiste assegno il suo valore
    ad una variabile della pagina, altrimenti assegno il valore null che mi farà cadere nel caso default dello switch.
*/
if(isset($_REQUEST['scelta'])) $scelta = $_REQUEST['scelta']; else $scelta = null;

    switch($scelta){
        case "calcolaValori":{
            /* se nel vettore delle REQUEST il valore della chiave 'scelta' vale calcolaValori allora
                estraggo i valori di base e altezza, eseguo i calcoli e comunico i risultati, il link
                presente dopo i risultati rimanda alla pagina PHP.
            */
            $b = $_REQUEST['base'];
            $h = $_REQUEST['altezza'];

            $area = $b * $h;
            $perim = ($b + $h) * 2;
            echo('Rettangolo di dimensioni: '.$b.'x'.$h.'<br />');
            echo('<b>Area: </b>'.$area.'<br />');
            echo('<b>Perimetro: </b>'.$perim.'<br /><br />');
            echo('<a href="request2.php">Torna al form</a>');
            break;
        }
        default:{
            /* se nel vettore delle REQUEST non è presente la chiave 'scelta' o per errore ha un 
            valore diverso da quello/i aspettato/i, allora presento informazioni di default, in questo caso il form
            per l'inserimento dei dati.
            NB: in questo form è presente il campo hidden (non si vede a video ma c'è nel form) e contiene il valore 'calcolaValori' per 
            entrare nel case che esegue i calcoli.
            */
            echo('Inserisci i dati base e altezza di un ipotetico rettangolo:<br />
                <form action="request2.php" method="get">
                Base: <input type="text" name="base"><br />
                Altezza: <input type="text" name="altezza"><br />
                <input type="hidden" name="scelta" value="calcolaValori">
                <input type="submit" value="Esegui calcoli...">
            </form>');
            break;
        }
    }

echo('  </body>
    </html>');
?>