/*  Data: 06/10/22
    Author: Francesco Pradella
    Filename: p01.c
    Abstracty: Realizzare il diagramma di un algoritmo che richiesti all'utente il giorno ed il mese dell'anno
corrente, calcola e comunica quanti giorni sono passati dall'inizio dell'anno.
Consideriamo febbraio sempre di 28 giorni.
*/
#include <stdio.h>

int main(){
    int giorno = 0;
    int mese = 0;
    int cnt = 0;
    int totaleG = 0;

    // fase di input mese e giorno
    printf("Inserisci il giorno: ");
    scanf("%d", &giorno);
    fflush(stdin);
    printf("Inserisci il mese: ");
    scanf("%d", &mese);
    fflush(stdin);

    cnt = 1;
    while(cnt < mese){
        if(cnt==1 || cnt==3 || cnt==5 || cnt==7 || cnt==8 || cnt==10){
            // eseguo quesa operazione se il cnt è gennaio-marzo-maggio-luglio-agosto.
            totaleG = totaleG + 31;
        }
        else{
            if(cnt == 2){
                // eseguo questa operazione se cnt è febbraio.
                totaleG = totaleG + 28;
            }
            else{
                // eseguo questa operazione se cnt è un mese da 30 giorni.
                totaleG = totaleG + 30;
            }
        }
        cnt = cnt + 1;
    }
    totaleG = totaleG + giorno; // aggiungo i giorni del mese inserito.
    printf("Giorni totali da inizio anno: %d", totaleG);
    getch();
    return(0);
}

