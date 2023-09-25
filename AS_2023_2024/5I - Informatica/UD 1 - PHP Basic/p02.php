<?php
    echo("<HTML>
        <HEAD><TITLE>Prove con i Vettori</TITLE></HEAD>
        <BODY>
    ");

    $vet = Array(5,2,8,5,3,9,8,4);

    for($i=0; $i<6; $i++)
        echo($vet[$i]." - ");

    echo("<br ><br />");
    for($i=0; $i<count($vet); $i++)
        echo($vet[$i]." - ");

    $vet = Array();
    echo("<br ><br />");
    for($i=0; $i<rand(5, 10); $i++)
        //$vet[$i] = rand(1, 99);
        array_push($vet, rand(1,99));

    for($i=0; $i<count($vet); $i++)
        echo($vet[$i]." - ");

    echo("</BODY>
        </HTML>
    ");
?>