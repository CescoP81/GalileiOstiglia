/*
    Realizzare le seguenti operazioni su di un vettore di 10 elementi interi:
    1- Dichiarare il vettore
    2- Inizializzarlo con valori random compresi tra 5 e 15
    3- Visualizza il vettore.
    4- Visualizza i valori primi presenti nel vettore
    5- Calcolare la somma di tutti i valori del vettore.
    6- Determinare il valore maggiore presente nel vettore.
    7- Ricercare e comunicare se un valore inserito da tastiera compare tra quelli presenti nel vettore.
    8- Determinare il valor medio tra i valori del vettore.
    9- Calcolare e stampare la somma dei valori pari e dei valori dispari.
    10- Determinare il valore minimo presente nel vettore

    ogni punto deve essere eseguito senza uno switch-case, quando si inizia il codice per un determinato punto
    inserire un commento //Punto xx, dove xx è il numero del punto che si risolve.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

int main(){
    // punto 1
    int vet[DIM];
    int i;
    int div, primo;
    int somma;
    int max;
    int src, trovato;
    float media;
    int sommaP, sommaD;
    int min;
    char junk;

    srand(time(NULL));

    // punto 2
    for(i=0; i<DIM; i++){
        vet[i] = 5 + rand()%11;
    }

    // punto 3
    printf("punto 3: ");
    for(i=0; i<DIM; i++){
        printf("%3d", vet[i]);
    }
    printf("\n---\n");

    // punto 4
    printf("punto 4: ");
    for(i=0; i<DIM; i++){
        primo = 1;
        div = 2;
        while(div < vet[i]){
            if(vet[i]%div == 0)
                primo = 0;
            div = div + 1;
        }
        if(primo == 1)
            printf("%3d", vet[i]);
    }
    printf("\n---\n");

    // punto 5
    printf("punto 5: ");
    somma = 0;
    for(i=0; i<DIM; i++){
        somma = somma + vet[i];
    }
    printf("Somma dei valori %d", somma);
    printf("\n---\n");

    //punto 6
    printf("punto 5: ");
    max = vet[0];
    for(i=1; i<DIM; i++){
        if(vet[i] > max)
            max = vet[i];
    }
    printf("Valore maggiore presente %d", max);
    printf("\n---\n");

    //punto 7
    printf("punto 7:\n");
    printf("Inserisci un valore intero compreso tra 5 e 15: ");
    scanf("%d", &src);
    junk = getchar();
    trovato = 0;
    for(i=0; i<DIM; i++){
        if(vet[i] == src)
            trovato = 1;
    }
    if(trovato == 1)
        printf("Il valore %d compare una o piu' volte.", src);
    printf("\n---\n");

    //punto 8
    printf("punto 8: ");
    somma = 0;
    for(i=0; i<DIM; i++){
        somma = somma + vet[i];
    }
    media = (float)somma/DIM;
    printf("Il valor media vale: %.2f", media);
    printf("\n---\n");

    //punto 9
    printf("punto 9: ");
    sommaP = 0;
    sommaD = 0;
    for(i=0; i<DIM; i++){
        if(vet[i]%2 == 0)
            sommaP = sommaP + vet[i];
        else
            sommaD = sommaD + vet[i];
    }
    printf("Totale pari= %d; Totale dispari= %d", sommaP, sommaD);
    printf("\n---\n");

    //punto 10
    printf("punto 10: ");
    min = vet[0];
    for(i=1; i<DIM; i++){
        if(vet[i] < min)
            min = vet[i];
    }
    printf("Valore minore presente %d", min);
    printf("\n---\n");
    return(0);
}