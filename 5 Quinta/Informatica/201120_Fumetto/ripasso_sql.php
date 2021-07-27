<?php
    if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
    else $sc = null;

    //$sc = $_REQUEST['scelta'];

    $host="localhost";
    $user="root";
    $password="";
    $database="scuola2021";

    $db = new mysqli($host,$user,$password,$database);
    $sql = "SELECT * FROM fumetto";
    // $db->query() --> invoco il metodo query() dell'oggetto db
    $resultSet = $db->query($sql); // equivalente $db->query("SELECT * FROM fumetto")
    $record = $resultSet->fetch_assoc();

    while($record){
        echo($record['id']."  ".$record['collana']."  ".$record['titolo']."  ".$record['editore']."  ".$record['prezzo']."  ".$record['anno_pub']."<br />");
        $record = $resultSet->fetch_assoc();
    }
    $db->close();
    echo("<br><br>");

    switch($sc){
        case "add_fumetto":{
            $collana=$_REQUEST['collana'];
            $titolo=$_REQUEST['titolo'];
            $editore=$_REQUEST['editore'];
            $prezzo=$_REQUEST['prezzo'];
            $anno=$_REQUEST['anno'];

            $db= new mysqli ($host,$user,$password,$database);
            $sql= "INSERT INTO fumetto (collana,titolo,editore,prezzo,anno_pub) ";
            $sql.="VALUES('$collana','$titolo','$editore',$prezzo,'$anno')";

            if($db->query($sql)){
                echo("Inserimento avvenuto.");
            }
            else{
                echo("Problemi in inserimento.");
            }
            $db->close();
            echo("<a href=\"ripasso_sql.php\" > Aggiorna pagina</a>" );
        break;
        }
        default:{
        echo("<form action=\"ripasso_sql.php\" method=\"get\">");
            echo("collana: <input type=\"text\" name=\"collana\"> <br>");
            echo("titolo: <input type=\"text\" name=\"titolo\"> <br>");
            echo("editore: <input type=\"text\" name=\"editore\"> <br>");
            echo("prezzo: <input type=\"text\" name=\"prezzo\"> <br>");
            echo("Anno_pub: <input type=\"text\" name=\"anno\"> <br>");
            echo("<input type=\"hidden\" name=\"scelta\" value=\"add_fumetto\">");
            echo("<input type=\"submit\" value=\"Aggiungi fumetto\">");
            echo("</form>");
        break;
        }
    }

?>