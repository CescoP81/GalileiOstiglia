<?php
$db_host= "localhost";
$db_user= "root";
$db_password= "";
$db_name= "scuola2223";

/* formattazione del link:
    ../meteostation.php?scelta=addLettura&temp=&umid=&lumi=

    es:
    http://IP-ADDRESS/meteostation.php?scelta=addLettura&temp=28.5&umid=75&lumi=5
*/
$t = $_REQUEST['temp'];
$u = $_REQUEST['umid'];
$l = $_REQUEST['lumi'];
$sc = $_REQUEST['scelta'];

switch($sc){
    case "addLettura":{
        
        break;
    }
}


?>