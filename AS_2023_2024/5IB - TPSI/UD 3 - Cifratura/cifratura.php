<?php
if(isset($_REQUEST['scelta'])) $sc=$_REQUEST['scelta']; else $sc = null;

switch($sc){
    case "registra":{
        /* in questo case arrivo dopo aver cliccato il bottone nel form per 
        eseguire una nuova registrazione, la costante "registra" è nel campo hidden
        chiamato scelta */
        $nome = $_REQUEST['nome_utente'];
        $cognome = $_REQUEST['cognome_utente'];
        $mail = $_REQUEST['mail_utente'];
        $passwd = $_REQUEST['passwd_utente'];

        echo($nome." ".$cognome." ".$mail." ".$passwd."<br />");

        //cifrare la password
        $passwd = md5($passwd."xyz");
        echo($nome." ".$cognome." ".$mail." ".$passwd."<br />");

        // mi collego al DB e eseguo l'inserimento dei dati nella tabella
        $db = new mysqli("localhost","root","","scuola2324");
        $sql = "INSERT INTO utente(nome, cognome, email, passwd)
                VALUES('$nome','$cognome','$mail','$passwd')";
        
        echo($sql);
        if($db->query($sql))
            echo("Registrazione avvenuta con successo.<br />");
        else
            echo("Problema in registrazione.<br />");
        
        $db->close();
        break;
    }
    default:{
        // caso in cui l'utente non abbia eseguito ancora nessuna operazione
        // quindi presento il form di inserimento dati da cifrare.
        echo('
            <form action="cifratura.php" method="get">
                Nome: <input type="text" name="nome_utente"><br />
                Cognome: <input type="text" name="cognome_utente"><br />
                email: <input type="text" name="mail_utente"><br />
                password: <input type="password" name="passwd_utente"><br/>
                <input type="hidden" name="scelta" value="registra">
                <input type="submit" value="Registra Nuovo Utente">   
            </form>
        ');
        break;
    }
}
?>