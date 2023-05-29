#include <conio.h>

int main(){
    int val1, val2;     // valori di partenza di cui trovare i divisori comuni.
    int div;            // variabile per il ciclo dei divisori.
    int min_val;        // variabile in cui mettere il minimo tra i due valori iniziali.
    int i;

    val1 = 18;
    val2 = 36;

    if(val1<val2)    min_val = val1;
    else    min_val = val2;

    // ciclo for dei divisori da 1 al valore minimo compreso.
    for(div=1; div<=min_val; div++){
        if((val1%div == 0) && (val2%div == 0))
            printf("%d divisore di val1 e val2\n", div);
        
        /* condizione alternativa, if innestate
        if(val1%div == 0){
            if(val2%div == 0){
                printf("%d divisore di val1 e val2\n", div);
            }
        }*/
    }

    // ciclo while
    div = 1;
    while(div <= min_val){
        if((val1%div == 0) && (val2%div == 0))
            printf("%d divisore di val1 e val2\n", div);
        
        /* condizione alternativa, if innestate
        if(val1%div == 0){
            if(val2%div == 0){
                printf("%d divisore di val1 e val2\n", div);
            }
        }*/
        div = div + 1; // div++;
    }

    // supponendo val1 < val2
    // ciclo da val1 a val2
    for(i=val1; i<=val2; i++){
        printf("%d ", i);
    }

    // ciclo da val2 a val1
    for(i=val2; i>=val1; i--){
        printf("%d", i);
    }
}