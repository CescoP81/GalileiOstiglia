// DA RIVEDERE //
#include <stdio.h>
#include <stdlib.h>

int main(){
   FILE *fpin;
   char cf;
   char csrc;
   int newline;

   printf("C: ");
   scanf("%c", &csrc);
   fflush(stdin);

   fpin = fopen("parole.txt", "rb");
   newline = 1;
   while(fread(&cf, sizeof(char), 1, fpin) > 0){
      if(cf == '\n')
         newline = 1;
      if(newline){
         if((cf == csrc) || (cf == 'A'+(csrc-'a'))){
            printf("%c", cf);
            newline = 0;    
         }
      }
      else{
         printf("%c", cf);
      }
   }
   fclose(fpin);
   return(0);
}