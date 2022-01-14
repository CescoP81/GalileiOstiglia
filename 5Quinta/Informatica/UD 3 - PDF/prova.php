<?php
require('../fpdf184/fpdf.php');

   $pdf = new FPDF();
   $pdf->AddPage();
   $pdf->SetFont('Times','I',26);
   $pdf->Cell(50,10,'Hello World!',1,1);

   $pdf->SetFont('Times','I',12);
   $pdf->Cell(70,10,'Buongiorno Mondo!',1,1);
  
   $cnt = 1;
   while($cnt<=5){
      $pdf->Cell(70,10,$cnt,1,1);
      $cnt++; 
   }

   $pdf->Output();
?>