<?php
function menuOperativo(){
    echo("<div style=\"text-align: right;\">Amministratore: ".$_SESSION['nome_utente']."</div>");
    // creo il menu operativo della pagina.
    // utilizzo il blocco nav di base come specificato nella documentation.
    echo("<nav class=\"nav\">");
        echo("<a class=\"nav-link\" href=\"index.php\">Home</a>");
        echo("<a class=\"nav-link\" href=\"camera.php?scelta=showCamera\">Elenco Camere</a> ");
        echo("<a class=\"nav-link\" href=\"camera.php?scelta=formCamera\">Nuova Camera</a>");

        echo("<a class=\"nav-link\" href=\"cliente.php?scelta=showCliente\">Elenco Clienti</a> ");
        echo("<a class=\"nav-link\" href=\"cliente.php?scelta=formCliente\">Nuovo Cliente</a>");
        
        echo("<a class=\"nav-link\" href=\"prenotazione.php?scelta=showPrenotazione\">Elenco Prenotazioni</a> ");
        echo("<a class=\"nav-link\" href=\"prenotazione.php?scelta=formPrenotazione\">Nuova Prenotazione</a>");
    
        echo("<a class=\"nav-link\" href=\"index.php?scelta=logout\">Logout</a>");
    
    echo("</nav>");
}
?>