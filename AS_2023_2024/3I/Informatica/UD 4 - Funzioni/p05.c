/*
Realizzare un programma che utilizzando Funzioni, switch-case e cicli realizzi i seguenti algoritmi:
- [ ] Visualizza e conta i divisori di un numero (usando il FOR).
- [ ] Genera N numeri casuali maggiori di zero e minori di 100, con N passato come parametro.
- [ ] Visualizza un rettangolo di '#' con base e altezza ricevuti come parametri.
*/
#include <stdio.h>
#include <stdlib.h> // utile per random
#include <time.h>   // utile per random

void divisoriNumero(int _n);
void generaCasuali(int _n);
void disegnaRettangolo(int _base, int _altezza);

int main(){
    int scelta; // utilizzata per la scelta dell'utente dal menu proposto.
    int numero; // variabile per il case 1.
    int b, h;   // variabili per il case 3.

    do{
        printf("\n == MENU ==\n");
        printf("1 -> Divisori di un numero.\n");
        printf("2 -> Numeri random.\n");
        printf("3 -> Rettangolo di ash.\n");
        printf("0 -> USCITA.\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        fflush(stdin);

        switch(scelta){
            case 1:{
                printf("Inserisci un numero: ");
                scanf("%d", &numero);
                fflush(stdin);
                divisoriNumero(numero);
                break;
            }
            case 2:{
                printf("Quanti casuali generare: ");
                scanf("%d", &numero);
                fflush(stdin);
                generaCasuali(numero);
            }
            case 3:{
                printf("Inserisci la base: ");
                scanf("%d", &b);
                fflush(stdin);
                printf("Inserisci altezza: ");
                scanf("%d", &h);
                fflush(stdin);
                disegnaRettangolo(b, h);
                break;
            }
        }
        printf("\n\n"); // andata a capo del messaggio di pausa.
        system("PAUSE");
    }while(scelta != 0);
    return(0);
}

void divisoriNumero(int _n){
    int div; // variabile per testare i divisori con un ciclo.
    int cnt; // variabile per contare i divisori trovati.

    cnt = 0;
    for(div=1; div<=_n; div++){
        if(_n%div == 0){ // significa che div è un divisore di _n
            printf("%d ", div);
            cnt = cnt + 1;
        }
    }
    printf("\nNumero divisori trovati: %d\n", cnt);
}

void generaCasuali(int _n){
    srand(time(NULL));
    int i; // variabile per il ciclo di generazione numeri random.
    int nRandom; // variabile per il numero random generato.

    for(i=1; i<=_n; i++){
        nRandom = 1 + rand()%99;
        printf("%d ", nRandom);
    }
}

void disegnaRettangolo(int _base, int _altezza){
    int r, c; // variabili per i cicli righe e colonna.
    for(r=1; r<=_altezza; r++){
        for(c=1; c<=_base; c++){
            printf("# ");
        }
        printf("\n");
    }
}