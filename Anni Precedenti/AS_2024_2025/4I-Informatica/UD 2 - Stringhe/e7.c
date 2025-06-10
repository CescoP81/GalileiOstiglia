/** Per passare una matrice ad una funzione oltre al nome
 * dobbiamo specificare anche le due dimensioni ricordarsi che la prima dimensione è il numero delle righe,
 * mentre la seconda è il numero delle colonne.
*/
#include <stdio.h>

const int RIGHE = 5;
const int COLONNE = 20;

void setParole(char _parole[RIGHE][COLONNE], int _nrParole);
void listaParole(char _parole[RIGHE][COLONNE], int _nrParole);
void contaVocali(char _parole[RIGHE][COLONNE], int _nrParole);

int main(){
    char parole[RIGHE][COLONNE];

    setParole(parole, 3);
    printf("\n\n");
    listaParole(parole, 3);
    printf("\n\n");
    contaVocali(parole, 3);
    return(0);
}
void setParole(char _parole[RIGHE][COLONNE], int _nrParole){
    int i;
    for(i=0; i<_nrParole; i++){
        printf("Inserisci la parola %d: ", i+1);
        // nella gets utilizzo la matrice in cui salvare le parole, e specifico l'indice della
        // riga, non metto nessun indice per la colonna (seconda dimensione).
        gets(_parole[i]); 
    }
}
void listaParole(char _parole[RIGHE][COLONNE], int _nrParole){
    int i;
    printf("Lista delle parole presenti:\n");
    for(int i=0; i<_nrParole; i++){
        printf("%s\n", _parole[i]);
    }
}
void contaVocali(char _parole[RIGHE][COLONNE], int _nrParole){
    int i;
    int j;
    int cnt;

    for(i=0; i<_nrParole; i++){
        cnt = 0;
        j = 0;
        while(_parole[i][j] != '\0'){
            if(_parole[i][j] == 'a')
                cnt++;
            if(_parole[i][j] == 'e')
                cnt++;
            if(_parole[i][j] == 'i')
                cnt++;
            if(_parole[i][j] == 'o')
                cnt++;
            if(_parole[i][j] == 'u')
                cnt++;
            j++;
        }
        printf("Vocali in %s: %d\n", _parole[i], cnt);
    }
}