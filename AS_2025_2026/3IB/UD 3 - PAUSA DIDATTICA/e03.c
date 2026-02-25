/*
Realizzare un programma C che richiede un numero N da tastiera, se compreso tra 1 e 35, 
calcola quanti passaggi occorrono per superare il valore 100, seguendo questo schema:
Se N è un numero pari allora somma a se stesso la sua metà, se N è un numero dispari aggiunge 1.
*/
#include <stdio.h>

int main(){
    int n;  // numero iniziale da cui partire.
    int cnt; // numero passaggi effettuati.
    char junk;

    printf("Inserisci numero iniziale (1-35): ");
    scanf("%d", &n);
    junk = getchar();

    if(n>=1 && n<=35){
        cnt = 0;
        while(n <= 100){
            printf("%d ", n);
            if(n%2 == 0){
                n = n + (n/2);
            }
            else{
                n = n + 1;
            }
            cnt++;
        }
        printf("\nEsce con valore: %d in nr. passaggi: %d", n, cnt);
    }
    else{
        printf("Valore %d iniziale non valido!\n", n);
    }
    return(0);
}