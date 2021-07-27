#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Struttura base di un processo.
---------------------------------
char name: Singolo carattere tra 'a' e 'z' random.
int value: Valore random tra 1 e 300
*/
typedef struct{
    char name;
    int value;
}Processo;

/* Funzione che alloca lo spazio necessario al numero di processi richiesti, modificando il contatore dei processi attualmente allocati.
@param Processo** riferimento al puntatore delle celle Processo.
@param int* riferimento al contatore dei processi allocati.
@param int numero di processi da allocare.
@return void
*/
void push(Processo **stack, int* stack_counter, int push_counter){
    int i;
    if(push_counter){
        if(*stack_counter == 0){
            *(stack) = (Processo *) malloc(push_counter * sizeof(Processo));
            for(i=0; i<push_counter; i++){
                (*stack+i)->name = 'a' + rand()%26; // 'a' --> 97d
                (*stack+i)->value = rand()%300 + 1;
                //printf("Creo Processo...\n");
            }
            *stack_counter = *stack_counter + push_counter;
        }
        else{
            *stack_counter += push_counter;
            *(stack) = (Processo *) realloc(*stack, *stack_counter*sizeof(Processo));
            for(i=((*stack_counter)-push_counter); i<*stack_counter; i++){
                (*stack+i)->name = 'a' + rand()%26;
                (*stack+i)->value = rand()%300 + 1;
                //printf("Creo Processo...\n");
            }
        }
    }
}

/* Funzione che dealloca il numero di processi richiesti, se il numero di processi da de-allocare è maggiore del numero di processi
 esistenti genera un messaggio di errore.
@param Processo** riferimento al puntatore delle celle Processo.
@param int* riferimento al contatore dei processi allocati.
@param int numero di processi da de-allocare.
@return void
*/
void pop(Processo **stack, int* stack_counter, int pop_counter){
    if(pop_counter > *stack_counter)
        printf("\n# Numero processi insufficiente #\n");
    else{
        printf("Processi che vengono eliminati:\n");
        int i;
        //for(i=(*stack_counter-pop_counter-1); i<*stack_counter; i++){
        for(i=*stack_counter-1; i>=*stack_counter-pop_counter; i--){
            printf("%c : %d\n", (*stack+i)->name, (*stack+i)->value);
        }
        *stack_counter = *stack_counter - pop_counter;
        *(stack) = (Processo *) realloc(*stack, *stack_counter * sizeof(Processo));
        printf("\n\n");
    }
}

/* Funzione ricorsiva per mostrare lo stack come struttura Li-Fo, l'ultimo elemento inserito viene visualizzato in alto.
@param Processo* Puntatore allo stack allocato.
@param int Numero di processi allocati nello stack.
@return void
*/
void stackStatusR(Processo *stack, int stack_counter){
    if(stack == NULL){
        printf("_______\n");
        printf(" STACK\n");
    }
    else{
        if(stack_counter == 1){
            printf("%c : %3d\n", (stack+stack_counter-1)->name, (stack+stack_counter-1)->value);
            printf("_______\n");
            printf(" STACK\n");
        }
        else{
            printf("%c : %d\n", (stack+stack_counter-1)->name, (stack+stack_counter-1)->value);
            stackStatusR(stack, stack_counter-1);
        }  
    } 
}


void stackStatus(Processo *stack, int stack_counter){
    int i;
    for(i=0; i<stack_counter; i++){
        printf("%c : %d\n", (stack+i)->name, (stack+i)->value);
    }
}

