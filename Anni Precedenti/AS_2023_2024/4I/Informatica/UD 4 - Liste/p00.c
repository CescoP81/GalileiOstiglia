#include <stdio.h>

void f1(int **p);
void f2(int **p);

int main(){
    int a;
    int *pa;

    a = 5;
    pa = &a;
    f1(&pa);
    f2(&pa);
    printf("%d\n", a);  // stampo il valore della variabile a
    printf("%d", pa);   // stampo il contenuto del puntatore, cioè l'indirizzo contenuto.
    return(0);
}

void f1(int **p){
    **p = 8;    // cambio il valore nella variabile puntata dal puntatore passato per riferimento.
}
void f2(int **p){
    *p = 0;     // cambio il contenuto del puntatore passato per riferimento.
}
