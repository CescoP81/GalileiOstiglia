<?php
include("header.html");

	// da qui inizia il mio algoritmo PHP
	
	// recupero del dato in arrivo dal form
	$valore = $_REQUEST['val'];
	
	// verifico che sia un primo oppure no.
	$cnt = 0;
	$i;
	for($i=2;$i<$valore; $i++)
	{
		if($valore%$i == 0)
			$cnt++;
	}
	
	if($cnt == 0 && $valore!=1)
		echo("Il numero ".$valore." è primo");
	else
		echo("Il numero ".$valore." non è primo");

	echo("<br><br>");
	echo("<a href=\"form1.html\">Torna al form</a>");
include("footer.html");
?>