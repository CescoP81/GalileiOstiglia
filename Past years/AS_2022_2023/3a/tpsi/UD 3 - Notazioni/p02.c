/* Perogramma che codifica un numero in virgola a base 10 in numero binario con notazione fissa; tutti i bit sono assegnati alla parte decimale
    il numero inserito quindi deve essere nella forma 0.xxxx */
#include <stdio.h>
#include <math.h>

#define DIM 8

int main(){
    float nf;
    int bin[DIM];
    int i;
    float pot;
    float verifica;

    // Inserimento di un numero da convertire con parte intera pari a zero.
    printf("Inserisci un numero(0,xxx): ");
    scanf("%f", &nf);
    fflush(stdin);

    if(!(int)nf){ // equivalente a scrivere if((int)nf == 0)
        // eseguo la conversione della parte decimale per moltiplicazioni successive e tenendo sempre la parte decimale per la moltiplica successiva.
        // la parte intera ottenuta è il bit da assegnare al vettore.
        nf = nf * 2;
        for(i=0; i<DIM; i++){
            printf("%d -> ", (int)nf);
            bin[i] = (int)nf;
            nf = nf - (int)nf;
            nf = nf * 2;
            printf("%f\n", nf);
        }

        // visualizzo il binario ottenuto e con la funzione pow e variabile verifica vado a verificare il numero ottenuto.
        verifica = 0.0;
        printf("\n\nConvertito:\n");
        for(i=0; i<DIM; i++){
            printf("%d", bin[i]);
            
            //printf("%d -> ", bin[i]);
            pot = bin[i] * (1/ pow(2, i+1));
            //printf("%d %f\n", i+1, pot);
            verifica = verifica + pot;        
        }
        printf("\nVerifica: %f", verifica);
    }
    else{
        printf("ERRORE: il numero non e' nella formula 0.xxx, parte intera a zero.");
    }
    return(0);
}