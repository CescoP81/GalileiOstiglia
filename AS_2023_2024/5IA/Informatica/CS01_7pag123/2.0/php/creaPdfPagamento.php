<?php
// QUESTA PAGINA PHP RICEVE L'ID DI UN DIPENDENTE E CREA IL RELATIVO PDF,
// SENZA ALCUNA RIGA DI HTML O ALTRO.
require("../include/fpdf/fpdf.php");
$pdf = new FPDF();

$idD = $_REQUEST['idDipendente'];

$pdf->addPage();
$pdf->setFont('Arial','',16);
$str = "Voglio gli stipendi di ".$idD;
$pdf->cell(40,10,$str,1);
$pdf->output();
?>