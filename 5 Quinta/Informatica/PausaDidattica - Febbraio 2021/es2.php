<?php
/*
    Pagina PHP "autosufficiente", nel caso di default visualizza il form di inserimento dati
    e viene invocata dal form per manipolare i dati inseriti.
    Utilizzo di una variabile scelta per discriminare quale case eseguire.
    Se scelta non è settata tra le variabili REQUEST[] allora viene dato null di default.
*/
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; 
else $sc=null;

    echo("<html><head><title>Pausa Didattica II</title></head><body>");
    switch($sc){
        case "calcola":{
            $a = $_REQUEST['altezza'];
            $b = $_REQUEST['base'];

            echo($b." ".$a."<br />");
            echo("Area rettangolo: ".($a*$b)."<br />");
            echo("Perimetro: ".($a+$a+$b+$b));
            echo("<br /><br />");
            echo("<a href=\"es2.php\">Torna ad inserimento dati.</a>");
            break;
        }
        default:{
            // mostro il form di inserimento dati.
            echo("<form action=\"es2.php\" method=\"GET\">");
                echo("Misura Base: <input type=\"text\" name=\"base\"><br />");
                echo("Misura Altezza: <input type=\"text\" name=\"altezza\"><br />");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"calcola\">");
                echo("<input type=\"submit\" value=\"Calcola\">");
            echo("</form>");
            
            break;
        }
    }
    echo("</body></html>");
?>