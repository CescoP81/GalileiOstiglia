#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int x;
    float y;
    char n[10];
}Elemento;

int main(){
    Elemento e; // -> Elemento *e1
    Elemento ev[2];
    Elemento tmp;

    e.x = 5;
    e.y = 10.76;
    printf("E: %d %f\n", e.x, e.y);

    ev[0].x = 6;
    ev[0].y = 9.80;
    strcpy(ev[0].n,"Alberto");
    
    ev[1].x = 2;
    ev[1].y = 2.345;
    strcpy(ev[1].n,"paolo");

    printf("Ev[0]: %d %f %s\n", ev[0].x, ev[0].y, ev[0].n);
    printf("Ev[1]: %d %f %s\n", ev[1].x, ev[1].y, ev[1].n);

    tmp = ev[0];
    ev[0] = ev[1];
    ev[1] = tmp;

    printf("\nEv[0]: %d %f %s\n", ev[0].x, ev[0].y, ev[0].n);
    printf("Ev[1]: %d %f %s\n", ev[1].x, ev[1].y, ev[1].n);

    // -------------------------------
    Elemento* e1;
    Elemento* e2;
    Elemento* tmp2;
    e1 = (Elemento *) malloc(sizeof(Elemento)); // ->int *a = (int *) malloc(sizeof(int)) -> 4byte

    e1->x = 18;
    e1->y = 8.67;
    strcpy(e1->n, "Angela");

    printf("\nE1: %d %f %s\n", e1->x, e1->y, e1->n);

    tmp2 = e1;
    e1 = e2;
    e2 = tmp2;

    // ----------------
    Elemento v1[5];
    Elemento *v2
    v2 = (Elemento*) malloc(5*sizeof(Elemento));

}