#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANGE 20

int main(){
    int val;
    int i;
    srand(time(NULL));              // inizializzo il generatore di numeri random

    i=1;
    while(i<=5){
        val = rand()%MAX_RANGE;     // genero un numero random e calcolo il modulo (resto) con MAX_RANGE
        printf("%d ", val);
        i++;
    }

    return(0);
}