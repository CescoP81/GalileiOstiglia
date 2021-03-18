<?php
/* Script PHP che genera il PDF delle tabelle Meteo_Stazioni e Meteo_Temperature. */
require('../fpdf182/fpdf.php');

$pdf = new FPDF();
$pdf->AddPage();

// aggancio al database e recupero dei dati da stampare in PDF.
$db = new mysqli("localhost","root","","scuola2021");
$sql = "SELECT mt.valore, ms.nome AS stazione ";
$sql .= "FROM meteo_temperature AS mt, meteo_stazioni AS ms ";
$sql .= "WHERE mt.id_stazione = ms.id ORDER BY ms.id";

// Creo la riga di intestazione della tabella.
$pdf->SetFont('Arial', 'B', 16);
$pdf->Cell(10,10, "#", 1, 0,'C');
$pdf->Cell(30,10, "Valore", 1, 0, 'C');
$pdf->Cell(30,10, "Stazione", 1, 1, 'C');

// creo le righe della tabella con i dati di ogni singolo record estratto dalla SELECT.
$pdf->SetFont('Arial','',12);
$resultSet = $db->query($sql);
$record = $resultSet->fetch_assoc();
$cnt = 1;
while($record){
    $pdf->Cell(10,10, $cnt,1);
    $pdf->Cell(30,10, $record['valore'],1);
    $pdf->Cell(30,10, $record['stazione'],1,1);
    $record = $resultSet->fetch_assoc();
    $cnt++;
}
$db->close();

// Carico a fianco della tabella valori, il grafico multilinea delle temperature presenti.
$pdf->Image('http://scuola.localhost/5I_AS2021/Informatica/210304_ProvaPdf/multilinea_spezzata.php', 85, 10, 115, 0, 'PNG');

$pdf->Output();
?>