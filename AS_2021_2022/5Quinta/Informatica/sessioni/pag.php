<?php
session_start();
require('oggetto.php');

if(!isset($_SESSION['o'])){
   $x = new Obj();
   $_SESSION['o'] = serialize($x);
}

   //session_destroy();
//$o = new Obj();

$x = unserialize($_SESSION['o']);
$x->getCnt();
$_SESSION['o'] = serialize($x);

?>