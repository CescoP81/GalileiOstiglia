#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// COSTANTI
const int DIM = 15;
// PROTOTIPI
/**
 * Inizializza un vettore di 15 elementi interi con valori random, multipli di un valore minore di 10 passato come parametro.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @param int Parametro per i multipli.
*/
void initVettore(int _v[], int _dim, int _valore);
/**
 * Visualizza il contenuto di ogni singola cella del vettore
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void vediVettore(int _v[], int _dim);
/**
 * Determina la media del vettore, visualizza tutti i valori superiori alla media e restituisce il valore medio al main che lo visualizza.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @return Valor medio del vettore.
*/
int mediaVettore(int _v[], int _dim);
/**
 * Ricerca nel vettore un valore passato come parametro, se viene trovato ed il valore è pari allora lo azzera, altrimenti lo raddoppia.
 * Ricerca un valore v1 nel vettore e se il valore è pari lo sostituisce con v2, se è dispari gli aggiunge v2.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @param int Valore da ricercare
*/
void ricercaSostituisci(int _v[], int _dim, int _v1);
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
    int mediaVet;

    // punto 1
    printf("Punto 1\n");
    initVettore(vet, DIM, 7);
    vediVettore(vet, DIM);

    // punto 2
    printf("\nPunto 2\n");
    vediVettore(vet, DIM);
    mediaVet = mediaVettore(vet, DIM);
    printf("\nMedia calcolata: %d\n", mediaVet);

    // punto 3
    printf("\nPunto 3\n");
    ricercaSostituisci(vet, DIM, 21);
    vediVettore(vet, DIM);
    
    // punto 4
    printf("\nPunto 4\n");
    vediVettore(vet, DIM);
    if(trovaDoppi(vet, DIM) == 1)
        printf("Nel vettore sono presenti numeri uguali consecutivi.");
    else
        printf("Nel vettore non vi sono numeri uguali consecutivi.");

    return(0);
}

void initVettore(int _v[], int _dim, int _valore){
    srand(time(NULL));
    int i;
    
    if(_valore >0 && _valore<10){
        for(i=0; i<_dim; i++){
            do{
                _v[i] = rand()%100+1;
            }while(_v[i]%_valore != 0);
        }
    }
    else{
        printf("Valore di riferimento errato!\n");
    }
}

void vediVettore(int _v[], int _dim){
    int i;
    printf("Vettore: ");
    for(i=0; i<_dim; i++)
        printf("%3d", _v[i]);
    printf("\n");
}

int mediaVettore(int _v[], int _dim){
    int i;
    int somma, media;

    // calcolo la media
    somma = 0;
    for(i=0; i<_dim; i++)
        somma = somma + _v[i];
    media = somma / _dim;

    // visualizzo i valori superiori alla media
    for(i=0; i<_dim; i++){
        if(_v[i] > media)
            printf("%3d", _v[i]);
    }

    return(media);
}

void ricercaSostituisci(int _v[], int _dim, int _v1){
    int i;
    for(i=0; i<_dim; i++){
        if(_v[i] == _v1){
            if(_v1%2 == 0) //equivalente if(_v[i]%2 == 0)
                _v[i] = 0;
            else
                _v[i] = _v[i] * 2;
        }
    }
}

int trovaDoppi(int _v[], int _dim){
    int i;
    int trovato;

    trovato = 0;
    for(i=0; i<_dim-1; i++){    // mi devo fermare una cella prima, altrimenti i+1 punta fuori del vettore.
        if(_v[i] == _v[i+1])
            trovato = 1;
    }

    return(trovato);
}