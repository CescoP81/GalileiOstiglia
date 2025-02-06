<?php
require('../../../../../fpdf186/fpdf.php');
require('../include/lib.php');

class MYPDF extends FPDF{
    /**
     * Realizzo l'override della funzione Header, questa funzione viene richiamata di default
     * ogni volta che viene chamata la AddPage oppure viene creata una nuova pagina in automatico.
     */
    function Header(){
        $this->SetFont('Arial', '', 18);
        $this->Cell(160, 10, 'Import-Export s.n.c.', 0, 1);
        $this->SetFont('Arial', '', 14);
        $this->Cell(160, 10, 'Sede Legale: Via della Resilienza, 18 - 46035 Ostiglia (MN)', 0, 1);
        $this->SetFont('Arial', '', 12);
        $this->Cell(160, 10, 'sito: http://www.impexp.it - mail: info@impexp.it', 0, 1);
        $this->Image('../img/lion.png',160,10,30,30);
        $this->Ln();
    }
    /**
     * Override della funzione Footer aggiungendo la riga di chiusura
     * al fondo della pagina.
     */
    function Footer(){
        $this->SetXY(10,277);
        $this->SetFont('Arial', '', 12);
        $this->Cell(190,10,$this->PageNo(), 'T', 0, 'C');
    }
}

$mypdf = new MYPDF();
// Aggiungo una pagina al pdf.
    $mypdf->AddPage();

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