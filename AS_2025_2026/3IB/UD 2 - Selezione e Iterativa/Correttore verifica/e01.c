/*
Realizzare un programma C che richieda l’inserimento di 3 valori interi, determina e comunica:
1. Se sono in ordine crescente
2. La media dei valori inseriti
3. Il valore maggiore e minore inseriti e di quanto differiscono.
*/
#include <stdio.h>

int main(){
    int a,b,c;
    float media;
    int min, max;
    char junk;

    // inserimento valori
    printf("Inserisci A: ");
    scanf("%d", &a);
    junk = getchar();

    printf("Inserisci B: ");
    scanf("%d", &b);
    junk = getchar();

    printf("Inserisci C: ");
    scanf("%d", &c);
    junk = getchar();

    printf("Valori inseriti: %d %d %d\n", a, b,c);
    
    //verifico ordine crescente
    if((a<b) && (b<c)){         // (a<b<c)
        printf("Confermato ordine crescente\n");
    }
    else{
        printf("Non sono in ordine crescente.\n");
    }

    // calcolo e comunicazione della media.
    media = 0.0;
    media = a+b+c;
    media = media / 3;
    printf("La media dei valori vale: %.2f\n", media);

    // valore maggiore minore e differenza tra i due
    min = a;
    max = a;
    if(b>max)
        max = b;
    if(b<min)
        min = b;
    if(c>max)
        max = c;
    if(c<min)
        min = c;
    
    printf("valore maggiore: %d, minore: %d, differenza: %d\n", max, min, (max-min));

    return(0);
}