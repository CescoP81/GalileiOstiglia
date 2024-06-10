/*  Data: 22/10/22
    Author: Francesco Pradella
    Filename: p07.c
    Abstracty: Esercizio nr. 15 pag. 153
*/
#include <stdio.h>

int main(){
    int scattiPrecedenti;
    int scattiAttuali;
    float costoScatto;
    float costoFisso;
    float costoTotale;

    scattiPrecedenti = 0; scattiAttuali = 0; costoScatto = 0; costoFisso = 0; costoTotale = 0;

    // fase di input dati:
    printf("Scatti Precedenti: ");
    scanf("%d", &scattiPrecedenti);
    fflush(stdin);

    printf("Scatti Attuali: ");
    scanf("%d", &scattiAttuali);
    fflush(stdin);

    printf("Costo dello scatto: ");
    scanf("%f", &costoScatto);
    fflush(stdin);

    printf("Costo fisso/canone: ");
    scanf("%f", &costoFisso);
    fflush(stdin);

    // fase di calcolo richiesto
    costoTotale = costoFisso + ((scattiAttuali - scattiPrecedenti) * costoScatto);
    printf("Totale da pagare: %.2f", costoTotale);

    return(0);
}