<?php
session_start();

if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;

if($sc == "LOGIN"){
    // vado a ricercare l'utente nel database
    $u = $_REQUEST['username'];
    $p = $_REQUEST['passwd'];

    $db = new mysqli("localhost","root","","scuola2324");
    $sql = "SELECT * FROM utenti WHERE mail='$u' AND password='$p'";
    $resultSet = $db->query($sql);
    if($resultSet->num_rows == 1){
        $record = $resultSet->fetch_assoc();
        
        $_SESSION['nome'] = $record['nome'];
        $_SESSION['cognome'] = $record['cognome'];
        $_SESSION['loggato'] = true;
    }
    else{
        echo("Errore nei dati inseriti, Utente e Password non corretti.<br /><br />");
    }
    $db->close();
}

if($sc == "LOGOUT"){
    // distruggo la sessione quindi eseguo il logout dell'utente
    $_SESSION['loggato'] = false;
}

if($_SESSION['loggato'] == true){
    // mostro un messaggio di utente loggato
    echo('Bentornato '.$_SESSION['nome'].' '.$_SESSION['cognome'].'<br />');
    echo('<a href="index.php?scelta=LOGOUT">ESCO</a><br />');
    echo('<a href="pagina2.php">Passa a pagina 2</a>');
}
else{
    // mostro il form per eseguire il login.
    echo('
        <form action="index.php" method="get">
            Username:<br /><input type="text" name="username"><br>
            Password:<br /><input type="password" name="passwd"><br />
            <input type="hidden" name="scelta" value="LOGIN">
            <input type="submit" value="ENTRA">
        </form>');
}
?>