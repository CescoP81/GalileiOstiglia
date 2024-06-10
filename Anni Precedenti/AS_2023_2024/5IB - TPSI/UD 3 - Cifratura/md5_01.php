<?php
// creo una stringa inizializzata con una parola di mio gradimento.
$str = "Francesco";

// creo una variabile e assegno il risultato della cifratura con funzione MD5
$strCifrata = md5($str);

// stampo la stringa originale e la stringa cifrata.
echo("Originale: ".$str."<br />Cifrata MD5: ".$strCifrata);

$strSha1 = sha1($str);
echo("<br /><br />Originale: ".$str."<br />Cifrata MD5: ".$strSha1);
?>