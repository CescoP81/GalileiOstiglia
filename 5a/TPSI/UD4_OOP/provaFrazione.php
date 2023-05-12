<?php
require('Frazione.php');

$f = new Frazione(7,3);

echo("Numeratore: ".$f->getNumeratore()."<br />");
echo("Denominatore: ".$f->getDenominatore()."<br />");
echo("<br />");

$f->setNumeratore(12);
$f->setDenominatore(7);
echo("Numeratore: ".$f->getNumeratore()."<br />");
echo("Denominatore: ".$f->getDenominatore()."<br />");
$f->stampaFrazione();
echo("<br />");
echo("Decimale: ". $f->getDecimale());
?>