<?php
function scriviNavBar(){
    echo("<nav class=\"navbar navbar-expand-lg bg-body-tertiary\">
            <div class=\"container-fluid\">
            
                <div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">
                    <ul class=\"navbar-nav me-auto mb-2 mb-lg-0\">
                        <li class=\"nav-item\">
                            <a class=\"nav-link active\" aria-current=\"page\" href=\"index.php\">Home</a>
                        </li>
                    
                        <li class=\"nav-item dropdown\">
                            <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                                Tabella Uomo
                            </a>
                            <ul class=\"dropdown-menu\">
                                <li><a class=\"dropdown-item\" href=\"uomo.php?scelta=formUomo\">Aggiungi Uomo</a></li>
                                <li><a class=\"dropdown-item\" href=\"uomo.php?scelta=vediUomo\">Vedi tabella</a></li>
                            </ul>
                        </li>

                        <li class=\"nav-item dropdown\">
                            <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                                Tabella Donna
                            </a>
                            <ul class=\"dropdown-menu\">
                                <li><a class=\"dropdown-item\" href=\"donna.php?scelta=formDonna\">Aggiungi Donna</a></li>
                                <li><a class=\"dropdown-item\" href=\"donna.php?scelta=vediDonna\">Vedi tabella</a></li>
                            </ul>
                        </li>

                        <li class=\"nav-item dropdown\">
                            <a class=\"nav-link dropdown-toggle\" href=\"#\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
                                Tabella Figli
                            </a>
                            <ul class=\"dropdown-menu\">
                                <li><a class=\"dropdown-item\" href=\"donna.php?scelta=formDonna\">Aggiungi Donna</a></li>
                                <li><a class=\"dropdown-item\" href=\"donna.php?scelta=vediDonna\">Vedi tabella</a></li>
                            </ul>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>   
    ");
}
?>