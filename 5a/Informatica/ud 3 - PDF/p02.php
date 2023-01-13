<?php
/*
    Pagina di esempio nell'utilizzo della libreria free FDPF
    Alcuni componenti base e operazioni basilari come cambio colore, font, celle con bordi o senza.
    http://www.fpdf.org
    Ver 1.84
*/
require("../../../fpdf184/fpdf.php");

$mypdf = new FPDF();
$mypdf->AddPage();
$mypdf->SetFont('Arial','B',16);
$mypdf->Cell(40,10,'Cella senza bordi',0,1);
$mypdf->Cell(80,10,'Cella con bordi e andata a capo', 1,1);
$mypdf->SetFont('Times', '', '12');              // cambio carattere
$mypdf->Cell(80,10,'Questo testo in Times New Romans', 1,1);
$mypdf->Ln();

$mypdf->Cell(80,10,utf8_decode("Lettere accentate à è ì ò ù"), 1,1);    // per avere le accentate metodo 1 ma deprecato
$str = "Lettere accentate à è ì ò ù";
$mypdf->Cell(80,10,iconv('UTF-8', 'windows-1252', $str), 1,1);          // metodo due supportato da PHP > 8.2
$mypdf->Ln();

$mypdf->SetTextColor(200,0,100);            // cambio colore del testo formato RGB
$mypdf->Cell(80,10,'Testo colorato', 1,1);
$mypdf->Ln();

$mypdf->SetTextColor(0,0,0);
$mypdf->Cell(80,10,'Testo nuovamente nero', 0,1);

$mypdf->Output();
?>