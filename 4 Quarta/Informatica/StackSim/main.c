#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "process.c"        // includo il file con la struttura e le funzioni per un processo.

int main(){
    Processo *stack;        // puntatore al vettore dinamico di Processi.
    int stack_counter;      // contatore dei processi attualmente allocati.
    int scelta;             // scelta del menu proposto.
    int n_push, n_pop;      // variabili per il numero di push o pop richieste.

    stack = NULL;           // inizializzo il puntatore stack a null.
    stack_counter = 0;      // il contatore di processi inizialmente è zero.
    
    do{
        stackStatusR(stack, stack_counter);
        printf("\nNr. processi: %d - Size Processo: %d - Stack Size: %d\n\n",stack_counter, sizeof(Processo), stack_counter*sizeof(Processo));

        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("0. USCITA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        fflush(stdin);

        if(scelta == 1){
            printf("Nr. processi da allocare: ");
            scanf("%d", &n_push);
            fflush(stdin);
            push(&stack, &stack_counter, n_push);
        }
        if(scelta == 2){
            printf("Nr. processi da de-allocare: ");
            scanf("%d", &n_pop);
            fflush(stdin);
            pop(&stack, &stack_counter, n_pop);
        }
        if(scelta != 1 && scelta != 2 && scelta != 0)
            printf("Scelta non valida!\n");
    }while(scelta != 0);
    return(0);
}