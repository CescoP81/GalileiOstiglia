#include <stdio.h>

int main(){
    int scelta;     // variabiler per memorizzare la scelta utente
    char junk;      // variabile di comodo
    int num;        // variabile per input valore dell'utente.
    int div;        // variabile per cicli dei divisori.
    int cnt;        // variabile contatore o accumulatore.

    do{
        printf("---------\n");
        printf("1 -> Verifica PRIMO\n");
        // da realizzare
        printf("2 -> Visualizza divisori\n");
        printf("3 -> Verifica numero perfetto\n");
        printf("0 -> TERMINA PROGRAMMA\n");
        printf("scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                // Determina se un numero acquisito da tastiera è primo oppure no.
                // fase di input valore

                // Determines whether a number entered from the keyboard is prime or not.
                // value input phase
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                // conteggio dei divisori di un numero
                cnt = 0;
                for(div=1; div <= num; div++){
                    if(num%div == 0)
                        cnt = cnt + 1;
                }
                // stampa del messaggio in base al numero di divisori trovati.
                if(cnt <= 2){
                    printf("Il numero %d risulta essere PRIMO!\n", num);
                }
                else{
                    printf("Il numero %d NON risulta essere PRIMO\n", num);
                }
                break;
            }
            case 2:{
                printf("Sono entrato nella scelta 2...\n");
                break;
            }
            case 3:{
                printf("Sono entrato nella scelta 3...\n");
                break;
            }
            default:{
                printf("Scelta non valida...\n");
                break;
            }
        }
        printf("\n\n");
    }while(scelta != 0);
    return(0);
}