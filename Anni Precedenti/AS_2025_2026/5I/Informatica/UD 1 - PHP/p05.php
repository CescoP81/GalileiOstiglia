<?php
$vet1 = array(5,6,4,3,8,9,10,43);

// visualizzo il contenuto di determinate celle conoscendo l'indice
echo($vet1[0].'<br />');
echo($vet1[1].'<br />');
echo($vet1[2].'<br />');
echo('<br /><br />');

// visualizzo il contenuto di tutte le celle sapendo la dimensione del vettore
for($i=0; $i<6; $i++){
    echo($vet1[$i].', ');
}
echo('<br /><br />');
$dim = count($vet1);
echo('Numero valori: '.$dim.'<br />');
for($i=0; $i<$dim; $i++){
    echo($vet1[$i].', ');
}

echo('<br /><br />');
array_push($vet1, 99);
array_push($vet1, 101);
$dim = count($vet1);
echo('Numero valori: '.$dim.'<br />');
for($i=0; $i<$dim; $i++){
    echo($vet1[$i].', ');
}

// esempio di array associativi: al posto dei singoli indici ho delle chiavi univoche.
echo('<br /><br />');
$vet2 = array(
    "mela" => "verde",
    "arancia" => "arancione",
    "banana" => "gialla",
    "anguria" => "rossa");

echo($vet2['arancia'].'<br />');
echo($vet2['anguria'].'<br />');
echo($vet2[2].'<br />');

// recupero chiavi di un vettore associativo e stampa di tutti i valori presenti
// step 1: recupero tutte le chiavi che compongono il mio vettore
$keys = array_keys($vet2);
$dim = count($keys);        // recupero il numero di chiavi inserite nell vettore keys
echo('Chiavi presenti: '.$dim.'<br />');
for($i=0; $i<$dim; $i++){   // keys lavora con gli indici numerici da 0 a n-1 chiavi
    echo($keys[$i].'<br />');
}
echo('<br />');
for($i=0; $i<$dim; $i++){
    echo($keys[$i].' -> '.$vet2[$keys[$i]].'<br />');
}
?>