<?php
// controllo variabili passate tramire URL (indirizzo web)
if(isset($_REQUEST['scelta'])) $scelta = $_REQUEST['scelta'];
else $scelta = "caso_base";

// inizio parte del codice della pagina
include("header.html");
	echo("<div class=\"container\">");
	//echo("scelta: ".$scelta);
	switch($scelta){
		case "caso_base":{
			echo("<form action=\"script.php\" method=\"get\">");
				echo("<div class=\"form-group\">
					<label for=\"inputBase\">Base</label>
						<input class=\"form-control form-control-sm\" type=\"text\" id=\"inputBase\" name=\"base_rettangolo\">
					<label for=\"inputAltezza\">Altezza</label>
						<input class=\"form-control form-control-sm\" type=\"text\" id=\"inputAltezza\" name=\"altezza_rettangolo\">
				</div>
				<input type=\"hidden\" name=\"scelta\" value=\"esegui_calcoli\" />
				<button type=\"submit\" class=\"btn btn-success\">Perimetro&Area Rettangolo</button>
			</form>");
			break;
		}
		case "esegui_calcoli":{
			$br = $_REQUEST['base_rettangolo'];
			$ar = $_REQUEST['altezza_rettangolo'];
			
			$perimetro = ($br+$ar) * 2;
			$area = $br * $ar;
			
			echo("Rettangolo: ".$br."x".$ar."<br />");
			echo("Perimetro: ".$perimetro."<br />");
			echo("Area: ".$area."<br />");
			echo("<a href=\"script.php\">Back to form</a>");
			
			break;
		}
		default:{
			echo("Scelta non valida");
			break;
		}
	}
	echo("</div>");
include("footer.html");
?>