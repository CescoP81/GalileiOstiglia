#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printMenu();

int main(){
    int scelta;

    do{
        scelta = printMenu();
        switch(scelta){
            case 1:{
                printf("Caso 1...\n");
                break;
            }
            case 2:{
                printf("Caso 1...\n");
                break;
            }
            case 3:{
                printf("Caso 1...\n");
                break;
            }
            default:{
                printf("Scelta non valida\n");
                break;
            }
        }
    }while(scelta);
    return(0);
}

int printMenu(){
    int sc;
    printf("1- ....\n");
    printf("2- ....\n");
    printf("3- ....\n");
    printf("0- USCITA\n");
    printf("Scelta: ");
    scanf("%d", &sc);
    fflush(stdin);
    return(sc);
}