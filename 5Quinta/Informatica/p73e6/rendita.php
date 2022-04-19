<?php
/* Questa pagina è dedicata alla gestione delle rendite annuali, le operazioni che compie sono:
   - Visualizzazione del form per inserire una nuova rendita.
      - Inserimento di un nuova rendita nella rispettiva tabella
   - Visualizzazione di tutte le rendite presenti nel database.
*/
session_start();
if(isset($_REQUEST['sc'])) $sc = $_REQUEST['sc']; else $sc=null;
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;

require("require/funzioni.php");   // contiene funzioni sviluppate per le diverse pagine.
require("require/openPage.php");   // contiene il codice HTML standard di apertura di ogni pagina.

if($_SESSION['loggato']){
    writeMenu();

    switch($sc){
        case "nuovaRendita":{
            echo("<div class=\"alert alert-success\">Aggiunta nuova rendita - Anno Contabile ".Date("Y")."</div>");
            echo("<form action=\"rendita.php\" method=\"post\">");
                echo("<div class=\"row\">");
                    echo("<div class=\"col col-5\">");
                        echo("<div class=\"mb-3\">
                            <label for=\"inZona\" class=\"form-label\">Zona Cittadina:</label>
                            <select class=\"form-select\" name=\"zona\" id=\"inZona\" aria-label=\"Default select example\">");
                                $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
                                $sql = "SELECT * FROM p73e6_zona ORDER BY nome ASC";
                                $rs = $db->query($sql);
                                while($record = $rs->fetch_assoc())
                                    echo("<option value=\"".$record['id']."\">".$record['nome']."</option>");
                                $db->close();
                            echo("</select>
                        </div>");
                    echo("</div>");
                    echo("<div class=\"col col-5\">");
                        echo("<div class=\"mb-3\">
                            <label for=\"inTipologia\" class=\"form-label\">Tipologia Immobile:</label>
                            <select class=\"form-select\" name=\"tipologia\" id=\"inTipologia\" aria-label=\"Default select example\">");
                                $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
                                $sql = "SELECT * FROM p73e6_tipologia ORDER BY nome ASC";
                                $rs = $db->query($sql);
                                while($record = $rs->fetch_assoc())
                                    echo("<option value=\"".$record['id']."\">".$record['nome']."</option>");
                                $db->close();
                            echo("</select>
                        </div>");
                    echo("</div>");
                    echo("<div class=\"col col-2\">");
                        echo("<div class=\"mb-3\">
                            <label for=\"inPrezzo\" class=\"form-label\">Prezzo mq:</label>
                            <input class=\"form-control\" type=\"text\" name=\"prezzoMq\" id=\"inPrezzo\" placeholder=\"\" aria-label=\"default input example\">
                        </div>");
                    echo("</div>");
                echo("</div>");   
                echo("<input type=\"hidden\" name=\"sc\" value=\"addRendita\">
                <button type=\"submit\" class=\"btn btn-primary\">Inserisci</button>");
            echo("</form>");
            break;
        }
        case "addRendita":{
            $idZona = $_REQUEST['zona'];
            $idTipologia = $_REQUEST['tipologia'];
            $prezzo = $_REQUEST['prezzoMq'];
            $anno = Date("Y");

            $sql = "INSERT INTO p73e6_rendita_annua(anno, prezzo_mq, idZona, idTipologia) VALUE ($anno, $prezzo, $idZona, $idTipologia)";
            $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
            if($db->query($sql))
                echo("<div class=\"alert alert-success\">Nuova rendita aggiunta con successo!</div>");
            else
                echo("<div class=\"aler aler-danger\">Problema in aggiunnta!</div>");
            
            $sql = "SELECT z.nome AS Zona, t.nome AS Tipologia, r.prezzo_mq AS 'Prezzo al mq'
                FROM p73e6_zona AS z, p73e6_tipologia AS t, p73e6_rendita_annua AS r
                WHERE z.id = r.idZona AND t.id = r.idTipologia
                ORDER BY z.nome ASC, t.nome";
            $resultSet = $db->query($sql);
            showResultTable($resultSet, "Tabelle delle rendite annuali");
            $db->close();
            break;
        }
        case "listaRendite":{
            $db = new mysqli(DBHOST, DBUSER, DBPASSWORD, DBNAME);
            $sql = "SELECT z.nome AS Zona, t.nome AS Tipologia, r.prezzo_mq AS 'Prezzo al mq'
                FROM p73e6_zona AS z, p73e6_tipologia AS t, p73e6_rendita_annua AS r
                WHERE z.id = r.idZona AND t.id = r.idTipologia
                ORDER BY z.nome ASC, t.nome";
            //echo($sql);
            $resultSet = $db->query($sql);
            showResultTable($resultSet, "Tabelle delle rendite annuali");
            $db->close();
            break;
        }
    }
}
require("require/closePage.php"); // contiene il codice HTML standard di chiusura di ogni pagina.
?>