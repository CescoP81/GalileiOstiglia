<?php
/*  #########################
    # VARIABILI 'GLOBALI'   #
    # UTILI A PIU' PAGINE   #
    #########################
*/
$db_host = "localhost";
$db_user = "root";
$db_password = ""; // su uWamp impostare root come lo user.
$db_name = "5ics01";

/*  #########################
    # FUNZIONI 'GLOBALI'    #
    # UTILI A PIU' PAGINE   #
    #########################
*/
function writeHeader(){
    echo('<!DOCTYPE html>
        <html lang="it">
        <head>
            <meta charset="utf-8">
            <meta name="viewport" content="width=device-width, initial-scale=1">
            <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">
            <title>CS01 - Azienda Vendita Software</title>
        </head>
        <body>
            <div class="container">');
}

function writeFooter(){
    echo('</div>
            <!-- Prima di chiudere il body vado ad inserire eventuali sezioni di script--> 
            <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/js/bootstrap.bundle.min.js" integrity="sha384-FKyoEForCGlyvwx9Hj09JcYn3nv7wiPVlz7YYwJrWVcXK/BmnVDxM+D2scQbITxI" crossorigin="anonymous"></script>   
        </body>
    </html>');
}

function writeMainMenu(){
    echo('<a href="index.php">HOME</a> | 
        <a href="categoria.php?scelta=listaCategoria">Lista Categorie</a> | 
        <a href="categoria.php?scelta=formNuovaCategoria">Nuova Categoria</a> | 
        
        <a href="produttore.php?scelta=">Lista Produttori</a> | 
        <a href="produttore.php?scelta=">Nuovo Produttore</a> |
        <br />       
    ');
}
?>