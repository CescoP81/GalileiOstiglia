<?php
// questo file contiene funzioni e variabili utili in più pagine per non doverle ricopiare.
$DBHOST = "localhost";
$DBUSER = "root";
$DBPASSWORD = ""; // per voi è root
$DBNAME = "cs02pag188";

function writeHeader(){
    echo('
        <!DOCTYPE HTML>
        <html>
            <head>
                <meta charset="utf-8">
                <meta name="viewport" content="width=device-width, initial-scale=1">
                <title>Caso studio 02 Pag 188</title>
                <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
            </head>
            <body>
                <div class="container">
    ');
    return;
}

function writeFooter(){
    echo('
                </div>
                <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
            </body>
        </html>
    ');
    return;
}

function writeMenu(){
    echo('
        <nav class="navbar navbar-expand-lg bg-body-tertiary">
            <div class="container-fluid">
                <a class="navbar-brand" href="#">Home</a>
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                                Regione
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="regione.php?scelta=formRegione">Nuova Regione</a></li>
                                <li><a class="dropdown-item" href="regione.php?scelta=listaRegioni">Lista Regioni</a></li>
                            </ul>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>
    ');
    return;
}
?>