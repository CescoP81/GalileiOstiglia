/* Programma che converte un numero decimale in formato binario con virgola mobile. */
#include <stdio.h>
#include <math.h>

#define DIM 16

/**
 * Inizializza un vettore ponendo tutti i bit a zero.
 * @param int[] Riferimento al vettore.
 * @param int Dimensione del vettore.
*/
void initVettore(int[], int);
/**
 * Calcola e ritorna il numero minimo di bit necessari per rappresentare il numero passato.
 * @param float Valore intero di cui calcolare il numero minimo di bit.
 * @return Numero di bit minimi necessari.
 */
int calcolaBitParteIntera(float);
/**
 * Stampa un vettore rappresentante un numero in virgola mobile.
 * @param int[] Riferimento al vettore contenente i bit.
 * @param int Dimensione del vettore.
 * @param int Numero di bit assegnati alla parte intera del numero codificato.
*/
void stampaBinario(int[], int, int);
/**
 * Converte la parte intera di un numero in virgola in formato binario.
 * @param int[] Riferimento al vettore.
 * @param int Numero di bit da utilizzare per la parte intera.
 * @param int Valore intero da codificare.
*/
void convertiInteraInBinario(int[], int, int);
/**
 * Converte la parte decimale di un numero in virgola in formato binario
 * @param int[] Vettore da utilizzare.
 * @param int Numero di bit assegnati alla parte decimale.
 * @param int Valore decimale da convertire utilizzando il numero di bit assegnati.
*/
void convertiDecimaleInBinario(int[], int, float);

/* #### MAIN PROGRAM #### */
int main(){
    float nrOriginale;
    int nrBitParteIntera;
    int nrBitParteDecimale;
    int binVirgolaMobile[DIM];
    int i;
    int dividendo;

    initVettore(binVirgolaMobile, DIM);

    printf("Inserisci un numero con la virgola: ");
    scanf("%f", &nrOriginale);
    fflush(stdin);

    // determino quanti bit minimo mi occorrono per la parte intera.
    dividendo = (int)nrOriginale;
    nrBitParteIntera = 0;
    nrBitParteIntera = calcolaBitParteIntera(nrOriginale);
    
    nrBitParteDecimale = DIM - nrBitParteIntera;
    printf("Bit parte intera: %d - parte decimale: %d\n",nrBitParteIntera, nrBitParteDecimale);
    stampaBinario(binVirgolaMobile, DIM, nrBitParteIntera);
    printf("\n");

    // inizio codificando la parte intera nel vettore binario
    convertiInteraInBinario(binVirgolaMobile, nrBitParteIntera, (int)nrOriginale);
    stampaBinario(binVirgolaMobile, DIM, nrBitParteIntera);
    printf("\n");

    // converto la parte decimale del numero
    convertiDecimaleInBinario(binVirgolaMobile, nrBitParteDecimale, nrOriginale);
    stampaBinario(binVirgolaMobile, DIM, nrBitParteIntera);
    return(0);
}

/* #### FUNCTIONS DEFINITION #### */
void initVettore(int _b[], int _d){
    int i;
    for(i=0; i<_d; i++)
        _b[i] = 0;
}
int calcolaBitParteIntera(float _num){
    int nrBitParteIntera;
    int dividendo;
    dividendo = (int)_num;
    nrBitParteIntera = 0;
    while(dividendo>=pow(2,nrBitParteIntera))
        nrBitParteIntera++; 
    return(nrBitParteIntera); 
}
void stampaBinario(int _b[], int _d, int _nrBitInteri){
    int i;
    for(i=0; i<_d; i++){
        printf("%d", _b[i]);
        if(i == _nrBitInteri-1) 
            printf(".");
    }
}
void convertiInteraInBinario(int _b[], int _nrBit, int _num){
    int i;
    for(i=0; i<_nrBit; i++){
        _b[_nrBit-i-1]=_num%2;
        _num = _num / 2;
    }
}
void convertiDecimaleInBinario(int _b[], int _nrBit, float _nf){
    int i;
    _nf = _nf - (int)_nf;
    _nf = _nf * 2;
    for(i=DIM-_nrBit; i<DIM; i++){
        //printf("-%d-\n", i);
        _b[i] =(int)_nf;
        _nf = _nf - (int)_nf;
        _nf = _nf * 2;
    }
}