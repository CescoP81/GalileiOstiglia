<?php
/*  Realizzare una pagina PHP che grazie a opportune scelte gestite con switch-case permette di:
    1. Permettere di inserire una mail e una password su un Database (la password deve essere cifrata md5)
    2. Verificare su database la presenza della coppia mail-password inserita dall'utente.

    STEP:
    1. creare su db una tabella di prova che registri id, mail, password.
    2. prevedere un form per inserimento nuova mail e password.
        2.1. inserire i dati su db
    3. prevedere un form per verificare mail e password.
        3.1. verificare (interrogare) nel database la presenza della coppia mail-password richiesta 
        e visualizzare l'id corrispondente.

    CREATE TABLE cif_02(
        id integer unsigned auto_increment,
        mail varchar(100),
        passwd char(32),
        primary key(id)
    )
*/
$host = "localhost";
$user = "root";
$password = "";
$db_name = "scuola2223";

if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

echo("<html>
        <head><title>Prova di cifratura MD5</title>
        </head>
        <body>
");
echo("<table border=1>
        <tr><td>
            <b>Nuovo record cifrato</b><br />
            <form action=\"p02.php\" method=\"POST\">
                Mail: <input type=\"text\" name=\"mail\"><br />
                Password: <input type=\"password\" name=\"passwd\"><br />
                <input type=\"hidden\" name=\"scelta\" value=\"addNewMail\">
                <input type=\"submit\" value=\"Inserisci nuova mail\">
            </form>
        </td>
        <td>
            <b>Verifica record cifrato</b><br />
            <form action=\"p02.php\" method=\"POST\">
                Mail: <input type=\"text\" name=\"mail\"><br />
                Password: <input type=\"password\" name=\"passwd\"><br />
                <input type=\"hidden\" name=\"scelta\" value=\"verifyMail\">
                <input type=\"submit\" value=\"Verifica mail\">
            </form>
        </td>
    </table><br /><br />");

    switch($sc){
        case "addNewMail":{
            $m = $_REQUEST['mail'];
            $p = $_REQUEST['passwd'];
            $p = md5($p);

            $db = new mysqli($host, $user, $password, $db_name);
            $sql = "INSERT INTO cif_02(mail, passwd) VALUES('$m', '$p')";
            if($db->query($sql))
                echo("Tutto ok...");
            else
                echo("Problema...");
            $db->close();
            break;
        }
        case "verifyMail":{
            $m = $_REQUEST['mail'];
            $p = $_REQUEST['passwd'];
            $p = md5($p);

            $db = new mysqli($host, $user, $password, $db_name);
            $sql = "SELECT id FROM cif_02 WHERE mail='$m' AND passwd='$p'";
            $resultSet = $db->query($sql);
            if($resultSet->num_rows > 0){
                $record = $resultSet->fetch_assoc();
                echo("Record trovato! ID: ".$record['id']);
            }
            else{
                echo("Nessuna coppia mail-password inserita.");
            }
            break;
        }
    }
echo("</body>");
?>