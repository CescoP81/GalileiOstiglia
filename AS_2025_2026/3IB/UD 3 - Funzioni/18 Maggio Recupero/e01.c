#include <stdio.h>
#include "lib.c"

int main(){
    int n1, n2;
    int result;
    int scelta;
    char junk;

    do{
        printf("--- MENU ---\n");
        printf("1-> Punto a\n");
        printf("2-> Punto b\n");
        printf("3-> Punto c\n");
        printf("4-> Punto d\n");
        printf("0-> TERMINA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                printf("Inserisci valore minimo: ");
                scanf("%d", &n1);
                junk = getchar();

                printf("Inserisci valore massimo: ");
                scanf("%d", &n2);
                junk = getchar();

                result = inputNumberRange(n1, n2);
                printf("Valore inserito: %d\n", result);
                break;
            }
            case 2:{
                printf("Inserisci primo valore: ");
                scanf("%d", &n1);
                junk = getchar();

                printf("Inserisci secondo valore: ");
                scanf("%d", &n2);
                junk = getchar();

                result = moltiplicaConSomme(n1, n2);
                printf("Prodotto dei due valori: %d\n", result);
                break;
            }
            case 3:{
                printf("Inserisci primo valore: ");
                scanf("%d", &n1);
                junk = getchar();

                result = numeroDivisori(n1);
                printf("Divisori trovati in totale: %d\n", result);
                break;
            }
            case 4:{
                do{
                    printf("Inserisci valore: ");
                    scanf("%d", &n1);
                    junk = getchar();
                }while(n1<=0 || n1>100);

                result = totaleNumero(n1);
                printf("Somma dell cifre: %d\n", result);
                break;
            }
        }
        printf("\n------\n\n");
    }while(scelta != 0);
    return(0);
}