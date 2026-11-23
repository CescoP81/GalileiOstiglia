/*  
    Creare un programma che richiede in input due lati di una figura; 
    se i lati sono uguali calcolare il perimetro della figura; se i lati sono diversi
    calcolare l'area della figura. Ovviamente comunicare il valore calcolato.
    (ipotizzando quadrato o rettangolo)

    Sintassi per confronti
    --------------------------------
    op1 == op2  => uguaglianza
    op1 != op2  => non uguali
    op1 < op2   => minore
    op1 <= op2  => minore o uguale
    op1 > op2   => maggiore
    op1 >= op2  => maggiore o uguale

    Invetire uguale e altro segno è errato '<=' corretto; '=<' non corretto
    Attenzione che op1 = op2 significa assegnare a op1 il valore di op2, anche se messo in una IF.
*/
#include <stdio.h>

int main(){
    int l1, l2;             // valori iniziali richiesti in input
    int area, perimetro;    // valori calcolati secondo il tipo di figura individuato
    char junk;              // variabile di comodo per pulire il buffer di tastiera/input

    // acquisizione dei valori
    printf("Inserisci il Lato 1:");
    scanf("%d", &l1);
    junk = getchar();

    printf("Inserisci il Lato 2: ");
    scanf("%d", &l2);
    junk = getchar();

    // determino il tipo di figura in base ai valori di l1 e l2
    if(l1 == l2){
        // sono in presenza di due valori uguali quindi calcolo il perimetro
        perimetro = l1 * 4;
        printf("Perimetro del QUADRATO: %d\n", perimetro);
    }
    else{
        area = l1 * l2;
        printf("Area del RETTANGOLO: %d\n", area);
    }

    /* al posto della else posso fare una seconda IF ed il risultato non cambia.
    if(l1 != l2){
        area = l1 * l2;
        printf("Area del RETTANGOLO: %d\n", area);
    }
    */

    return 0;    
}