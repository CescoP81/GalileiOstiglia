<!doctype html>
<html>
    <head>
        <title>Esempio di input valori da HTTP REQUEST</title>
    </head>
    <body>
        <?php
            /*  Q: Come faccio a passare dei valori ad una pagina PHP?
                A: Utilizzo il passaggio per HTTP REQUEST con la struttura chiave=valore

                Esempio:
                http://.../e02.php?chiave1=12&chiave2=3

                la mia pagina riceve due chiavi (chiave1 e chiave2) con valori rispettivamente 12 e 3

                Q: come le recupero nella pagina PHP?
                A: Utilizzo i vettori associativi globali che vengono "creati" durante una HTTP REQUEST
                    $_GET[] $_POST[] $_REQUEST[]

                    $_GET['chiave1'] e $_GET['chiave2']
                        12              3
            */

            // verifico che esistano le chiave nel vettore GET altrimenti a e b li imposto con valori di default 0
            if(isset($_GET['chiave1']))
                $a = $_GET['chiave1'];
            else
                $a = 0;

            if(isset($_GET['chiave2']))
                $b = $_GET['chiave2'];
            else
                $b = 0;

            echo("Chiave 1: ".$a."<br />");
            echo("Chiave 2: ".$b."<br />");
            // esego la somma
            $c = $a + $b;

            // comunico la somma
            echo("somma= ".$c);

            echo("<br /><br />");
            // utilizzo il REQUEST
            if(isset($_REQUEST['chiave1']))
                $a = $_REQUEST['chiave1'];
            else
                $a = 0;

            if(isset($_REQUEST['chiave2']))
                $b = $_REQUEST['chiave2'];
            else
                $b = 0;

            echo("Chiave 1: ".$a."<br />");
            echo("Chiave 2: ".$b."<br />");
            // esego la somma
            $c = $a + $b;

            // comunico la somma
            echo("somma= ".$c);
        ?>
    </body>
</html>