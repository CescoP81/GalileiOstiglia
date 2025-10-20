<?php
/* Realizzare una pagina PHP che tramite indirizzo e chiavi HTTP REQUEST riceva 3 valori 'valore1' 'valore2'
'valore3' contenenti 3 valori interi di cui determinare il minimo, il massimo e se sono stati passati 
in ordine crescente.
es di indirizzo http:
http://localhost/.../p03.php?valore1=4&valore2=8&valore3=9
*/
echo('<DOCTYPE html>
    <html>
        <head><title>Serie di tre numeri interi</title></head>
        <body>
');

    $v1 = $_REQUEST['valore1']; // v1 è la variabile della pagina; valore1 è la chiave da specificare nell'indirizzo http.
    $v2 = $_REQUEST['valore2'];
    $v3 = $_REQUEST['valore3'];

    echo('Valori inseriti: '.$v1.','.$v2.','.$v3.'<br /><br />');

    // test dell'ordine crescente
    if($v1<$v2 && $v2<$v3){
        echo('OK, i tre valori sono in ordine crescente!<br />');
    }
    else{
        echo('I tre valori non sono in ordine crescente!<br />');
    }

    // calcolo del minimo.
    $min = $v1;
    if($v2 < $min)
        $min = $v2;
    if($v3 < $min)
        $min = $v3;
    echo('Il valore minimo passato con HTTP REQUEST è: '.$min.'<br />');

    // calcolo del massimo.
    $max = $v1;
    if($v2 > $max)
        $max = $v2;
    if($v3 > $max)
        $max = $v3;
    echo('Il valore maggiore passato con HTTP REQUEST è: '.$max.'<br />');
echo('</body></html>');
?>