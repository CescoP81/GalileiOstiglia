/*
    Programma che richiede due valori da tastiera e se necessario li ordina in modo crescente
    ri-stampo i due valori
*/
#include <stdio.h>

int main(){
    int v1, v2; // variabili per i valori iniziali
    int tmp;    // variabile temporanea per eseguire lo scambio di v1 e v2 se richiesto
    char junk;

    // inserimento valori iniziali
    printf("Inserisci V1: ");
    scanf("%d", &v1);
    junk = getchar();

    printf("Inserisci V2: ");
    scanf("%d", &v2);
    junk = getchar();

    // determino se sono in ordine crescente o se devo eseguire lo scambio
    /* es:
        v1 = 5;
        v2 = 2
        NON SONO IN ORDINE CRESCENTE QUINDI DEVO ESEGUIRE LO SCAMBIO
        dopo lo scambio devo avere
        v1 = 2
        v2 = 5
    */
    if(v1 > v2){
        // devo eseguire lo scambio
        tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    // stampa valori ordinati crescenti
    printf("V1 = %d\n", v1);
    printf("V2 = %d\n", v2);

    return 0;
}

/* ALTERNATIVA ERRATA ALLE RIGHE 30 - 39
    if(v1 > v2){
        printf("V2 = %d\n", v2);
        printf("V1 = %d\n", v1);
    }
    else{
        printf("V1 = %d\n", v1);
        printf("V2 = %d\n", v2);
    }
    
    !ERRATA!
    perchè stampa in ordine crescente MA non ordina i valori nelle variabili, 
    NON ESEGUE scambio di valori tra le variabili.
*/