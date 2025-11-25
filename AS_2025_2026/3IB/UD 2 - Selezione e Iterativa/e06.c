/*
Richiedo un valore intero positivo minore o uguale di 50,
quindi visualizzo tutti i suoi divisori.
*/
#include <stdio.h>

int main(){
    int val;
    int divisore;
    char junk;

    printf("Inserisci un valore(<= 50): ");
    scanf("%d", &val);
    junk = getchar();

    if(val <= 50){
        printf("Divisori trovati: ");
        divisore = 1;
        while(divisore <= val){
            if(val%divisore == 0){
                printf("%d ", divisore);
            }
            divisore = divisore + 1;
        }
    }
    else{
        printf("Numero iniziale troppo grande.\n");
    }


    return(0);
}