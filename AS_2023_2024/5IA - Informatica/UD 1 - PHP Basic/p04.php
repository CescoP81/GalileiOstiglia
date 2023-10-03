<?php
/* check variabili */
if(isset($_REQUEST['baseUtente'])) $b=$_REQUEST['baseUtente']; else $b=0;
if(isset($_REQUEST['altezzaUtente'])) $h=$_REQUEST['altezzaUtente']; else $h=0;


/* Apertura codice HTML per pagina valida */
echo("<html>
        <head><title>Prova form dinamico</title></head>
        <body>");

/* Creazione form html */
    echo("<form action=\"p04.php\">
            Base:
            <input type=\"text\" name=\"baseUtente\"><br />
            Altezza:
            <input type=\"text\" name=\"altezzaUtente\"><br />
            <input type=\"submit\" value=\"Calcola area e perimetro\">        
        </form>");

/* controllo valori ed eventuali calcoli */
/*$b = $_REQUEST['baseUtente'];
$h = $_REQUEST['altezzaUtente']; Spostate in alto ad inizio pagina con controllo */

if($b<=0 || $h<=0)
    echo("Problema con i dati...");
else{
    echo("Area= ".($b*$h)."<br />");
    echo("Perimetro = ".(($b+$h)*2)."<br />");
}

/* Chiusura della pagina html valida */
echo("</body></html>");
?>