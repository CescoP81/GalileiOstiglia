/*
    Esempi di utilizzo dei cicli con numeri random e verifiche numeriche.
    data: 2026.02.24
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int random; // conterrà il valore generato random.
    int i;      // variabile per ipotetico ciclo for
    int somma;  // somma dei divisori di un numero
    int div;    // variabile per testare i divisori di un numero.

    // visualizza 15 numeri random, per ogni numero determinare e comunicare se è
    // pari o dispari e se è un numero perfetto.

    for(i=1; i<=15; i++){   // ciclo che gira 15 volte per generare i 15 valori richiesti.
        // genero un nuemro random.
        random = 1 + rand()%50;
        printf("%d -> ", random);
        if(random%2 == 0){
            printf("PARI, ");
        }
        else{
            printf("DISPARI, ");
        }

        div = 1;
        somma = 0;
        while(div <= random){       // ciclo dei divisori sul numero random generato r20
            if(random%div == 0)
                somma = somma + div;
            div = div + 1;
        }

        if(somma == (random*2)){
            printf("PERFETTO.\n");
        }
        else{
            printf("NON PERFETTO.\n");
        }
    }
    return(0);
}