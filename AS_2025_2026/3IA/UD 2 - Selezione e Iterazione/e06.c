/*
Realizzare un programma "Guess the Code" che operi nel seguente modo:  
All'avvio il programma inizializza cinque variabili chiamate c1 c2 c3 c4 c5 con cinque valori interi positivi 
compresi tra 0 e 9(per la fase di sviluppo inserirli a mano da codice sorgente), successivamente propone all'untente 
l'inserimento di cinque valori in altrettante variabili chiamate u1 u2 u3 u4 u5. Il programma verifica 
se le cifre u corrispondono con le cifre c (ovviamente di pari posizione u1-c1, u2-c2) e mostra all'utente la cifra 
dove ha indovinato mentre un '?' dove la cifra inserita è errata. Il programma tiene conto dei tentativi effettuati 
dall'utente ed il programma termina quando l'utente identifica tutte e cinque le cifre del codice.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int c1, c2, c3, c4, c5; // variabili per le cifre del codice originale
    int u1, u2, u3, u4, u5; // variabili per le cifre del codice utente.
    int numeroTentativi;    // contatore dei tentativi effettuati.
    int cifreIndovinate;    // numero di cifre indovinta ad ogni tentativo.
    int indovinato;         // booleano 0/1 indica se ho indvinato oppure no il codice.
    char junk;

    /*
    c1 = 1;
    c2 = 2;
    c3 = 3;
    c4 = 4;
    c5 = 5;
    */
    srand(time(NULL));
    c1 = rand()%10;
    c2 = rand()%10;
    c3 = rand()%10;
    c4 = rand()%10;
    c5 = rand()%10;

    numeroTentativi = 0;
    indovinato = 0;
    while(indovinato == 0){     // indovinato != 1
        numeroTentativi = numeroTentativi + 1;
        // step 1 inserimento cifre del codice utente.
        printf("Inserisci cifra 1: ");
        scanf("%d", &u1);
        junk = getchar();

        printf("Inserisci cifra 2: ");
        scanf("%d", &u2);
        junk = getchar();

        printf("Inserisci cifra 3: ");
        scanf("%d", &u3);
        junk = getchar();

        printf("Inserisci cifra 4: ");
        scanf("%d", &u4);
        junk = getchar();

        printf("Inserisci cifra 5: ");
        scanf("%d", &u5);
        junk = getchar();

        // step 2 controllo delle cifre utente con quelle originali codice
        cifreIndovinate = 0;
        if(u1 == c1){
            printf("%d", u1);
            cifreIndovinate = cifreIndovinate + 1;
        }
        else{
            printf("?");
        }

        if(u2 == c2){
            printf("%d", u2);
            cifreIndovinate = cifreIndovinate + 1;
        }
        else{
            printf("?");
        }

        if(u3 == c3){
            printf("%d", u3);
            cifreIndovinate = cifreIndovinate + 1;
        }
        else{
            printf("?");
        }

        if(u4 == c4){
            printf("%d", u4);
            cifreIndovinate = cifreIndovinate + 1;
        }
        else{
            printf("?");
        }

        if(u5 == c5){
            printf("%d", u5);
            cifreIndovinate = cifreIndovinate + 1;
        }
        else{
            printf("?");
        }

        // controllo se numeroCifre indovinate è uguale a quante sono da indovinate
        if(cifreIndovinate == 5){
            printf("\n YOU WIN...\n");
            printf("with %d attempts\n", numeroTentativi);
            indovinato = 1;
        }
        else{
            printf("\nTry Again!!");
        }
        printf("\n------------------\n");
    }
    return(0);
}