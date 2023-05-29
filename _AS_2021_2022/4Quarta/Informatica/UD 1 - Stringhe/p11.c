#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
   char *str;
   int cnt;    // contatore locazioni occupate
   int flag;
 
   cnt = 1;
   str = malloc(sizeof(char) * cnt);   // alloco almeno una posizione
   
   flag = 1;
   cnt = 1;
   do{
      *(str + cnt - 1) = getche();                 // alla posizione iesima assegno il carattere premuto
      if(*(str + cnt - 1) != 13){                  // se diverso da invio
         cnt++;                                    // incremento il contatore posizioni    
         str = realloc(str, sizeof(char)*(cnt));   // rialloco il blocco di memoria
      }
      else{
         *(str + cnt - 1) = '\0';
         flag = 0;
      }
   }while(flag);
   

   printf("\n\n");
   printf("Testo: %s\n", str);
   printf("Inseriti(compreso terminatore): %d char\n", cnt);

   cnt = 0;
   while(*(str+cnt) != '\0')
      cnt++;
   printf("Stringa lunga: %d char", cnt);

   return(0);
}
