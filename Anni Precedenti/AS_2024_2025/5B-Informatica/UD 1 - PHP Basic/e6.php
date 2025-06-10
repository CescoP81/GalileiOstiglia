<?php
    echo('<!DOCTYPE HTML>
        <html>
            <head>
                <meta charset="UTF-8">
                <title>Prova di REQUEST HTTP</title>
            </head>
            <body>    
    ');
    // -- insert here your code --
    // http://..../e6.php?scelta=
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
    else $sc = null;

        switch($sc){
            case 1:{
                echo('Sono entrato nel caso 1...');
                break;
            }
            case 2:{
                echo('Sono entrato nel caso 2...');
                break;
            }
            case 3:{
                echo('Sono entrato nel caso 3...');
                break;
            }
            default:{
                echo('Scelta assento o non valida.');
                break;
            }
        }
    // -- end of php code
    echo('</body>
    </html>
    ');
?>