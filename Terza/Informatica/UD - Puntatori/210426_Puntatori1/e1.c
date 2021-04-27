#include <conio.h>
#include <stdio.h>

int main(){
    int a;
    int *pa;
    int **ppa;

    a = 20;

    pa = &a;

    printf("A: %d\n", a);
    printf("PA: %d, *PA: %d\n", pa, *pa);

    ppa = &pa;
    printf("PPA: %d, *PPA: %d, **PPA: %d", ppa, *ppa, **ppa);
    return(0);
}