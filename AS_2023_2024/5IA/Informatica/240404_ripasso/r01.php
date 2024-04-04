<?php
    require("head.php");
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

    switch($sc){
        case "usaValori":{
            // r01.php?inputTxt1=5&inputTxt2=10&scelta=usaValori
            // in questo case arrivo dal form e vado a utilizzare i valori inseriti dall'utente.
            $v1 = $_REQUEST['inputTxt1'];
            $v2 = $_REQUEST['inputTxt2'];

            echo('Valore 1: '.$v1.' Valore 2: '.$v2.'<br />
                <a href="r01.php">Torna indietro</a>');

            // realizzare un piccolo algoritmo che visualizza i divisori comuni dei due numeri ricevuti.
            
            break;
        }
        default:{
            // di default creo il form per acquisire due valori.
            echo('
                <form action="r01.php" method="get">
                    <div class="mb-3">
                        <label for="inputTxt1" class="form-label">Valore 1:</label>
                        <input class="form-control form-control-sm" type="text" name="inputTxt1" placeholder="Inserisci valore intero" aria-label="inputTxt1">
                    </div>

                    <div class="mb-3">
                        <label for="inputTxt2" class="form-label">Valore 2:</label>
                        <input class="form-control form-control-sm" type="text" name="inputTxt2" placeholder="Inserisci valore intero" aria-label="inputTxt2">
                    </div>

                    <input type="hidden" name="scelta" value="usaValori">
                    <button type="submit" class="btn btn-primary">Invia</button>
                </form>
            ');
            break;
        }
    }

    require("foot.php");
?>