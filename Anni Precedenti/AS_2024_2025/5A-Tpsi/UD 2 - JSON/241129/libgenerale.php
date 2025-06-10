<?php
/**
 * Funzione per la creazione della navBar comune a tutte le pagine della UI.
 */
$dbHost = "localhost";
$dbUser = "root";
$dbPassword = "";
$dbName = "scuola2324";
function scriviNavbar(){
    echo('
        <nav class="navbar navbar-expand-lg bg-body-tertiary">
            <div class="container-fluid">
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                        <!--
                        <li class="nav-item">
                            <a class="nav-link" href="index.php">Home</a>
                        </li>
                        -->
                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            Temperatura
                            </a>
                            <ul class="dropdown-menu">
                                <!--<li><a class="dropdown-item" href="temperatura.php?scelta=addTemp">aggiungi Temperatura</a></li>-->
                                <li><a class="dropdown-item" href="temperatura.php?scelta=listaTemp">Visualizza lista </a></li>
                            </ul>
                        </li>
                       
                        <!--
                        <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                        Github
                        </a>
                        <ul class="dropdown-menu">
                            <li><a class="dropdown-item" href="redirect.php">Join Github</a></li>
                            
                        </ul>
                    </li>-->

                    </ul>
                </div>
            </div>
        </nav>
    ');
    return;
}
?>