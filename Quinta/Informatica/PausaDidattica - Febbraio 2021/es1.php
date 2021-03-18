<?php
/*
    Pagina php che viene invocata dalla pagina es1.html, recupera i dati passati dal form
    tramite il vettore REQUEST[] e utilizza tali dati per il calcolo di area e perimetro.
*/
$b = $_REQUEST['base_rettangolo'];
$a = $_REQUEST['altezza'];

echo($b." ".$a."<br />");
echo("Area rettangolo: ".($a*$b)."<br />");
echo("Perimetro: ".($a+$a+$b+$b));

?>