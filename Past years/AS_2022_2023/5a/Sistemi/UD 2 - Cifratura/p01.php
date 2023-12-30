<?php
$str_originale = "Banane2000";
$str_cifrata = md5($str_originale);

echo($str_originale." -- ".$str_cifrata);
?>