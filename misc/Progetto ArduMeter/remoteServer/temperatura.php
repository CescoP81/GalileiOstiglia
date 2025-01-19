<?php
require("libgenerale.php"); 
//echo($dbHost." ".$dbUser." ".$dbPassword." ".$dbName."<br />");

if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
    switch($sc){
        case "addtemp":{
            date_default_timezone_set('Europe/Rome');	// importante per avere l'allineamento ora solare/legale.
            $t = $_REQUEST['temp'];	// inviato da arduino
            $u = $_REQUEST['umid'];	// inviato da arduino
            
            $d = date("Y-m-d");		// data della lettura
            $o = date("H:i:s");		// orario della lettura.

            if($db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName)){
                echo("DB Link OK.\n");
            }
            else{
                echo("No DB Link.\n");
            }
            $sql = "INSERT INTO temperatura (temperatura, umidita, datamisura, ora) VALUES($t, $u, '$d', '$o')";
            //echo("<br >".$sql);
            if($db->query($sql)){
                echo("Insert: OK!\n");
            }
            else{
                echo("Insert: PROBLEM!\n");
            }
            break;
        }
        case "listatemp":{
            echo('Case disabilitato, togliere scelta oppure cliccare <a href="temperatura.php">Qui.</a>');
            break;
        }
        case "exportCSV":{
            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            $sql = "SELECT * 
                    FROM temperatura 
                    ORDER BY id DESC";
            //        LIMIT 50";
            $rs = $db->query($sql);

            header('Content-Type: text/csv');
            
            $record = $rs->fetch_assoc();
            $keys = array_keys($record);
            for($i=0; $i<count($keys); $i++){
                echo($keys[$i]);
                if($i<count($keys)-1)
                    echo(',');
                else
                    echo("\n");
            }
            while($record = $rs->fetch_assoc()){
                echo($record['id'].','
                .$record['datamisura'].','
                .$record['ora'].','
                .$record['temperatura'].','
                .$record['umidita']);          
                
                echo("\n");
            }
            $db->close();
            break;
        }
        default:{
            $db = new mysqli($dbHost, $dbUser, $dbPassword, $dbName);
            require("head.php");
            //scriviNavBar();
            echo('<div class="alert alert-primary">UI  Temperatura - Ver 1.0</div>');
            echo('<div class="row">');
                echo('<div class="col col-4">');
                    echo('<div class="alert alert-success text-center h2">Oggi '.Date("d/m/Y").'</div>');
                    
                    echo('<div class="row">');
                        $sql = "SELECT t.ora, t.temperatura
                                FROM temperatura AS t
                                ORDER BY id DESC
                                LIMIT 1";
                        $rs = $db->query($sql);
                        $record = $rs->fetch_assoc();
                        echo('<div class="col col-6">Ultima lettura</div>');
                        echo('<div class="col col-3">'.$record['ora'].'</div><div class="col-3">'.$record['temperatura'].' °C</div>');
                    echo('</div>');

                    echo('<div class="row">');
                        $sql = "SELECT MIN(t.temperatura) AS minima
                                FROM temperatura AS t
                                WHERE datamisura='".Date("Y/m/d")."'
                                ORDER BY id DESC
                                LIMIT 1";
                        $rs = $db->query($sql);
                        $record = $rs->fetch_assoc();
                        echo('<div class="col col-6">Temperatura Minima</div>');
                        echo('<div class="col col-6">'.$record['minima'].' °C</div>');
                    echo('</div>');

                    echo('<div class="row">');
                        $sql = "SELECT MAX(t.temperatura) AS massima
                                FROM temperatura AS t
                                WHERE datamisura='".Date("Y/m/d")."'
                                ORDER BY id DESC
                                LIMIT 1";
                        $rs = $db->query($sql);
                        $record = $rs->fetch_assoc();
                        echo('<div class="col col-6">Temperatura Massima</div>');
                        echo('<div class="col col-6">'.round($record['massima'], 2).' °C</div>');
                    echo('</div>');

                    echo('<div class="row">');
                        $sql = "SELECT AVG(t.temperatura) AS media
                                FROM temperatura AS t
                                WHERE datamisura='".Date("Y/m/d")."'
                                ORDER BY id DESC
                                LIMIT 1";
                        $rs = $db->query($sql);
                        $record = $rs->fetch_assoc();
                        echo('<div class="col col-6">Temperatura media</div>');
                        echo('<div class="col col-6">'.round($record['media'],1).' °C</div>');
                    echo('</div>');

                    echo('<div class="row mb-4">');
                        $sql = "SELECT COUNT(t.id) AS 'letture'
                                FROM temperatura AS t
                                WHERE datamisura='".Date("Y/m/d")."'";
                        $rs = $db->query($sql);
                        $record = $rs->fetch_assoc();
                        echo('<div class="col col-6">Numero letture</div>');
                        echo('<div class="col col-6">'.$record['letture'].'</div>');
                    echo('</div>');

                    echo('<div class="row mb-4">');
                        echo('<div class="col">');
                            echo('<div class="alert alert-primary">Specifiche</div>');
                            echo('Il progetto è attivo nell\'aula nr. 43 - "Informatica primo piano", collocato a parete ad un\'altezza approssimativa
                            di 150cm da terra. La board Arduino UNO R3 effettua un campionamento della temperatura e umidità con sensore DHT22 ogni 30 minuti con
                            relativo caricamento su database remoto.
                            <br />
                            Link alle caratteristiche del sensore DHT22 utilizzato:
                            <a href="https://www.az-delivery.de/it/products/dht22-temperatursensor-modul" target="new">AZ-Delivery Sensori</a>
                            ');
                        echo('</div>');
                    echo('</div>');
                echo('</div>'); // chiude la col-4 del riepilogo.

                echo('<div class="col col-8">'); // colonna con le ultime 50 letture.
                    $sql = "SELECT * 
                            FROM temperatura 
                            ORDER BY id DESC
                            LIMIT 50";
                    $rs = $db->query($sql);
                    
                    if($rs){
                        echo('<table class="table table-striped table-hover">
                            <thead>
                                <tr>
                                    <th scope="col">id</th>
                                    <th scope="col">data</th>
                                    <th scope="col">ora</th>
                                    <th scope="col">Temp °C</th>
                                    <th scope="col">Umidità %</th>                                    
                                </tr>
                            </thead>
                        ');
                        echo('<tbody');
                        while($record = $rs->fetch_assoc()){
                            echo('<tr>
                                <th scope="row">'.$record['id'].'</th>
                                <td>'.$record['datamisura'].'</td>
                                <td>'.$record['ora'].'</td>
                                <td>'.$record['temperatura'].'</td>
                                <td>'.$record['umidita'].'</td>                                
                                </tr>
                            ');
                        }
                        echo('</tbody>');
                        echo('<caption>Lista delle ultime 50 temperatura rilevate.');
                        echo('</table>');
                    }
                echo('</div>'); // chiude la col-8 delle letture
            echo('</div>'); // chiude la row iniziale
            $db->close();
            require("foot.php");
            break;
        }              
    }
?>
