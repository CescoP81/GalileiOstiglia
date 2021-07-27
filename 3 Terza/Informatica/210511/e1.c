/*
    Semplice algoritmo che richiede le misure di un rettangolo,
    intese come base e altezza, quindi disegna il rettangolo con asterischi
    ed inoltre calcola e comunica area e perimetro.
*/
#include <stdio.h>

int main(){
    int base, altezza;
    //int i, j;
    int area, perimetro;

    // 1° step -> input dei dati.
    printf("Base: ");
    scanf("%d", &base);
    fflush(stdin);
    printf("Altezza: ");
    scanf("%d", &altezza);
    fflush(stdin);

    // 2° step -> rappresento il rettangolo di asterischi.
    for(int i=1; i<=altezza; i++){
        for(int j=1; j<=base; j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\n\n");

    // 3° step -> calcolo e comunico area e perimetro
    area = base * altezza;
    perimetro = (base + altezza) * 2;
    printf("Area: %d\n", area);
    printf("Perimetro: %d\n", perimetro);
    return(0);
}
