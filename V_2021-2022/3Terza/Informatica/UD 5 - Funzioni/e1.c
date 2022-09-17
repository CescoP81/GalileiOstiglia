// sezione di inclusione delle librerie
#include <stdio.h>
// sezione di definizione delle costanti

// sezione di definizione dei prototipi
/**
 * @brief Funzione che stampa una serie numerica da 1 al numero intero passato come parametro.
 * @param int Numero di fine serie.
 */
void stampaSerieNumerica(int);
/**
 * @brief Funzione che stampa il valore massimo tra 3 valori passati come parametri.
 * @param int Primo numero
 * @param int Secondo numero
 * @param int Terzo numero
 */
void stampaValoreMassimo(int, int, int);

/**
 * @brief Funzione che restituisce la somma di due numeri passati come parametri.
 * @param int Primo numero.
 * @param int Secondo numero.
 * @return Somma dei numeri passati
 * 
 * @return int 
 */
int sommaDueNumeri(int, int);

// sezione del main program
int main(){
   int a,b,c;
   a = 9; b=10; c=1;
   stampaSerieNumerica(b);
   printf("\n\n");
   stampaSerieNumerica(c);
   printf("\n\n");
   stampaSerieNumerica(a);
   printf("\n\n");
   stampaValoreMassimo(a,b,c);
   printf("\n\n");
   printf("Somma: %d", sommaDueNumeri(a,b));
   return(0);
}

// sezione delle funzioni
void stampaSerieNumerica(int _n){
   int i;
   for(i=1; i<=_n; i++)
      printf("%3d,", i);
}

void stampaValoreMassimo(int _x, int _y, int _z){
   int max;
   max = _x;
   if(_y > max) max = _y;
   if(_z > max) max = _z;
   printf("Valore massimo passato: %d\n", max);
}

int sommaDueNumeri(int _x, int _y){
   int s;
   s = _x + _y;
   return(s);
}