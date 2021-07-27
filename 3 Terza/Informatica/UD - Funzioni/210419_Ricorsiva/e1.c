#include <conio.h>
#include <stdio.h>

#define DIM 10

void stampaNumeri(int _limite);
void stampaNumeriR(int _n, int _limite);

void stampaInvertiti(int _limite);
void stampaInvertitiR(int _limite);
void stampaInvertitiR2(int n, int _limite);

int main(){
    int i;

    // visualizzare i numeri da 1 a DIM
    for(i=1; i<=DIM; i++)
        printf("%3d", i);
    
    printf("\n\n");
    // visualizzo la serie di prima richiamando una funzione.
    stampaNumeri(DIM);

    printf("\n\n");
    stampaNumeriR(1, DIM);

    printf("\n\n");
    for(i=DIM; i>=1; i--)
        printf("%3d", i);
    printf("\n\n");
    stampaInvertiti(DIM);
    printf("\n\n");
    stampaInvertitiR(DIM);
    printf("\n\n");
    stampaInvertitiR2(1, DIM);
    return(0);
}

void stampaNumeri(int _limite){
    int i;
    for(i=1; i<=_limite; i++)
        printf("%3d", i);
}

void stampaNumeriR(int _n, int _limite){
    if(_n <= _limite){
        printf("%3d", _n);
        stampaNumeriR(_n+1, _limite);
    }
}

void stampaInvertiti(int _limite){
    int i;
    for(i=_limite; i>=1; i--)
        printf("%3d", i);
}

void stampaInvertitiR(int _limite){
    if(_limite >= 1){
        printf("%3d", _limite);
        stampaInvertitiR(_limite-1);
    }
}

void stampaInvertitiR2(int _n, int _limite){
    if(_n <= _limite){
        stampaInvertitiR2(_n+1, _limite);
        printf("%3d", _n);
    }
}