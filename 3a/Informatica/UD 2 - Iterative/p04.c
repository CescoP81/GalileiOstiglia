/*
Algoritmo che visualizza una tabellina a scelta tra i primi 10 numeri naturali,
le altre tabelline sono sostituite da un carattere '#'.
Deve prevedere il controllo sull'input della tabellina scelta.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    // dichiaro le variabili
    int riga;
    int colonna;
    int riga_scelta;

    system("CLS");
    // ciclo di richiesta della riga da visualizzare, con controllo sull'input
    do{
        printf("Scelgi una tabellina da 1 a 10: ");
        scanf("%d", &riga_scelta);
        fflush(stdin);
    }while(riga_scelta<1 || riga_scelta>10);

    // Cicli innestati per la creazione della tabella
    riga = 1;
    while(riga <= 10){
        colonna = 1;
        while(colonna <= 10){
            if(riga == riga_scelta){
                printf("%4d", (riga*colonna));
            }
            else{
                printf(" ###");
            }
            colonna = colonna + 1;
        }
        printf("\n");
        riga = riga + 1;
    }
    return(0);
}