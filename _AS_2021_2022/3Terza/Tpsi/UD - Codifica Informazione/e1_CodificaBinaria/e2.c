/*
Realizzare un programma C che richiede un numero decimale intero (es 145) minore o uguale a 9999
e lo converte nelle seguenti basi: 2 8 16 e una a scelta dell'utente compresa tra 11 e 20.
*/
#include <conio.h>
#include <stdio.h>

#define BIT 12

int main(){
    int numero;
    int i;
    int tmp;
    int baseScelta;

    // richiedo il numero
    do{
        printf("Numero: ");
        scanf("%d", &numero);
        fflush(stdin);
    }while(numero>9999);

    // scomposizione in binario
    printf("\nBase 2: ");
    tmp = numero;
    for(i=0; i<BIT; i++){
        printf("%d ", tmp%2);
        tmp = tmp/2;
    }

    // scomposizione in binario
    printf("\nBase 8: ");
    tmp = numero;
    for(i=0; i<BIT; i++){
        printf("%d ", tmp%8);
        tmp = tmp/8;
    }

    // scomposizione in binario
    printf("\nBase 16: ");
    tmp = numero;
    for(i=0; i<BIT; i++){
        printf("%d ", tmp%16);
        tmp = tmp/16;
    }

    // richiedo la base(tra 11 e 20) all'utente per la scomposizione
    // se il valore inserito è inferiore a 11 OR superiore a 20, resto nel ciclo e richiedo un'altro valore.
    do{
        printf("\n\nBase: ");
        scanf("%d", &baseScelta);
        fflush(stdin);
    }while(baseScelta<11 || baseScelta>20);

    printf("\nBase %d: ", baseScelta);
    tmp = numero;
    for(i=0; i<BIT; i++){
        printf("%d ", tmp%baseScelta);
        tmp = tmp / baseScelta;
    }
    return(0);
}