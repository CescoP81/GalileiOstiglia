#include <stdio.h>

int main(){
    int a;
    int b;
    char junk;

    printf("Inserisci a: ");
    scanf("%d", &a);

    printf("Inserisci b: ");
    scanf("%d", &b);

    printf("Valori inseriti: %d %d", a, b);
    return(0);
}