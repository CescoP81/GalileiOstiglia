<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Prova di form per raccolta dati</title>
        <meta charset="utf-8">
        <!-- parte richiesta dal framework Bootstrap -->
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
    </head>
    <body>
        <?php
            /*  Possibilità di richiamo della pagina
                1. http://.../e03.php -> senza nessuna chiave impostata
                2. http://.../e03.php?scelta=calcola&inputA=4&inputB=6
                Nel secondo caso le chiavi scelta, inputA, inputB diventano
                indici nel vettore $_GET
            */
            if(isset($_GET['scelta'])){ //capisco se sono nel caso 1 o 2
                switch($_GET['scelta']){    // capisco con la switch che tipo di scelta ho generato
                    case "calcola":{
                        $r = $_GET['inputRaggio'];

                        $circonf = 2 * 3.14 * $r;
                        $area = 3.14 * $r * $r; // $r*$r -> pow($r, 2);

                        echo('Cironferenza: '.$circonf.'<br />');
                        echo('Area: '.$area.'<br /><br />');

                        echo('<a href="e04.php">Torna al form...</a>');
                        break;
                    }
                }
            }
            else{   // non ho una scelta come chiave nella request
                echo('<div class="container-fluid">
                    <h1>Form Inserimento Dati</h1>
                    <form action="e04.php" method="get">
                        <div class="mb-3">
                            <label for="inputRaggio" class="form-label">Inserisci il raggio:</label>
                            <input class="form-control form-control-lg" type="text" name="inputRaggio" id="inputRaggio" placeholder="Valore del raggio" aria-label="default input example">
                        </div>
                        <input type="hidden" name="scelta" id="scelta" value="calcola">
                        <button class="btn btn-success" type="submit">Calcola Area e Circonferenza</button>
                    </form>            
                </div>');
            }
        ?>
        <!-- sezione script richiesta dal framework Bootstrap -->
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>
</html>