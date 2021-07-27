#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char cognome[20];
    int anni;
} Persona;

int main(){
    int i,j,cnt=0;
    Persona* v1;
    Persona* v2;
    Persona* v3;

    v1 = (Persona*) malloc(5*sizeof(Persona));
    v2 = (Persona*) malloc(5*sizeof(Persona));
    v3 = (Persona*) malloc(10*sizeof(Persona));

    (*(v1+0)).anni = 10;
    strcpy((*(v1+0)).cognome, "Lillo");

    (*(v1+1)).anni = 11;
    strcpy((*(v1+1)).cognome, "Asan");

    (*(v1+2)).anni = 12;
    strcpy((*(v1+2)).cognome, "Marce");

    (*(v1+3)).anni = 13;
    strcpy((*(v1+3)).cognome, "Fabione");

    (*(v1+4)).anni = 14;
    strcpy((*(v1+4)).cognome, "Ganz");

    (*(v2+0)).anni = 10;
    strcpy((*(v2+0)).cognome, "Lillo");

    (*(v2+1)).anni = 36;
    strcpy((*(v2+1)).cognome, "CR7");

    (*(v2+2)).anni = 25;
    strcpy((*(v2+2)).cognome, "Paolino");

    (*(v2+3)).anni = 77;
    strcpy((*(v2+3)).cognome, "Kulugol");

    (*(v2+4)).anni = 3;
    strcpy((*(v2+4)).cognome, "Gorgione");

    printf("\n");

    for(i = 0; i<5; i++){
        *(v3+i) = *(v1+i);
        cnt++;
    
        for(j = 0; j<5; j++){
            if(((*(v1+j)).anni) != ((*(v2+i)).anni) || strcmp(((*(v1+j)).cognome), ((*(v2+i)).cognome)) != 0){
                printf("%d - %d entra\n", i, j);
                *(v3+i+5) = *(v2+i);
                cnt++;
                break;
            }
        }
    }

    for(i = 0; i<cnt; i++){
        printf("Persona %d: %s %d\n", i, (*(v3+i)).cognome, (*(v3+i)).anni);
    }
    
}
