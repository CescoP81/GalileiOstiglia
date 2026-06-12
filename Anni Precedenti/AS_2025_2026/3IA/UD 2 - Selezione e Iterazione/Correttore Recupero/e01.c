/*
  Realizzare un programma C che permetta di inserire 4 valori interi, 
  al termine dell’inserimento comunica il valore minore inserito, 
  se i valori sono in ordine decrescente, le medie tra primo e secondo e tra terzo e quarto. 
*/
#include <stdio.h>

int main(){
    int a,b,c,d;
    int min;
    float mA, mB;
    char junk;

    // fase di input
    printf("Inserisci A: ");
    scanf("%d", &a);
    junk = getchar();

    printf("Inserisci B: ");
    scanf("%d", &b);
    junk = getchar();

    printf("Inserisci C: ");
    scanf("%d", &c);
    junk = getchar();

    printf("Inserisci D: ");
    scanf("%d", &d);
    junk = getchar();

    // determino il valore minore tra i 4 inseriti.
    min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    if(d < min) min = d;

    printf("Valore minore inserito: %d\n", min);

    // controllo decrescenza
    if((a>b) && (b>c) && (c>d)){
        printf("I valori sono in ordine decrescente.\n");
    }
    else{
        printf("I valori NON SONO in ordine decrescente.\n");
    }

    mA = a+b;
    mB = c+d;
    printf("Media tra I e II: %.2f\n", (mA/2));
    printf("Media tra III e IV: %.2f", (mB/2));
    return(0);
}