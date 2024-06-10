/* Realizzare un programma suddiviso nelle seguenti funzioni:
    a) int inputNumber(int, int): Prevede due parametri interi, ed esegue l'input di un numero da tastiera restituendolo al main,
     secondo il seguente schema: 
      1- se i due parametri sono 0 accetta qualunque numero in input,
      2- se i due parametri sono diversi da zero con p1 < p2 accetta in input solo valori compresi tra p1 e p2 estremi compresi,
      3- se p1=0 e p2>0 allora accetta qualunque valore positivo finché non viene inserito un valore inferiore a p2;
     tutti gli altri casi restituisce -1.
       
    b) int getMaxValue(int, int, int): vengono passati tre valori interi in ordine casuale, la funzione restituisce al main il maggiore tra i tre.
       
    c) void orderValues(int, int, int, int): riceve tre valori in ordine casuale e come ultimo parametro un intero 0/1 (0 ordine decrescente; 1 ordine crescente).
     In base all'ordine impostato i tre valori vengono ordinati, quando la funzione trova due valori da scambiare chiama la funzione 
      - void swapValue(int, int) che esegue lo scambio di valore tra due variabili.

Verificare nel main program il funzionamento corretto delle funzioni.
Attenzione, come parametri ho indicato solamente il tipo di dato, se è passaggio per valore o riferimento lo devi decidere tu.
*/
#include <stdio.h>

/**
 * @brief Funzione per l'input di un numero da tastiera secondo vari criteri
 * 
 * @param int Estremo p1
 * @param int Estremo p2
 * @return int Numero inserito da tastiera e verificto.
 */
int inputNumber(int, int);
/**
 * @brief Ritorna il massimo valore tra tre passati come parametri.
 * @param int Parametro 1
 * @param int Parametro 2
 * @param int Parametro 3
 * @return int Il valore massimo
 */
int getMaxValue(int, int, int);
/**
 * @brief Ordina tre valori secodo l'ordine deciso dall'ultimo parametro.
 * @param int* Riferimento al primo valore
 * @param int* Riferimento al secondo valore
 * @param int* Riferimento al terzo valore
 * @param int Modo ordinamento (0->decrescete, 1->crescete) * 
 */
void orderValue(int*, int*, int*, int);

/**
 * @brief Scambia il contenuto di due variabili passate per riferimento.
 * @param int* Prima variabile.
 * @param int* Seconda variabile. * 
 */
void swapValue(int*, int*);


int main(){
   int n1, n2, n3;
   int max;
   int ordinamento;

   // fase di input dei tre valori.
   n1 = inputNumber(4, 10);
   printf(" Valore 1 inserito: %d\n\n", n1);

   n2 = inputNumber(8, 0);
   printf(" Valore 2 inserito: %d\n\n", n2);

   n3 = inputNumber(0,0);
   printf(" Valore 3 inserito: %d\n\n", n3);

   // stampo tutti e tre i valor inseriti e controllo che rispettino i criteri voluti in fase di input.
   printf("Valori inseriti: %d %d %d\n\n", n1,n2,n3);

   max = getMaxValue(n1, n2, n3);            // chiamata della funzione che determina il massimo
   printf("Massimo inserito: %d\n\n", max);  // stampa del massimo determinato.

   orderValue(&n1, &n2, &n3, 1);             // chiedo il riordino dei tre valori passati per riferimento in modo crescente (1 come ultimo parametro); 0 per decrescente.
   printf("Valori ordinati: %d %d %d", n1, n2, n3);
   return(0);
}

int inputNumber(int p1, int p2){
   int num;
   // se entrambri gli estremi sono zero accetto in input qualunque numero.
   if(p1 == 0 && p2 == 0){ // caso a.1
      printf("Inserisci un numero: ");
      scanf("%d", &num);
      fflush(stdin);
      return(num);
   }

   // se entrambri gli estremi sono diversi da zero e p1 < p2; accetto numeri nell'intervallo p1<>p2
   if(p1 != 0 && p2 != 0 && p1<p2){ // caso a.2
      do{
        printf("Inserisci un numero: ");
         scanf("%d", &num);
         fflush(stdin);
      }while(num<p1 || num>p2);
      return(num);
   }
   
   // se p1 è uguale a zero e p2 è maggiore di zero, accetto numeri positivi minori di p2
   if(p1 == 0 && p2>0){ // caso a.3
      do{
         printf("Inserisci un numero: ");
         scanf("%d", &num);
         fflush(stdin);
      }while(num>p2);
      return(num);
   }
   // qualunque altro caso di p1 e p2 viene ignorato e ritornato -1
   return(-1);
}

int getMaxValue(int _n1, int _n2, int _n3){
   int max;
   max = _n1;                    // il primo valore lo assegno a max
   if(_n2 > max)  max = _n2;     // se uno dei due valori restanti è maggiore di max, max viene modificato.
   if(_n3 > max) max = _n3;
   return(max);
}

void orderValue(int *_n1, int *_n2, int *_n3, int _order){
   int scambio; // flag di esecuzione di uno scambio

   // ordinamento crescente
   if(_order == 1){
      do{                        // ciclo che itera finche viene effettuato almeno uno scambio.
         scambio = 0;
         if(*_n1 > *_n2){
            swapValue(_n1, _n2);
            scambio = 1;
         }
         if(*_n2 > *_n3){
            swapValue(_n2, _n3);
            scambio = 1;
         }
         if(*_n1 > *_n3){
            swapValue(_n1, _n3);
            scambio = 1;
         }
      }while(scambio);
   }

   // ordinamento decrescente
   if(_order == 0){
      do{                        // ciclo che itera finche viene effettuato almeno uno scambio.
         scambio = 0;
         if(*_n1 < *_n2){
            swapValue(_n1, _n2);
            scambio = 1;
         }
         if(*_n2 < *_n3){
            swapValue(_n2, _n3);
            scambio = 1;
         }
         if(*_n1 < *_n3){
            swapValue(_n1, _n3);
            scambio = 1;
         }
      }while(scambio);
   }
}

void swapValue(int *_x, int *_y){
   int tmp;
   tmp = *_x;
   *_x = *_y;
   *_y = tmp;
}