#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define DIM 8

// prototipi
/* Funzione che codifica un valore decimale in un vettore di 8 bit.
@param int Numero in base 10 da convertire in binario.
@param int[] Vettore in cui codificare il valore decimale.
@return void*/ 
void decToBin(int, int[]);

/* Funzione che riceve un vettore contente la codifica binaria e lo stampa al contrario.
@param int[] Vettore contenente la condifica binaria.
@return void*/
void printBin(int[]);

/* Funzione che calcola e restituisce la somma tra due vettori binari.
@param int[] Vettore binario 1.
@param int[] Vettore binario 2.
@param int[] Vettore binario risultate dalla somma.
@return int Bit di overflow: 1 c'è overflow / 0 non vi è overflow.*/
int sommaBin(int[], int[], int[]);

/* Funzione che realizza il complemento a 2 di un numero binario
@param int[] Vettore di bit binari.
@return void*/
void complementoDue(int []);

/* Funzione che inverte tutti i bit di un numero binario
@param int[]  Vettore di bit binari
@return void. */
void invertiBinario(int []);

int main(){
    int a, b;
    int bin1[DIM];  // vettori per la codifica in binario.
    int bin2[DIM];
    int bin3[DIM];  // vettore per la somma di bin1 + bin2
    int overflow;

    printf("Inserisci a: ");
    scanf("%d", &a);
    fflush(stdin);

    printf("Inserisci b: ");
    scanf("%d", &b);
    fflush(stdin);

    // condificare a e b nei rispettivi vettori bin1 e bin2
    decToBin(a, bin1);
    decToBin(b, bin2);

    // stampo i due vettori:
    printf("\nBin1: ");
    printBin(bin1);
    printf("\nBin2: ");
    printBin(bin2);

    overflow = sommaBin(bin1, bin2, bin3);
    if(overflow == 0){
        printf("\n\nBin3: ");
        printBin(bin3);
    }
    else{
        printf("\n!!OVERFLOW!! risultato non codificabile in 8 bit!\n");
    }

    // Verifico il complemento a 2
    printf("\n\n");
    decToBin(20, bin1);
    printBin(bin1);
    printf("\n");
    complementoDue(bin1);
    printBin(bin1);

    /* Verifico di nuovo il complemento a 2*/
    printf("\n\n");
    decToBin(20, bin1);
    invertiBinario(bin1);
    printBin(bin1);
    printf("\n");
    decToBin(1, bin2);
    printBin(bin2);
    printf("\n");
    sommaBin(bin1, bin2, bin1);
    printBin(bin1);
    /*
    11101011 -> bin1 dopo InvertiBinario
    00000001 -> bin2 contiene la codifica di 1 decimale in binario
    11101100 -> bin3 somma di bin1+bin2
    */

    return(0);
}

void decToBin(int _value, int _v[]){
    int i;
    for(i=0; i<DIM; i++){
        _v[i] = _value % 2;
        _value = _value / 2;
    }
}

void printBin(int _v[]){
    int i;
    for(i=DIM-1; i>=0; i--){
        printf("%d", _v[i]);
    }
}

int sommaBin(int _v1[], int _v2[], int _ris[]){
    int tmp[DIM+1];
    int i;
    // azzeramento del vettore temporaneo per la somma
    for(i=0; i<DIM+1; i++)
        tmp[i] = 0;
    
    // ciclo di somma
    for(i=0; i<DIM; i++){
        tmp[i] = tmp[i] + _v1[i] + _v2[i];
        tmp[i+1] = tmp[i] / 2;
        tmp[i] = tmp[i] % 2;
    }

    if(tmp[DIM] == 1){  // la cella DIM di tmp è la cella del possibile OVERFLOW.
        return(1);
    }
    else{
        for(i=0; i<DIM; i++)    // se non è presente overflow, allora copio tmp in _ris così da restituirlo al main.
            _ris[i] = tmp[i];
        return(0);
    }
}

void complementoDue(int _v1[]){
    int i;
    int trovato;

    trovato = 0;
    for(i=0; i<DIM; i++){
        if(trovato == 1){
            if(_v1[i] == 0)
                _v1[i] = 1;
            else
                _v1[i] = 0;
        }
        if(trovato == 0 && _v1[i]==1){
            trovato = 1;
        }
    }
}
/*
 20 -> 00010100
-20 -> 11101100

*/

void invertiBinario(int _v1[]){
    int i;
    for(i=0; i<DIM; i++){
        if(_v1[i] == 1) _v1[i] = 0;
        else _v1[i] = 1;
    }
}