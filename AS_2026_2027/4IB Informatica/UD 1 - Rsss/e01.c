#include <stdio.h>

#define DIM 5

int main(){
    int altezza[DIM];
    int i;
    char junk;
    int a_min;
    int a_media;
    int a_src;  // altezza da ricercare
    int a_cnt;  // contatore di quante volte trovo altezza da ricercare.

    // inizializzazione a zero
    for(i=0; i<DIM; i++){
        altezza[i] = 0;
    }

    // popolamento manuale dell'array
    for(i=0; i<DIM; i++){
        printf("Inserisci la %d altezza: ", i+1);
        scanf("%d", &altezza[i]);
        junk = getchar();
    }

    // stampa dei valori inseriti come verifica dell'avvenuto inserimento.
    for(i=0; i<DIM; i++){
        printf("%d ", altezza[i]);
    }
    printf("\n\n");
    //--------- QUELLO CHE SCRITTO SOPRA NON DEVE ESSERE TOCCATO PERCHE' FUNZIONA!

    // calcolo e stampo altezza minima.
    a_min = altezza[0];
    for(i=1; i<DIM; i++){
        if(altezza[i] < a_min)
            a_min = altezza[i];
    }
    printf("Altezza minima rilevata: %d\n", a_min);

    // calcolo e stampo l'altezza media tra quelle presenti.
    a_media = 0;
    for(i=0; i<DIM; i++){
        a_media = a_media + altezza[i];
    }
    a_media = a_media / DIM;
    printf("Altezza media del vettore: %d\n", a_media);

    // ricerca e conteggio di una determinata altezza.
    printf("Quale altezza cerchi: ");
    scanf("%d", &a_src);
    junk = getchar();

    a_cnt = 0;
    for(i=0; i<DIM; i++){
        if(altezza[i] == a_src){
            a_cnt = a_cnt + 1;
        }
    }
    printf("L'altezza %d compare %d volta/e.\n", a_src, a_cnt);

    // comunico quali celle contengono altezze inferiori alla media.
    for(i=0; i<DIM; i++){
        if(altezza[i] < a_media)
            printf("Cella %d presenta un'altezza inferiore alla media(%d)\n", i, altezza[i]);
    }

    return 0;
}