#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 999

int main(){
    int val; // variabile per il valore inserito dall'utente.
    int div; // variabile per il ciclo dei divisori.
    int somma_div; // somma dei divisori per algoritmo num perfetto.
    int cnt_div; // contatore dei divisori trovati.
    int risposta; // variabile per la scelta dell'utente.

    do{
        system("CLS");
        // richiesta del valore all'utente.
        do{
            printf("Inserisci un valore: ");
            scanf("%d", &val);
            fflush(stdin);
        }while(val < MIN || val > MAX);

        // chiedo all'utente cosa vuole fare con il numero inserito.
        printf("\n");
        printf("1 -> Verifica numero primo.\n");
        printf("2 -> Verifica numero perfetto.\n");
        printf("Scelta: ");
        scanf("%d", &risposta);
        fflush(stdin);

        if(risposta == 1){
            // ciclo determina numero primo
            cnt_div = 0;
            div = 1;
            while(div <= val){
                if(val%div == 0){
                    cnt_div = cnt_div + 1;
                }
                div = div + 1;
            }
            if(cnt_div <= 2)
                printf("Il numero %d e' primo!\n", val);
            else
                printf("Il numero %d non e' primo.\n", val);
        }
        if(risposta == 2){
            // ciclo determina numero perfetto
            somma_div = 0;
            div = 1;
            while(div < val){
                if(val%div == 0){
                    somma_div = somma_div + div;
                }
                div = div + 1;
            }
            if(somma_div == val){
                printf("%d e' perfetto con somma divisori %d.\n", val, somma_div);
            }
            else{
                printf("%d non e' perfetto con somma divisori %d.\n", val, somma_div);
            }
        }
        if(risposta<1 || risposta>2)
            printf("Scelta non valida!!\n");
        
        printf("\n");
        printf("Vuoi ripetere? (1->si / 0->no): ");
        scanf("%d", &risposta);
        fflush(stdin);        
    }while(risposta == 1);
}