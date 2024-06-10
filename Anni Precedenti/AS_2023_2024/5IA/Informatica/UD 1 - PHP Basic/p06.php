<?php
require("head.php");

// realizzo il form per l'inserimento del dato.
    echo("
        <form action=\"p06.php\" method=\"post\">
            <div class=\"mb-3\">
                <label for=\"numeroValori\" class=\"form-label\">Numero 1:</label>
                <input type=\"text\" class=\"form-control\" id=\"numeroValori\" name=\"numeroValori\" placeholder=\"Insert a number\">
            </div>

            <button type=\"submit\" class=\"btn btn-primary\">Genera sequenza numeri</button>
        </form>
    ");

    // verifico di avere un numero valori presente nel vettore delle request.
    if(isset($_REQUEST['numeroValori'])) $nValori = $_REQUEST['numeroValori']; else $nValori = null;

    if($nValori){
        // utilizzo il valore per generare il vettore.
        $vet = Array();
        for($i=0; $i<$nValori; $i++){
            array_push($vet, rand(10,25));
        }

        /*for($i=0; $i<$nValori; $i++)
            echo($vet[$i]." - ");
        // */
        for($i=0; $i<$nValori; $i++){
            echo($vet[$i].": ");
            $cnt = 0;
            for($j=1; $j<=$vet[$i]; $j++){  // ciclo dei divisori
                if($vet[$i]%$j == 0)
                    $cnt++;
            }
            if($cnt<=2) echo("OK primo<br />");
            else echo("<br />");
        }

    }
    else{
        echo("
            <div class=\"alert alert-warning\" role=\"alert\">
                Attenzione mancante numero valori.
            </div>
        ");
    }

require("foot.php");
?>