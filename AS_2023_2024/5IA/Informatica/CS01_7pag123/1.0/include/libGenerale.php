<?php
$dbHost = "localhost";
$dbUser = "root";
$dbPassword = "";
$dbName = "scuola2324";
/**
 * Funzione per la creazione della navBar comune a tutte le pagine della UI.
 */
function scriviNavbar(){
    echo('
        <nav class="navbar navbar-expand-lg bg-body-tertiary">
            <div class="container-fluid">
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                    
                        <li class="nav-item">
                            <a class="nav-link" href="index.php">Home</a>
                        </li>

                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            Città
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="citta.php?scelta=formNuovaCitta">
                                <i class="bi-plus-circle" style="font-size: 1rem; color: cornflowerblue;"></i>
                                Nuova Città</a></li>
                                <li><a class="dropdown-item" href="citta.php?scelta=listaCitta">Lista Città</a></li>
                            </ul>
                        </li>

                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            Reparto
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="reparto.php?scelta=formNuovoReparto">Nuovo Reparto</a></li>
                                <li><a class="dropdown-item" href="reparto.php?scelta=listaReparto">Lista Reparti</a></li>
                            </ul>
                        </li>

                        <li class="nav-item dropdown">
                            <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                            Dipendente
                            </a>
                            <ul class="dropdown-menu">
                                <li><a class="dropdown-item" href="dipendente.php?scelta=formNuovoDipendente">Nuovo Dipendente</a></li>
                                <li><a class="dropdown-item" href="dipendente.php?scelta=listaDipendente">Lista Dipendenti</a></li>
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