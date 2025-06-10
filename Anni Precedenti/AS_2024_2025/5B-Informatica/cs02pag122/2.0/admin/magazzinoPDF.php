<?php
require('../../../../../fpdf186/fpdf.php');
require('../include/lib.php');

$mypdf = new FPDF();

// Aggiungo una pagina al pdf.
    $mypdf->AddPage();

    $mypdf->SetFont('Arial', '', 18);
    $mypdf->Cell(160, 10, 'Import-Export s.n.c.', 0, 1);
    $mypdf->SetFont('Arial', '', 14);
    $mypdf->Cell(160, 10, 'Sede Legale: Via della Resilienza, 18 - 46035 Ostiglia (MN)', 0, 1);
    $mypdf->SetFont('Arial', '', 12);
    $mypdf->Cell(160, 10, 'sito: http://www.impexp.it - mail: info@impexp.it', 0, 1);
    $mypdf->Image('../img/lion.png',160,10,30,30);

    $mypdf->Ln();

    // imposto un carattere Arial a 14pt
    $mypdf->SetFont('Arial', '', 14);

    // aggancio al database e selezione di tutti i record della tabella magazzino
    $db = new mysqli($DBHOST, $DBUSER, $DBPASSWORD, $DBNAME);
    $sql = "SELECT * FROM magazzino ORDER BY nome";
    $resultSet = $db->query($sql);
    
    // creazione di tutte le celle per visualizzare i dati estratti.
    $mypdf->Cell(10,10,'ID',0,0,'C');
    $mypdf->Cell(70,10,'Nome',0,0,'C');
    $mypdf->Cell(80,10,'Città',0,0,'C');
    $mypdf->Cell(30,10,'Provincia',0,0,'C');
    $mypdf->Ln();
    $i=0;
    $cnt = $resultSet->num_rows;
    while($record = $resultSet->fetch_assoc()){
        $i++;
        $mypdf->Cell(10, 10, $record['id'], 1, 0, 'C');
        $mypdf->Cell(70, 10, $record['nome'], 1, 0);
        $mypdf->Cell(80, 10, $record['citta'], 1, 0);
        $mypdf->Cell(30, 10, $record['provincia'], 1, 0, 'C');
        $mypdf->Ln();
    }
    $mypdf->Cell(90,10,'Magazzini presenti: '.$i.' oppure cnt:'.$cnt, 0,1);

    

    $mypdf->Output();
?>