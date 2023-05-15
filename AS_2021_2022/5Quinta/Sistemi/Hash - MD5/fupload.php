<?php
echo("<!doctype html>");
echo("<html><head><title>File Uploads</title></head><body>");

if(isset($_REQUEST['scelta'])) $sc = $_REQUEST['scelta']; else $sc = null;

switch($sc){
   case "up":{
      echo($_FILES['ufile']['name']." -> ".$_FILES['ufile']['tmp_name']."<br />");
      if(move_uploaded_file($_FILES['ufile']['tmp_name'], $_FILES['ufile']['name']))
         echo("Caricato...");
      else
         echo("Troubles");
      break;
   }
   default:{
      echo("<form enctype=\"multipart/form-data\" action=\"fupload.php\" method=\"POST\"> 
         File: <input type=\"file\" name=\"ufile\"><br />
         <input type=\"hidden\" name=\"scelta\" value=\"up\">
         <input type=\"submit\" value=\"Up\">
         </form>
      ");
      break;
   }
}


echo("</body></html>");
?>