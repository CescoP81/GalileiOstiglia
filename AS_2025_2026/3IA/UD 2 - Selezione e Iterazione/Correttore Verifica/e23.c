/*
Realizza a video il seguente schema grafico utilizzando più cicli iterativi while() annidati:
* * * * *
  * * * *
    * * *
      * *
        *
      - -
    - - -
  - - - - 
- - - - -
*/
#include <stdio.h>

int main(){
    int r;  // righe
    int c;  // colonne
    int s;  // ciclo spazi
    int spazi;  // numero spazi da realizzare

    r = 1;                      // triangolo superiore
    spazi = 0;
    while(r <= 5){
        s = 1;
        while(s <= spazi){
            printf("  ");
            s = s + 1;
        }
        c = r;
        while(c <= 5){
            printf("* ");
            c = c + 1;
        }
        printf("\n");
        spazi = spazi + 1;
        r = r + 1;
    }

    r = 1;                      // triangolo inferiore
    spazi = 3;
    while(r <= 4){
        s = 1;
        while(s <= spazi){
            printf("  ");
            s = s + 1;
        }

        c = 1;
        while(c <= r + 1){
            printf("- ");
            c = c + 1;
        }
        printf("\n");
        r = r + 1;
        spazi = spazi - 1;
    }
    return(0);
}