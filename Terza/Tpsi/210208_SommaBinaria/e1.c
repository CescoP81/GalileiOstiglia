/*
    1001 +  -> 9    ==> bin1[]
    0011    -> 3    ==> bin2[]
    1100    -> 12   ==> bin3[]

    1000 +  -> 8
    1000    -> 8
  1 0000    -> 16 Non è rappresentabile. OVERFLOW [il numero non è rappresentabile con i bit a disposizione]
*/
#include <conio.h>
#include <stdio.h>

#define DIM 4

int main(){
    int n1, n2;     //variabili per i numeri in base 10
    int bin1[DIM], bin2[DIM], bin3[DIM+1];
    int i;

    // I° STEP: richiedo i due valori in base 10 da condificare e sommare.
    printf("Numero 1: ");
    scanf("%d", &n1);
    fflush(stdin);
    printf("Numero 2: ");
    scanf("%d", &n2);
    fflush(stdin);

    // II STEP: converto i due numeri decimali in forma binaria
    for(i=0; i<DIM; i++){   // conversione primo numero
        bin1[i] = n1%2;
        n1 = n1 / 2;
    }
    for(i=0; i<DIM; i++){   // conversione secondo numero
        bin2[i] = n2%2;
        n2 = n2 / 2;
    }

    // III STEP: visualizzo i vettori binari, al CONTRARIO
    printf("Bin 1: ");
    for(i=DIM-1; i>=0; i--)
        printf("%d", bin1[i]);
    printf("\n");
    printf("Bin 2: ");
    for(i=DIM-1; i>=0; i--)
        printf("%d", bin2[i]);
    printf("\n");

    // IV STEP: eseguo la somma binaria tra bin1 e bin2 con risultato in bin3
    for(i=0; i<DIM+1; i++)  // azzero il vettore bin3 per prepararlo alla somma.
        bin3[i] = 0;

    for(i=0; i<DIM; i++){
        bin3[i] = bin1[i] + bin2[i] + bin3[i];
        bin3[i+1] = bin3[i] / 2;
        bin3[i] = bin3[i] % 2;
    }

    printf("Bin 3: ");
    if(bin3[DIM] == 1)
        printf("OVERFLOW!");
    else{
        for(i=DIM-1; i>=0; i--)
            printf("%d", bin3[i]);
    }
}