#include <stdio.h>

const int RIGHE = 5;
const int COLONNE = 20;

// per passare una matrice ad una funzione oltre al nome
// dobbiamo specificare anche le due dimensioni
// ricordarsi che la prima dimensione è il numero delle righe, mentre la seconda
// è il numero delle colonne.
void input(char _parole[RIGHE][COLONNE]);

int main(){
    char parole[RIGHE][COLONNE];

    input(parole);

    printf("\n\n");
    for(int i=0; i<RIGHE; i++){
        printf("%s ", parole[i]);
    }
    return(0);
}

void input(char _parole[RIGHE][COLONNE]){
    int i;
    for(i=0; i<RIGHE; i++){
        printf("Inserisci: ");
        // nella gets utilizzo la matrice in cui salvare le parole, e specifico l'indice della
        // riga, non metto nessun indice per la colonna (seconda dimensione).
        gets(_parole[i]); 
    }
}