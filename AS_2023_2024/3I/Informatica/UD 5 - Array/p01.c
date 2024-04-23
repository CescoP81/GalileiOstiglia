/* Programma di dichiarazione e inizializzazione di un vettore monodimensionale
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// dichiaro una costante intera per la dimensione del vettore
const int DIM = 10;
// SEZIONE DEI PROTOTIPI
void initVettore(int _v[], int _dim);
void vediVettore(int _v[], int _dim);
void generaVettore(int _v[], int _dim);
void vediVettoreGrafico(int _v[], int _dim);
// SEZIONE DEL MAIN
int main(){
    int vet[DIM];

    initVettore(vet, DIM);
    vediVettore(vet, DIM);
    printf("\n");
    generaVettore(vet, DIM);
    vediVettore(vet, DIM);
    printf("\n");
    vediVettoreGrafico(vet, DIM);
    return(0);
}
// SEZIONE FUNZIONI
void initVettore(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        _v[i] = 0;
    }
}
void vediVettore(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%3d", _v[i]);
    }
}
void generaVettore(int _v[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _v[i] = 1 + rand()%20;  // riempio il vettore con valori random compresi tra 1 e 20 (estremi compresi).
    }
}
void vediVettoreGrafico(int _v[], int _dim){
    int i;
    //printf("%c %c %c %c %c\n", 191, 192, 196, 217, 218);
    
    printf("%c", 218);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i!=_dim-1)
            printf("%c", 194);
    }
    printf("%c", 191);
    
    printf("\n");

    printf("%c", 179);
    for(i=0; i<_dim; i++){
        printf("%3d", _v[i]);
        printf("%c", 179);
    }

    printf("\n");

    printf("%c", 192);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i!=_dim-1)
            printf("%c", 193);
    }
    printf("%c", 217);
    printf("\n");
    
    for(i=0; i<_dim; i++)
        printf("%4d", i);
    
    printf("\n");

}