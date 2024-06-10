<?php
/*
Esempio di utilizzo della libreria fpdf per la creazione di file PDF dinamici.
Richiede il download della libreria dal sito www.fpdf.org

Sul sito, nell sezione Documentazione è disponibile tutta la API della libreria.
Nella sezione tutorial sono presente esempi di primo utilizzo.
*/
require("fpdf/fpdf.php");

$pdf = new FPDF();

$pdf->addPage();
$pdf->setFont('Arial','',16);
$pdf->cell(40,10,'Hello World',1);
$pdf->output();

?>