<?php
class GDGraph{
   private $image;
   private $white;
   private $black;

   function __construct($x=300, $y=300){
      $this->image = imageCreate($x,$y);
      $this->white = imageColorAllocate($this->image, 255,255,255);
      $this->black = imageColorAllocate($this->image, 0,0,0);
   }

   public function output(){
      //echo($this->image);
      return(imagePNG($this->image));  
   }
}
?>