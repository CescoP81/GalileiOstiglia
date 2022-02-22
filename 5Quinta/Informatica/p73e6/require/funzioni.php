<?php
/*  #################################
    #  COSTATI DI CONNESSIONE MYSQL #
    #################################*/
    /* Il valore delle costanti deve essere
    cambato in accordo con i dati del mySQL in uso */
  define("DBHOST","localhost");
  define("DBUSER","root");
  define("DBPASSWORD","");
  define("DBNAME","scuola2122");

/*  ###################
    #  FUNZIONI VARIE #
    ###################*/
  /** Visualizza il menu principale di navigazione.
   */
  function writeMenu(){
      echo("
      <nav class=\"navbar navbar-expand-lg navbar-light bg-light\">
      <div class=\"container-fluid\">
        <button class=\"navbar-toggler\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">
          <span class=\"navbar-toggler-icon\"></span>
        </button>
        <div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">
          <ul class=\"navbar-nav me-auto mb-2 mb-lg-0\">
            <li class=\"nav-item\">
              <a class=\"nav-link\" aria-current=\"page\" href=\"index.php\">Home</a>
            </li>

            <li class=\"nav-item dropdown\">
              <a class=\"nav-link dropdown-toggle\" href=\"#\" id=\"navbarDropdown\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
              Proprietari
              </a>
              <ul class=\"dropdown-menu\" aria-labelledby=\"navbarDropdown\">
                <li><a class=\"dropdown-item\" href=\"proprietari.php?sc=listaProprietari\">Lista Proprietari</a></li>
                <li><a class=\"dropdown-item\" href=\"proprietari.php?sc=nuovoProprietario\">Nuovo Proprietario</a></li>
              </ul>
            </li>

            <li class=\"nav-item\">
              <a class=\"nav-link\" href=\"zone.php\">Zone e Tipologie</a>
            </li>

            <li class=\"nav-item dropdown\">
              <a class=\"nav-link dropdown-toggle\" href=\"#\" id=\"navbarDropdown\" role=\"button\" data-bs-toggle=\"dropdown\" aria-expanded=\"false\">
              Immobili
              </a>
              <ul class=\"dropdown-menu\" aria-labelledby=\"navbarDropdown\">
                <li><a class=\"dropdown-item\" href=\"immobili.php?sc=listaImmobili\">Lista Immobili</a></li>
                <li><a class=\"dropdown-item\" href=\"immobili.php?sc=nuovoImmobile\">Nuovo Immobile</a></li>
              </ul>
            </li>
            
            <li class=\"nav-item\">
              <a class=\"nav-link\" href=\"index.php?sc=logout\">Logout</a>
            </li>
          </ul>
        </div>
      </div>
    </nav>
    <br />");
  }

  function showResultTable($resultSet, $caption=null){
    $record = $resultSet->fetch_assoc();
    $keys = array_keys($record);
    /*for($i=0; $i<count($keys); $i++)
      echo($keys[$i]." ");*/

    echo("<table class=\"table table-striped\">");
      if($caption) echo("<caption>$caption</caption>");
      echo("<thead>");
        echo("<tr>");
          //echo("<th scope=\"col\">#</th>");
          for($i=0; $i<count($keys); $i++)
            echo("<th scope=\"col\">".$keys[$i]."</th> ");
        echo("</tr>");
      echo("</thead>");
      echo("<tbody>");
      while($record){
        echo("<tr>");
        for($i=0; $i<count($keys); $i++)
          echo("<td>".$record[$keys[$i]]."</td>");
        echo("</tr>");
        $record = $resultSet->fetch_assoc();
      }
      echo("</tbody>");
    echo("</table>");
  }
?>