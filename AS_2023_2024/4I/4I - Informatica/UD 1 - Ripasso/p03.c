/*
    - Inizializzazione di un vettore di 10 elementi con valori random compresi tra 1 e 25 (estremi compresi).
    - Visualizzazione vettore.
    - Ordinamento vettore Crescente-decrescente.
    - Swap tra posizioni.
    - Ricerca valore.
    - Sostituzione valore.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM=10;
/**
 * Inizializza un vettore con valori random compresi tra 1 e 25 estremi compresi.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void initVettore(int[], int);
/**
 * Stampa un vettore a video
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void printVettore(int[], int);
/**
 * Ordina in modo crescente un vettore di interi.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void orderAscending(int[], int);
/**
 * Ordina in modo decrescente un vettore di interi.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void orderDescending(int[], int);
/**
 * Ordina un vettore in modo crescente o decrescente a scelta dell'utente
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @param int Scelta ordinamento 0->Crescente / 1->Decrescente
*/
void orderVettore(int[], int, int);
/**
 * Scambia i valori contenuti in due posizioni scelte dall'utente.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @param int Posizione 1.
 * @param int Posizione 2.
 * @return 0->Se lo scambio non è possibile, 1->Se lo scambio è stato effettuato.
*/
int swapPosizioniVettore(int[], int, int, int);

/**
*cerca la mediana
*@param int[] vettore da usare
*@param int dimensione del vettore
*@return float mediana
*/
float srcMediana(int [], int);

/**
*creca la moda 
*@param int[] vettpre da utilizzare
*@param int dimensione del vettore
*@return int moda
*/
int srcModa(int [], int);

int main(){
    int vettore[DIM];
    float mediana;

    initVettore(vettore, DIM);          // genero un vettore.
    printVettore(vettore, DIM);         // stampo il vettore.

    orderAscending(vettore, DIM);       // ordino il vettore in modo crescene.
    printVettore(vettore, DIM);         // stampo il vettore.

    initVettore(vettore, DIM);          // genero il vettore con nuovi valori.
    orderDescending(vettore, DIM);      // ordino il vettore in modo decrescente.
    printVettore(vettore, DIM);         // stampo il vettore.

    printf("\n");
    initVettore(vettore, DIM);          // genero il vetore con nuovi valori.
    printVettore(vettore, DIM);         // stampo il vettore.
    orderVettore(vettore, DIM, 1);      // ordino il vettore in modo decrescente con parametro 1.
    printVettore(vettore, DIM);         // stampo il vettore.

    printf("\n");
    // prima chiamata della swap con indici validi
    if(swapPosizioniVettore(vettore, DIM, 2, 6))
        printVettore(vettore, DIM);
    else
        printf("Errore negli indici...\n");

    // seconda chiamata della swap con indici non validi, la funzione ritorna 0->False
    if(swapPosizioniVettore(vettore, DIM, 2, 12))
        printVettore(vettore, DIM);
    else
        printf("Errore negli indici...\n");
        
    mediana=srcMediana(vettore, DIM);
    printf("%.2f", mediana);
    return(0);
}

void initVettore(int _vet[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _vet[i] = 1 + (rand()%25);
    }
}
void printVettore(int _vet[], int _dim){
    int i;

    for(i=0; i<_dim; i++){
        printf("%3d", _vet[i]);
    }
    printf("\n");
}
void orderAscending(int _vet[], int _dim){
    int i, j;
    int tmp;
    for(i=0; i<_dim; i++){
        for(j=i; j<_dim; j++){
            if(_vet[i] > _vet[j]){
                tmp = _vet[i];
                _vet[i] = _vet[j];
                _vet[j] = tmp;
            }
        }
    }
}
void orderDescending(int _vet[], int _dim){
    int i, j;
    int tmp;
    for(i=0; i<_dim; i++){
        for(j=i; j<_dim; j++){
            if(_vet[i] < _vet[j]){
                tmp = _vet[i];
                _vet[i] = _vet[j];
                _vet[j] = tmp;
            }
        }
    }
}
void orderVettore(int _vet[], int _dim, int _order){
    int i, j;
    int tmp;

    if(_order == 0){ // 0 --> Ordine crescente
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_vet[i] > _vet[j]){
                    tmp = _vet[i];
                    _vet[i] = _vet[j];
                    _vet[j] = tmp;
                }
            }
        }
    }
    if(_order == 1){ // 1 --> Decrescente
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_vet[i] < _vet[j]){
                    tmp = _vet[i];
                    _vet[i] = _vet[j];
                    _vet[j] = tmp;
                }
            }
        }
    }
}
int swapPosizioniVettore(int _vet[], int _dim, int _pos1, int _pos2){
    int tmp;
    if(_pos1<0 || _pos1>=_dim)
        return(0);
    if(_pos2<0 || _pos2>=_dim)
        return(0);

    tmp = _vet[_pos1];
    _vet[_pos1] = _vet[_pos2];
    _vet[_pos2] = tmp;
    return(1);
}

float srcMediana(int _vet[], int _dim){
	int i;
	float m;
	int pos=_dim/2;		//finds the middle of the vector
	
	orderAscending(_vet, _dim);		//orders the vector
	if(_dim % 2 == 1){
		m=_vet[pos];
	}else{
		m=(float)(_vet[pos]+_vet[pos-1])/2;
	}
	
	return(m);
}

int srcModa(int _vet[], int _dim){
	int i;
	int moda=0;
	
	if()
}
