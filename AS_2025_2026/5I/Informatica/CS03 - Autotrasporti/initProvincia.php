<?php
$jsonStr = file_get_contents("provincia.json");

$json = array(json_decode($jsonStr));

//echo($json.'<br />');
var_dump($json);
//var_dump($json[0]->Foglio1);

foreach($json[0]->Foglio1 as $prov){
    //echo($prov->provincia.' - '.$prov->sigla.'<br />');
    $sql = "INSERT INTO PROVINCIA(nome, sigla) VALUE('$prov->provincia', '$prov->sigla')";
    echo($sql.'<br />');
}
// */



?>