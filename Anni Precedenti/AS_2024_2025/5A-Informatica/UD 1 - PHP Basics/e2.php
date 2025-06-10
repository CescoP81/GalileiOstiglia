<?php
/* semplice script PHP che ricevendo due valori mediante richiesta HTTP 
    nelle chiavi 'valore_a' e 'valore_b', comunica a video il valore maggiore
    ricevuto.

    http://.../e2.php?valore_a=7&valore_b=9

    http://scuola.local/AS_2024_2025/5A-Informatica/UD%201%20-%20PHP%20Basics/e2.php?valore_a=5&valore_b=9
*/
    // con isset verifico l'esistenza delle chiavi richieste nel vettore REQUEST
    // se la chiave esiste allora il contenuto lo sposto in una variabile semplice '$a' e '$b'.
    // altrimenti alle variabili semplici assegno un valore di default per esempio null.
    if(isset($_REQUEST['valore_a']))
        $a = $_REQUEST['valore_a'];
    else
        $a = null;

    if(isset($_REQUEST['valore_b']))
        $b = $_REQUEST['valore_b'];
    else
        $b = null;

    // fase successiva dove utilizzo i valori per l'algoritmo richiesto.
    if($a > $b){
        echo('Il valore maggiore tra i due è: '.$a.'<br />');
    }
    else{
        echo('Il maggiore tra i due è: '.$b.'<br />');
    }

?>