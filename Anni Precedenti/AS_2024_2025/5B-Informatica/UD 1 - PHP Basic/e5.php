<?php
    /*
    Realizzare uno script PHP che riceve un valore intero nel vettore
    delle request con chiave 'Val'. 
    Lo script calcola e comunica il successivo numero primo.
    Formattare correttamente la pagina secondo lo standard HTML
    per visualizzare il risultato.

    http://..../e5.php?Val=23
    */
    echo('<!DOCTYPE HTML>
        <html>
            <head>
                <meta charset="UTF-8">
                <title>Prova di REQUEST HTTP</title>
            </head>
            <body>    
    ');

    // -- insert here your code --
    if(isset($_REQUEST['Val'])) $num = $_REQUEST['Val'];
    else $num = -1;

    if($num > -1){
        // significa che ho un valore valido passato dalla HTTPP Request.
        // quindi posso procedere con l'algoritmo di ricerca del successivo numero primo.

        $primo = 0;
        do{
            $num = $num + 1;
            $cnt = 0;
            for($i=1; $i<=$num; $i++){
                if($num % $i == 0)
                    $cnt++;
            }
            if($cnt <= 2)
                $primo = 1;
        }while($primo == 0);
        echo("Il successivo numero primo è: ".$num);
    }
    else{
        echo("Il numero inserito non è valido, oppure variabile inesistente.");
    }

    // -- end of php code
    echo('</body>
    </html>
    ');
?>