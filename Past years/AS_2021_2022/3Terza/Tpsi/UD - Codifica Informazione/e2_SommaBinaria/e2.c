/*  Programma di simulazione somma OTTALE -> derivato dall somma binaria.
*/
#include <conio.h>
#include <stdio.h>

#define DIM 4

int main(){
    int n1, n2;
    int ott1[DIM], ott2[DIM], ott3[DIM+1];
    int i;

    // I° STEP: richiedo i due valori in base 10 da condificare e sommare.
    printf("Numero 1: ");
    scanf("%d", &n1);
    fflush(stdin);
    printf("Numero 2: ");
    scanf("%d", &n2);
    fflush(stdin);

    // II STEP: converto i due numeri decimali in forma ottale (resti possibili da 0 a 7)
    for(i=0; i<DIM; i++){   // conversione primo numero
        ott1[i] = n1%8;
        n1 = n1 / 8;
    }
    for(i=0; i<DIM; i++){   // conversione secondo numero
        ott2[i] = n2%8;
        n2 = n2 / 8;
    }

    // III STEP: visualizzo i vettori ottali, al CONTRARIO
    printf("OCT 1: ");
    for(i=DIM-1; i>=0; i--)
        printf("%d", ott1[i]);
    printf("\n");
    printf("OCT 2: ");
    for(i=DIM-1; i>=0; i--)
        printf("%d", ott2[i]);
    printf("\n");

    // IV STEP: eseguo la somma ottale tra ott1 e ott2 con risultato in ott3
    for(i=0; i<DIM+1; i++)  // azzero il vettore bin3 per prepararlo alla somma.
        ott3[i] = 0;

    for(i=0; i<DIM; i++){
        ott3[i] = ott1[i] + ott2[i] + ott3[i];
        ott3[i+1] = ott3[i] / 8;
        ott3[i] = ott3[i] % 8;
    }

    // V STEP: Visulizzo il vettore ottale ottenuto
    printf("Bin 3: ");
    if(ott3[DIM] != 0)
        printf("OVERFLOW!");
    else{
        for(i=DIM-1; i>=0; i--)
            printf("%d", ott3[i]);
    }
}