<?php
    echo("<HTML>
        <HEAD><TITLE>Prove di PHP</TITLE></HEAD>
        <BODY>
    ");

    echo("Hello World to 5IA...<br /><br />");

    $cnt = 1;
    while($cnt <= 10){
        $nRandom = rand(10, 45);
        if($nRandom%2 == 0)
            echo($nRandom. " è pari<br />");
        else
            echo($nRandom. " è dispari<br />");
        
        $cnt++;
    }

    echo("<br /><br />");
    $cnt = "MA che bello il PHP...";
    echo($cnt);
    echo("</BODY>
        </HTML>
    ");
?>