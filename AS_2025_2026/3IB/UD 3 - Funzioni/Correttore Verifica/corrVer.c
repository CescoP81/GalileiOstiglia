#include <stdio.h>
#include "lib.c"

int main(){
    int scelta;         // variabile per la scelta effettuata dall'utente.
    int scelta2;        // variabile per la scelta del caso C (crecente/descrescente);
    int v1, v2, v3;     // variabili usate nei casi A, B, C.
    int result;         // variabile per i risultati nei casi A e B.
    char junk;          // pulizia del buffer di tastiera.
    int cntScelte;      // contatore delle scelte totali effettuate.
    
    cntScelte = 0;
    do{
        cntScelte++;
        printf("--- MENU ---\n");
        printf("1-> Input Number\n");
        printf("2-> Get Max Divider\n");
        printf("3-> Order Numbers\n");
        printf("0-> USCITA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:{
                printf("Inserisci parametro 1: ");
                scanf("%d", &v1);
                junk = getchar();

                printf("Inserisci parametro 2: ");
                scanf("%d", &v2);
                junk = getchar();

                result = inputNumber(v1, v2);
                printf("Numero accettato: %d\n", result);
                break;
            }
            case 2:{
                printf("Inserisci parametro 1: ");
                scanf("%d", &v1);
                junk = getchar();

                printf("Inserisci parametro 2: ");
                scanf("%d", &v2);
                junk = getchar();

                printf("Inserisci parametro 2: ");
                scanf("%d", &v3);
                junk = getchar();

                result = getMaxDivider(v1, v2, v3);
                printf("Divisore maggiore comune trovato: %d\n", result);
                break;
            }
            case 3:{
                printf("Inserisci parametro 1: ");
                scanf("%d", &v1);
                junk = getchar();

                printf("Inserisci parametro 2: ");
                scanf("%d", &v2);
                junk = getchar();

                printf("Inserisci parametro 2: ");
                scanf("%d", &v3);
                junk = getchar();
                do{
                    printf("Ordinamento 0->decrescente; 1->Crescente: ");
                    scanf("%d", &scelta2);
                    junk = getchar();
                }while(scelta2<0 || scelta2>1);
                orderValues(&v1, &v2, &v3, scelta2);
                printf("Valori ordinati: %d %d %d\n", v1, v2, v3);
                break;
            }
        }
    }while(scelta != 0);
    printf("Grazie, hai usato questo programma %d volta/e.", cntScelte);
    return(0);
}