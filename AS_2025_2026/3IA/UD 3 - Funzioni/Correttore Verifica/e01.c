#include <stdio.h>
#include "lib.c"
int main(){
    int scelta;
    int cntScelte;
    char junk;
    int val;
    int num, n;
    int a, b, c;

    cntScelte = 0;
    do{
        cntScelte++;
        printf("-- Menu --\n");
        printf("1-> Punto 1\n");
        printf("2-> Punto 2\n");
        printf("3-> Punto 3\n");
        printf("4-> Punto 4\n");
        printf("5-> USCITA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                val = inputNumeroFiltrato(4,50,3);
                printf("Numero valido inserito: %d", val);
                break;
            }
            case 2:{
                num = 6;
                n = 3;
                val = trovamiPrimo(num, n);
                printf("Il %d numero primo successivo a %d e': %d", n, num, val);
                break;
            }
            case 3:{
                printf("Inserisci A: ");
                scanf("%d", &a);
                junk = getchar();

                printf("Inserisci B: ");
                scanf("%d", &b);
                junk = getchar();

                printf("Inserisci C: ");
                scanf("%d", &c);
                junk = getchar();

                ordinaTreValori(&a, &b, &c);
                printf("I tre valori ordinati sono A:%d, B:%d, C:%d", a, b, c);
                break;
            }
            case 4:{
                printf("Inserisci lato A: ");
                scanf("%d", &a);
                junk = getchar();

                printf("Inserisci lato B: ");
                scanf("%d", &b);
                junk = getchar();
                val = determinaFigura(a, b);
                if(val == -1)
                    printf("Misure figura non valide.");
                else
                    printf("Valore calcolato: %d", val);
                break;
            }
            case 5:{
                printf("Hai usato il programma %d volta/e, grazie e arrivederci!", cntScelte);
                break;
            }
            default:{
                printf("Scelta non valida!\n");
            }
        }
        printf("\n------\n");
    }while(scelta != 5);
    return(0);
}