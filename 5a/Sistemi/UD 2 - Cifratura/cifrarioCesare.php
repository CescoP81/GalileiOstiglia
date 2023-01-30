<?php
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

$alfabetoOriginale = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
$alfabetoDiCesare = "NOPQRSTUVWXYZABCDEFGHIJKLM";
echo("<html>
        <head><title>Cifrario di Cesare</title></head>
        <body>");
    
    echo("<table>");
        echo("<tr><td>Alfabeto Originale:</td>");
            $i=0;
            while($i<strlen($alfabetoOriginale)){
                echo("<td>".$alfabetoOriginale[$i]."</td>");
                $i++;
            }
            echo("</tr>");
            echo("<tr><td>Alfabeto Originale:</td>");
            $i=0;
            while($i<strlen($alfabetoDiCesare)){
                echo("<td>".$alfabetoDiCesare[$i]."</td>");
                $i++;
            }
            echo("</tr>");
    echo("</table>");

    echo("<hr>");

    echo("<form action=\"cifrarioCesare.php\" method=\"get\">");
        echo("Stringa originale: <input type=\"text\" name=\"str\">");
        echo("<input type=\"hidden\" name=\"scelta\" value=\"cifra\">");
        echo("<input type=\"submit\" value=\"cifra\">");
    echo("</form>");

    echo("<br />");

    echo("<form action=\"cifrarioCesare.php\" method=\"get\">");
        echo("Stringa cifrata: <input type=\"text\" name=\"str\">");
        echo("<input type=\"hidden\" name=\"scelta\" value=\"decifra\">");
        echo("<input type=\"submit\" value=\"Decifra\">");
    echo("</form>");

    echo("<hr>");

    switch($sc){
        case "cifra":{
            echo("entro");
            //$strOriginale = "Oggi vedo il sole e sono molto, molto, felice!";
            $strOriginale = $_REQUEST['str'];
            $strCifrata="";
        
            $strOriginale = strtoupper($strOriginale);
            $i=0;
            echo("Lunghezza stringa: ".strlen($strOriginale)." caratteri.<br />");
            
            while($i<strlen($strOriginale)){
                if($strOriginale[$i]==' ' || $strOriginale[$i]=='.' || $strOriginale[$i]==',' || $strOriginale[$i]=='!' || $strOriginale[$i]=='?'){
                    $strCifrata .= $strOriginale[$i];
                }
                else{
                    $src = 0;
                    while($strOriginale[$i] != $alfabetoOriginale[$src])
                        $src++;
                    $strCifrata .= $alfabetoDiCesare[$src];            
                }
                $i++;
            }
            echo("<b>Stringa originale:</b> ".$strOriginale . "<br />");
            echo("<b>Stringa cifrata:</b> ".$strCifrata . "<br />");
            break;
        }
        case "decifra":{
            $strCifrata = $_REQUEST['str'];
            $strDecifrata = "";
            $i=0;
            while($i<strlen($strCifrata)){
                if($strCifrata[$i]==' ' || $strCifrata[$i]=='.' || $strCifrata[$i]==',' || $strCifrata[$i]=='!' || $strCifrata[$i]=='?'){
                    $strDecifrata .= $strCifrata[$i];
                }
                else{
                    $src = 0;
                    while($strCifrata[$i] != $alfabetoDiCesare[$src])
                        $src++;
                    $strDecifrata .= $alfabetoOriginale[$src];            
                }
                $i++;
            }
            echo("<b>Stringa cifrata:</b> ".$strCifrata . "<br />");
            echo("<b>Stringa decifrata:</b> ".$strDecifrata);
            break;
        }
    }    

    

    //---------------------
    

echo("</body></html>");
?>