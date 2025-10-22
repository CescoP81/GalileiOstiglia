<?php
/* questo codice è inserito nel file: request1.php
    viene richiamato dalla pagina/file request1.html
*/

/* --parte iniziale del codice html della pagina, scritto con la funzione echo */
echo('<!DOCTYPE>
    <html>
        <head>
            <title>Passaggio dati da FORM HTML a PHP</title>
        </head>
        <body>
');

// recupero i dati dal vettore REQUEST ottenuti dal FORM HTML e li elaboro per poi comunicare i risultati
$b = $_REQUEST['base'];
$h = $_REQUEST['altezza'];

$area = $b * $h;
$perim = ($b + $h) * 2;
    echo('Rettangolo di dimensioni: '.$b.'x'.$h.'<br />');
    echo('<b>Area: </b>'.$area.'<br />');
    echo('<b>Perimetro: </b>'.$perim.'<br /><br />');
    echo('<a href="request1.html">Torna al form</a>');

echo('  </body>
    </html>');
?>