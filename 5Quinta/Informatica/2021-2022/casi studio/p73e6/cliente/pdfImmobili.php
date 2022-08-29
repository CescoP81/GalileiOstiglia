<?php
   require("../../fpdf184/fpdf.php");
   require("../require/funzioni.php");

   $pdf = new FPDF();
   $pdf->AddPage();

   $pdf->Image('..\\require\logo.png',100,10);
   $pdf->SetY(60);

   $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
   $sql = "SELECT * FROM p73e6_proprietario WHERE id=".$_REQUEST['idProprietario'];
   $rs = $db->query($sql);
   $record = $rs->fetch_assoc();

   $pdf->SetFont('Times','B',12);
   $pdf->Cell(50,5,"Spett.le",0,1);
   $pdf->SetFont('Times','',12);
   $pdf->Cell(50,5,$record['cognome']." ".$record['nome'],0,1);
   $pdf->Cell(50,5,$record['via'].",".$record['civico'].", ".$record['citta'],0,1);
   $pdf->Cell(50,5,"Telefono: ".$record['telefono'],0,1);
   $pdf->Cell(50,5,"E-mail: ".$record['mail'],0,1);
   $db->close();

   $pdf->Ln();
   $pdf->Ln();
   $pdf->Ln();
   // recupero gli immobili posseduti dal determinato cliente.
   $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
   $sql = "SELECT i.nome AS 'Immobile', i.via, i.civico, i.metratura, i.piano, i.locali, 
      z.nome AS 'Zona', t.nome AS 'Tipologia' 
      FROM p73e6_immobile AS i, p73e6_zona AS z, p73e6_tipologia AS t, p73e6_possiede AS p 
      WHERE p.idProprietario='".$_REQUEST['idProprietario']."' 
         AND p.idImmobile=i.id
         AND i.idZona=z.id AND i.idTipologia = t.id";
   $rs = $db->query($sql);
   $db->close();
   $pdf->SetFont('Times','IB',14);
   $pdf->Cell(50,10,'Immobili posseduti',0,1);
   $pdf->SetFont('Times','B',12);
   $pdf->Cell(5,10,"#","B");
   $pdf->Cell(40,10,"Immobile","B");
   $pdf->Cell(50,10,"Indirizzo","B");
   $pdf->Cell(10,10,"mq","B");
   $pdf->Cell(15,10,"Piano","B");
   $pdf->Cell(20,10,"Nr. Locali","B");
   $pdf->Cell(25,10,"Zona","B");
   $pdf->Cell(25,10,"Tipologia","B",1);
   $pdf->SetFont('Times','',12);
   $cnt = 1;
   while($record = $rs->fetch_assoc()){
      $pdf->SetFont('Times','B',12);
         $pdf->Cell(5,10,$cnt);
      $pdf->SetFont('Times','',12);
      $pdf->Cell(40,10,$record['Immobile']);
      $pdf->Cell(50,10,$record['via']." ".$record['civico']);
      $pdf->Cell(10,10,$record['metratura']);
      $pdf->Cell(15,10,$record['piano']);
      $pdf->Cell(20,10,$record['locali']);
      $pdf->Cell(25,10,$record['Zona']);
      $pdf->Cell(30,10,$record['Tipologia'],0,1);
      $cnt++;
   }

   $pdf->Ln();
   
   $sql = "SELECT i.nome AS 'Immobile',
            i.metratura, ra.prezzo_mq,
            (i.metratura*ra.prezzo_mq) AS 'Totale Valore'
         FROM p73e6_proprietario AS p, 
            p73e6_possiede AS po, 
            p73e6_immobile AS i, 
            p73e6_rendita_annua AS ra 
         WHERE p.id = po.idProprietario 
            AND po.idImmobile = i.id 
            AND i.idZona = ra.idZona
            AND i.idTipologia = ra.idTipologia
            AND p.id=".$_REQUEST['idProprietario'];
   $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
   $rs = $db->query($sql);
   $db->close();

   $pdf->SetFont('Times','IB',14);
   $pdf->Cell(50,10,'Rendite',0,1);
   $pdf->SetFont('Times','B',12);

   $pdf->SetFont('Times','B',12);
   $pdf->Cell(5,10,"#","B");
   $pdf->Cell(100,10,"Immobile","B");
   $pdf->Cell(30,10,"Metratura mq","B");
   $pdf->Cell(30,10,"Prezzo/mq","B");
   $pdf->Cell(25,10,"Totale","B",1);
   $pdf->SetFont('Times','',12);
   $cnt = 1;
   $totale = 0;
   while($record = $rs->fetch_assoc()){
      $pdf->SetFont('Times','B',12);
         $pdf->Cell(5,10,$cnt);
      $pdf->SetFont('Times','',12);
      $pdf->Cell(100,10,$record['Immobile']);
      $pdf->Cell(30,10,$record['metratura']);
      $pdf->Cell(30,10,chr(128).$record['prezzo_mq']);
      $pdf->Cell(25,10,chr(128).$record['Totale Valore']);
      $pdf->Ln();
      $totale += $record['Totale Valore'];
      $cnt++;
   }
   $pdf->SetFont('Times','B',12);
   $pdf->Cell(165,10,"Totale:",0,0,'R');
   $pdf->Cell(25,10,chr(128).$totale);
   $pdf->Output();
?>