#include <stdio.h>

int main(){
    int v1;
    int v2;
    int v3;
    char junk;

    printf("Inserisci il primo valore: ");
    scanf("%d", &v1);
    junk = getchar();

    printf("Inserisci il secondo valore: ");
    scanf("%d", &v2);
    junk = getchar();

    printf("Inserisci il terzo valore: ");
    scanf("%d", &v3);
    junk = getchar();
    
    printf("Valore inseriti: %d - %d - %d\n", v1, v2, v3);

    // prima soluzione con if annidate
    if(v1 < v2){
        if(v2 < v3){
            printf("I tre valori sono in ordine crescente...\n");
        }
        else{
            printf("I tre valori NON sono in ordine crescente...\n");
        }
    }
    else{
        printf("I tre valori NON sono in ordine crescente...\n");
    }

    // seconda soluzione con if e operatori logici
    printf("\n");
    if((v1 < v2) && (v2 < v3)){
        printf("I tre valori sono in ordine crescente...\n");
    }
    else{
        printf("I tre valori NON sono in ordine crescente...\n");
    }
    return(0);
}