/*
   - Creare un programma che richiami una funzione alla quale sono passate le 
   dimensioni di un rettangolo, la funzione calcola e restituisce area e perimetro.

   - Creare una funzione che riceve due parametri interi per riferimento ed esegue lo scambio
   dei valori contenuti.

   - Creare una funzione che visualizza la serie numerica compresa tra
   il valore più piccolo e più grande, passati come parametri.
*/
#include <stdio.h>
/**
 * @brief Funzione che calcola e restituise area e perimetro di un rettangolo.
 * @param int Base del rettangolo.
 * @param int Altezza del rettangolo.
 * @param int* Address varaibile per area.
 * @param int* Address variabile per perimetro.
 */
void areaPerimetroRettangolo(int, int, int*, int*);

/**
 * @brief Scambia il contenuto di due variabili passate per riferimento.
 * @param int* Address prima variabile.
 * @param int* Address seconda variabile.
 */
void scambio(int*, int*);

/**
 * @brief Serie numerica tra il valore minimo e massimo passati come parametri. I valori
 * posso anche non essere in ordine crescente.
 * @param int Primo valore.
 * @param int Secondo valore. 
 */
void serieMinMax(int, int);

int main(){
   int base = 6;
   int altezza = 5;
   int area, perimetro;
   int v1, v2;
   int x, y;

   areaPerimetroRettangolo(base, altezza, &area, &perimetro);
   printf("Rettagolo %dx%d, area: %d, perimetro: %d\n\n", base, altezza, area, perimetro);
   
   v1 = 5;
   v2 = 19;
   printf("V1: %d - V2: %d\n", v1, v2);
   scambio(&v1, &v2);
   printf("V1: %d - V2: %d\n", v1, v2);

   printf("\n\n");
   x=4; y=10;
   serieMinMax(y,x);
   return(0);
}

void areaPerimetroRettangolo(int _b, int _h, int *_area, int *_perimetro){
   *_area = _b * _h;
   *_perimetro = (_b+_h) * 2;
}

void scambio(int *_n1, int *_n2){
   int tmp;
   tmp = *_n1;
   *_n1 = *_n2;
   *_n2 = tmp;
}

void serieMinMax(int v1, int v2){
   int i;
   if(v1>v2)
      scambio(&v1,&v2);
   
   for(i=v1; i<=v2; i++)
      printf("%d ", i);
}