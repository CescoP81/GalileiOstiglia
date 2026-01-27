/*
    Semplice programma che esegue tre diverse operazioni su numeri interi, selezionabili
    da un menu numerico con discriminazione tramite switch-case.
    Utilizzo della forma iterativa do-while.
*/
#include <stdio.h>

int main(){
    int scelta;     // variabile per la scelta utente.
    int num;        // variabile per il numero in input dell'utente.
    int div;        // variabile per eventuali operazioni sui divisori di un numero.
    int cnt;        // variabile per conteggi tipo divisori, multipli etc...
    char junk;

    do{
        printf("-- MENU --\n");
        printf("1 -> Visualizza divisori\n");
        printf("2 -> Verifica numero primo\n");
        printf("3 -> Verifica numero perfetto\n");
        printf("0 -> Termina Programma!\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                // Visualizza a video i divisori di un numero intero acquisito da tastiera.
                // Displays on screen the divisors of an integer entered from the keyboard.
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                // Determina i divisori di un numero contenuto nella variabile num
                // Determines the divisors of a number contained in the variable num
                for(div=1; div<=num; div++){
                    if(num%div == 0){
                        printf("%d ", div);
                    }    
                }
                printf("\n\n");
                break;
            }
            case 2:{
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                cnt = 0;
                for(div=1; div<=num; div++){
                    if(num%div == 0){
                        cnt = cnt + 1;
                    }
                }

                if(cnt <= 2){
                    printf("Il numero %d risulta PRIMO\n", num);
                }
                else{
                    printf("Il numero %d NON risulta essere PRIMO\n", num);
                }
                printf("\n\n");
                break;
            }
            case 3:{
                printf("Sono nel caso 3...\n");
                break;
            }
        }

    }while(scelta != 0);
    return(0);
}