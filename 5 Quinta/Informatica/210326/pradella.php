<!DOCTYPE html>
<html>
    <head><title>Esercizio di prova</title></head>
    <body>
<?php
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

    // realizzo il menu operativo della pagina.
    echo("<a href=\"pradella.php?scelta=1\">Vedi Clienti</a> | ");
    echo("<a href=\"pradella.php?scelta=2\">Vedi Spedizioni</a> | ");
    echo("<a href=\"pradella.php?scelta=3\">Report Corrieri</a> | <br />");

    // parte dinamica con php
    switch($sc){
        case 1:{
            // punto 1: visualizzare la tabella clienti
            $db = new mysqli("localhost", "root", "", "scuola2021");
            $sql = "SELECT * FROM p8_cliente ORDER BY id";
            $resultSet = $db->query($sql); // equivalente: $db->query("SELECT * FROM p8_cliente ORDER BY nominativo");

            echo("<table border=1>");
                echo("<tr><th>#</th><th>Nominativo</th><th>Prov. Residenza</th></tr>");
                $record = $resultSet->fetch_assoc();
                while($record){
                    echo("<tr>");
                        echo("<td>".$record['id']."</td>");
                        echo("<td>".$record['nominativo']."</td>");
                        echo("<td>".$record['prov_residenza']."</td>");
                    echo("</tr>");
                    $record = $resultSet->fetch_assoc();
                }
            echo("</table>");
            $db->close();
            break;
        }
        case 2:{
            // punto 1: visualizzare la tabella spedizioni terminate, cioè hanno data e corriere associato.
            $db = new mysqli("localhost", "root", "", "scuola2021");
            $sql = "SELECT sp.id, cl.nominativo, cl.prov_residenza, sp.data_spedizione, sp.partenza, sp.destinazione, co.denominazione AS corriere ";
            $sql .= "FROM p8_cliente AS cl, p8_corriere AS co, p8_spedizione AS sp ";
            $sql .= "WHERE cl.id=sp.id_cliente AND sp.id_corriere=co.id";
            $resultSet = $db->query($sql);
            
            echo("<table border=1>");
                echo("<tr>
                    <th>#ID</th>
                    <th>Nominativo</th>
                    <th>Prov. Residenza</th>
                    <th>Data Spedizione</th>
                    <th>Luogo Partenza</th>
                    <th>Luogo Destinazione</th>
                    <th>Corriere Incaricato</th>
                </tr>");
                $record = $resultSet->fetch_assoc();
                while($record){
                    echo("<tr>");
                        echo("<td>".$record['id']."</td>");
                        echo("<td>".$record['nominativo']."</td>");
                        echo("<td>".$record['prov_residenza']."</td>");
                        echo("<td>".$record['data_spedizione']."</td>");
                        echo("<td>".$record['partenza']."</td>");
                        echo("<td>".$record['destinazione']."</td>");
                        echo("<td>".$record['corriere']."</td>");
                    echo("</tr>");
                    $record = $resultSet->fetch_assoc();
                }
            echo("</table>");
            $db->close();
            break;
        }
        case 3:{
            // punto 3: report corrieri, visualizza il numero di spedizioni per ogni corriere.
            $db = new mysqli("localhost", "root", "", "scuola2021");
            $sql = "SELECT co.id, co.denominazione FROM p8_corriere AS co";
            $resultSet = $db->query($sql);

            echo("<table border=1>");
                echo("<tr>
                    <th>Denominazione Corriere</th>
                    <th>Nr. Spedizioni Effettuati</th>
                </tr>");
            $recordCo = $resultSet->fetch_assoc();
            while($recordCo){
                $sql = "SELECT COUNT(sp.id) AS n_spedizioni FROM p8_spedizione AS sp, p8_corriere AS co WHERE sp.id_corriere=co.id AND co.id=".$recordCo['id'];
                //echo($sql."<br />");
                $resultSet2 = $db->query($sql);
                $record = $resultSet2->fetch_assoc();
                echo("<tr><td>".$recordCo['denominazione']."</td><td>".$record['n_spedizioni']."</td></tr>");

                $recordCo = $resultSet->fetch_assoc();
            }
            echo("</table>");
            $db->close();
            break;
        }
    }
?>
    </body>
</html>