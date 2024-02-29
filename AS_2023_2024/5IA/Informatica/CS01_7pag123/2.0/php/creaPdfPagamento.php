<?php
// QUESTA PAGINA PHP RICEVE L'ID DI UN DIPENDENTE E CREA IL RELATIVO PDF,
// SENZA ALCUNA RIGA DI HTML O ALTRO.
require("../include/fpdf/fpdf.php");
$pdf = new FPDF();
$idD = $_REQUEST['idDipendente'];

// recupero dei dati del dipendente
$db = new mysqli("localhost","root","","scuola2324");
/*
$sql = "SELECT d.Cognome, d.Nome, r.nomeReparto
         FROM dipendente AS d, reparto AS r
         WHERE d.id=$idD AND d.idReparto=r.id";
        // echo($sql);*/
$sql = "SELECT d.Cognome, d.Nome, c.NomeCitta AS 'residenza',
            r.NomeReparto, c1.NomeCitta AS 'Citta Reparto' 
        FROM dipendente AS d, Citta AS c, Citta AS c1, Reparto AS r 
        WHERE d.idCittaResidenza=c.id AND d.idReparto=r.id AND r.idCittaReparto=c1.id AND d.id=$idD";
$rs = $db->query($sql);
$record = $rs->fetch_assoc();

// mi salvo il cognome e nome del dipendente per creare il nome del file pdf.
$cognome = $record['Cognome'];
$nome = $record['Nome'];

// stampo i dati di intestazione nel pdf.
$pdf->addPage();
$pdf->setFont('Arial','',16);
$pdf->cell(50,10,"Spett.le",0,1);
$pdf->cell(40,10,$record['Cognome']." ".$record['Nome'],0,1);
$pdf->cell(40,10,"Residente a: ".$record['residenza'],0,1);
$pdf->cell(50,10,"Reparto: ".$record['NomeReparto']." di ".$record['Citta Reparto'],0,1);
$pdf->Ln();

// recupero tutti i pagamenti relativi al dipendente scelto
$sql ="SELECT * 
        FROM pagamento as p, dipendente as d 
        WHERE d.id=p.idDipendente AND d.id=$idD 
        ORDER BY p.data DESC";

$rs = $db->query($sql);

// riga di intestazione tabella
$pdf->setFont('Arial','B',14);
$pdf->cell(30,10,"Data",1);
$pdf->cell(120,10,"Causale", 1);
$pdf->cell(40,10,"Importo",1,1);

$pdf->setFont('Arial','',12);
$totaleImporti = 0;
while($record = $rs->fetch_assoc()){
    $pdf->cell(30,10,$record['data'],'L');
    $pdf->cell(120,10,$record['causale'],0);
    $pdf->cell(40,10,$record['importo'],'LR',1,'R');
    $totaleImporti = $totaleImporti + $record['importo'];
}
$pdf->setFont('Arial','B',14);
$pdf->cell(150,10,"Totale: ",'T',0,'R');
$pdf->cell(40,10,$totaleImporti, 1, 1,'R');

// lasciato output() viene creato un file PDF nominato doc.pdf
//$pdf->output();
$cognome = $cognome.$nome;
$pdf->output('', $cognome);
?>