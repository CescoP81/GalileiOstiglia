<?php
    echo("<html>");
    echo("<head><title>Selection dinamiche</title></head>");
    echo("<body>");
       echo("<form>");
            echo("<select name=\"id_docente\">");
                echo("<option value=\"1\">Pradella");
                echo("<option value=\"2\">Bottoni");
                echo("<option value=\"3\">Barbi");
                echo("<option value=\"4\">Ravelli");
            echo("</select>");
       echo("</form>");

       echo("<br /><br />");

       $db = new mysqli("localhost","root","","scuola2021");
       $sql = "SELECT * FROM docente";
       $resultSet = $db->query($sql);

       echo("<form>");
            echo("<select name=\"id_docente\">");
                $record = $resultSet->fetch_assoc();
                while($record){
                    echo("<option value=\"".$record['id']."\">".$record['cognome']." ".$record['nome']);
                    $record = $resultSet->fetch_assoc();
                }
            echo("</select>");
        echo("</form>");
        $db->close();
    echo("</body>");
    echo("</html>");
?>