/*
Realizzare un programma C che richieda ripetutamente l’inserimento di 10 valori, per ogni valore inserito
comunica se è un valore pari o dispari, il numero di divisori (compreso se stesso), se è un numero perfetto.
*/
#include <stdio.h>

int main(){
    int cnt;                // numero delle ripetizioni di input
    int n;                  // valore inserito dall'utente
    int divisore;           // variabile per il ciclo dei divisori.
    int numeroDivisori;     // conteggio dei divisori di un numero.
    int sommaDivisori;      // somma dei divisori trovati per un numero (mi serve per il perfetto)
    char junk;

    cnt = 1;
    while(cnt <= 3){
        printf("Inserisci un numero: ");
        scanf("%d", &n);
        junk = getchar();

        if(n % 2 == 0)
            printf("E' un numero pari!\n");
        else
            printf("E' un numero dispari!\n");
        
        divisore = 1;
        sommaDivisori = 0;
        numeroDivisori = 0;
        while(divisore <= n){
            if(n%divisore == 0){    // se trovo un divisore del numero inserito
                numeroDivisori = numeroDivisori + 1;
                sommaDivisori = sommaDivisori + divisore;
            }
            divisore = divisore + 1;
        }

        // comunico il numero divisori e se la somma è uguale al doppio del numero allora è perfetto.
        printf("Numero divisori: %d\n", numeroDivisori);
        if(sommaDivisori == (n*2))
            printf("Il numero e' PERFETTO\n");
        printf("----------\n");

        cnt = cnt + 1;
    }
    return(0);
}