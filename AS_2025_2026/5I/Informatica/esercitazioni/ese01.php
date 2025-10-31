<?php
/* Realizzare una pagina PHP che permetta di inserire 3 valori interi, 
    recuperati quindi i valori dal vettore REQUEST comunicare se sono in ordine 
    crescente e se rappresentano una terna pitagorica.
*/
require("lib.php");
    writeStart();
            if(isset($_REQUEST['scelta']) == true) $sc = $_REQUEST['scelta']; else $sc = null;
            
            echo('Verifica crescenza tra numeri e terna pitagorica<br />');
            switch($sc){
                case "calcolaValori":{
                    // recupero i valori dalle REQUEST
                    $v1 = $_REQUEST['val1'];
                    $v2 = $_REQUEST['val2'];
                    $v3 = $_REQUEST['val3'];

                    // verifico se sono in ordine crescen
                    if(($v1<$v2) && ($v2<$v3)){
                        echo('I valori inseriti sono in ordine crescente: '.$v1.' '.$v2.' '.$v3.'<br />');
                    }

                    // verifico la terna pitagorica
                    if(($v1*$v1) + ($v2*$v2) == ($v3*$v3)){
                        echo('I valori rappresentano una terna pitagorica.<br ><br />');
                    }
                    echo('<a href="ese01.php">Torna al form</a>');
                    break;
                }
                default:{
                    // visualizza il form di inserimento dati essenziali tre numeri interi
                    echo('<form action="ese01.php" method="get">
                        <b>Valore 1:</b><br />
                        <input class="form-control" type="text" name="val1" placeholder="" aria-label="default input example">
                        <b>Valore 2:</b><br />
                        <input class="form-control" type="text" name="val2" placeholder="" aria-label="default input example">
                        <b>Valore 3:</b><br />
                        <input class="form-control" type="text" name="val3" placeholder="" aria-label="default input example">
                        
                        <input type="hidden" name="scelta" value="calcolaValori">
                        <button type="submit" class="btn btn-primary mb-3">Crescenti e terna pitagorica?</button>
                    </form>');
                    break;
                }
            }

// parte fissa di chiusura delle pagine php con framework.
    writeEnd();
?>