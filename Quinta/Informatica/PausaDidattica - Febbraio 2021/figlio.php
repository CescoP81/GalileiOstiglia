<?php
// determino in che stato sono le variabili chiave del mio script php
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

// costruzione della pagina e gestione dei vari eventi con una struttura switch-case
    echo("<html>
        <head>
            <title>Gestione tabella figlio</title>
        </head>");
    echo("<body>");
    echo("<a href=\"figlio.php?scelta=nuovo_figlio\">Nuovo Figlio</a> | ");
    echo("<a href=\"figlio.php\">Visualizza Tabella Figlio</a><br /><br />");
    
    switch($sc){
        case "nuovo_figlio":{ // realizza il form di inserimento dati per un nuovo figlio.
            echo("Form di inserimento nuovo figlio:<br />");
            echo("<form action=\"figlio.php\" method=\"get\">");
                echo("Nome: <input type=\"text\" name=\"nomef\"><br />");

                $db = new mysqli("localhost","root","","pausa_didattica");
                // operazioni per creare la selection relativa al padre.
                $sql = "SELECT p.id, p.cognome, p.nome FROM padre AS p ORDER BY p.cognome";
                $resultSet = $db->query($sql);
                echo("Seleziona un Padre:\n <select name=\"idpadre\">\n");
                    $record = $resultSet->fetch_assoc();
                    while($record){
                        echo("\t<option value=\"".$record['id']."\">".$record['cognome']." ".$record['nome']."\n");
                        $record = $resultSet->fetch_assoc();
                    }
                echo("</select>\n<br />");

                // operazioni per creare la selection relativa alla madre.
                $sql = "SELECT m.id, m.cognome, m.nome FROM madre AS m ORDER BY m.cognome";
                $resultSet = $db->query($sql);
                echo("Selezionare una Madre:\n");
                echo("<select name=\"idmadre\">\n");
                    $record = $resultSet->fetch_assoc();
                    while($record){
                        echo("\t<option value=\"".$record['id']."\">".$record['cognome']." ".$record['nome']."\n");
                        $record = $resultSet->fetch_assoc();
                    }    
                echo("</select>\n<br />");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"aggiungi_figlio\">");
                echo("<input type=\"submit\" value=\"Aggiungi il nuovo Figlio\">");
                $db->close();
            echo("</form>");
            break;
        }
        case "aggiungi_figlio":{
            $nome_figlio = $_REQUEST['nomef'];
            $idp = $_REQUEST['idpadre'];
            $idm = $_REQUEST['idmadre'];

            $db = new mysqli("localhost","root","","pausa_didattica");
                $sql = "INSERT INTO figlio(nome, id_padre, id_madre) VALUES('$nome_figlio', '$idp', '$idm')";
                if($db->query($sql)) echo("Nuovo figlio aggiunto con successo.<br />");
                else echo("Problema in inserimento nel DB.<br />");
            $db->close();
            break;
        }
        case "cancella_figlio":{
            $idf = $_REQUEST['idfiglio'];
            $db = new mysqli("localhost","root","","pausa_didattica");
            $sql = "DELETE FROM figlio WHERE id=$idf";
            if($db->query($sql)) echo("Cancellazione avvenuta.<br />");
            else echo("Problema in fase di cancellazione.<br />");
            $db->close();
            break;
        }
        case "modifica_figlio":{
            $idf = $_REQUEST['idfiglio'];
            $db = new mysqli("localhost","root","","pausa_didattica");
            $sql = "SELECT * FROM figlio WHERE id='$idf'";
            $resultSet = $db->query($sql);
            $record = $resultSet->fetch_assoc();

            $nomef = $record['nome'];
            $idm = $record['id_madre'];
            $idp = $record['id_padre'];

            echo("<form action=\"figlio.php\" method=\"get\">");
                echo("Nome: <input type=\"text\" name=\"nomef\" value=\"$nomef\"><br />");

                $db = new mysqli("localhost","root","","pausa_didattica");
                // operazioni per creare la selection relativa al padre.
                $sql = "SELECT p.id, p.cognome, p.nome FROM padre AS p ORDER BY p.cognome";
                $resultSet = $db->query($sql);
                echo("Seleziona un Padre:\n <select name=\"idpadre\">\n");
                    $record = $resultSet->fetch_assoc();
                    while($record){
                        echo("\t<option value=\"".$record['id']."\"");
                        if($record['id'] == $idp)
                            echo(" selected>".$record['cognome']." ".$record['nome']."\n");
                        else
                            echo(">".$record['cognome']." ".$record['nome']."\n");
                        $record = $resultSet->fetch_assoc();
                    }
                echo("</select>\n<br />");

                // operazioni per creare la selection relativa alla madre.
                $sql = "SELECT m.id, m.cognome, m.nome FROM madre AS m ORDER BY m.cognome";
                $resultSet = $db->query($sql);
                echo("Selezionare una Madre:\n");
                echo("<select name=\"idmadre\">\n");
                    $record = $resultSet->fetch_assoc();
                    while($record){
                        echo("\t<option value=\"".$record['id']."\"");
                        if($record['id'] == $idm)
                            echo(" selected>".$record['cognome']." ".$record['nome']."\n");
                        else
                            echo(">".$record['cognome']." ".$record['nome']."\n");
                        $record = $resultSet->fetch_assoc();
                    }    
                echo("</select>\n<br />");
                echo("<input type=\"hidden\" name=\"idfiglio\" value=\"$idf\">");
                echo("<input type=\"hidden\" name=\"scelta\" value=\"aggiorna_figlio\">");
                echo("<input type=\"submit\" value=\"Aggiorna il Figlio\">");
                $db->close();
            echo("</form>");
            break;
        }
        case "aggiorna_figlio":{
            $idf = $_REQUEST['idfiglio'];
            $nome_figlio = $_REQUEST['nomef'];
            $idp = $_REQUEST['idpadre'];
            $idm = $_REQUEST['idmadre'];
            $db = new mysqli("localhost","root","","pausa_didattica");
                $sql = "UPDATE figlio SET id_padre='$idp', id_madre='$idm', nome='$nome_figlio' WHERE id=$idf";
                echo($sql."<br />");
                if($db->query($sql)) echo("Aggiornamento avvenuto con successo.<br />");
                else echo("Problemi in aggiornamento.<br />");
            $db->close();
            break;
        }
        default:{
            $db = new mysqli("localhost","root","","pausa_didattica");
            $sql = "SELECT f.id, f.nome AS 'Figlio', p.cognome AS 'Cognome Padre', p.nome AS 'Nome Padre', m.cognome AS 'Cognome Madre', m.nome AS 'Nome Madre' ";
            $sql .= "FROM figlio AS f, padre AS p, madre AS m ";
            $sql .= "WHERE p.id=f.id_padre AND f.id_madre=m.id";

            echo("<table border=\"0\">");
                echo("<tr>");
                    echo("<th>Figlio</th>");
                    echo("<th colspan=\"2\">Padre</th>");
                    echo("<th  colspan=\"2\">Madre</th>");
                    echo("<th  colspan=\"2\">Operazioni di Gestione</th>");
                echo("</tr>");
                $resultSet = $db->query($sql);
                $record = $resultSet->fetch_assoc();
                while($record){
                    echo("<tr>");
                        echo("<td>".$record['Figlio']."</td>");
                        echo("<td>".$record['Cognome Padre']."</td>");
                        echo("<td>".$record['Nome Padre']."</td>"); 
                        echo("<td>".$record['Cognome Madre']."</td>");
                        echo("<td>".$record['Nome Madre']."</td>");
                        echo("<td style=\"text-align: center;\">
                            <a href=\"figlio.php?scelta=cancella_figlio&idfiglio=".$record['id']."\">
                            <img src=\"../bsicons/trash-fill.svg\" alt=\"Cancella\" /></a>
                            <a href=\"figlio.php?scelta=modifica_figlio&idfiglio=".$record['id']."\">
                            <img src=\"../bsicons/mouse2.svg\" alt=\"Modifica\" /></a>
                        </td>");
                    echo("</tr>");
                    $record = $resultSet->fetch_assoc();
                }
            echo("</table>");
            $db->close();
            break;
        }
    }
    echo("</body>");
    echo("</html>")
?>