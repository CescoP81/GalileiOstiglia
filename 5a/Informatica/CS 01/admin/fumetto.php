<?php
/*  Gestione della tabella cs01_casaEditrice
    Richiede i seguenti file dalla cartella include:
    - lib.php
    - head.html 
    - foot.html
*/
// gestione della tabella cs01_fumetto
require("../include/lib.php");
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

require("../include/head.html");
    adminNavBar();
    switch($sc){
        case "formNuovoFumetto":{
            echo("<form method=\"get\" action=\"fumetto.php\">
                    <div class=\"mb-3\">
                        <label for=\"inputTitolo\" class=\"form-label\">Titolo:</label>
                        <input type=\"text\" name=\"titoloF\" class=\"form-control\" id=\"inputTitolo\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputNumero\" class=\"form-label\">Numero:</label>
                        <input type=\"text\" name=\"numeroF\" class=\"form-control\" id=\"inputNumero\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputData\" class=\"form-label\">Data Uscita:</label>
                        <input type=\"text\" name=\"dataF\" class=\"form-control\" id=\"inputData\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>
                    <div class=\"mb-3\">
                        <label for=\"inputPrezzo\" class=\"form-label\">Prezzo:</label>
                        <input type=\"text\" name=\"prezzoF\" class=\"form-control\" id=\"inputPrezzo\" aria-describedby=\"emailHelp\">
                        <div id=\"emailHelp\" class=\"form-text\">Campo obbligatorio.</div>
                    </div>");
                    // devo dare la possibilità di scegliere la casa editrice.
                    $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
                    $sql = "SELECT * FROM cs01_casaEditrice";
                    $resultSet = $db->query($sql);
                    echo("<div class=\"mb-3\">");
                        echo("<label for=\"inputPrezzo\" class=\"form-label\">Casa Editrice:</label>");
                        echo("<select name=\"idEditrice\" class=\"form-select\" aria-label=\"Default select example\">");
                        while($record = $resultSet->fetch_assoc()){
                            echo("<option value=\"".$record['id']."\">".$record['nome']."</option>");
                        }
                        echo("</select>");
                    echo("</div>");
                    $db->close();
            echo("<input type=\"hidden\" name=\"scelta\" value=\"addFumetto\">
                <button type=\"submit\" class=\"btn btn-primary\">Inserisci Nuovo Fumetto</button>
            ");
            break;
        }
        case "addFumetto":{
            $titoloF = $_REQUEST['titoloF'];
            $numeroF = $_REQUEST['numeroF'];
            $dataF = $_REQUEST['dataF'];
            $prezzoF = $_REQUEST['prezzoF'];
            $idEditrice = $_REQUEST['idEditrice'];

            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            $sql = "INSERT INTO cs01_fumetto(titolo, numero, dataUscita, prezzo, idCasaEditrice) 
                    VALUES('$titoloF', $numeroF, '$dataF', $prezzoF, $idEditrice)";
            //echo($sql);
            if($db->query($sql))
                echo("<div class=\"alert alert-success\">Nuovo fumetto aggiunto.</div>");
            else
                echo("<div class=\"alert alert-danger\">Problema inserimento fumetto</div>");
            $db->close();
            break;
        }
        case "listaFumetti":{
            $db = new mysqli($mysql_host, $mysql_user, $mysql_password, $mysql_db);
            //$sql = "SELECT * FROM cs01_fumetto";
            $sql = "SELECT fu.id, fu.titolo, fu.dataUscita AS 'Data Uscita', fu.numero, fu.prezzo, fu.immagine, ce.nome AS 'Casa Editrice' 
                    FROM cs01_fumetto AS fu, cs01_casaEditrice AS ce 
                    WHERE fu.idCasaEditrice = ce.id";
            //*/
            $rs = $db->query($sql);
            showResultSetTable($rs, "Elenco fumetti disponibili");
            $db->close();
            break;
        }
    }
require("../include/foot.html");
?>