/*
Realizzare un programma che richieda l'inserimento di tre valori in altrettante variabili chiamate val1, val2, val3.
Il programma deve:
    a. Determinare qual'è il valore maggiore e minore inserito.
    b. SE val1 < val3: visualizzare tutti i valori tra val1 e val2 comunicando quanti sono numeri primi. Altrimenti visualizzare un quadrato di '#' con lato val3.
    c. SE val1 è un numero pari, scomporlo in fattori primi. ATRIMENNTI stampare a video il messaggio "Numero non utilizzabile".
    d. visualizzare a video un rettangolo di '*' vuoto all'interno, con lati val1 come base e val2 come altezza.

es d:
5 - 3

*****
*   *
*****
*/
#include <stdio.h>

int main(){
    int val1, val2, val3;
    int max, min;
    int num, div, cntDiv, cntPrimi;
    int x, y;

    // input da tastiera dei tre valori richiesti.
    printf("Inserisci Val1: ");
    scanf("%d", &val1);
    fflush(stdin);
    printf("Inserisci Val2: ");
    scanf("%d", &val2);
    fflush(stdin);
    printf("Inserisci Val3: ");
    scanf("%d", &val3);
    fflush(stdin);
    printf("\n----\n\n");

    // punto A
    max = val1;
    if(val2 > max) max = val2;
    if(val3 > max) max = val3;

    min = val1;
    if(val2 < min) min = val2;
    if(val3 < min) min = val3;

    printf("Valori minore e maggiore: %d %d", min, max);
    printf("\n----\n");

    // punto B
    if(val1 < val3){
        cntPrimi = 0;
        num = val1;
        while(num < val2){                  // imposto un ciclo da val1 a val2 utilizzando la variabile num per non perdere val1.
            printf("%d", num);
            cntDiv=0;
            div=1;
            while(div <= num){              // ciclo dei divisori per testare ogni numero se primo oppure no.
                if(num%div == 0)
                    cntDiv++;
                div++;
            }
            if(cntDiv <= 2){                // condizione del numero primo basata sul numero di divisori trovati.
                printf(" -> Primo");
                cntPrimi = cntPrimi + 1;
            }
            printf("\n");
            num++;
        }
        printf("I numero di valori primi trovati e': %d", cntPrimi);
    }
    else{
        x = 1;
        while(x <= val3){                   // doppio ciclo per graficare il quadrato con lato val3
            y = 1;
            while(y <= val3){
                printf("#");
                y++;
            }
            printf("\n");
            x++;
        }
    }
    printf("\n----\n");

    // PUNTO C
    if(val1%2 == 0){                        // test su val1 se pari oppure no
        num = val1;
        div = 2;
        while(num>1){                       // ciclo di scomposizione in fattori primi es. 24 -> 2, 2, 2, 3
            if(num%div == 0){
                printf("%d, ", div);
                num = num / div;
            }
            else
                div = div + 1;
        }
    }
    else
        printf("Numero non utilizzabile.");
    printf("\n----\n");

    // punto D
    if(val1>=3 && val2>=3){                             // condizione, non richiesta, su val1 e val3 se troppo piccoli non è possibile realizzare il buco interno alla figura.
        x=1;
        while(x<=val2){                                 // ciclo per le righe basato su val2 richiesto come altezza.
            y=1;
            while(y<=val1){                             // ciclo sulle colonne basato su val1 richiesto come base.
                if(x==1 || x==val2 || y==1 || y==val1)
                    printf("#");
                else
                    printf(" ");
                y++;
            }
            printf("\n");
            x++;
        }
    }
    else
        printf("Impossibile realizzare il buco interno.");
    return(0);
}