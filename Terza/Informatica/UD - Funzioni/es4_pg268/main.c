/* Esercizio 4 - pag 268
Scrivi un programma che generi le temperature minime e massime di ogni giorno del mese di Gennaio.
Le temperature vengono inserite in due array che vengono poi visualizzati su richiesta dell'utente.
Su richiesta dell'utente, viene calcolata la media tra le temperature massime e il giorno in cui si è avuta
la differenza minore tra le temperature massima e minima.
*/
#include <conio.h>
#include <stdio.h>
#include "lib.c"

#define DIM 31

int main(){
    int tmp_min[DIM];
    int tmp_max[DIM];
    float media_max;
    int giorno_differenza_minore;
    int scelta;
    
    initTemperature(tmp_min, tmp_max, DIM);

    do{
        printf("\n\n1. Stampa temperature massime.\n");
        printf("2. Stampa temperature minime.\n");
        printf("3. Stampa media temperature massime.\n");
        printf("4. Giorno con minore escursione.\n");
        printf("0. USCITA.\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:{
                printf("Massime:\n");
                stampaTemperature(tmp_max, DIM);
                break;
            }
            case 2:{
                printf("Minime:\n");
                stampaTemperature(tmp_min, DIM);
                break;
            }
            case 3:{
                printf("Massime:\n");
                stampaTemperature(tmp_max, DIM);

                media_max = tmp_media(tmp_max, DIM);
                printf("\nMedia delle massime: %.2f\n", media_max);
                break;
            }
            case 4:{
                giorno_differenza_minore = deltaMinore(tmp_min, tmp_max, DIM);
                printf("\nGiorno con escursione minore: %d.", giorno_differenza_minore);
                break;
            }
            case 0:{
                printf("Programma terminato...");
                break;
            }
        }
    }while(scelta != 0);
    return(0);
}
/*  // test delle funzioni create prima dello switch case finale.
    initTemperature(tmp_min, tmp_max, DIM);
    stampaTemperature(tmp_min, DIM);
    printf("\n\n");
    stampaTemperature(tmp_max, DIM);

    printf("\n\n");
    media_max = tmp_media(tmp_max, DIM);
    printf("Media delle massime: %.2f\n", media_max);

    giorno_differenza_minore = deltaMinore(tmp_min, tmp_max, DIM);
    printf("Giorno con escursione minore: %d.", giorno_differenza_minore);
*/