<?php
   require('../fpdf184/fpdf.php');

   $pdf = new FPDF();
   $pdf->AddPage();

   // Mi collego al DB per il recupero dei dati.
   $db = new mysqli("localhost","root","","scuola2122");
   $sql = "SELECT * FROM p62e1_Localita";
   $resultSet = $db->query($sql);

   // creo riga di intestazioni tabella.
   $pdf->SetFillColor(210,210,210);
   $pdf->SetFont('Times','B',12);
   $pdf->Cell(10,10,"Id",1,0,'C',true);
   $pdf->Cell(40,10,"Cap",1,0,'C',true);
   $pdf->Cell(100,10,"Nome",1,0,'C',true);
   $pdf->Cell(40,10,"Prov",1,0,'C',true);
   $pdf->Ln();

   // stampo ogni singolo record dentro a delle celle.
   $pdf->SetFont('Times','',12);
   $record = $resultSet->fetch_assoc();
   while($record){
      $pdf->SetFont('Times','B',12);
      $pdf->Cell(10,10,$record['Id'],1,0,'C');
      $pdf->SetFont('Times','',12);
      $pdf->Cell(40,10,$record['cap'],1,0);
      $pdf->Cell(100,10,$record['nome'],1,0);
      $pdf->Cell(40,10,$record['prov'],1,0);
      $pdf->Ln();
      $record = $resultSet->fetch_assoc();
   }

   $pdf->Ln();
   $pdf->Ln();

   $sql = "SELECT c.*, l.Nome, l.Prov, l.Cap 
            FROM p62e1_Cliente AS c, p62e1_Localita AS l 
            WHERE c.idLocalita=l.Id";
   $resultSet = $db->query($sql);

   // creo riga di intestazioni tabella.
   $pdf->SetFillColor(210,210,210);
   $pdf->SetFont('Times','B',12);
   $pdf->Cell(10,10,"ID",1,0,'C',true);
   $pdf->Cell(40,10,"Ragione Sociale",1,0,'C',true);
   $pdf->Cell(25,10,"Telefono",1,0,'C',true);
   $pdf->Cell(15,10,"P. IVA",1,0,'C',true);
   $pdf->Cell(20,10,"Id Agente",1,0,'C',true);
   $pdf->Cell(15,10,"Fido",1,0,'C',true);
   $pdf->Cell(35,10,"Localita'",1,0,'C',true);
   $pdf->Cell(15,10,"Cap",1,0,'C',true);
   $pdf->Cell(15,10,"Prov.",1,0,'C',true);
   $pdf->Ln();

   $record = $resultSet->fetch_assoc();
   $pdf->SetFont('Times','',12);
   while($record){
      $pdf->Cell(10,10,$record['Id'],1,0,'C');
      $pdf->Cell(40,10,$record['ragioneSociale'],1,0);
      $pdf->Cell(25,10,$record['numTelefono'],1,0);
      $pdf->Cell(15,10,$record['partitaIva'],1,0);
      $pdf->Cell(20,10,$record['idAgente'],1,0);
      $pdf->Cell(15,10,$record['fido'],1,0);
      $pdf->Cell(35,10,$record['Nome'],1,0);
      $pdf->Cell(15,10,$record['Cap'],1,0);
      $pdf->Cell(15,10,$record['Prov'],1,0);
      $pdf->Ln(); 
      $record = $resultSet->fetch_assoc();
   }
   $db->close();
   $pdf->Output();
?>