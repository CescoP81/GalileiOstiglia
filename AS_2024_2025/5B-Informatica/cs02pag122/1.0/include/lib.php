<?php
/* Questo file contiene tutte le funzioni utili e che saranno richiamate nelle diverse pagine,
il file sarà incluso nei file php che si trovano in /php. */
$DBHOST = "localhost";
$DBUSER = "root";
$DBPASSWORD = "";
$DBNAME = "5B_AS2425"; // cs02pag122 se lo avete chiamato così!

/**
 * Funzione che genera la parte iniziale di ogni pagina, costruendo il corpo della pagina partendo dai tag fondamentali, genera il codice fino
 * alla DIV generale che conterrà tutta l'interfaccia predisposta nelle diverse pagine di gestione.
 */
function writeHeader(){
    echo('
        <!DOCTYPE HTML>
            <html>
                <head>
                    <meta charset="utf-8">
                    <title>CASO STUDIO 02 PAGINA 122</title>
                    <meta name="viewport" content="width=device-width, initial-scale=1">
                    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
                </head>
                <body>
                    <div class="container">
    ');
    return;
}

/**
 * Funzione che genera le righe di chiusura di ogni pagina così da chiudere in modo corretto ogni interfaccia.
 */
function writeFooter(){
    echo('
                    </div>
                    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>
                    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.min.js" integrity="sha384-0pUGZvbkm6XF6gxjEnlmuGrJXVbNuzT9qBBavbLwCsOGabYfZo0T0to5eqruptLy" crossorigin="anonymous"></script>
                </body>
            </html>');
    return;
}

/**
 * Funzione che genera il codice HTML e Bootstrap per rappresentare una barra di navigazione ad inizio pagina o comunque dove viene richiamata.
 */
function writeMenu(){
    echo('
        <nav class="navbar navbar-expand-lg bg-body-tertiary">
            <div class="container-fluid">
                <a class="navbar-brand" href="#">HOME</a>
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                                PRODOTTO
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="prodotto.php?scelta=formNuovoProdotto">Add Prodotto</a></li>
                                <li><a class="dropdown-item" href="prodotto.php?scelta=listaProdotto">List Prodotto</a></li>
                            </ul>
                        </li>

                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                                MAGAZZINO
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="magazzino.php?scelta=formNuovoMagazzino">Add Magazzino</a></li>
                                <li><a class="dropdown-item" href="magazzino.php?scelta=listaMagazzino">List Magazzino</a></li>
                            </ul>
                        </li>

                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                                ACQUISTO
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="acquisto.php?scelta=formNuovoAcquisto">Add Acquisto</a></li>
                                <li><a class="dropdown-item" href="acquisto.php?scelta=listaAcquisto">List Acquisto</a></li>
                            </ul>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>    
    '); //*/

    return;
}
?>