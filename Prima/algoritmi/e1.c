#include <stdio.h>

int main(){
    // creo le quattro "scatolette" per i dati iniziali e i risultati.
    int base;
    int altezza;
    int perimetro;
    int area;

    // FASE UNO: richiesta dei dati iniziali
    printf("Base: ");
    scanf("%d", &base);
    fflush(stdin);

    printf("Altezza: ");
    scanf("%d", &altezza);
    fflush(stdin);

    // FASE DUE: eseguo il calcolo richiesto
    perimetro = base + base + altezza + altezza;
    area = base * altezza;

    //FASE 3: Comunico i risultati calcolati.
    printf("Area: %d\n", area);
    printf("Perimetro: %d\n", perimetro);

    getchar();
    return(0);
}