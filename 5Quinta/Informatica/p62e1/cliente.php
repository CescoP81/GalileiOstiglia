<?php
require("../funzioni.php");
require("../head.html");
?>
<nav class="navbar navbar-expand-lg navbar-light bg-light">
   <div class="container-fluid">
      <div class="collapse navbar-collapse" id="navbarSupportedContent">
         <ul class="navbar-nav me-auto mb-2 mb-lg-0">
            <!-- blocco delle scelte per Loclità -->
            <li class="nav-item dropdown">
               <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                  Località
               </a>
               <ul class="dropdown-menu" aria-labelledby="navbarDropdown">
                  <li><a class="dropdown-item" href="localita.php?scelta=listaLocalita">Lista Località</a></li>
                  <li><a class="dropdown-item" href="localita.php?scelta=formLocalita">Nuovo Località</a></li>
                  <!--<li>
                     <hr class="dropdown-divider">
                  </li>
                  <li><a class="dropdown-item" href="#">Something else here</a></li>-->
               </ul>
            </li>

            <!-- blocco delle scelte per Cliente -->
            <li class="nav-item dropdown">
               <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                  Cliente
               </a>
               <ul class="dropdown-menu" aria-labelledby="navbarDropdown">
                  <li><a class="dropdown-item" href="cliente.php?scelta=listaCliente">Lista Clienti</a></li>
                  <li><a class="dropdown-item" href="cliente.php?scelta=formCliente">Nuovo Cliente</a></li>
                  <!--<li>
                     <hr class="dropdown-divider">
                  </li>
                  <li><a class="dropdown-item" href="#">Something else here</a></li>-->
               </ul>
            </li>
         </ul>         
      </div>
   </div>
</nav>
<?php
if (isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

switch ($sc) {
   case "listaCliente": {
         $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);
         $sql = "SELECT c.Id, c.ragioneSociale, c.indirizzo, c.numTelefono, c.partitaIva, c.idAgente, c.fido, l.cap, l.nome  
                  FROM p62e1_Localita AS l, p62e1_cliente AS c
                  WHERE c.idLocalita=l.Id";

         if($rs = $db->query($sql)){
            echo ("<table class=\"table table-success table-striped table-hover\">
               <thead>
                  <tr>
                     <th scope=\"col\">#</th>
                     <th scope=\"col\">Ragione Sociale</th>
                     <th scope=\"col\">Indirizzo</th>
                     <th scope=\"col\">Nr. Telefono</th>
                     <th scope=\"col\">Partita Iva</th>
                     <th scope=\"col\">Agente</th>
                     <th scope=\"col\">Fido</th>
                     <th scope=\"col\">Cap</th>
                     <th scope=\"col\">Paese</th>
                     <!--<td>Gestione</td>-->
                  </tr>
               </thead>");
            echo ("<tbody>");
            $record = $rs->fetch_assoc();
            while($record){
               echo ("<tr>
                  <th scope=\"row\">".$record['Id']."</th>
                  <td>".$record['ragioneSociale']."</td>
                  <td>".$record['indirizzo']."</td>
                  <td>".$record['numTelefono']."</td>
                  <td>".$record['partitaIva']."</td>
                  <td>".$record['idAgente']."</td>
                  <td>".$record['fido']."</td>
                  <td>".$record['cap']."</td>
                  <td>".$record['nome']."</td>
                  
                  <!--<td>
                     <a href=\"personeTable.php?scelta=deleteRecord&id_persona=" . $record['Id'] . "\">Delete</a> | 
                     <a href=\"personeTable.php?scelta=formModifica&id_persona=" . $record['Id'] . "\">
                     <svg xmlns=\"http://www.w3.org/2000/svg\" width=\"16\" height=\"16\" fill=\"currentColor\" class=\"bi bi-pen\" viewBox=\"0 0 16 16\">
                     <path d=\"m13.498.795.149-.149a1.207 1.207 0 1 1 1.707 1.708l-.149.148a1.5 1.5 0 0 1-.059 2.059L4.854 14.854a.5.5 0 0 1-.233.131l-4 1a.5.5 0 0 1-.606-.606l1-4a.5.5 0 0 1 .131-.232l9.642-9.642a.5.5 0 0 0-.642.056L6.854 4.854a.5.5 0 1 1-.708-.708L9.44.854A1.5 1.5 0 0 1 11.5.796a1.5 1.5 0 0 1 1.998-.001zm-.644.766a.5.5 0 0 0-.707 0L1.95 11.756l-.764 3.057 3.057-.764L14.44 3.854a.5.5 0 0 0 0-.708l-1.585-1.585z\"/>
                     </svg></a>
                  </td>-->
               </tr>");
               $record = $rs->fetch_assoc();
            }
            echo ("</tbody>");
            echo ("<caption>Tabella 'p62e1_Cliente' su DB scuola2021</caption>");
            echo ("</table>");
         }
         else{
            echo("Error...");
         }
         $db->close();
         break;
      }
   case "formCliente":{
      ?>
         <form action="cliente.php" method="get">
            <div class="mb-3">
            <label for="txt1" class="form-label">Cognome Nome</label>
            <input class="form-control" type="text" placeholder="Default input" id="txt1" name="ragioneSociale" aria-label="default input example">
            
            <label for="txt2" class="form-label">Indirizzo</label>
            <input class="form-control" type="text" placeholder="Default input" id="txt2" name="indirizzo" aria-label="default input example">
            
            <label for="txt3" class="form-label">Telefono</label>
            <input class="form-control" type="text" placeholder="Default input" id="txt3" name="numeroTelefono" aria-label="default input example">
            
            <label for="txt4" class="form-label">Partita Iva</label>
            <input class="form-control" type="text" placeholder="Default input" id="txt4" name="partitaIva" aria-label="default input example">
            
            <label for="txt5" class="form-label">Id Agente</label>
            <input class="form-control" type="text" placeholder="Default input" id="txt5" name="idAgente" aria-label="default input example">
            
            <label for="txt6" class="form-label">Fido</label>
            <input class="form-control" type="text" placeholder="Default input" id="txt6" name="fido" aria-label="default input example">
            
            <?php
               //le località disponibili le devo estrarre dal database -->
               $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);
               $sql = "SELECT * FROM p62e1_Localita ORDER BY nome ASC";
               $rs = $db->query($sql);
               $db->close();
               echo("\n\n");
               echo("<label for=\"sel1\" class=\"form-label\">Paese</label>\n");
               echo("\t<select class=\"form-select\" id=\"sel1\" name=\"idLocalita\" aria-label=\"Default select example\">\n");
                  $record = $rs->fetch_assoc();
                  while($record){
                     echo("\t\t<option value=\"".$record['Id']."\">".$record['nome']." (".$record['prov'].")</option>\n");
                     $record = $rs->fetch_assoc();
                  }
               echo("\t</select>\n\n");
            ?>
            <input type="hidden" name="scelta" value="addCliente">
            <button type="submit" class="btn btn-primary">Inserisci Cliente</button>
         </form>
      <?php
      break;
   }
   case "addCliente":{
      $rg = $_REQUEST['ragioneSociale'];
      $ind = $_REQUEST['indirizzo'];
      $tel = $_REQUEST['numeroTelefono'];
      $iva = $_REQUEST['partitaIva'];
      $agente = $_REQUEST['idAgente'];
      $fido = $_REQUEST['fido'];
      $localita = $_REQUEST['idLocalita'];

      $sql = "INSERT INTO p62e1_Cliente(ragioneSociale, indirizzo, numTelefono, partitaIva, idAgente, fido, idLocalita) 
            VALUES('$rg','$ind','$tel','$iva','$agente',$fido,$localita)";
      
      $db = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB);
      if($db->query($sql)) echo("Inserimento corretto...");
      else echo("Problema in inserimento");
      $db->close();
      
      break;
   }
   default: {
         echo ("caso di default...");
         break;
      }
}
require("../foot.html");
?>