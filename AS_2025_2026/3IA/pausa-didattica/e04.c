#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n;          // numero input iniziale su cui si sviluppa il programma.
    char junk;      // variabile per pulire dopo la scanf.
    int cnt;        // ciclo degli N numeri random da generare
    int nRandom;    // numero random casuale generato.
    int div;        // variabile per un ciclo di divisori.
    int nRandom2;   // numeri random tra 1 e 10.
    int somma;      // somma dei numeri random generati tra 1 e 10.

    // inserimento del numero N iniziale
    printf("Inserisci un n: ");
    scanf("%d", &n);
    junk = getchar();

    // stabilisco in che range è situato N.
    if(n>=5 && n<=15){  // se N è compreso tra 5 e 15 estremi COMPRESI
        // devo generare N numeri random compresi tra 1 e 25
        cnt = 1;
        while(cnt <= n){
            nRandom = 1 + rand()%25;
            printf("%d-> ", nRandom);

            // capisco se il numero generato è pari oppure dispari
            if(nRandom%2 == 0){ // condizione del numero pari.
                // visualizzo i divisori del numero generato random pari
                div = 1;
                while(div <= nRandom){
                    if(nRandom%div == 0)
                        printf("%d ", div);
                    div = div + 1;
                }
            }
            else{   // cado nell'else se il numero random è un dispari.
                somma = 0;
                while(nRandom > 0){
                    nRandom2 = 1 + rand()%10;
                    printf("%d ", nRandom2);
                    somma = somma + nRandom2;
                    nRandom = nRandom - 1; // utilizzo il numero gernato random dispari come contatore finche è maggiore di 0
                }
                printf("; somma: %d.", somma);
            }
            printf("\n");
            cnt = cnt + 1;
        }
    }
    else{   // il numero è esterno al range indicato dal testo, quindi verificherò se è un numero primo oppure no.
        cnt = 0;
        div = 1;
        while(div <= n){
            if(n%div == 0)
                cnt = cnt + 1;
            div = div + 1;
        }
        if(cnt <= 2)
            printf("Il numero %d iniziale e' un NUMERO PRIMO.\n", n);
        else
            printf("Il numero %d iniziale non e' un NUMERO PRIMO.\n", n);
    }
    return(0);
}