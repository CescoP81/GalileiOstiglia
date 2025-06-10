<?php
// commento mono riga

/*
    commento
    multi
    riga
*/
echo('Hello World<br />');

// dichiarazione di una variabile.
$var;       // dichiaro una variabile vuota.
$var = 5;   // assegno il valore intero 5 alla variabile var. 
echo($var.'<br />');    // operatore . (punto) serve per concatenare stringhe a variabili.

$var = $var / 2;        // la variabile ora contiene un float
echo($var.'<br />');

$var = "Hello World II";    // la variabile ora contiene una stringa
echo($var.'<br />');

// se si vuole ottenere un numero random da assegna alla variabile var.
// vado su php.net
$var = rand();
echo($var.'<br />');

$var = rand(1, 20);     // var ottiene un numero random compreso tra 1 e 20
echo($var.'<br />');

// esempio di condinzionali
// gli operatori logici visti in C
// AND &&; OR ||;
// Uguale ==; Diverso !=
// < <= > >=
// sono uguali a quelli usati nel precedente linguaggio C/C++
if($var >= 10){
    echo('Il valore di var è <b>maggiore</b> o uguale di 10<br />');
}
else{
    echo('Il valore di var è <b>inferiore</b> a 10<br />');
}
//== anche il costrutto switch-case è identico al C/C++ ==

// esempio con iterative
// anche in PHP le iterative girano per condizione VERA

// vedere tutti i numeri da 1 a $var compreso (var è generato random qualche riga sopra)
for($i=1; $i<=$var; $i++){
    echo($i.' ');
}
echo('<br />');

// stesso ciclo ma con utilizzo della while
$i = 1;
while($i <= $var){
    echo($i.' ');
    $i++; //$i = $i+1;
}
echo('<br />');
echo('<br />');

// dichiarazione e utilizzo dei vettori
$vet = array();

for($i=0; $i<10; $i++){     // init con metodo 1
    $vet[$i] = rand(1,20);
}
for($i=0; $i<10; $i++){
    echo($vet[$i].' ');
}
echo('<br />');

$vet = null;
$vet = array();
for($i=0; $i<10; $i++){         // init con metodo 2 (più elegante usare la funzione ad hoc)
    array_push($vet, rand(1,20));
}
for($i=0; $i<10; $i++){
    echo($vet[$i].' ');
}
echo('<br />');

echo('Numero di elementi: '.count($vet));

?>