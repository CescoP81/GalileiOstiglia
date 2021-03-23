#include <conio.h>
#include <stdio.h>

void stampaA(int **ppa);

int main(){
    int a;
    int *pa;

    a = 18;
    printf("%d\n", a);

    pa = &a;
    printf("%d - %d\n\n", pa, *pa);

    stampaA(&pa);
}

void stampaA(int **ppa){
    printf("Indirizzo del puntatore ad a: %d\n", ppa);
    printf("Contenuto del puntatore pa: %d\n", *ppa);
    printf("Contenuto di a: %d", **ppa);
}