#include <stdio.h>

int main(){
    int v1,v2;          // variabili per i valori inseriti da utente.
    int mcm,MCD;        // variabili per i valori che devo determinare.
    int min,max;        // Variabili per i valori minimo e massimo.
    int i;

    // step 1: input controllato dei due valori, condizione siano > di zero.
    do{
        printf("Inserisci un valore: ");
        scanf("%d", &v1);
        fflush(stdin);
    }while(v1 <= 0);

    do{
        printf("Inserisci un valore: ");
        scanf("%d", &v2);
        fflush(stdin);
    }while(v2 <= 0);

    // step 2: determino il minimo e il massimo
    if(v1<v2){
        min = v1;
        max = v2;
    }
    else{
        min = v2;
        max = v1;
    }
    
    if(v1 != v2){
        // step 3: minimo comune multiplo.
        mcm = max;
        while((mcm%v1!=0) || (mcm%v2!=0)){
            mcm = mcm+1;
        }
        printf("\nIl minimo comune multiplo e': %d\n\n", mcm);
    
        // step 4: massimo comun divisore
        for(i=1; i<=min; i++){
            if(v1%i==0 && v2%i==0)
                MCD = i;
        }
        printf("Il massimo comun divisore e': %d\n", MCD);
    }
    return(0);
}