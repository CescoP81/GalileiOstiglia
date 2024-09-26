<?php
$var1;  // dichiaro una variabile chiamata var1 e dal contenuto vuoto.

$var1 = 22; // assegno alla variabile un valore intero pari a 19.
echo($var1); // visualizzo il contenuto della variabile var1.
echo('<br />');

$var1 = $var1 / 2;
echo($var1);
echo('<br />');

$var1 = "Hello world";
echo($var1);
echo('<br />');

// esempio di selezione
$var1 = 22;
if($var1 >= 10){
    echo('Var1 è maggiore o uguale di 10.');
}
else{
    echo('Var1 è minore sicuramente di 10.');
}
echo('<br />');

// operatore di concatenazione tra stringhe e variabili
echo('la variabile vale: ' . $var1 . '<br />');

// Generare un numero random
// in C conosco la rand()
$var1 = rand(5, 25);
echo('Numero random: '.$var1.'<br />');

// ciclo di 10 numeri random
for($i=0; $i<10; $i++){
    $var1 = rand(5,25);
    echo($var1.' ');
}
echo('<br /><br />');

// Dichiarazione e utilizzo dei vettori/array
// metodo sbrigativo
$vet = array();
for($i=0; $i<10; $i++){
    $vet[$i] = rand(10,20);
}
for($i=0; $i<10; $i++){
    echo($vet[$i]. ' ');
}
echo('<br />');

// metodo migliore
$vet = array();
for($i=0; $i<10; $i++){
    array_push($vet, rand(10,20));    
}
for($i=0; $i<10; $i++){
    echo($vet[$i]. ' ');
}
echo('<br />');

// conoscere la lunghezza di un vettore
echo('Vet è lungo '.count($vet).' celle!<br />');
?>