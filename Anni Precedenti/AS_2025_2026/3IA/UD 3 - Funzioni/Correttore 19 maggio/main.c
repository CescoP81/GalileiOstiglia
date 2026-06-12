#include <stdio.h>
#include "lib.c"

int main(){
    int num;
    int a, b;
    int scelta;
    int risultato;
    char junk;

    do{
        printf("--- menu ---\n");
        printf("1-> Trova amico\n");
        printf("2-> Inserisci primo\n");
        printf("3-> Numero divisori\n");
        printf("4-> Tabellina amica\n");
        printf("0-> TERMINA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                do{
                    printf("Inserisci un numero tra 1 e 750: ");
                    scanf("%d", &num);
                    junk = getchar();
                }while(num<1 || num>750);
                risultato = trovaUnAmico(num);
                printf("Numero amico trovato: %d", risultato);
                break;
            }
            case 2:{
                printf("Inserisci a: ");
                scanf("%d", &a);
                junk = getchar();
                printf("Inserisci b: ");
                scanf("%d", &b);
                junk = getchar();

                risultato = inputPrime(a, b);
                printf("Numero primo tra %d e %d: %d", a, b, risultato);
                break;
            }
            case 3:{
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();
                risultato = numeroDivisori(num);
                printf("Il numero %d ha un totale di %d divisori.", num, risultato);
                break;
            }
            case 4:{
                do{
                    printf("Inserisci la tabellina desiderata tra 2 e 10: ");
                    scanf("%d", &num);
                    junk = getchar();
                }while(num<2 || num>10);
                printf("\n");
                tabellinaMascherata(num);
                break;
            }
        }
        printf("\n ----- \n");
    }while(scelta != 0);
    return(0);
}