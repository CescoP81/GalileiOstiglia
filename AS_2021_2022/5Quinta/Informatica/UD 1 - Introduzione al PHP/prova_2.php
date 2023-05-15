<?php
/*
   http://www.dominio.com?x=5&y=6&z=89
   http://www.dominio.com -> dominio o pagina che viene richiamata.
   ? -> ? è un operatore di concatenzione per la URL.
   x=5&y=6&z=89 -> coppie variabile-valore

   in PHP è presente un VETTORE ASSOCIATIVO composto dalle
   variabili passate nella URL ed il loro valore.
   Questo vettore si chiama $_REQUEST[]
*/
echo("<html>   
      <head>
         <title>Prova di pagina PHP</title>
      </head>
      <body>");

      // istruzioni PHP per il recupero delle variabili e loro utilizzo
      //$var = 90;

      /* 
      http://scuola.localhost/5%20Quinta/Informatica/UD%201%20-%20Introduzione%20al%20PHP/prova_2.php
      ?
      start=83
      */
      $var = $_REQUEST['start'];
      if($var <= 100){
         for($i=$var; $i<=100; $i++)
            echo($i."<br />");
      }
      else{
         echo("Punto di inizio superiore al LIMITE di fine.");
      }


echo("</body>
      </html>");
?>