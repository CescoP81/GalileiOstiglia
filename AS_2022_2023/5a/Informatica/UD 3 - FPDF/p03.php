<?php
/*
    Pagina di esempio nell'utilizzo della libreria free FDPF
    Recupero di dati da un database e presentazione sottoforma di tabulato PDF.
    http://www.fpdf.org
    Ver 1.84

    tabella: prova_pdf
    -id PK
    -Postazione intero da 0 a 2
    -mmPioggia intero da 0 a 49
*/
$host = "localhost";
$user = "root";
$password = "";
$db_name = "scuola2223";

require("../../../fpdf184/fpdf.php");
$mypdf = new FPDF;                  // creo l'oggetto fpdf
$mypdf->AddPage();                  // alloco una pagina bianca
$mypdf->SetFont('Arial','',12);    // imposto il font iniziale

$db = new mysqli($host, $user, $password, $db_name);    // dal DB recupero tutti i record della tabella prova_pdf.
    $sql = "SELECT * FROM prova_pdf";
    $rs = $db->query($sql);
$db->close();

    $mypdf->SetFont('Arial','B',14);
        $mypdf->Cell(15,10,"ID",1,0);
        $mypdf->Cell(50,10,"postazione",1,0);
        $mypdf->Cell(50,10,"mmPioggia",1,1);
    $mypdf->SetFont('Arial','',14);
    while($row = $rs->fetch_assoc()){
        $mypdf->SetFont('Arial','B',14);
            $mypdf->Cell(15,8,$row['id'],'LBR',0);
        $mypdf->SetFont('Arial','',14);
            $mypdf->Cell(50,8,$row['postazione'],'B',0);
            $mypdf->Cell(50,8   ,$row['mmPioggia'],'RB',0);
        $mypdf->Ln();
    }
    $mypdf->Output();
?>