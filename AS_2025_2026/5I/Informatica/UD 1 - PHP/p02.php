<?php
/*
    Attraverso l'indirizzo HTTP chiamato posso passare dei valori alla pagina PHP.
    I valori vengono passati secondo la struttura chiave=valore dove chiave sarà
    un identificatore univoco in un vettore, mentre valore sarà appunto il valore contenuto da quella cella
    del vettore.

    HTTP REQUEST (richiesta http)
    http://localhost/cartella1/p02.php?chiave1=5&chiave2=9

    quindi:
    chiave1 e chiave2 sono le chiavi del vettore generale REQUEST, mentre 5 e 9 saranno i valori associati.
*/
echo('<DOCTYPE html>
    <html>
        <head><title>Prova di valori passati come parametri http</title></head>
        <body>
');
    $v1 = $_REQUEST['base'];
    $v2 = $_REQUEST['altezza'];

    $area = $v1 * $v2;
    echo('Area rettangolo di base '.$v1.' di altezza '.$v2.': '.$area);
echo('</body></html>');
?>