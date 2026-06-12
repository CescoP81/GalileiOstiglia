/*
Realizzare un programma C che permetta l’inserimento di 10 valori interi, per ogni valore inserito comunica i
divisori indicando con P se pari o D se dispari e se il valore è un numero primo oppure no.
*/
#include <stdio.h>

int main(){
    int valIn;  // valore in input;
    int cnt;    // contatore ciclo di input = 10
    int cntDiv; // contatore per i divisori
    int div;    // variabile per i divisori.
    char junk;

    cnt = 1;
    while(cnt <= 3){
        printf("Inserisci un valore: ");
        scanf("%d", &valIn);
        junk = getchar();

        cntDiv = 0;
        div = 1;
        while(div <= valIn){
            if(valIn%div == 0){
                printf("%d -> ", div);
                if(div%2 == 0)
                    printf("P\n");
                else
                    printf("D\n");
                cntDiv = cntDiv + 1;
            }
            div = div + 1;
        }
        
        if(cntDiv <= 2)
                printf("%d e' un primo\n\n", valIn);
        cnt = cnt + 1; // aumento il contatore dei numeri inseriti.
    }
    return(0);
}