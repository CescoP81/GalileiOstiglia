<?php
header("Content-Type: image/png");
require('graph.php');

   $g = new GDGraph(600,200);
   $g->output();
?>