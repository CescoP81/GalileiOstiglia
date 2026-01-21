/*
Realizza a video il seguente schema grafico utilizzando più cicli iterativi while() annidati:
* * * * * *
* *       *
*   *     *
*     *   *
*       * *
* * * * * *
*/
#include <stdio.h>

int main(){
    int r; //variabile per il ciclo delle righe
    int c; // variabile per il ciclo delle colonne

    r = 1;
    while(r <= 6){
        c = 1;
        while(c <= 6){
            if((c==1) || (c==6) || (r==1) || (r==6) || (r==c)){
                printf("* ");
            }
            else{
                printf("  ");
            }
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }
    return(0);
}