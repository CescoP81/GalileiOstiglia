/*
    Realizzare un programma che preveda 2 valor interi:
    valore1 = 13; valore2=10
    e due vettori di 8 celle intere
    b1[8]; b2[8]

    Realizzare l'agoritmo che calcola la somma dei due binari in un terzo vettore
    b[3]

    Visualizzare il vettore risultato "b3".
*/
#include <stdio.h>
#include <math.h>

#define DIM 8

void initBinario(int[], int);
void convertIntegerToBinary(int[], int, int);
void showBinaryNumber(int[], int);
int sumBinaryNumbers(int[], int[], int[], int);


int main(){
    // creo vettori e variabili necessarie al programma.
    int b1[DIM];
    int b2[DIM];
    int b3[DIM];
    int n1, n2;

    // azzero i vettori.
    initBinario(b1, DIM);
    initBinario(b2, DIM);

    // richiedo il primo numero da convertire.
    printf("Inserisci N1: ");
    scanf("%d", &n1);
    fflush(stdin);
    convertIntegerToBinary(b1, DIM, n1);

    // richiedo il secondo numero da convertire.
    printf("Inserisci N2: ");
    scanf("%d", &n2);
    fflush(stdin);
    convertIntegerToBinary(b2, DIM, n2);

    // mostro i due numeri convertiti.
    showBinaryNumber(b1, DIM);
    printf("\n");
    showBinaryNumber(b2, DIM);

    printf("\n");
    printf("\n");
    // eseguo la somma di b1 e b2 in b3, mi baso sul valore di ritorno della funzione per capire se ho un risultato
    // rappresentabile con il numero di bit a disposizione oppure no.
    if(sumBinaryNumbers(b1, b2, b3, DIM) == 0){
        printf("Risultato rappresentabile: ");
        showBinaryNumber(b3, DIM);
    }
    else{
        printf("Attenzione la somma ha generato OVERFLOW, risultato non rappresentabile.");
    }
    return(0);
}

void initBinario(int _b[], int _dim){
    int i;
    for(i=0; i<_dim; i++)
        _b[i] = 0;
}

void convertIntegerToBinary(int _b[], int _dim, int _num){
    int i;
    for(i=0; i<_dim; i++){
        _b[i] = _num%2;
        _num = _num / 2;
    }
}

void showBinaryNumber(int _b[], int _dim){
    int i;
    for(i=0; i<_dim; i++)
        printf("%d", _b[_dim-i-1]);
}

int sumBinaryNumbers(int _b1[], int _b2[], int _b3[], int _dim){
    int i;
    int of; // flag di overlow -> se la somma genera un riporto sulla cifra più significativa.

    of = 0;
    for(i=0; i<_dim; i++){
        _b3[i] = _b1[i] + _b2[i] + of;
        of = _b3[i] / 2;
        _b3[i] = _b3[i] % 2;
    }
    return(of);
}