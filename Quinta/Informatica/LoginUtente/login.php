<?php
session_start();
if(!isset($_REQUEST['scelta'])) $_REQUEST['scelta'] = null;

if($_REQUEST['scelta'] == "login"){
    $u_nome = $_REQUEST['utente_nome'];
    $u_password = $_REQUEST['utente_password'];

    $db = new mysqli("localhost", "root", "", "scuola2021");
        $sql = "SELECT * FROM utente WHERE email='$u_nome' AND upassword='$u_password'";

        //echo("Query: ".$sql."<br><br>");

        $resultSet = $db->query($sql);
        if($resultSet->num_rows == 1){
            $record = $resultSet->fetch_assoc();
            echo($record['nome']." ".$record['cognome']." ".$record['email']);
            $_SESSION['id_utente'] = $record['id'];
            $_SESSION['nome'] = $record['nome'];
            $_SESSION['cognome'] = $record['cognome'];
            $_SESSION['logged_in'] = true;
        }
        else{
            echo("Utente non riconosciuto. Nome utente o Password errati.");
            echo("<a href=\"login.html\">Login</a>");
        }
    $db->close();
}
if($_REQUEST['scelta'] == "logout"){
    $_SESSION['logged_in'] = false;
}

if($_SESSION['logged_in']){
    echo("<a href=\"forum.php\">Forum</a> | ");
    echo("<a href=\"login.php?scelta=logout\">Logout</a>");
}
else{
    echo("Nessun utente loggato.<br >");
    echo("<a href=\"login.html\">Login</a>");
}
?>