#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
}Elemento;

int main(){
    Elemento e;
    e.val = 5;

    Elemento *x;
    x = malloc(sizeof(Elemento));
    x->val = 7;

    printf("%d",e.val);
    printf("\n%d", x->val);
}