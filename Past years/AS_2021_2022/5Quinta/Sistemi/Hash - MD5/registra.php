<?php
/* pagina che visualizza un form di "registrazione" dove vengono
richiesti i dati al cliente, e vengono registrati sul database,
la password inserita dal cliente deve essere codifica in MD5*/

if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

echo("
   <html>
      <head><title>Form Registrazione Cliente</title></head>
      <body>");

   switch($sc){
      case "addCliente":{
         // recupero i valori che arrivano dal form via indirizzo http
         $n = $_REQUEST['nome'];
         $m = $_REQUEST['mail'];
         $p = $_REQUEST['passwd'];

         $db = new mysqli("localhost", "fpradella", "fpradella", "fpradella");
         $sql = "INSERT INTO cliente(nome, email, passwd) VALUES ('$n','$m','".md5($p)."')";

         echo($sql);
         if($db->query($sql))
            echo("Registrazione avvenuta con successo.");
         else
            echo("Problema in registrazione.");
         $db->close();
         break;
      }
      default:{
         // caso iniziale in cui viene visualizzato il form di richiesta dati cliente.
         echo("
            <form action=\"registra.php\" method=\"get\">
               Nome: <input type=\"text\" value=\"es. Rossi Gino\" name=\"nome\"><br />
               mail: <input type=\"text\" value=\"es. ginor@gmail.com\" name=\"mail\"><br />
               Password: <input type=\"password\" name=\"passwd\" name=\"passwd\"><br />
               <input type=\"hidden\" name=\"scelta\" value=\"addCliente\">
               <input type=\"submit\" value=\"Registrami\">
            </form>
         ");
         break;
      }
   }
echo("</body></html>");
?>