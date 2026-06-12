/*
    Realizza un programma che richiede in input un valore N intero compreso tra 1 e 10.
    Calcolare quanti passaggi occorrono per superare il velore 1000 sapendo che,
    se il numero N è pari allora ad N sommo la sua metà, se N è dispari allora a N aggiungo 1.

    data: 2026.02.24
*/
#include <stdio.h>

int main(){
    int n;      // valore iniziale
    char junk;
    int cnt;    // contatore dei passaggi.

    do{
        printf("Inserisci un valore (1-10): ");
        scanf("%d", &n);
        junk = getchar();
    }while(n<1 || n>10);

    cnt = 0;
    while(n <= 1000){
        cnt = cnt + 1;
        printf("%d ", n);
        if(n%2 == 0)
            n = n + (n/2);
        else 
            n = n + 1;
    }

    printf("\nPassaggi richiesti: %d\n", cnt);
    return(0);
}