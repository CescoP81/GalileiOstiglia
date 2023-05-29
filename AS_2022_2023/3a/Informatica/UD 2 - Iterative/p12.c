#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANGE 0
#define MAX_RANGE 9

int main(){
    int c1, c2, c3;     // variabili per le cifre random.
    int u1, u2, u3;     // variabili per le cifre utente.
    int cntIndovinate;  // contatore delle cifre azzeccate
    int cntTentativi;   // contatore dei tentativi effettuati.

    srand(time(NULL));
    c1 = MIN_RANGE + (rand()%(MAX_RANGE - MIN_RANGE +1));
    c2 = MIN_RANGE + (rand()%(MAX_RANGE - MIN_RANGE +1));
    c3 = MIN_RANGE + (rand()%(MAX_RANGE - MIN_RANGE +1));

    cntTentativi = 0;
    do{
        system("CLS");
        cntTentativi = cntTentativi + 1;
        cntIndovinate = 0;
        printf("Inserisci cifra: ");
        scanf("%d", &u1);
        fflush(stdin);
        printf("Inserisci cifra: ");
        scanf("%d", &u2);
        fflush(stdin);
        printf("Inserisci cifra: ");
        scanf("%d", &u3);
        fflush(stdin);

        printf("Codice: ");
        if(u1 == c1){
            printf("%d", u1);
            cntIndovinate = cntIndovinate + 1;
        }
        else
            printf("*");

        if(u2 == c2){
            printf("%d", u2);
            cntIndovinate = cntIndovinate + 1;
        }
        else
            printf("*");

        if(u3 == c3){
            printf("%d", u3);
            cntIndovinate = cntIndovinate + 1;
        }
        else
            printf("*");
        printf("\n\n");
        if(cntIndovinate == 3)
            printf("CODICE INDOVINATO!\n");
        else
            printf("CODICE ERRATO, RITENTA!\n");
        system("PAUSE");
    }while(cntIndovinate != 3);
    return(0);
}