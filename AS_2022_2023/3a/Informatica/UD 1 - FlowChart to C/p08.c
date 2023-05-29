/*  Data: 24/10/22
    Author: Francesco Pradella
    Filename: p08.c
    Abstracty: Esercizio nr. 10 pag. 153
*/
#include <stdio.h>

int main(){
    int numero;
    int potenza;
    int cnt;
    int risultato;

    printf("Inserisci numero: ");
    scanf("%d", &numero);
    fflush(stdin);

    potenza = 1;
    while(potenza <= 5){
        printf("%d ^%d: ", numero, potenza);

        risultato = numero;
        cnt = 1;
        while(cnt < potenza){
            risultato = risultato * numero;
            cnt = cnt + 1;
        }
        printf("%d", risultato);
        printf("\n");
        potenza = potenza + 1;
    }
    return(0);
}