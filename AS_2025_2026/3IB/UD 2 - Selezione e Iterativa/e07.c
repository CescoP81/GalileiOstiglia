/*
Realizzare un programma "Guess the Code" che operi nel seguente modo:  
All'avvio il programma inizializza cinque variabili chiamate c1 c2 c3 c4 c5 con cinque valori
interi positivi compresi tra 0 e 9(per la fase di sviluppo inserirli a mano da codice sorgente), 
successivamente propone all'utente l'inserimento di cinque valori in altrettante variabili chiamate u1 u2 u3 u4 u5. 

Il programma verifica se le cifre u corrispondono con le cifre c (ovviamente di pari posizione u1-c1, u2-c2) 
e mostra all'utente la cifra dove ha indovinato mentre un '?' dove la cifra inserita è errata. 
Il programma tiene conto dei tentativi effettuati dall'utente ed il programma termina quando l'untente 
identifica tutte e cinque le cifre del codice.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int c1, c2, c3, c4, c5; // variabili per il codice numerico originale.
    int u1, u2, u3, u4, u5; // variabili per il codice numerico utente.
    char junk;
    int numeriIndovinati; // indica il numero di cifre che ho indovinato tentanto la fortuna.
    int indovinato; // variabile booleana 0/1 che indica se ho indovinato o meno il codice.
    int numeroTentativi;

    srand(time(NULL));
    /*
    c1 = 1;
    c2 = 2;
    c3 = 3;
    c4 = 4;
    c5 = 5;*/
    c1 = rand()%10;
    c2 = rand()%10;
    c3 = rand()%10;
    c4 = rand()%10;
    c5 = rand()%10;

    numeroTentativi = 0;
    indovinato = 0;
    while(indovinato == 0){ // oppure indovinato != 1
        numeroTentativi = numeroTentativi + 1;
        // step 1: richiesta all'utente delle 5 cifre possibili.
        printf("Inserisci la cifra 1: ");
        scanf("%d", &u1);
        junk = getchar();

        printf("Inserisci la cifra 2: ");
        scanf("%d", &u2);
        junk = getchar();

        printf("Inserisci la cifra 3: ");
        scanf("%d", &u3);
        junk = getchar();

        printf("Inserisci la cifra 4: ");
        scanf("%d", &u4);
        junk = getchar();

        printf("Inserisci la cifra 5: ");
        scanf("%d", &u5);
        junk = getchar();

        // step 2: controllo delle singole cifre immesse con quelle del codice da indovinare.
        numeriIndovinati = 0;
        printf("\nVerifica Codice....\n");
        if(u1 == c1){
            printf("%d", u1);
            numeriIndovinati = numeriIndovinati + 1;
        }
        else{
            printf("?");
        }

        if(u2 == c2){
            printf("%d", u2);
            numeriIndovinati = numeriIndovinati + 1;
        }
        else{
            printf("?");
        }

        if(u3 == c3){
            printf("%d", u3);
            numeriIndovinati = numeriIndovinati + 1;
        }
        else{
            printf("?");
        }

        if(u4 == c4){
            printf("%d", u4);
            numeriIndovinati = numeriIndovinati + 1;
        }
        else{
            printf("?");
        }

        if(u5 == c5){
            printf("%d", u5);
            numeriIndovinati = numeriIndovinati + 1;
        }
        else{
            printf("?");
        }

        // step 3: determino se ho vinto oppure no
        if(numeriIndovinati == 5){
            printf("\nYOU WIN!!\n");
            printf("with %d attempts!\n", numeroTentativi);
            indovinato = 1;
        }
        else{
            printf("\nTry Again...\n");
        }

        printf("\n--------------------\n\n");
    }
    return(0);
}