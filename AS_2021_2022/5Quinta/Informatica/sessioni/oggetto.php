<?php
class Obj{
   private $cnt;
   function __construct()
   {
      $this->cnt=1;
      echo("Eggetto creato...");
   }
   function getCnt(){
      echo($this->cnt);
      $this->cnt++;
   }
}
?>