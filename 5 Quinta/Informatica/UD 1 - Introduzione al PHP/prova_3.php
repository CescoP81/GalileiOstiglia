<?php
function showFormMisure(){
   echo("<form action=\"prova_3.php\" method=\"get\">
   Base: <input type=\"text\" name=\"base\"><br />
   Altezza: <input type=\"text\" name=\"altezza\"><br />
   <input type=\"hidden\" name=\"step\" value=\"calcola_misure\">
   <input type=\"submit\" value=\"Calcola Area e Perimetro\">
");
}
/**
 * Description: Script di esempio con form e scelta multipla all'interno della stessa pagina.
 * evitiamo di creare le pagine HTML con i form e le pagine PHP per l'elaborazione dei dati.
 * Entrambe le operazioni sono gestite dalla stessa pagina, discriminando cosa fare grazie
 * ad un blocco di selezione switch-case.
 */
echo("<html>   
<head>
   <title>Prova di pagina PHP</title>
</head>
<body>");

   // fase di test delle variabili passate dal form, potrebbero non essere inizializzate
   // quindi un test iniziale evita di avere valori casuali o non validi.
   if(isset($_REQUEST['step'])) $step = $_REQUEST['step']; else $step = null;
   if(isset($_REQUEST['base'])) $b = $_REQUEST['base']; else $b = null;
   if(isset($_REQUEST['altezza'])) $h = $_REQUEST['altezza']; else $h = null;
   
   // blocco di selezione dell'operazione da eseguire, se chiamo la pagina nulla è presente 
   // nella stringa di indirizzo, se invece la pagina viene richiamata dal form allora sono
   // presenti le variabili step, base, altezza.
   switch($step){
      default:{
         showFormMisure();
         break;
      }
      case "calcola_misure":{
         $perimetro = $b+$b+$h+$h;
         $area = $b*$h;

         echo("<pre>");
         for($i=1; $i<=$h; $i++){
            for($j=1; $j<=$b; $j++){
               echo("#");
            }
            echo("<br />");
         }
         echo("</pre>");
         echo("<br />");
         echo("Rettangolo di misure: ".$b."x".$h."<br />");
         echo("Perimetro: ".$perimetro."<br />");
         echo("Area: ".$area."<br />");
         echo("<br /><br />");
         echo("<a href=\"prova_3.php\">Torna al form</a>");
         break;
      }
   }
echo("</body>
   </html>");
?>