<?php
/* Realizzare una pagina PHP che permetta l'inserimento di un valore intero,
    recuperato dal vettore REQUEST il valore: se compreso tra 10 e 20 inizializzare
    un vettore di altrettante celle con valori casuali dispari. Visualizzare il vettore
    e comunicarne la media complessiva.
    (reference alla funzione random in PHP: https://www.php.net/manual/it/function.rand.php)
*/
require("lib.php");
    writeStart();
            if(isset($_REQUEST['scelta']) == true) $sc = $_REQUEST['scelta']; else $sc = null;
            
            echo('Genera vettore random...<br />');
            switch($sc){
                case "generaVettoreRandom":{
                    // recupero i valori dalle REQUEST
                    $numCelle = $_REQUEST['numeroCelle'];
                    if($numCelle >=10 && $numCelle<=20){
                        // il numero di celle è valido, quindi genero il vettore con numeri dispari
                        $vet = array();
                        $randomico=0;
                        for($i=0; $i<$numCelle; $i++){
                            $randomico = rand(1, 50);
                            if($randomico%2 == 0) $randomico = $randomico + 1;

                            array_push($vet, $randomico);
                        }

                        // stampo il vettore generato con numeri random dispari.
                        echo('<br >Vettore di '.$numCelle.' valori dispari: <br />');
                        for($i=0; $i<$numCelle; $i++){
                            echo($vet[$i].', ');
                        }
                        echo('<br /><br />');
                    }
                    else{
                        echo('Numero celle scelto non valido...<br />');
                    }

                    echo('<a href="ese02.php">Torna al form</a>');
                    break;
                }
                default:{
                    // visualizza il form di inserimento dati essenziali tre numeri interi
                    echo('<form action="ese02.php" method="get">
                        <b>Numero celle:</b><br />
                        <input class="form-control" type="text" name="numeroCelle" placeholder="" aria-label="default input example">
                        
                        <input type="hidden" name="scelta" value="generaVettoreRandom">
                        <button type="submit" class="btn btn-primary mb-3">Genera Array</button>
                    </form>');
                    break;
                }
            }

// parte fissa di chiusura delle pagine php con framework.
    writeEnd();
?>