<?php
// Con require carico un file di libreria, che deve essere nella stessa cartella del file php su cui sto
// lavorando. Quindi richiamo le funzioni di apertura pagina e chiusura pagina inserite nella libreria.
require("lib.php");
    writeStart();

            // parte dinamica che cambia in base ai dati che voglio visualizzare, per esempio:
            // - form per raccolta dati.
            // - codice di inserimento/modifica/cancellazione record da tabelle.
            // - visualizzazione di tabelle mysql.
            if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
            echo('Esempio di pagina dinamica con richiesta lati rettangolo, calcolo area e perimetro<br />');
            switch($sc){
                case "calcolaValori":{
                    // arrivo con i dati dal form,
                    // li devo recuperare dal vettore REQUEST,
                    // usare per i calcoli e comunicare i valori
                    $b = $_REQUEST['base'];
                    $h = $_REQUEST['altezza'];

                    $area = $b * $h;
                    $perim = ($b + $h) * 2;
                    echo('L\'area del rettangolo equivale a: '.$area.'<br />');
                    echo('Il perimetro del rettangolo equivale a: '.$perim.'<br /><br />');
                    echo('<a href="boot02.php">Torna al form</a>');
                    break;
                }
                default:{
                    // visualizza il form di inserimento dati essenziali base e altezza.
                    echo('<form action="boot02.php" method="get">
                        <b>Base:</b><br />
                        <input class="form-control" type="text" name="base" placeholder="Valore base" aria-label="default input example">
                        <b>Altezza:</b><br />
                        <input class="form-control" type="text" name="altezza" placeholder="valore altezza" aria-label="default input example">
                        <input type="hidden" name="scelta" value="calcolaValori">
                        <button type="submit" class="btn btn-primary mb-3">Calcola Area e Perimetro</button>
                    </form>');
                    break;
                }
            }

// parte fissa di chiusura delle pagine php con framework.
    writeEnd();
?>