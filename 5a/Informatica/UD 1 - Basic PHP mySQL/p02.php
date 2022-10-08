<?php
    require("../head.html");

    $db = new mysqli("localhost","root","","scuola2223");
    $sql = "SELECT * FROM studenti";

    $rs = $db->query($sql);
    /*while($record = $rs->fetch_assoc()){
        echo($record['id']." ".$record['cognome']." ".$record['nome']." ".$record['classe']."<br />");
    }*/

    echo("<table class=\"table\">");
        echo("<thead>
            <tr>
                <th scope=\"col\">#</th>
                <th scope=\"col\">Cognome</th>
                <th scope=\"col\">Nome</th>
                <th scope=\"col\">Classe</th>
            </tr>
        </thead>");
    echo("<tbody>");
        while($record = $rs->fetch_assoc()){
            echo("<tr>
                <th scope=\"row\">".$record['id']."</th>
                <td>".$record['cognome']."</td>
                <td>".$record['nome']."</td>
                <td>".$record['classe']."</td>
            </tr>");
        }
    echo("</tbody>
    </table>");
    $db->close();
    require("../foot.html");
?>