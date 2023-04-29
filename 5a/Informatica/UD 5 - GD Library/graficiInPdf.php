<?php
    require("../../../fpdf184/fpdf.php");

    $mypdf = new FPDF();
    $mypdf->AddPage();
    $mypdf->SetFont('Arial','B',16);
    $mypdf->Cell(40,10,'Hello World!',0, 1);
    
    $mypdf->Image('http://scuola.localhost/5a/Informatica/UD%205%20-%20GD%20Library/graficoAnno.php', null, null,null,null, 'PNG');
    $mypdf->Image('http://scuola.localhost/5a/Informatica/UD%205%20-%20GD%20Library/graficoAnno.php?rifAnno=2022', null, null,null,null, 'PNG');
    $mypdf->Output();
?>