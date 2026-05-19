#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

int trovaUnAmico(int _n){
    
    int sommaCifreN;
    int sommaCifreR;
    int r;
    int tmp;

    // calcolo la somma delle cifre del numero originale
    sommaCifreN = 0;
    while(_n > 0){
        sommaCifreN += _n % 10;
        _n = _n / 10;
    }
    printf("%d ", sommaCifreN);
    srand(time(NULL));
    do{
        r = 1 + rand()%750;                 // genero un numero random
        sommaCifreR = 0;
        tmp = r;                            // mi salvo il random in tmp visto che poi lo scompongo e lo perdo
        while(r>0){                         // calcolo la somma cifre del numero random
            sommaCifreR += r % 10;
            r = r / 10;
        }
    }while(sommaCifreN != sommaCifreR);     // ciclo finche le due somme sono diverse, quando uguali la condizione è falsa e in tmp ho un numero valido.
    printf("-%d %d- ", sommaCifreN, sommaCifreR);
    return(tmp);
}

int inputPrime(int _n1, int _n2){
    int val;
    int div;
    int cntDiv;
    char junk;

    if(_n1 < _n2){
        do{
            printf("Inserisci un valore primo tra %d e %d: ", _n1, _n2);
            scanf("%d", &val);
            junk = getchar();

            div = 2;
            cntDiv = 0;
            while(div < val){
                if(val%div == 0)
                    cntDiv++;
                div++;
            }
        }while(cntDiv != 0 || val < _n1 || val > _n2);
        return(val);
    }
    else
        return(-1);
}

int numeroDivisori(int _n){
    int divP;
    int divD;
    int div;

    divP = 0;
    divD = 0;
    div = 1;
    while(div <= _n){
        if(_n % div == 0){
            if(div%2 == 0)
                divP++;
            else
                divD++;
        }
        div++;
    }
    printf("Numero divisori pari: %d\n", divP);
    printf("Numero divisori dispari: %d\n", divD);
    return(divP+divD);
}

void tabellinaMascherata(int _n){
    int r;
    int c;

    for(r=1; r<=10; r++){
        for(c=1; c<=10; c++){
            if(r==_n || c==_n)
                printf("%3d", (r*c));
            else
                printf("  *");
        }
        printf("\n");
    }
}