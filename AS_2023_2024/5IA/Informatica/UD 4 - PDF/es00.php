<?php
    require("fpdf/fpdf.php");

    $mypdf = new FPDF();

    // Aggiungo una pagina al pdf.
    $mypdf->AddPage();

    // imposto un carattere Arial a 14pt
    $mypdf->SetFont('Arial', '', 14);

    // creo una cella con del testo all'interno.
    $mypdf->Cell(60, 10, 'Il mio primo PDF', 1, 0); // prima cella

    $mypdf->Cell(10,10,'',1,0); // cella vuota di spaziatura

    $mypdf->Cell(60, 10, 'Seconda riga', 1, 0); // seconda cella

    $mypdf->Cell(50 , 10, '', 1, 0); // cella vuota di spaziatura

    $mypdf->Cell(60, 10, 'Terza cella testo', 1, 0); // cella che eccede i 190mm totali
    
    $mypdf->Output();
?>