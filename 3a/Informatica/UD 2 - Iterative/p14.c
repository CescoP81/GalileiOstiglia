#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int N;  // Numero di valori da generare che rispettano la condizione
    int d1; // primo divisore.
    int d2; // secondo divisore.
    int r;  // numero generato random.
    int cnt; // variabile contatore dei numeri generati corretti.

    // step 1. input dei valori necessari
    do{
        printf("Inserisci N: ");
        scanf("%d", &N);
        fflush(stdin);
    }
    while(N<=0);

    // step 2: richiedo i due divisori 
    do{
        printf("Inserisci il primo divisore: ");
        scanf("%d", &d1);
        fflush(stdin);
    }while(d1<1 || d1>99);
    do{
        printf("Inserisci il secondo divisore: ");
        scanf("%d", &d2);
        fflush(stdin);
    }while(d2<1 || d2>99);

    // step 3: Genero numeri casuali, solo quando rispettano la condizione
    // aumento il contatore, il ciclo "gira" finche contatore non arriva a N
    srand(time(NULL));
    cnt = 1;
    while(cnt <= N){
        r = (rand()%99) + 1;            // genero un numero casuale
        if(r%d1==0 && r%d2==0){
            printf("%d ", r);
            cnt = cnt + 1;
        }
    }
    return(0);
}