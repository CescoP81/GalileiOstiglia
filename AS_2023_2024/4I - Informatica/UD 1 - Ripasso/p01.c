/*
    Author: Pradella Francesco
    Date: 14.09.23
    Abstract: Esercitazione di ripasso argomenti anno precedente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define DIM 10;
const int DIM=10;

int main(){
    int nRandom;
    int cnt;
    int vet[DIM];

    srand(time(NULL));


    nRandom = rand()%100;   // Generates a random number between 0 and 99.
    if(nRandom >= 50){
        printf("Il numero %d e' maggiore o uguale a cinquanta.\n", nRandom);
    }
    else{
        printf("Il numero %d e' inferiore a cinquanta.\n", nRandom);
    }
    printf("\n");

    cnt = 1;
    while(cnt <= 10){ // Generates ten random number between 10 and 30.
        nRandom = 10 + rand()%(30-10+1);
        printf("%d - ", nRandom);
        cnt++;
    }
    printf("\n\n");

    for(cnt=1; cnt<=10; cnt++){ // Same as previous example but with for structure.
        nRandom = 10 + rand()%(30-10+1);
        printf("%d - ", nRandom);
    }
    printf("\n\n");


    return(0);
}