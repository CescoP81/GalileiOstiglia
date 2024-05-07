#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// COSTANTI
const int DIM = 15;
// PROTOTIPI
/**
 * Inizializza un vettore di 15 elementi interi con valori random compresi tra 10 e 30 estremi esclusi.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void initVettore(int _v[], int _dim);
/**
 * Visualizza il contenuto di ogni singola cella del vettore
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void vediVettore(int _v[], int _dim);
/**
 * Ricerca un valore v1 nel vettore e se il valore è pari lo sostituisce con v2, se è dispari gli aggiunge v2.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @param int Valore da ricercare
 * @param int Valore sostitutivo.
*/
void ricercaSostituisci(int _v[], int _dim, int _v1, int _v2);
/**
 * Determina il valore massimo e visualizza in quali posizioni compare, ritorna al main il valore massimo determinato.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @return Valore massimo presente nel vettore.
*/
int massimoVettore(int _v[], int _dim);
/**
 * Verifica se vi sono valori uguali adiacenti nel vettore. Ritorna al main il valore 1 se la verifica è positiva,
 * 0 se è negativa. (es 14 15 20 20 27 12. il valore 20 si ripete su due celle adiacenti).
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @return 1 se sono stati trovati doppioni, 0 se non sono stati trovati.
*/
int trovaDoppi(int _v[], int _dim);
// MAIN
int main(){
    int vet[DIM];
    int maxVet;

    // punto 1
    printf("Punto 1\n");
    initVettore(vet, DIM);
    vediVettore(vet, DIM);

    // punto 2
    printf("\nPunto 2\n");
    ricercaSostituisci(vet, DIM, 15, 10);
    vediVettore(vet, DIM);

    // punto 3
    printf("\nPunto 3\n");
    vediVettore(vet, DIM);
    maxVet = massimoVettore(vet, DIM);
    printf("Valore massimo determinato: %d\n", maxVet);

    // punto 4
    printf("\nPunto 4\n");
    vediVettore(vet, DIM);
    if(trovaDoppi(vet, DIM) == 1)
        printf("Nel vettore sono presenti numeri uguali consecutivi.");
    else
        printf("Nel vettore non vi sono numeri uguali consecutivi.");

    return(0);
}

// FUNZIONI
void initVettore(int _v[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _v[i] = 10+1+(rand()%(30 - 10 - 1));
    }
}

void vediVettore(int _v[], int _dim){
    int i;
    printf("Vettore: ");
    for(i=0; i<_dim; i++)
        printf("%3d", _v[i]);
    printf("\n");
}

void ricercaSostituisci(int _v[], int _dim, int _v1, int _v2){
    int i;
    for(i=0; i<_dim; i++){
        if(_v[i] == _v1){
            if(_v1%2 == 0)  // equivalente if(_v[i]%2 == 0)
                _v[i] = _v2;
            else
                _v[i] = _v[i] + _v2;
        }
    }
}

int massimoVettore(int _v[], int _dim){
    int i;
    int max;

    // determino il valore massimo presente nel vettore.
    max = _v[0];
    for(i=1; i<_dim; i++){
        if(_v[i] > max)
            max = _v[i];
    }

    // lo ricerco nel vettore e quando lo trovo stampo la posizione (indice)
    for(i=0; i<_dim; i++){
        if(_v[i] == max)
            printf("_v[%d], ", i); // corretto anche mettere i+1 cioè secondo la notazione "umana".
    }
    printf("\n");
    return(max);
}

int trovaDoppi(int _v[], int _dim){
    int i;
    int trovato;

    trovato = 0;
    for(i=0; i<_dim-1; i++){ // mi devo fermare una cella prima, altrimenti i+1 punta fuori del vettore.
        if(_v[i] == _v[i+1])
            trovato = 1;
    }

    return(trovato);
}