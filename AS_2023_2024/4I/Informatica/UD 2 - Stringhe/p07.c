/**
 * Realizzare un programma C che richiede ripetutamente stringe(di max 10 char) all'utente e ogni stringa inserita la aggiunge ad una stringa totale di lunghezza 32 caratteri. Il programma termina quando l'utente riempie i 32 caratteri totali. Se li ha riempiti in modo perfetto (senza resto) comunica "Bravo", altrimenti comunica la stringa totale e le lettere eccedenti la misura di 32 caratteri.
*/
#include <stdio.h>
#include "lib.c"

const int DIM_ONE = 10;
const int DIM_TWO = 32;

int main(){
    char strInput[DIM_ONE + 1];
    char strOutput[DIM_TWO + 1];
    int index1; // utilizzo l'indice 1 sulla stringa immessa in input.
    int index2; // utilizzo l'indice 2 sulla stringa che vado comporre.

    initStringa(strInput, DIM_ONE+1);
    initStringa(strOutput, DIM_TWO+1);

    index2 = 0;
    do{
        printf("Output: %s (%d)\n------\n", strOutput, lunghezzaStringa(strOutput));
        inputStringa(strInput);

        if(lunghezzaStringa(strOutput) + lunghezzaStringa(strInput) <= DIM_TWO){
            index1 = 0;
            while(strInput[index1] != '\0'){
                strOutput[index2] = strInput[index1];
                index1++;
                index2++;
            }
        }
        else{
            index1 = 0;
            while(lunghezzaStringa(strOutput) < DIM_TWO){
                strOutput[index2] = strInput[index1];
                index1++;
                index2++;    
            }
        }
    }while(lunghezzaStringa(strOutput) < DIM_TWO);

    if(strInput[index1] == '\0'){
        printf("Perfetto, hai riempito esattamente %d caratteri con parole diverse.", DIM_TWO);
    }
    else{
        printf("Ahia, alcuni caratteri eccedono la lunghezza massima, eccoli qui:\n");
        while(strInput[index1] != '\0'){
            printf("%c", strInput[index1]);
            index1 = index1 + 1;
        }
    }

    return(0);
}