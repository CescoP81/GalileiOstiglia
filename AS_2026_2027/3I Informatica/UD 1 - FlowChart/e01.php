<?php
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
    else $sc = null;
?>
<!DOCTYPE html>
<html>
    <head>
        <title>Algoritmo somma in PHP</title>
    </head>
    <body>
        <?php
            if($sc==null){
                echo('<form action="e01.php" method="get">
                    Inserisci A: <input type="text" name="a"><br />
                    Inserisci B: <input type="text" name="b"><br />
                    <input type="hidden" name="scelta" value="somma">
                    <input type="submit" value="Esegui la somma">
                </form>');
            }
            if($sc == "somma"){
                $a = $_REQUEST['a'];
                $b = $_REQUEST['b'];

                $c = $a + $b;

                if($c >= 10){
                    echo('C='.$c.' valore maggiore o uguale a 10! <br />');
                }
                else{
                    echo('C='.$c.' valore minore a 10! <br />');
                }
                echo('<br /><a href="e01.php">Torna alla Home</a>');
            }
        ?>
    </body>
</html>