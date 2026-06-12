/*
    Creare un programma C che richiesto un numero intero N da tastiera, visualizza tutti
    i numeri da 1 a N e per ogni numero visualizza i suoi divisori.
*/
#include <stdio.h>

int main(){
    int n;
    int numero;
    int divisore;
    char junk;

    printf("Inserisci un numero: ");        // fase di input iniziale.
    scanf("%d", &n);
    junk = getchar();

    numero = 1;
    wile(numero <= n){                      // ciclica per i numeri da 1 a N usando la variabile 'numero'.
        printf("Numero %d: ", numero);
        divisore = 1;
        while(divisore <= numero){          // ciclica per i divisori che vanno da 1 a 'numero'
            if(numero%divisore == 0){
                printf("%d ", divisore);
            }
            divisore = divisore + 1;
        }
        printf("\n");
        numero = numero + 1;
    }

    return(0);
}