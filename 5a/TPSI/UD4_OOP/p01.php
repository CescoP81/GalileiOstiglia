<?php
    require("studente.php");

    $s = new Studente("Alberto", "Rossi", 34);
    $s1 = new Studente("Rosa", "Bianchi", 24);

    echo($s->getNome()." ".$s->getCognome()." ".$s->getEta()."<br />");
    echo($s1->getNome()." ".$s1->getCognome()." ".$s1->getEta());

    $s1->getNome()
?>