<?php
/* p9.php genera il pdf della tabella p9_cliente e p9_ordine */

require('../fpdf182/fpdf.php');
$pdf = new FPDF();

// recupero i dati cliente dal database, nello specifico il cliente con ID = 1.
$db = new mysqli("localhost","root","","scuola2021");
$sql = "SELECT * FROM p9_cliente WHERE id=1";
$resultSet = $db->query($sql);
$record = $resultSet->fetch_assoc();

$pdf->addPage();

$pdf->Image("http://scuola.localhost/Quinta/Informatica/210408_Ripasso/logo.jpeg", 140,10, 50, 30, "JPEG");
$pdf->SetY(40);

$pdf->SetFont('Arial','B',14);
$pdf->Cell(40,10,"Cliente:", 0, 1);
$pdf->SetFont('Arial','',14);
$pdf->Cell(40, 10, $record['cognome']." ".$record['nome'], 0, 1);
$pdf->Cell(40, 10, $record['residenza'], 0, 1);
$pdf->Cell(40, 10, $record['cap']." ".$record['paese']." (".$record['provincia'].")", 0, 10);

$pdf->Ln();
$pdf->Ln();

$pdf->SetFont('Arial','B',14);
$pdf->Cell(150,10,"Dettagli ordine:", "B", 1);
$pdf->SetFont('Arial','',14);
$sql = "SELECT o.descrizione, o.prezzo ";
$sql .= "FROM p9_ordine AS o, p9_cliente as c ";
$sql .= "WHERE c.id=o.id_cliente AND c.id=1";
$resultSet = $db->query($sql);

$record = $resultSet->fetch_assoc();
$totale = 0;
while($record){
    $pdf->Cell(150, 10, $record['descrizione'], "L", 0);
    $pdf->Cell(40,10, chr(128).number_format((float)$record['prezzo'],2,'.',''), 1, 1, "R");
    $totale = $totale + $record['prezzo'];
    $record = $resultSet->fetch_assoc();
}
$pdf->SetFont('Arial','B',14);
$pdf->Cell(150,10,"Totale:", "T",0,"R");
$pdf->Cell(40,10,chr(128).number_format((float)$totale,2,'.',''),1,1,"R");



$pdf->Output();
?>