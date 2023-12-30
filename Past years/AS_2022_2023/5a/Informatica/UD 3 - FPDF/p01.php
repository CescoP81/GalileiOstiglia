<?php
/*
    Pagina di esempio nell'utilizzo della libreria free FDPF
    http://www.fpdf.org
    Ver 1.84
*/
require("../../../../fpdf184/fpdf.php");

$mypdf = new FPDF();
$mypdf->AddPage();
$mypdf->SetFont('Arial','B',16);
$mypdf->Cell(40,10,'Hello World!');
$mypdf->Output();
?>