<?php
// usare http://..../e1.php?val1=3&val2=9&val3=21

if(isset($_REQUEST['val1'])) $v1 = $_REQUEST['val1']; else $v1 = null;
if(isset($_REQUEST['val2'])) $v2 = $_REQUEST['val2']; else $v2 = null;
if(isset($_REQUEST['val3'])) $v3 = $_REQUEST['val3']; else $v3 = null;

// punto 1
if($v1<$v2 && $v2<$v3)
    echo("I tre valori sono in ordine crescente.<br />");
else
    echo("I tre valori non rispettano la condizione richiesta.<br />");

// punto 2
$min = $v1;
if($v2 < $min) $min = $v2;
if($v3 < $min) $min = $v3;
$max = $v1;
if($v2 > $max) $max = $v2;
if($v3 > $max) $max = $v3;

echo("Valore minimo inserito: ".$min." e valore massimo: ".$max."<br />");

if($v3 > $v2){
    echo("Valori compresi tra ".$v2." e ".$v3." multipli di ".$v1.":<br />");
    for($i=$v2; $i<$v3; $i++){
        if($i % $v1 == 0)
            echo($i." ");
    }
}
else{
    echo("Serie non realizzabile con i valor inseriti.<br />");
}
?>