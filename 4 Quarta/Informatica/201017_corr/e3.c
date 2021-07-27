#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DIM 5

void riempi_mat(int [][DIM]);
void riempi_vet(int []);
int match(int [][DIM], int []);

int main(){
    srand(time(NULL));
    int mat[DIM][DIM];
    int vet[DIM];
    int x;

    riempi_mat(mat);
    riempi_vet(vet);

    x = match(mat,vet);
    if(!x)
        printf("Vettore non presente come colonna matrice");
    else
        printf("Vettore corrispoindente in nr. %d colonne", x);    
    return(0);   
}

/* funzione che inizializza la matrice 5x5 con valori random 1-9 */
void riempi_mat(int m[][DIM]){
    int i,j;
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            m[i][j] = rand()%9+1;
        }
    }

    // stampo per "controllo", ma potrei evitare.
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* funzione che inizializza il vettore di 5 elementi  con valori random 1-9 */
void riempi_vet(int v[]){
    int i;
    for(i=0; i<DIM; i++){
        v[i] = rand()%9+1;
    }

    for(i=0; i<DIM; i++){
        printf("%d ",v[i]);
    }
    printf("\n\n");
}

/* funzione che confronta il vettore con ogni COLONNA della matrice,
    se tutti i valori corrispondono viene incrementato il contatore trovato.
    ritorna al mail il numero di volte che il vettore è uguale ad una colonna
*/
int match(int m[][DIM], int v[]){
    int i,j;
    int cnt;
    int trovato;

    trovato = 0;
    for(i=0; i<DIM; i++){
        cnt = 0;
        for(j=0; j<DIM; j++){
            if(v[j] == m[j][i])
                cnt++;
        }
        if(cnt == DIM)
            trovato++;
    }
    return(trovato);
}