/*
    Realizzare un programma C che esegua le seguenti operazioni su un vettore
    di 10 elementi interi:
    - Caricamento del vettore da tastiera, con valori interi, univoci!
    - Calcolo della media dei valori PARI e dei valori DISPARI.
    - Determinazione se compaiono più valori pari o dispari.

    - Copia tra vettori di stessa dimensione.
    - Moltiplica vettore per fattore x.
    - Ricerca valore nel vettore e restituzione prima posizione valida.
    - 
*/
#include <stdio.h>
#define DIM 6

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
/**
 * @brief Funzione che calcola la media dei valori pari o dispari del vettore.
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
 * @param int Flag 0/Pari - 1/Dispari.
 * @return float Media dei valori calcolati.
*/
float mediaValori(int[], int, int);

/**
 * @brief Funziona che determina se nel vettore compaiono più valori pari o dispari
 * @param int[] Vettore da utilizzare
 * @param int Dimensione del vettore
 * @return int Flag 0/Pari 1/Dispari -1/Ugual numero pari e dispari.
*/
int contaPariContaDispari(int[], int);

int main(){
    int vet[DIM];

    inputVettoreUnivoco(vet, DIM);
    printf("Vettore inserito: ");
    stampaVettore(vet, DIM);
    printf("\n\n");

    printf("Media dei valori pari: %.2f\n", mediaValori(vet, DIM, 0));
    printf("Media dei valori dispari: %.2f\n", mediaValori(vet, DIM, 1));
    printf("\n\n");

    if(contaPariContaDispari(vet,DIM) == 1)
        printf("Nel vettore sono presenti più valori dispari.\n");
    if(contaPariContaDispari(vet,DIM) == 0)
        printf("Nel vettore sono presenti più valori pari.\n");
    if(contaPariContaDispari(vet,DIM) == -1)
        printf("Nel vettore sono presenti tanti pari quanti dispari.\n");
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

float mediaValori(int _v[], int _d, int _pd){
    int somma=0;
    int i;
    int cnt = 0;

    for(i=0; i<_d; i++){
        if(_v[i]%2 == _pd){
            somma = somma + _v[i];
            cnt++;
        }
    }
    return((float)somma/cnt);
}

int contaPariContaDispari(int _v[], int _d){
    int i;
    int cntPari, cntDispari;

    cntPari = 0;
    cntDispari = 0;
    for(i=0; i<_d; i++){
        if(_v[i]%2 == 0)
            cntPari++;
        else
            cntDispari++;
    }
    if(cntPari == cntDispari) return(-1);
    if(cntPari > cntDispari) return(0);
    else return(1);
}
