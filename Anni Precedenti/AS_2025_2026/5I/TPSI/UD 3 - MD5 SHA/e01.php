<?php
$str = "Annalisa";
echo(md5($str).'<br />');

$str = "abc" . $str;
echo(md5($str).'<br />');

/*  Funzioni di cifratura:
    MD5
    SHA1
*/ 
echo(var_dump($_SERVER));
?>