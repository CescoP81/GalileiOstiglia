<?php
/* Creazione di output formattato CSV, export da database. */
header('Content-Type: text/csv');
header('Content-Disposition: attachment; filename="sample.csv"');

// collegamento al daabase per recuperare tutti i record della tabella fumetto.
$db = new mysqli("localhost","root","","scuola2021");
$sql = "SELECT titolo, collana, editore, anno_pub AS 'anno pubblicazione' FROM fumetto";
$resultSet = $db->query($sql);
$db->close();

$record = $resultSet->fetch_assoc();
$columns = array_keys($record);
 // PRIMA VERSIONE CONVERTENDO OGNI RECORD IN UNA RIGA CSV.
/*
$str_csv = "";
$str_csv = implode(',', $columns);
echo($str_csv."\n");
while($record){
    $str_csv = "";
    $str_csv = implode(',', $record);
    echo($str_csv."\n");
    $record = $resultSet->fetch_assoc();
}
// */

 // SECONDA VERSIONE ANTEMPONENDO UN PROGRESSIVO AD OGNI RIGA CSV.
$str_csv = "#,";
$str_csv .= implode(',', $columns);
echo($str_csv."\n");
$cnt = 1;
while($record){
    $str_csv = $cnt.",";
    $str_csv .= implode(',', $record);
    echo($str_csv."\n");
    $cnt++;
    $record = $resultSet->fetch_assoc();
}
// */
?>