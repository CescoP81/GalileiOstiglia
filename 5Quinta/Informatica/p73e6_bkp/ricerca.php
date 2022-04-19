<?php
/* Questa pagina è dedicata alla gestione delle ricerche.
/  VEDERE:
   Ajax =>  https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API
            https://developer.mozilla.org/en-US/docs/Web/API/fetch
            https://developer.mozilla.org/en-US/docs/Web/API/Response
*/
session_start();
if(isset($_REQUEST['sc'])) $sc = $_REQUEST['sc']; else $sc=null;
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;

require("require/funzioni.php");   // contiene funzioni sviluppate per le diverse pagine.
require("require/openPage.php");   // contiene il codice HTML standard di apertura di ogni pagina.

if($_SESSION['loggato']){
   writeMenu();

}
require("require/closePage.php"); // contiene il codice HTML standard di chiusura di ogni pagina.
?>