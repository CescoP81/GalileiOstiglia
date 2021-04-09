<?php
// Script per la creazione di un PDF della tabella stipendi-dipendenti.
require('../fpdf182/fpdf.php');
$pdf = new FPDF(); // creo un oggetto di tipo fpdf -> quindi avrò accesso alle funzioni (metodi) per gestire un pdf.

$pdf->addPage();
$pdf->SetFont('Arial','',14);

$db = new mysqli("localhost","root","","scuola2021");
$sql = "SELECT d.cognome, d.nome, s.cifra, s.data_accredito FROM dipendente AS d, stipendio AS s WHERE d.id=s.id_dipendente";
$resultSet = $db->query($sql);

while($record = $resultSet->fetch_assoc()){
    $pdf->Cell(30,10,$record['cognome'], 1, 0);
    $pdf->Cell(30,10,$record['nome'], 1, 0);
    $pdf->Cell(30,10,$record['cifra'], 1, 0);
    $pdf->Cell(30,10,$record['data_accredito'], 1, 0);
    $pdf->Ln();
}
$db->close();
$pdf->Output();
?>