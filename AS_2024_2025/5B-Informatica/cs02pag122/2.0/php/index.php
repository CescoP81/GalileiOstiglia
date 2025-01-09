<?php
session_start();
if(!isset($_SESSION['logged'])) $_SESSION['logged'] = false;
if(!isset($_REQUEST['scelta'])) $sc = null; else $sc = $_REQUEST['scelta'];

// includo la libreria con funzioni necessarie all'interfaccia.
require('../include/lib.php');
// richiamo la funzione per la creazione della sezione iniziale delle pagine
writeHeader();

// arrivo alla pagina dopo aver inserito le credenziali
// per eseguire un login come admin. (ci arrivo da un form).
if($sc == "login"){
    $u = $_REQUEST['username'];
    $p = $_REQUEST['password'];

    if($u == "admin" && $p=="admin"){
        $_SESSION['logged'] = true;
    }
    else{
        echo('<div class="alert alert-warning">Credenziali non valide</div>');
    }
}
if($sc == "logout"){
    $_SESSION['logged'] = false;
    session_destroy();
}

if($_SESSION['logged'] == true){ // se sono loggato mostro il gestionale con menu.
writeMenu();

    // << your code start here >>
        echo('<div class="alert alert-success">Pare funzionare tutto E sono pure loggato!</div>');
    // << end fo your code >>

}
else{
    // non sono loggato quindi mostro il form per eventuale login
    echo('
        <form action="index.php">
            <div class="mb-3">
                <label for="inputUsername" class="form-label">Username:</label>
                <input type="text" name="username" class="form-control form-control-sm" id="inputUsername" aria-describedby="descrizioneHelp">
                <label for="inputPassword" class="form-label">Username:</label>
                <input type="password" name="password" class="form-control form-control-sm" id="inputPassword" aria-describedby="descrizioneHelp">
           </div>
                <input type="hidden" name="scelta" value="login">
                <button type="submit" class="btn btn-primary">Submit</button>
        </form>');
}
// richiamo la funzione per la creazione della sezione finale delle pagine.

writeFooter();
?>