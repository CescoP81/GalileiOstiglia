#include <conio.h>
#include <stdio.h>
#define DIM 5

void stampa_vet(int []);

int main(){
    int v[] = {3,7,5,12,9};
    int i;
    stampa_vet(v);
    return(0);
}

void stampa_vet(int _v[]){
    int i;
    for(i=DIM; i>=0; i--)
        printf("%d ", _v[i]+i);
}