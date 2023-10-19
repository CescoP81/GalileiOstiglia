<?php
/**
 * Il codice seguente si bassa sulla schematizzazione ER del file er01.drawio persente nella
 * cartella /UD 2 - mySQL Basics.
 * 
 * Il codice permette:
 * - Visualizza il form per l'inserimento di un nuovo record.
 * - Visualizza il contenuto della tabella Uomo nel database.
 * - Visualizza un messaggio di conferma di avvenuto inserimento record.
 */

 if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

 require("head.php");

    // costruisco il form bootstrap per l'inserimento dei dati di un nuovo record.
    echo("<div class=\"alert alert-primary\"><h3>Form inserimento nuovo record</h3></div>");
    echo("<form action=\"uomo.php\">
        <div class=\"mb-3\">
            <label for=\"nomeUomo\" class=\"form-label\">Nome:</label>
            <input type=\"text\" class=\"form-control\" id=\"nomeUomo\" name=\"nomeUomo\" placeholder=\"Insert a name\">
        </div>
        <div class=\"mb-3\">
            <label for=\"cognomeUomo\" class=\"form-label\">Cognome:</label>
            <input type=\"text\" class=\"form-control\" id=\"cognomeUomo\" name=\"cognomeUomo\" placeholder=\"Insert a surname\">
        </div>
        <div class=\"mb-3\">
            <label for=\"anniUomo\" class=\"form-label\">Anni:</label>
            <input type=\"text\" class=\"form-control\" id=\"anniUomo\" name=\"anniUomo\" placeholder=\"Insert an age\">
        </div>
        <div class=\"mb-3\">
            <label for=\"paeseUomo\" class=\"form-label\">Paese:</label>
            <input type=\"text\" class=\"form-control\" id=\"paeseUomo\" name=\"paeseUomo\" placeholder=\"Insert a place\">
        </div>
        <input type=\"hidden\" name=\"scelta\" value=\"addUomo\">
        <button type=\"submit\" class=\"btn btn-primary\">Inserisci nuovo record</button>
    </form>");

    // se $sc testata all'inizio della pagina è diversa da null e vale "addUomo" allora recupero le altre variabili dalla HTTP Request.
    // poi eseguo la query di inserimento del nuovo record.
    if($sc == "addUomo"){
        $n = $_REQUEST['nomeUomo'];
        $c = $_REQUEST['cognomeUomo'];
        $a = $_REQUEST['anniUomo'];
        $p = $_REQUEST['paeseUomo'];

        $sql = "INSERT INTO Uomo(nome, cognome, anni, paese)
                VALUES('$n','$c',$a,'$p');";

        $db = new mysqli("localhost", "root","","scuola2324");
        if($db->query($sql)){
            echo("<div class=\"alert alert-success\">
                Record aggiunto...
            </div>");
        }
        else{
            echo("<div class=\"alert alert-warning\">
                Record non aggiunto, possibile mancanza dati.
            </div>");
        }
        $db->close();
    }

    // creo una tabella bootstrap per visualizzare i dati presenti nel DB e selezionati dalla SELECT.
    echo("<div class=\"alert alert-primary\"><h3>Contenuto della tabella nel database</h3></div>");
    $db = new mysqli("localhost","root","","scuola2324"); // apro uno stream dati con il database -> mysql
    $sql = "SELECT *        
             FROM uomo";
    $resultSet = $db->query($sql);
    $db->close();

    echo("<table class=\"table table-striped\"> 
        <thead>
            <tr>
                <th>ID</th>
                <th>Nome</th>
                <th>Cognome</th>
                <th>Anni</th>
                <th>Paese</th>
            </tr>
        </thead>
        <tbody>
    ");
        while($record = $resultSet->fetch_assoc()){
            echo("<tr>
                <th>".$record['id']."</th>
                <td>".$record['nome']."</td>
                <td>".$record['cognome']."</td>
                <td>".$record['anni']."</td>
                <td>".mb_convert_encoding($record['paese'], "utf-8")."</td>
            ");
        }
        echo("</tbody>");
        echo("<caption>Elenco uomini presenti nel database</caption>");
    echo("</table>");
 require("foot.php");

 $str = "pinco pallo";
 $str = mb_convert_encoding($str, "utf-8");
?>