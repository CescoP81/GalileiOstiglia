<?php

require("head.php");

    // realizzo il form per la richiesta dei dati...
    echo("
        <form action=\"p05.php\" method=\"get\">
            <div class=\"mb-3\">
                <label for=\"numeroUno\" class=\"form-label\">Numero 1:</label>
                <input type=\"text\" class=\"form-control\" id=\"numeroUno\" name=\"numeroUno\" placeholder=\"Insert a number\">
            </div>

            <div class=\"mb-3\">
                <label for=\"numeroDue\" class=\"form-label\">Numero 2:</label>
                <input type=\"text\" class=\"form-control\" id=\"numeroDue\" name=\"numeroDue\" placeholder=\"Insert a number\">
            </div>

            <div class=\"mb-3\">
                <label for=\"numeroTre\" class=\"form-label\">Numero 3:</label>
                <input type=\"text\" class=\"form-control\" id=\"numeroTre\" name=\"numeroTre\" placeholder=\"Insert a number\">
            </div>

            <button type=\"submit\" class=\"btn btn-primary\">Verifica ordine crescenza</button>
        </form>
    ");
// p05.php?numeroUno=5&numeroDue=7&numeroTre=9
    // realizzo la parte che controlla i dati se la pagina è richiamata dal bottone del form
    if(isset($_REQUEST['numeroUno'])) $n1 = $_REQUEST['numeroUno']; else $n1 = null;
    if(isset($_REQUEST['numeroDue'])) $n2 = $_REQUEST['numeroDue']; else $n2 = null;
    if(isset($_REQUEST['numeroTre'])) $n3 = $_REQUEST['numeroTre']; else $n3 = null;

    if($n1 && $n2 && $n3){      // verifico che esistano tutti e tre i numeri necessari
        if($n1<=$n2 && $n2<=$n3){
            echo("
                <div class=\"alert alert-success\" role=\"alert\">
                    I tre valori sono in ordine crescente.
                </div>
            ");
        }
        else{
            echo("
                <div class=\"alert alert-danger\" role=\"alert\">
                    I tre valori NON SONO in ordine crescente.
                </div>
            ");
        }
    }
    else{
        echo("
            <div class=\"alert alert-warning\" role=\"alert\">
                Attenzione UNO O PIU' VALORI NON PRESENTI!
            </div>
        ");
    }

require("foot.php");
?>