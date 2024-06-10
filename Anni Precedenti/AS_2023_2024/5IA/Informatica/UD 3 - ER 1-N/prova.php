<?php
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
require("head.php");
    echo("<a href=\"prova.php?scelta=formAutomobile\">Nuova Auto</a> | ");
    echo("<a href=\"prova.php?scelta=listaAutomobili\">Lista auto</a> | <br /><br />");
    
    // voglio mostrare sempre il contenuto della tabella automodelli
    $sql = "SELECT ModAut.nome, ModAut.annoProduzione AS 'Anno Produzione', ModAut.cilindrata, MarcAut.nome AS Marca
    FROM ModelloAutomobile AS ModAut, MarcaAutomobile AS MarcAut
    WHERE ModAut.idMarcaAutomobile = MarcAut.id";

    $db = new mysqli("localhost","root","","scuola2324");
    $rs = $db->query($sql);
    while($record = $rs->fetch_assoc()){
        echo($record['nome']." ".$record['Anno Produzione']. " - ".$record['cilindrata']." - ".$record['Marca']."<br />");
    }
    $db->close();
    echo("<br /><br />");

    switch($sc){
        case "formAutomobile":{
            echo("Creo il nuovo form per un'automobile...<br />");
            echo("<form action=\"prova.php\" method=\"get\">");
                echo("Nome Modello:<br /><input type=\"text\" name=\"nomeAuto\"><br />");
                echo("Anno produzione:<br/><input type=\"text\" name=\"annoAuto\"><br />");
                echo("Cilindrata:<br /><input type=\"text\" name=\"cilindrataAuto\"><br />");

                //MAI USARE UN INPUT TEXT PER UNA Foreign KEY!!
                //echo("Marca:<br /><input type=\"text\" name=\"idMarcaAuto\"><br />");

                $db = new mysqli("localhost","root","","scuola2324");
                $sql = "SELECT * FROM MarcaAutomobile";
                $rs = $db->query($sql);
                $db->close();              
                echo("\n\nMarca: <br /><select name=\"idMarcaAuto\">");
                    while($record = $rs->fetch_assoc()){
                        echo("\n<option value=\"".$record['id']."\">".$record['nome']." - ".$record['nazionalita']);
                    }
                    /*echo("<option value=\"1\">Marca 1");
                    echo("<option value=\"2\">Marca 2");
                    echo("<option value=\"3\">Marca 3");
                    echo("<option value=\"4\">Marca 4");*/
                echo("\n</select><br />");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"addAutomobile\">");
                echo("\n<input type=\"submit\" value=\"Inserisci l'auto\">");
            echo("</form>");
            break;
        }
        case "addAutomobile":{
            $na = $_REQUEST['nomeAuto'];
            $aa = $_REQUEST['annoAuto'];
            $ca = $_REQUEST['cilindrataAuto'];
            $idMarcaAuto = $_REQUEST['idMarcaAuto'];

            $sql = "INSERT INTO ModelloAutomobile(nome, annoProduzione, cilindrata, idMarcaAutomobile) 
            VALUES('$na', '$aa', '$ca', $idMarcaAuto)";
            echo($sql);
            $db = new mysqli("localhost", "root","","scuola2324");
            if($db->query($sql)){
                echo("Auto aggiunta con Successo.");
            }
            else{
                echo("Errore nei dati da inserire.");
            }
            $db->close();
        }
    }

require("foot.php");
?>