<?php
session_start();    // deve sempre essere la prima riga del codice PHP quando voglio usare le sessioni.
if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;
if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

/* Discrimino in base alla scelta che mi arriva (generalmente da un form o da un link)
cosa devo fare tra l'operazione di login oppure di logout.*/
if($sc == "login"){
    // eseguirò il controllo su database delle credenziali che ricevo da un form.
    $u = $_REQUEST['utente'];
    $p = $_REQUEST['passwd'];

    $sql = "SELECT * FROM utente WHERE mail='$u' AND passwd='".md5($p)."'";
    echo($sql);
}
if($sc == "logout"){
    //imposto a false la variabile di sessione 'loggato
    $_SESSION['loggato'] = false;
}

// costruisco la pagina in base allo stato del visitatore ovvero se loggato oppure no.
echo('<html>
        <head>
            <title>Prova di login con cifratura md5</title>
        </head>
        <body>');

        if($_SESSION['loggato'] == true){
            // sono nella condizione di un utente loggato.
            echo('Utente: '.$_SESSION['nome'].' '.$_SESSION['cognome'].'
            <a href="index.php?scelta=logout">ESCI</a>');
        }
        if($_SESSION['loggato' == false]){
            // non sono un utente autenticato quindi mostro il form per eseguire l'autentica.
            echo('<form action="index.php" method="get">
                Mail Utente: <input type="text" name="utente"><br />
                Password: <input type="password" name="passwd"><br />
                <input type="hidden" name="scelta" value="login">
                <input type="submit" value="Accedi">
            </form>');
        }
echo("  </body>
    </html>");
?>