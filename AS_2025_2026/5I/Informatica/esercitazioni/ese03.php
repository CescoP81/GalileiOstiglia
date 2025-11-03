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
            switch($sc){
                case "calcolaValori":{
                    $b = $_REQUEST['baseFigura'];
                    $h = $_REQUEST['altezzaFigura'];
                    $calcolo = $_REQUEST['areaPerimetro'];

                    echo('Figura di dimensioni: '.$b.'x'.$h.'<br />');
                    echo('Valore da calcola: '.$calcolo.'<br /><br />');

                    if($calcolo == "area"){
                        echo('Area della figura: '.($b*$h).'<br /><br />');
                    }
                    if($calcolo == "perimetro"){
                        echo('Perimetro della figura: '.(($b+$h)*2).'<br /><br />');
                    }

                    echo('<a href="ese03.php">Torna al form</a>');
                    break;
                }
                default:{
                    // visualizza il form di inserimento dati essenziali tre numeri interi
                    echo('<form action="ese03.php" method="get">
                        <b>Base:</b><br />
                        <input class="form-control" type="text" name="baseFigura" placeholder="" aria-label="default input example">
                        <b>Altezza:</b><br />
                        <input class="form-control" type="text" name="altezzaFigura" placeholder="" aria-label="default input example">

                        <!-- Creazione dei due radio button per la scelta se perimetro o area -->
                        <div class="form-check">
                            <input class="form-check-input" type="radio" name="areaPerimetro" value="area" checked id="radioDefault1">
                            <label class="form-check-label" for="radioDefault1">
                                Calcola Area
                            </label>
                            </div>
                            <div class="form-check">
                                <input class="form-check-input" type="radio" name="areaPerimetro" value="perimetro" id="radioDefault2">
                                <label class="form-check-label" for="radioDefault2">
                                Calcola Perimetro
                            </label>
                        </div>

                        <input type="hidden" name="scelta" value="calcolaValori">
                        <button type="submit" class="btn btn-primary mb-3">Calcola e Comunica</button>
                    </form>');
                    break;
                }
            }
// parte fissa di chiusura delle pagine php con framework.
    writeEnd();
?>