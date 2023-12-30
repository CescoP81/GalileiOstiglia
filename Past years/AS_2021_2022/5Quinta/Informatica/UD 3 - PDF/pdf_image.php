<?php
/* Creazione di un PDF con inserita un'immagine; il file è posizionato
nella stessa cartella del file php.
*/
   require('../fpdf184/fpdf.php');

   $pdf = new FPDF();
   $pdf->AddPage();
   $pdf->SetFont('Times','B',12);

   $pdf->Image('Barilla.jpg', 110, 0, 75);
   $pdf->SetXY(10,50);

   $pdf->Cell(50,10,"Testo di prova prima della img",1,0,'C');
   $pdf->Ln();  
   $pdf->Cell(50,10,"Testo di prova",1,0,'C');
   

   $pdf->Output();
?>