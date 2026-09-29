<!doctype html>
<html>
    <head>
        <title>Pagina di prova di PHP</title>
    </head>
    <body>
        <?php
            //phpinfo();

            $var;   // alloco un variabile vuota.

            $var = 19.5;  // inserisco un numero intero nella variabile.
            echo($var.'<br />');    // stampo il valore della variabile e concateno l'andata a capo in HTML
            //var_dump($var);

            $var = $var / 2;
            echo($var.'<br />');

            $var = "Hello Trotto";
            echo($var.'<br />');
            //var_dump($var);

            $var = 10;
            if($var < 12){
                echo('Variabile minore di 12<br />');
            }
            else{
                echo('Variabile maggiore o uguale a 12<br />');
            }
            echo('<br />');

            $var = 0;
            while($var <= 10){
                echo($var.' - ');
                $var++;
            }
            echo('<br />');
        ?>
    </body>
</html>