#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM = 10;

//== Prototipi
void initVettore(int _v[], int _dim);
void generaVettore(int _v[], int _dim);
void vediVettoreGrafico(int _v[], int _dim);
// funzione che scambia il valore di due celle passate come parametro, indice1, indice2
// la funzione ritorna 1 se lo scambio è avvenuto, 0 se non è avvenuto.
int scambiaCelle(int _v[], int _dim, int _indice1, int _indice2);
// funzione che conta quanti valori sono superiori ad un valore passato per parametro
int contaValore(int _v[], int _dim, int _src);
// MAIN
int main(){
    int vet[DIM];

    initVettore(vet, DIM);
    generaVettore(vet, DIM);
    vediVettoreGrafico(vet, DIM);

    if(scambiaCelle(vet, DIM, 2, 8) == 1){
        printf("\nScambio avvenuto\n");
        vediVettoreGrafico(vet, DIM);
    }
    else{
        printf("\nProblema durante lo scambio, controllare gli indici.\n");
    }

    if(scambiaCelle(vet, DIM, 2, 12) == 1){
        printf("\nScambio avvenuto\n");
        vediVettoreGrafico(vet, DIM);
    }
    else{
        printf("\nProblema durante lo scambio, controllare gli indici.\n");
    }

    printf("Numero di valori >= di 12: %d\n", contaValore(vet, DIM, 12));

    return(0);
}

// Funzioni
void initVettore(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        _v[i] = 0;
    }
}
void generaVettore(int _v[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _v[i] = 1 + rand()%20;  // riempio il vettore con valori random compresi tra 1 e 20 (estremi compresi).
    }
}
void vediVettoreGrafico(int _v[], int _dim){
    int i;
    //printf("%c %c %c %c %c\n", 191, 192, 196, 217, 218);
    printf("%c", 218);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i!=_dim-1)
            printf("%c", 194);
    }
    printf("%c", 191);
    printf("\n");
    printf("%c", 179);
    for(i=0; i<_dim; i++){
        printf("%3d", _v[i]);
        printf("%c", 179);
    }
    printf("\n");
    printf("%c", 192);
    for(i=0; i<_dim; i++){
        printf("%c%c%c", 196,196,196);
        if(i!=_dim-1)
            printf("%c", 193);
    }
    printf("%c", 217);
    printf("\n");
    for(i=0; i<_dim; i++)
        printf("%4d", i);
    printf("\n");
}
int scambiaCelle(int _v[], int _dim, int _indice1, int _indice2){
    int tmp;
    if(_indice1<0 || _indice1>=_dim || _indice2<0 || _indice2>=_dim){
        // se entro in questo if, allora uno o entrambi gli indici non
        // appartengono al vettore perchè inferiori a zero
        // oppure superiori alla dimensione
        return(0);
    }

    tmp = _v[_indice1];
    _v[_indice1] = _v[_indice2];
    _v[_indice2] = tmp;
    return(1);
}

int contaValore(int _v[], int _dim, int _src){
    int conta;
    int i;

    conta = 0;
    for(i=0; i<_dim; i++){
        if(_v[i] >= _src)
            conta = conta + 1; //conta++ // conta +=1;
    }

    return(conta); // ritorno il numero di valori contati che rispettano il criterio.
}