   <?php
      echo("<html>   
         <head>
            <title>Prova di pagina PHP</title>
         </head>
         <body>");

      // commento mono riga.

      /* commento
      multi 
      riga
      */

      // istruzione di output.
      echo("Hello world...\n<BR/><br /><br />");
      echo("Hello world II...<BR/><br /><br />");

      $var;          // istanzio una vaiabile.
      
      $var = 14;     // assegno il valore intero 14
      echo($var."<br />");

      $var = 26.987; // assegno il valore float a var.
      echo($var);

      $var = "Oggi piove, governo ladro!"; // assegno la stringa alla variabile var.
      echo("<br />".$var);

      /* le variabili si "adattano" al tipo di dato che vi inserisco, può essere un vantaggio
      ma richiede anche una certa attenzione, nelle righe che seguono, var contiene un valore intero,
      ma appena viene eseguita la divisione, var diventa un "float" cioè un valore con la virgola.
      Questa è una delle principali differenze con il linguaggio C.
      */

      $var = 9;
      $var = $var / 2;
      echo("<br />".$var);

      echo("<br /><br />");
      $var = 7;                        // esempio di if-else (la sintassi è identica al C.) Anche la switch-case è identica.
      if($var%2 == 0)
         echo($var." &egrave; Pari.");
      else
         echo($var." è Dispari.");

      echo("<br /><br />");
      echo("Uno&nbsp;&nbsp;&nbsp;&nbsp;due");

      echo("<br /><br />");
      for($i=1; $i<=10; $i++)          // esempio di ciclo FOR (la sintassi è identica al C.) Anche i cicli Wihile e do-while sono identici.
         echo("$i <br />");

      echo("</body>
      </html>");
?>
