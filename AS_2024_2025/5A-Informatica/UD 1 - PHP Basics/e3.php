<?php
/*  Realizza uno script che riceve tramite richiesta HTTP due valori numerici
    nelle chiavi 'valA' e 'valB'. Utilizzare i valori ricevuti per calcolare e comunicare
    area e perimetro di un ipotetico rettangolo.

    http://..../e3.php?valA=5&valB=9;
*/

if(isset($_REQUEST['valA'])) $va = $_REQUEST['valA'];
else $va = 0;

if(isset($_REQUEST['valB'])) $vb = $_REQUEST['valB'];
else $vb = 0;

if($va>0 && $vb>0){
    // ho due misure valide quindi posso eseguire i calcoli.
    echo('Il rettangolo ha misure: '.$va.'x'.$vb.'<br />');

    $area = $va * $vb;
    $perimetro = ($va + $vb) * 2;

    echo('Area: '.$area.'; perimetro: '.$perimetro.'<br />');
}
else{
    echo('Uno o entrambi i valori sono a zero.<br />');
}
?>