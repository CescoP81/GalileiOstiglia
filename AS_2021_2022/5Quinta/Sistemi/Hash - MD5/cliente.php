<?php
/* permette ad un utente di loggarsi e navigare come utente registrato.
   Questa pagina utilizza il concetto di SESSIONE
   https://www.php.net/manual/en/session.examples.basic.php
*/
session_start();

if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta'];
else $sc = null;

if(!isset($_SESSION['loggato'])) $_SESSION['loggato'] = false;


if($sc == "login"){
   $m = $_REQUEST['mail'];
   $p = $_REQUEST['passwd'];

   $db = new mysqli("localhost","fpradella","fpradella", "fpradella");
   $sql = "SELECT * 
            FROM cliente 
            WHERE email='$m' AND passwd='".md5($p)."'";
   echo($sql);
   $resultSet = $db->query($sql);
   if($resultSet->num_rows == 1){
      echo("<br />Utente esistente...");
      $_SESSION['loggato'] = true;
      $record = $resultSet->fetch_assoc();
      $_SESSION['nome_utente'] = $record['nome'];
   }
   else{
      echo("<br />Utente non presente...");
      $_SESSION['loggato'] = false;
   }
   $db->close();
}

if($sc == "logout"){
   $_SESSION['loggato'] = false;
}

if($_SESSION['loggato'] == false){
   // utente non loggato, visualizzo il form per fare il login
   echo("<form action=\"cliente.php\" method=\"get\">
      Mail: <input type=\"text\" name=\"mail\"><br />
      Password: <input type=\"password\" name=\"passwd\"><br />
      <input type=\"hidden\" name=\"scelta\" value=\"login\">
      <input type=\"submit\" value=\"Login\">   
   ");
}
if($_SESSION['loggato'] == true){
   echo("Utente Loggato: ".$_SESSION['nome_utente']."<br />");
   echo("<br /><br />");
   echo("<a href=\"#\">Nuovo Libro</a> | ");
   echo("<a href=\"#\">Ricerca Autore</a> | ");
   echo("<a href=\"#\">Nuovi Arrivi</a> | ");
   echo("<a href=\"#\">Offerte</a> | ");
   echo("<a href=\"cliente.php?scelta=logout\">LogOut</a>");
}
?>