/* Programma che richiede un numero da tastiera intero positivo,
se il numero è inferiore a 25 allora mostra tutti i valori dal valore
inserito fino al valore 50; altrimenti visualizza un messaggio generico
"Serie non realizzabile".
*/
#include <stdio.h>

int main(){
    int val; // variabile per valore inserito dall'utente.
    int tmp; // variabile per l'iterativa while.
    char junk; // variabile di comodo per pulire il buffer di tastiera.
    int sommaDivisori; // utilizzo per sommare tutti i divisori di un numero.

    // 1. richiesta del valore all'utente.
    printf("Inserisci un valore: ");
    scanf("%d", &val);
    junk = getchar();

    // test sul valore inserito
    if((val < 25) && (val>0)){
        // costruiamo l'iterativa per visualizzare tutti i valori da val fino a 50
        tmp = val;
        while(tmp <= 50){
            printf("%d ", tmp);
            tmp = tmp + 1; //tmp++;
        }

        // costruiamo l'iterativa per visualizzare SOLO i valori pari
        printf("\n");
        tmp = val;
        while(tmp <= 50){
            if(tmp%2 == 0){
                printf("%d ", tmp);
            }
            tmp = tmp + 1;
        }

        // visualizzare tutti i valori dispari e divisibili per 3
        printf("\nDispari e divisibili per 3: ");
        tmp = val;
        while(tmp<=50){
            if((tmp%2==1) && (tmp%3==0)){
                printf("%d ", tmp);
            }
            tmp = tmp + 1;
        }

        // visualizzare tutti i divisori di VAL
        printf("\nDivisori di VAL: ");
        tmp = 1;
        while(tmp <= val){
            if(val%tmp == 0){
                printf("%d ", tmp);
            }
            tmp = tmp + 1;
        }

        // Verificare se un numero è perfetto: la somma dei divisori di un numero è uguale 
        // al doppio del numero stesso.
        printf("\nNumero perfetto?: ");
        tmp = 1;
        sommaDivisori = 0;
        while(tmp <= val){
            if(val%tmp == 0){
                sommaDivisori = sommaDivisori + tmp;
            }
            tmp = tmp + 1;
        }
        
        if(sommaDivisori == (val*2)){
            printf("Confermato!");
        }
        else{
            printf("Risultato negativo.");
        }
    }
    else{
        printf("Serie non realizzabile...\n");
    }
    return(0);
}