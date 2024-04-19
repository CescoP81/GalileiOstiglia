#include <stdio.h>

const int NBIT = 16;

//== prototipi

/**
 * Converte un numero decimale in formato binario a 8 bit.
 * @param int[] Vettore a 8 bit interi per i resti 0/1.
 * @param int Dimensione del vettore (mi serve per i cicli).
 * @param int Valore in base 10 da convertire in base 2.
*/
void convertiBinario(int _v[], int _dim, int _valore);

/**
 * Visualizza un vettore rappresentante un numero binario, la visualizzazione viene eseguita dalla cella n-1 fino a 0 compresa.
 * @param int[] Vettore contenente i bit del numero binario.
 * @param int Dimensione del vettore.
*/
void visualizzaBinario(int _v[], int _dim);

void visualizzaBinarioGrafico(int _v[], int _dim);
//== MAIN
int main(){
    int b1[NBIT];
    int n1 = 23;
    
    convertiBinario(b1, NBIT, n1);
    visualizzaBinario(b1, NBIT);
    printf("\n\n");
    visualizzaBinarioGrafico(b1, NBIT);
    return(0);
}

//== definzione delle funzioni.
void convertiBinario(int _v[], int _dim, int _valore){
    int i;
    for(i=0; i<_dim; i++){
        _v[i] = _valore % 2;        // calcolo il resto della divisione per 2 e lo metto nella cella del vettore.
        _valore = _valore / 2;      // divido effettivamente il valore per 2.
    }
}

void visualizzaBinario(int _v[], int _dim){
    int i;
    for(i=_dim-1; i>=0; i--){
        printf("%d", _v[i]);
    }
}

/*
    Realizzare la visione in formato grafico del vettore contenente i Bit, 
    i caratteri da stamapre come bordi attorno alle celle li trovate nella ASCII table
    dal valore 169 in avanti, prave a realizzare la visuali qui sotto:
    ---------------------------------
    |  0|  1|  0|  1|  0|  0|  1|  0|
    ---------------------------------
       7   6   5   4   3   2   1   0
*/
void visualizzaBinarioGrafico(int _v[], int _dim){
    printf("%c\n", 180);
    printf("%c\n", 191);
}