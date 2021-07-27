<?php
require('../fpdf182/fpdf.php');

$robot = new FPDF(); // $db = new mysqli()

$robot->AddPage();
$robot->SetFont('Arial','',16);
//$robot->Cell(40,10,'Hello World!',1,1);

// recupero dati dal db
$db = new mysqli("localhost","root","","scuola2021");
$sql = "SELECT * FROM autore";
$resultSet = $db->query($sql);

$record = $resultSet->fetch_assoc();
while($record){
    $robot->Cell(10,10,$record['id'],0);
    $robot->Cell(30,10,$record['cognome'],0);
    $robot->Cell(35,10,$record['nome'],0);
    $robot->Cell(15,10,$record['provincia'],0);
    $robot->Cell(15,10,$record['anni'],0);
    $robot->Cell(15,10,$record['sesso'],0,1);
    $record = $resultSet->fetch_assoc();
}
$db->close();

$robot->Output();
?>