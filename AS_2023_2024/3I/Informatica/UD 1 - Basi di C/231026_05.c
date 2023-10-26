/*
    Author: Francesco P.
    Date:   2023.10.26
    file:   231026_04.c
    Desc:   Richiedi in input un valore intero (ipotizza sia una somma in euro),
            calcola e comunica a quanto corrispondono in Dollari (USD), YEN, Fiorino Ungherese.
*/
#include <stdio.h>

// costanti di cambio prese da XeCurrency il 26.10.23
const float EUROUSD = 1.05;     // cambio euro-dollaro
const float EUROYEN = 158.48;   // cambio euro-yen giapponese
const float EUROHUF = 382.63;   // cambio euro-fiorino ungherese

int main(){
    float euro = 0.0;
    float usd = 0.0;
    float yen = 0.0;
    float huf = 0.0;

    printf("Inserisci gli euro: ");
    scanf("%f", &euro);

    usd = euro * EUROUSD;
    printf("Dollari statunitensi: %.2f\n", usd);

    yen = euro * EUROYEN;
    printf("Yen giappinesi: %.2f\n", yen);

    huf = euro * EUROHUF;
    printf("Fiorini ungheresi: %.2f\n", huf);

    return(0);
}