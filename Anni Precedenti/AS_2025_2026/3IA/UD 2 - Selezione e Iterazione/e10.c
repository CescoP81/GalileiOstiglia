/*
    Semplice programma che esegue tre diverse operazioni su numeri interi, selezionabili
    da un menu numerico con discriminazione tramite switch-case.
    Utilizzo della forma iterativa do-while.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int scelta;     // variabile per la scelta utente.
    int num;        // variabile per il numero in input dell'utente.
    int div;        // variabile per eventuali operazioni sui divisori di un numero.
    int cnt;        // variabile per conteggi tipo divisori, multipli etc...
    int sommaDiv;   // variabile per sommare i divisori di un numero.
    char junk;
    int n;          // usato nel caso 4
    int cnt2;
    int old;

    do{
        printf("-- MENU --\n");
        printf("1 -> Visualizza divisori\n");
        printf("2 -> Verifica numero primo\n");
        printf("3 -> Verifica numero perfetto\n");
        printf("4 -> Genera N numeri casuali <1000 (n inserito da tastiera)\n");
        printf("5 -> Genera n numeri dispari <1000 (n inserito da tastiera)\n");
        printf("6 -> Genera n numeri casuali crescenti <9999 (n inserito da tastiera)\n");
        printf("7 -> Genera un numero casuale, determina il successivo numero primo\n");

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
                // Determina se un numero è primo oppure no.
                // Determine whether a number is prime or not.
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                // Ciclo di conteggio divisori
                // Divider counting cycle
                cnt = 0;
                for(div=1; div<=num; div++){
                    if(num%div == 0){
                        cnt = cnt + 1;
                    }
                }

                // Verifica sul numero di divisori trovato.
                // Check the number of divisors found.
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
                // Verifica se un numero inserito da tastiera è perfetto oppure no
                // Check if a number entered from the keyboard is correct or not
                printf("Inserisci un numero: ");
                scanf("%d", &num);
                junk = getchar();

                // somma dei divisori di un numero.
                // /um of the divisors of a number.
                sommaDiv = 0;
                for(div=1; div<=num; div++){
                    if(num%div == 0){
                        sommaDiv = sommaDiv + div;
                    }
                }

                // verifica della somma e messaggio all'utente.
                // Verify the amount and message to the user.
                if(sommaDiv == (num*2)){
                    printf("Il numero %d risulta essere PERFETTO.\n", num);
                }
                else{
                    printf("Il numero %d NON risulta essere PERFETTO.\n", num);
                }
                printf("\n\n");
                break;
            }
            case 4:{
                // acquisizione numero di valori da generare.
                printf("Inserisci N: ");
                scanf("%d", &n);
                junk = getchar();

                // generazione degli N numeri random minori di 1000.
                for(cnt=1; cnt<=n; cnt++){
                    num = 1 + rand()%999;
                    printf("%4d", num);
                    if(cnt%20 == 0)
                        printf("\n");
                }
                printf("\n\n");
                break;
            }
            case 5:{
                // acquisizione numero di valori da generare.
                printf("Inserisci N: ");
                scanf("%d", &n);
                junk = getchar();

                // generazione degli N numeri random dispari minori di 1000.
                cnt = 0;
                cnt2 = 0;
                while(cnt<n){
                    num = 1 + rand()%999;
                    if(num%2 != 0){
                        printf("%4d", num);
                        cnt = cnt + 1;
                        if(cnt%20 == 0)
                            printf("\n");
                    }
                    cnt2 = cnt2 + 1;
                }
                printf("\nNumeri totali generati: %d", cnt2);
                printf("\n\n");
                break;
            }
            case 6:{
                // acquisizione numero di valori da generare.
                printf("Inserisci N: ");
                scanf("%d", &n);
                junk = getchar();

                cnt = 0;
                cnt2 = 0;
                while((cnt < n) && (cnt2<500)){
                    // genero un numero random.
                    num = rand()%10000;

                    if(cnt == 0){           // se è il primo numero lo stampo e lo assegno alla variabile old (ultimo numero estratto)
                        printf("%d ", num);
                        old = num;
                        cnt = cnt + 1;
                    }else{
                        if(num > old){      // se numero estratto è maggiore dell'ultimo generato, allora stampo e assegno ad old. Mantengo la crescenza.
                            printf("%d ", num);
                            cnt = cnt + 1;
                            old = num;

                            if(cnt%20 == 0)
                                printf("\n");
                        }
                    }
                    cnt2 = cnt2 + 1;
                }
                printf("\n\n");
                break;
            }
            case 7:{
                // acquisizione numero di valori da generare.
                printf("Inserisci N: ");
                scanf("%d", &n);
                junk = getchar();

                do{
                    n = n + 1;
                    cnt = 0;
                    for(div=1; div<=n; div++){
                        if(n%div == 0)
                            cnt = cnt + 1;
                    }
                }while(cnt > 2);
                printf("Successivo numero PRIMOo: %d", n);
                printf("\n\n");
                break;    
            }
            default:{
                if(scelta != 0){
                    printf("Scelta non valida!\n");
                    printf("\n\n");
                }
                break;
            }
        }
    }while(scelta != 0);
    return(0);
}