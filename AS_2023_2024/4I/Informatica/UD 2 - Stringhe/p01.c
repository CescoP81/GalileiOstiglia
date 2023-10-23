#include <stdio.h>
const int DIM=21;

int main(){
    char str[DIM];
    int i;

    // init della stringa
    for(i=0; i<DIM; i++){
        str[i] = '\0';
    }
    printf("Inserisci una parola: ");
    scanf("%s", str);
    printf("\n");

    printf("Parola Inserista: %s", str);
    printf("\n");

    // visualizzazione char-by-char con ciclo for
    printf("Visualizzazione char-by-char: ");
    i=0;
    while(str[i] != '\0'){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");

    // Cosa c'è dentro al vettore oltre alla mia stringa? -> BananaP→@ ►½
    printf("Intero contenuto: ");
    for(i=0; i<DIM; i++){
        printf("%c", str[i]);
    }

    return(0);
}