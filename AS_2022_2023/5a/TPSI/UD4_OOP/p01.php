<?php
/**
 * @package GalileiOstiglia\5a\TPSI\UD4_OOP
 */
    require("studente.php");

    /** 
     * Funzione di prova esterna alla main function.
     * @param int $cnt number of prints.
     * @param string $s Optional. Nome da stampare, defaults to 'Pino'
     * @return void
     */
    function foo($cnt, $s = "Pino"){
        for(; $cnt>0; $cnt--)
            echo($s." - ");
    }

    /**
     * Main function of the file.
     * @return void
     */
    function main(){
        $s = new Studente("Alberto", "Rossi", 34);
        $s1 = new Studente("Rosa", "Bianchi", 24);

        echo($s->getNome()." ".$s->getCognome()." ".$s->getEta()."<br />");
        echo($s1->getNome()." ".$s1->getCognome()." ".$s1->getEta());

        $s1->getNome();
        echo("<br /><br />");
        foo(1);
        foo(3, "Angela");
    }

    main();
?>