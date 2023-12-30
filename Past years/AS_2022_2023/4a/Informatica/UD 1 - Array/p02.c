/*
    Realizzare un programma C che esegua le seguenti operazioni su un vettore
    di 10 elementi interi:
    - Caricamento del vettore da tastiera, con valori interi, univoci!
    - Calcolo della media dei valori PARI e dei valori DISPARI.
    - Determinazione se compaiono più valori pari o dispari.

    - Copia tra vettori di stessa dimensione.
    - Moltiplica vettore per fattore x.
    - Ricerca valore nel vettore e restituzione prima posizione valida.
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
/**
 * @brief Copia vettore src in dst
 * @param int[] Vettore sorgente
 * @param int[] Vettore destinazione
 * @param int Dimensione dei vettori
*/
void copiaVettore(int[], int[], int);
/**
 * @brief Funzione che moltiplica il contenuto di un vettore per un fattore x
 * @param int[] Vettore da utilizzare.
 * @param int Dimensione del vettore.
 * @param int Fattore moltiplicativo
*/
void moltiplicaVettore(int[], int, int);
/**
 * @brief Ricerca valore nel vettore, restituzione primo indice valido
 * @param int[] Vettore da utilizzare
 * @param int Dimensione del vettore
 * @param int Valore da cercare
 * @return int Indice del valore trovato.
*/
int ricercaValoreVettore(int[], int, int);

int main(){
    int vet[DIM];
    int vet2[DIM];
    int index;

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
    printf("\n\n");

    copiaVettore(vet, vet2, DIM);
    printf("Vettore 2 come copia di vett: ");
    stampaVettore(vet2, DIM);
    printf("\n\n");

    printf("Vettore moltiplicato x4: ");
    moltiplicaVettore(vet, DIM, 4);
    stampaVettore(vet, DIM);
    printf("\n\n");

    index = ricercaValoreVettore(vet, DIM, 26);
    if(index != -1)
        printf("Valore trovato nella posizione: %d", index);
    else{
        printf("Valore non trovato");
    }

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

void copiaVettore(int _src[], int _dst[], int _d){
    int i;
    for(i=0; i<_d; i++){
        _dst[i] = _src[i];
    }
}

void moltiplicaVettore(int _v[], int _d, int _x){
    int i;
    for(i=0; i<_d; i++){
        _v[i] = _v[i] * _x; // _v[i] *= _x;
    }
}

int ricercaValoreVettore(int _v[], int _d, int _src){
    int i;
    for(i=0; i<_d; i++){
        if(_v[i] == _src)
            return(i);
    }
    return(-1);
}