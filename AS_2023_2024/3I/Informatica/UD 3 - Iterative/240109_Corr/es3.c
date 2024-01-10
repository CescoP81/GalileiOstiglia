/*
Realizza un programma C che richiede in input un anno maggiore o uguale di 1900, il programma calcola e
comunica il terzo anno bisestile successivo all’anno inserito.
*/
#include <stdio.h>

int main(){
    int annoIniziale;
    int bisestile;
    int nuovoAnno;

    do{
        printf("Inserisci un anno successivo al 1900: ");
        scanf("%d", &annoIniziale);
        fflush(stdin);
    }while(annoIniziale < 1900);

    nuovoAnno = annoIniziale;
    bisestile = 0;
    do{
        nuovoAnno = nuovoAnno + 1;
        if(nuovoAnno%100 == 0){
            if(nuovoAnno%400 == 0){
                bisestile = bisestile + 1;
            }
        }
        else{
            if(nuovoAnno%4 == 0){
                bisestile = bisestile + 1;
            }
        }
    }while(bisestile < 3);

    printf("I terzo anno bisestile dopo il %d e': %d.", annoIniziale, nuovoAnno);
    return(0);
}