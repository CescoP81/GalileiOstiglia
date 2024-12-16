<?php
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

echo('
<!DOCTYPE HTML>
    <html>
        <head>
            <meta charset="utf-8">
            <title>CASO STUDIO 02 PAGINA 122</title>
            <meta name="viewport" content="width=device-width, initial-scale=1">
            <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
        </head>
        <body>
            <div class="container">
');
// START CODE HERE
if($sc == "esegui"){
    // arrivo dal form ed eseguo i punti richiesti...
    $v1 = $_REQUEST['val1'];
    $v2 = $_REQUEST['val2'];
    
    // punto 1
    $cnt = 0;
    for($i=1; $i<=$v1; $i++){
        if($v1%$i == 0)
            $cnt++;
    }
    if($cnt <= 2)
        echo($v1.' è un numero primo!<br />');
    else
    echo($v1.' non è un numero primo!<br />');

    $cnt = 0;
    for($i=1; $i<=$v2; $i++){
        if($v2%$i == 0)
            $cnt++;
    }
    if($cnt <= 2)
        echo($v2.' è un numero primo!<br />');
    else
    echo($v2.' non è un numero primo!<br />');

    // -------
    
    // punto 2
    $r = $v1;
    $c = $v2;
    echo('<table class="table table-striped">
        <caption>Tabelline da 1 a '.$r.'x'.$c.'</caption>
        <thead>
            <tr>
                <th scope="col">R/C</th>
                ');
                for($i=1; $i<=$c; $i++)
                    echo('<th scope="col">'.$i.'</th>');
    echo('
            </tr>
        </thead>
        <tbody>                
    ');
    for($i=1; $i<=$r; $i++){
        echo('<tr>
            <th scope="row">'.$i.'</th>
        ');
        for($j=1; $j<=$c; $j++){
            echo('<td>'.($i*$j).'</td>');
        }
    }
    echo('</tbody>
    </table>');

}
else{
    // mostro il form...
    echo('<form action="e2.php">
        <div class="mb-3">
            <label for="inputVa1" class="form-label">Valore 1:</label>
            <input type="text" name="val1" class="form-control form-control-sm" id="inputVal1" aria-describedby="descrizioneHelp">
            <div id="descrizioneHelp" class="form-text">Inserisci la descrizione del prodotto da inserire</div>
        </div>
        <div class="mb-3">
            <label for="inputVa2" class="form-label">Valore 2:</label>
            <input type="text" name="val2" class="form-control form-control-sm" id="inputVal2" aria-describedby="descrizioneHelp">
            <div id="descrizioneHelp" class="form-text">Inserisci la descrizione del prodotto da inserire</div>
        </div>
        <input type="hidden" name="scelta" value="esegui">
        <button type="submit" class="btn btn-primary">Submit</button>
    </form>');
}


// END CODE
echo('
            </div>
            <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>
            <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.min.js" integrity="sha384-0pUGZvbkm6XF6gxjEnlmuGrJXVbNuzT9qBBavbLwCsOGabYfZo0T0to5eqruptLy" crossorigin="anonymous"></script>
         </body>
    </html>');
?>