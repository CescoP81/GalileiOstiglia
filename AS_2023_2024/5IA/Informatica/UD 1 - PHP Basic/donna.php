<?php
/**
 * Il codice seguente si bassa sulla schematizzazione ER del file er01.drawio persente nella
 * cartella /UD 2 - mySQL Basics.
 * 
 * Il codice permette:
 * - Visualizza il form per l'inserimento di un nuovo record.
 * - Visualizza il contenuto della tabella Uomo nel database.
 * - Visualizza un messaggio di conferma di avvenuto inserimento record.
 */

 if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;
require("lib.php");
 require("head.php");
 scriviNavBar();
/*
 echo("<nav class=\"navbar navbar-expand-lg bg-body-tertiary\">
    <div class=\"container-fluid\">
    
        <div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">
            <ul class=\"navbar-nav me-auto mb-2 mb-lg-0\">
                <li class=\"nav-item\">
                    <a class=\"nav-link active\" aria-current=\"page\" href=\"uomo.php\">Home</a>
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
            </ul>
        </div>
    </div>
    </nav>   
    ");*/
    /*
    <li><hr class=\"dropdown-divider\"></li>
                    <li><a class=\"dropdown-item\" href=\"#\">Something else here</a></li>
                    </ul>
    <li class=\"nav-item\">
                    <a class=\"nav-link\" href=\"#\">Link</a>
                </li>
    <a class=\"navbar-brand\" href=\"#\">Navbar</a>
            <button class=\"navbar-toggler\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">
                <span class=\"navbar-toggler-icon\"></span>
            </button>

    <li class=\"nav-item\">
                    <a class=\"nav-link disabled\" aria-disabled=\"true\">Disabled</a>
                </li>

        <form class=\"d-flex\" role=\"search\">
                <input class=\"form-control me-2\" type=\"search\" placeholder=\"Search\" aria-label=\"Search\">
                <button class=\"btn btn-outline-success\" type=\"submit\">Search</button>
                </form>
    */
    // costruisco il form bootstrap per l'inserimento dei dati di un nuovo record.
    if($sc=="formDonna"){
        echo("<div class=\"alert alert-primary\"><h3>Form inserimento nuovo record</h3></div>");
        echo("<form action=\"uomo.php\">
            <div class=\"mb-3\">
                <label for=\"nomeUomo\" class=\"form-label\">Nome:</label>
                <input type=\"text\" class=\"form-control\" id=\"nomeUomo\" name=\"nomeUomo\" placeholder=\"Insert a name\">
            </div>
            <div class=\"mb-3\">
                <label for=\"cognomeUomo\" class=\"form-label\">Cognome:</label>
                <input type=\"text\" class=\"form-control\" id=\"cognomeUomo\" name=\"cognomeUomo\" placeholder=\"Insert a surname\">
            </div>
            <div class=\"mb-3\">
                <label for=\"anniUomo\" class=\"form-label\">Anni:</label>
                <input type=\"text\" class=\"form-control\" id=\"anniUomo\" name=\"anniUomo\" placeholder=\"Insert an age\">
            </div>
            <div class=\"mb-3\">
                <label for=\"paeseUomo\" class=\"form-label\">Paese:</label>
                <input type=\"text\" class=\"form-control\" id=\"paeseUomo\" name=\"paeseUomo\" placeholder=\"Insert a place\">
            </div>
            <input type=\"hidden\" name=\"scelta\" value=\"addUomo\">
            <button type=\"submit\" class=\"btn btn-primary\">Inserisci nuovo record</button>
        </form>");
    }

    // se $sc testata all'inizio della pagina è diversa da null e vale "addUomo" allora recupero le altre variabili dalla HTTP Request.
    // poi eseguo la query di inserimento del nuovo record.
    if($sc == "addDonna"){
        $n = $_REQUEST['nomeUomo'];
        $c = $_REQUEST['cognomeUomo'];
        $a = $_REQUEST['anniUomo'];
        $p = $_REQUEST['paeseUomo'];

        $sql = "INSERT INTO Uomo(nome, cognome, anni, paese)
                VALUES('$n','$c',$a,'$p');";

        $db = new mysqli("localhost", "root","","scuola2324");
        if($db->query($sql)){
            echo("<div class=\"alert alert-success\">
                Record aggiunto...
            </div>");
        }
        else{
            echo("<div class=\"alert alert-warning\">
                Record non aggiunto, possibile mancanza dati.
            </div>");
        }
        $db->close();
    }

    // creo una tabella bootstrap per visualizzare i dati presenti nel DB e selezionati dalla SELECT.
    if($sc=="vediDonna"){
        echo("<div class=\"alert alert-primary\"><h3>Contenuto della tabella nel database</h3></div>");
        $db = new mysqli("localhost","root","","scuola2324"); // apro uno stream dati con il database -> mysql
        $sql = "SELECT *        
                FROM donna";
        $resultSet = $db->query($sql);
        $db->close();

        echo("<table class=\"table table-striped\"> 
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Nome</th>
                    <th>Cognome</th>
                    <th>Anni</th>
                    <th>Paese</th>
                </tr>
            </thead>
            <tbody>
        ");
            while($record = $resultSet->fetch_assoc()){
                echo("<tr>
                    <th>".$record['id']."</th>
                    <td>".$record['nome']."</td>
                    <td>".$record['cognome']."</td>
                    <td>".$record['anni']."</td>
                    <td>".mb_convert_encoding($record['paese'], "utf-8")."</td>
                ");
            }
            echo("</tbody>");
            echo("<caption>Elenco uomini presenti nel database</caption>");
        echo("</table>");
    }
 require("foot.php");
?>