/* esercizio con switch case comprendente gli algoritmi
 degli esercizi 4-5-6-7 pag 210
*/
#include <stdio.h>

int main(){
   int scelta;
   int num1, num2, box;
   int num3;

   do{
      printf("1. Scambia numeri.\n");
      printf("2. Numeri uguali.");
      printf("3. Verifica terna pitagorica.\n");
      printf("0. USCITA\n");
      printf("Scelta: ");
      scanf("%d", &scelta);
      fflush(stdin);
      switch(scelta){
         case 1:{
            printf("Inserisci numero 1: ");
            scanf("%d", &num1);
            fflush(stdin);
            printf("Inserisci numero 2: ");
            scanf("%d", &num2);
            fflush(stdin);

            if(num1 > num2){  // devo eseguire lo scambio.
               box = num1;
               num1 = num2;
               num2 = box;
            }
            printf("N1: %d, N2: %d\n\n", num1, num2);
            break;
         }
         case 2:{
            printf("Inserisci numero 1: ");
            scanf("%d", &num1);
            fflush(stdin);
            printf("Inserisci numero 2: ");
            scanf("%d", &num2);
            fflush(stdin);
            printf("Inserisci numero 3: ");
            scanf("%d", &num3);
            fflush(stdin);
            if((num1==num2) || (num1==num3) || (num2==num3))
               printf("Ci sono almeno due numeri uguali tra loro.\n\n");
            else
               printf("Non sono presenti numeri uguali\n\n");
            break;
         }
         case 3:{
            printf("Inserisci numero 1: ");
            scanf("%d", &num1);
            fflush(stdin);
            printf("Inserisci numero 2: ");
            scanf("%d", &num2);
            fflush(stdin);
            printf("Inserisci numero 3: ");
            scanf("%d", &num3);
            fflush(stdin);
            // terna pitagorica -> x^2 + y^2 = z^2
            // x->num1 y->num2 z->num3
            // x^2 -> (x*x)
            if((num1*num1) + (num2*num2) == (num3*num3))
               printf("I numeri inseriti sono una terna pitagorica.\n\n");
            else
               printf("I numeri inseriti non sono una terna pitagorica.\n\n");
            break;
         }
         case 4:{
            break;
         }
         default:{
            printf("Scelta non valida.\n\n");
            break;
         }
      }
      printf("!!Premi un tasto per continuare!!");
      getchar();
   }while(scelta != 0);
   return(0);
}
