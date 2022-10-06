/*
    Realizzare un programma C che esegua le seguenti operazioni su un vettore
    di 10 elementi interi:
    - Caricamento del vettore da tastiera, con valori interi, univoci!
    - Calcolo della media dei valori PARI e dei valori DISPARI.
    - Determinazione se compaiono più valori pari o dispari.
*/
#include <stdio.h>
#define DIM 5

/**
 * @brief Funzione che inizializza un vettore di interi con valori univoci.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
 * */
void inputVettoreUnivoco(int[], int);
/**
 * @brief Funzione che stampa un vettore di interi.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
 * */
void stampaVettore(int[], int);

int main(){
    int vet[DIM];

    inputVettoreUnivoco(vet, DIM);
    printf("Vettore inserito: ");
    stampaVettore(vet, DIM);
    return(0);
}

void inputVettoreUnivoco(int _v[], int _d){
    int i;
    int trovato;
    int cnt;

    cnt = 0;
    while(cnt < _d){
        printf("Inserisci il valore: ");
        scanf("%d", &_v[cnt]);
        fflush(stdin);

        trovato = 0;
        for(i=0; i<cnt; i++){
            if(_v[i] == _v[cnt])
                trovato = 1;
        }

        if(!trovato)
            cnt = cnt + 1;
    }
} 

void stampaVettore(int _v[], int _d){
    int i;
    for(i=0; i<_d; i++)
        printf("%3d", _v[i]);
}
