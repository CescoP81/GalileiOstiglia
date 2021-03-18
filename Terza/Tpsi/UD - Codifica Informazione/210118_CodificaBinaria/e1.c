/*
    Algoritmo che condifica un numero decimale compreso tra 0 e 255  in formato binario.
*/
#include <conio.h>
#include <stdio.h>

#define DIM 32       // numero di bit della codifica binaria.
#define DIM_OTT 16
#define DIM_HEX 8

int main(){
    int num;        // variabile contenente il valore decimale intero.
    int bin[DIM];   // vettore per la codifica binaria di num.
    int i;
    int valore;

    // Step 1: richiedere il numero decimale intero da convertire.
    printf("Numero: ");
    scanf("%d", &num);
    fflush(stdin);

    // Step 2: converto il numero decimale in cifre binaria, con divisioni successive.
    /*for(i=0; i<DIM; i++){
        bin[i] = num%2;
        num = num / 2;
    } // */

    // togliere il commento a questo ciclo per vedere tutti i singoli valori interessati dalla scomposizione.
    printf("\n");
    valore = num;
    for(i=0; i<DIM; i++){
        printf("Num: %d -> R[%d]: %d -> (num/2):%d\n",valore, i, (valore%2), (valore/2));
        bin[i] = valore%2;
        valore = valore / 2;
    } // */


    // Step 3: Visualizzo il vettore binario, attenzione IN ORDINE INVERSO!
    printf("\nBinario: ");
    for(i=DIM-1; i>=0; i--){
        printf("%d", bin[i]);
        if(i%4 == 0) printf(" ");
    }


    // STEP 4: conversione OTTALE e la ESADECIMALE
    /* OTTALE (8) = resti 0 -> 7 int vet[]
       ESADECIMALE (16) = resti 0 -> 15 int vet[] però i simboli usati nella HEX 0-9 + A-F
    */
   int oct[DIM_OTT];
   valore = num;
   for(i=0; i<DIM_OTT; i++){
       oct[i] = valore%8;
       valore = valore / 8;
   }
   printf("\n\nOttale: ");
   for(i=DIM_OTT-1; i>=0; i--)
        printf("%d", oct[i]);

    int hex[DIM_HEX];
    valore = num;
    printf("\n\nEsadecimale: ");
    for(i=0; i<DIM_HEX; i++){
        hex[i] = valore % 16;
        valore = valore / 16;
    }
    for(i=DIM_HEX-1; i>=0; i--){
        if(hex[i] <= 9)
            printf("%d", hex[i]);
        else
            printf("%c", 'A'+(hex[i]-10) );
    }

    return(0);
}