<?php
/*
    Esempio di utilizzo della libreria FPDF unitamente all'interrogazione di un database
    e presentazione dei dati estratti.
    La banca dati utilizzata è quella relativa al Case Studio CS01_7pag123 di cui è presente
    il folder con file DDL.sql, DML.SQL.
*/
require("fpdf/fpdf.php");

$pdf = new FPDF();
$pdf->addPage();

$pdf->setFont('Arial','IB',16);
$pdf->cell(190,15,'Tabella Dipendenti Presenti','TR',1,'C');

// aggancio ad DB e recupero di tutti i dipendenti presenti.
$db = new mysqli("localhost","root","","scuola2324");
$sql = "SELECT d.id, d.cognome AS 'Cognome', d.nome AS 'Nome', c.nomeCitta AS 'Citta', r.nomeReparto AS 'Reparto'
         FROM Dipendente AS d, Citta AS c, Reparto AS r 
         WHERE d.idCittaResidenza=c.id AND d.idReparto = r.id";

// creo la riga di intestazione della tabella dipendenti.
    $pdf->setFont('Arial','B',14);
    $pdf->cell(10,10,'ID',1,0,'C');
    $pdf->cell(40,10,'Cognome',1,0,'C');
    $pdf->cell(40,10,'Nome',1,0,'C');
    $pdf->cell(40,10,'Residenza',1,0,'C');
    $pdf->cell(60,10,'Reparto',1,1,'C');

// recupero i dati dal DB e vado a creare le singole righe del pdf.
$rs = $db->query($sql);
while($record = $rs->fetch_assoc()){
    $pdf->setFont('Arial','B',12);
    $pdf->cell(10,10,$record['id'],1,0,'C');
    $pdf->setFont('Arial','',12);
    $pdf->cell(40,10,$record['Cognome'],1,0);
    $pdf->cell(40,10,$record['Nome'],1,0);
    $pdf->cell(40,10,$record['Citta'],1,0);
    $pdf->cell(60,10,$record['Reparto'],1,1);
}

$pdf->SetXY(110,220);
$pdf->Cell(40,10, 'Sono qui',1,0);

$pdf->output();
?>