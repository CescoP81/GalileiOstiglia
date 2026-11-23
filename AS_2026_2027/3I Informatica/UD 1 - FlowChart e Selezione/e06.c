/*  Creare un programma che richiede 4 valori in input memorizzandoli in
    quattro variabili (v1, v2, v3, v4).
    Stampa a video e calcola la somma dei valori compresi tra 10 e 20, estremi compresi.
*/
#include <stdio.h>

int main(){
    int v1, v2, v3, v4;     // variabili per i valori in input.
    int somma;              // variabile per la possibile somma da calcolare.
    char junk;              // variabile per pulizia buffer di input.

    //fase di input valori
    printf("Inserisci V1: ");
    scanf("%d", &v1);
    junk = getchar();

    printf("Inserisci V2: ");
    scanf("%d", &v2);
    junk = getchar();

    printf("Inserisci V3: ");
    scanf("%d", &v3);
    junk = getchar();

    printf("Inserisci V4: "),
    scanf("%d", &v4);
    junk = getchar();

    // controlli ed eventuali somme.
    somma = 0;
    if((v1 >= 10) && (v1 <= 20)){
        printf("Valore v1: %d\n", v1);
        somma = somma + v1;
    }

    if((v2 >= 10) && (v2 <= 20)){
        printf("Valore v2: %d\n", v2);
        somma = somma + v2;
    }

    if((v3 >= 10 ) && (v3 <= 20)){
        printf("Valore v3: %d\n", v3);
        somma = somma + v3;
    }

    if((v4 >= 10) && (v4 <= 20)){
        printf("Valore v4: %d\n", v4);
        somma = somma + v4;
    }

    printf("\nSomma dei valori idonei: %d\n", somma);

    return 0;
}
/*
    TABELLA DI VERITA' DELLA AND-&& logica
    A B -> &&
    v v     v
    v f     f
    f v     f
    f f     f
*/