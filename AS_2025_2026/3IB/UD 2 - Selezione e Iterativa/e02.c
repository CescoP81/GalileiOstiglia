/*
    Data: 2025.11.10
    Autore: Pradella Francesco
    Descrizione: Programma che richiede due valori in input, calcola area e perimetro
    dell'ipotetico rettangolo.
*/
#include <stdio.h>

int main(){
    int v1;
    int v2;
    int area;
    int perimetro;
    char junk; // variabile da usare dopo le scanf.

    // fase di input valori
    printf("Inserisci valore uno: ");
    scanf("%d", &v1);
    junk = getchar();

    printf("Inseriasci valore due: ");
    scanf("%d", &v2);
    junk = getchar();

    // calcolo area e perimetro.
    area = v1 * v2;
    perimetro = (v1 + v2) * 2;

    // comunico i risultati
    printf("L'area vale: %d \n", area);
    printf("Il perimetro vale: %d \n", perimetro);

    return(0);
}