/*  Data: 15/10/22
    Author: Francesco Pradella
    Filename: p03.c
    Abstracty: Realizzare un algoritmo che determina se due numeri inseriti in input sono amici/amicali.
    Due numeri si dicono amici se la somma dei divisori di A è uguale a B e allo stesso tempo
    la somma dei divisori di B è uguale ad A.
*/
#include <stdio.h>

int main(){
    int numA;
    int numB;
    int div;
    int sommaA;
    int sommaB;

    // fase di input dei due valori
    printf("Insersici A: ");
    scanf("%d", &numA);
    fflush(stdin);
    printf("Inserisci B: ");
    scanf("%d", &numB);
    fflush(stdin);

    // calcolo della somma divisori di A
    sommaA = 0;
    div = 1;
    while(div < numA){
        if(numA % div == 0){
            sommaA = sommaA + div;
        }
        div = div + 1;
    }

    // calcolo della somma divisori di B
    sommaB = 0;
    div = 1;
    while(div < numB){
        if(numB % div == 0){
            sommaB = sommaB + div;
        }
        div = div + 1;
    }

    //printf("SommaA %d - SommaB %d", sommaA, sommaB);

    // test finale della regola numeri amicali/amicabili/amici
    if((sommaA == numB) && (sommaB == numA)){
        printf("I due numeri sono AMICALI.");
    }
    else{
        printf("I due numeri NON SONO AMICALI.");
    }
    return(0);
}