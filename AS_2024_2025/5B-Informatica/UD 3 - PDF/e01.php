<?php
require('../../../fpdf/fpdf.php');

$mypdf = new FPDF();

// Aggiungo una pagina al pdf.
    $mypdf->AddPage();

    // imposto un carattere Arial a 14pt
    $mypdf->SetFont('Arial', '', 14);

    // creo una cella con del testo all'interno.
    $mypdf->Cell(50, 10, 'Il mio primo PDF', 1, 0); // prima cella

    $mypdf->Cell(10,10,'',1,1); // cella vuota di spaziatura
  
    $mypdf->Ln();
    $mypdf->Ln();

    for($i=1; $i<=10; $i++){
        for($j=1; $j<=10; $j++){
            $mypdf->Cell(15,10, $i*$j, 1, 0);
        }
        $mypdf->Ln();
    }

    $mypdf->Output();
?>