<?php
// parte fissa di apertura delle pagine PHP con framework Boostrap
echo('<!DOCTYPE html>
<html lang="it">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
        <title>Prima prova di Bootstrap</title>
    </head>
    <body>
        <div class="container">');
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
        echo('</div>
        <!-- Prima di chiudere il body vado ad inserire eventuali sezioni di script--> 
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>   
    </body>
</html>');
?>