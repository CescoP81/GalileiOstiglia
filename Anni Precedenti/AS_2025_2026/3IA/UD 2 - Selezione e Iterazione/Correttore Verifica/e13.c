/*Realizza a video il seguente schema grafico utilizzando più cicli iterativi while() annidati:
*
* *
* * *
* * * * * * * *
	    * * *
        * * 
	    *
*/
#include <stdio.h>

int main(){
    int r;
    int c;
    int spazi;

    r = 1;                  // triangolo superiore
    while(r <= 3){
        c = 1;
        while(c <= r){
            printf("* ");
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
    }

    c = 1;                  // riga lunga 8 asterischi centrale
    while(c <= 8){
        printf("* ");
        c = c + 1;
    }
    printf("\n");

    r = 3;                  // triangolo inferiore.
    while(r >= 0){
        spazi = 1;
        while(spazi <= 4){  // prima del triangolo ci sono sempre 4 spazi su ogni riga
            printf("  ");
            spazi = spazi + 1;
        }

        c = 1;
        while(c <= r){      // ciclo per gli asterisci sulle ultime 3 righe finali.
            printf("* ");
            c = c + 1;
        }
        printf("\n");
        r = r - 1;
    }
    return(0);
}