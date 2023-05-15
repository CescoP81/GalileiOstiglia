/* Realizzare un programma che gestisca tramite uno switch-case le seguenti opzioni
1. quadrato [input: lato; output: area, perimetro, diagonale]
2. cerchio [input: raggio; output: area, perimetro]
3. triangolo [input: C1, C2, C3 output: se c1=2 o c1=c2=c3 area e perimetro]
4. rombo [input: Dmax, dmin; output: area]
5. trapezio [input: Bmax, bmin, h; output: area]
*/
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main(){
   int lato, area, perimetro, diagonale;
   int raggio;
   int cat1, cat2, cat3;
   int altezza;
   int dMax, dmin;
   int bMax, bmin;
   int scelta;

   do{
      printf("1. Quadrato\n");
      printf("2. Cerchio\n");
      printf("3. Triangolo\n");
      printf("4. Rombo\n");
      printf("5. Trapezio\n");
      printf("0 -> Termina Programma\n");
      printf("Scelta: ");
      scanf("%d", &scelta);
      fflush(stdin);
      switch(scelta){
         case 1:{
            printf("Inserisci il lato: ");
            scanf("%d", &lato);
            fflush(stdin);

            area = lato * lato;
            perimetro = lato * 4;
            diagonale =(int)(lato * sqrt(2));

            printf("Area: %d\n", area);
            printf("Perietro: %d\n", perimetro);
            printf("Diagonale: %d\n\n", diagonale);
            break;
         }
         case 2:{
            printf("Inserisci il raggio: ");
            scanf("%d", &raggio);
            fflush(stdin);

            perimetro = (int)(2*3.14*raggio);
            area = (int)(3.14*raggio*raggio);

            printf("Perimetro: %d\n", perimetro);
            printf("Area: %d\n\n", area);
            break;
         }
         case 3:{
            printf("Cateto 1: ");
            scanf("%d", &cat1);
            fflush(stdin);
            printf("Cateto 2: ");
            scanf("%d", &cat2);
            fflush(stdin);
            printf("Cateto 3: ");
            scanf("%d", &cat3);
            fflush(stdin);
            if((cat1==cat2) && (cat2==cat3)){
               altezza =(int) (sqrt((cat1*cat1)+ ((cat2/2)*(cat2/2))));
               perimetro = cat1 + cat2 + cat3;
               area =(int) (cat1 * altezza) / 2;

               printf("Perimetro Equilatero: %d\n", perimetro);
               printf("Area Equilatero: %d\n\n", area);
               break;
            }
            else{
               if(cat1 == cat2){
                  altezza =(int) (sqrt((cat1*cat1)+ ((cat3/2)*(cat3/2))));
                  perimetro = cat1 + cat2 + cat3;
                  area =(int) (cat3 * altezza) / 2;
                  printf("Perimetro Isoscele: %d\n", perimetro);
                  printf("Area Isoscele: %d\n\n", area);
               }
               else{
                  printf("Triangolo non gestibile.\n\n");
               }
            }
            break;
         }
         case 4:{
            printf("Inserisci diagonale Maggiore: ");
            scanf("%d", &dMax);
            fflush(stdin);
            printf("Inserisci diagonale minore: ");
            scanf("%d", dmin);
            fflush(stdin);

            lato = (int) sqrt( ((dMax/2)*(dMax/2)) + ((dmin/2)*(dmin/2)) );
            perimetro = lato * 4;
            area = (dMax*dmin) / 2;
            printf("Area: %d\n", area);
            printf("Perietro: %d\n", perimetro);
            break;
         }
         case 5:{
            printf("Inserisci base maggiore: ");
            scanf("%d", &bMax);
            fflush(stdin);
            printf("Inserisci base minore: ");
            scanf("%d", &bmin);
            fflush(stdin);
            printf("Inserici altezza: ");
            scanf("%d", &altezza);
            fflush(stdin);

            area = (bmin+bMax) * altezza / 2;
            printf("Area: %d\n\n", area);
            break;
         }
         case 0:{
            printf("\nGrazie per aver usato questo programma.\n\n");
            break;
         }
         default:{
            printf("\n !! SCELTA NON VALIDA !! \n\n");
            break;
         }
      }
      printf("--> Premi un tast per continuare <--");
      getchar();
   }while(scelta != 0);
   
}