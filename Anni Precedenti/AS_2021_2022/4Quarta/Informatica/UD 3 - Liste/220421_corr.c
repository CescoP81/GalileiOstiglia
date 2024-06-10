#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lumaca{
   char nome[30];
   int n_gara;
   int velocita;
}Lumaca;
typedef struct nodo{
   Lumaca lumaca;
   struct Nodo *next;
}Nodo;
#define MAX_LUMACHE 5

/**
 * @brief Aggiunta di una nuova lumaca alla gara, scelgo l'aggiunta in testa.
 * @param Nodo** Riferimento alla lista
 * @param Lumaca Struttura da inserire nel nuovo nodo.
 */
void addtesta(Nodo **, Lumaca);
/**
 * @brief Ricerca una lumaca per nome.
 * @param Nodo* Riferimento alla lista.
 * @param char[] Stringa del nome da ricercare.
 */
void ricercaLumaca(Nodo *, char[]);
/**
 * @brief Ricerca e visualizza le lumache più veloce e più lenta in gara.
 * @param Nodo* Riferimento alla lista.
 */
void vediVeloceLenta(Nodo *);
/**
 * @brief Esclude una lumaca individuata dal numero di gara.
 * @param Nodo** Riferimento alla lista.
 * @param int Numero di gara da escludere.
 */
void escludiLumaca(Nodo **, int);
/**
 * @brief Genera due file binario e testo con inserite le lumache in gara.
 * @param Nodo* Riferimento alla lista. * 
 */
void salvaListaGara(Nodo *);

/**
 * @brief Funzione accessoria che conta quante lumache compongono la lista.
 * @param Nodo* Riferimento alla lista.
 * 
 * @return int Numero di lumache trovate.
 */
int contaLumache(Nodo *);
/**
 * @brief Funzione accessoria che visualizza la lista creata.
 * @param Nodo* Riferimento alla lista. * 
 */
void vediListaGara(Nodo *);
/**
 * @brief Funzione accessoria che ricerca la lumaca più lenta e restituisce il numero di gara.
 * @param Nodo* Riferimento alla lista
 * 
 * @return int Numero di gara della lumaca più lenta.
 */
int ricercaPiuLenta(Nodo *);

int main(){
   int scelta;
   Nodo *listaGara = NULL;

   do{
      printf("\n-------------------\n");
      printf("Lumache in gara: %d\n", contaLumache(listaGara));
      printf("-------------------\n");

      printf("1-> Inserisci nuova lumaca.\n");
      printf("2-> Ricerca lumaca per nome.\n");
      printf("3-> Lumaca piu' veloce e piu' lenta.\n");
      printf("4-> Escludi lumaca\n");
      printf("5-> Salva lista gara\n");
      printf("6-> Vedi Lista\n");
      printf("0-> USCITA\n");
      printf("scelta: ");
      scanf("%d", &scelta);

      switch(scelta){
         case 1:{
            Lumaca tmp;
            printf("Nome: ");
            scanf("%s", tmp.nome);
            printf("Numero di gara: ");
            scanf("%d", &(tmp.n_gara));
            printf("Velocita': ");
            scanf("%d", &(tmp.velocita));

            int presente = 0;
            Nodo *tmpNodo;
            tmpNodo = listaGara;
            while(tmpNodo){
               if(tmpNodo->lumaca.n_gara == tmp.n_gara)
                  presente = 1;
               tmpNodo = (Nodo*) tmpNodo->next;
            }
            if(!presente){
               if(contaLumache(listaGara) < MAX_LUMACHE){
                  addtesta(&listaGara, tmp);
               }
               else{
                  escludiLumaca(&listaGara, ricercaPiuLenta(listaGara));
                  addtesta(&listaGara, tmp);     
               }
            }
            else
               printf("Lumaca già presente.");
            printf("\n\n");
            vediListaGara(listaGara);
            break;
         }
         case 2:{
            char nome[30];
            printf("Inserisci nome: ");
            scanf("%s", nome);
            ricercaLumaca(listaGara, nome);
            break;
         }
         case 3:{
            vediVeloceLenta(listaGara);
            break;
         }
         case 4:{
            int nLumaca;
            printf("Numero Lumaca da escludere: ");
            scanf("%d", &nLumaca);
            fflush(stdin);
            escludiLumaca(&listaGara, nLumaca);         
            break;
         }
         case 5:{
            salvaListaGara(listaGara);
            printf("File Salvati\n");
            break;
         }
         case 6:{
            vediListaGara(listaGara);
            break;
         }
      }

   }while(scelta);
   return(0);
}

void addtesta(Nodo **_testa, Lumaca _lumaca){
   Nodo *tmp;
   tmp = (Nodo*) malloc(sizeof(Nodo));
   tmp->lumaca = _lumaca;
   tmp->next = (struct Nodo*) *_testa;
   *_testa = tmp;
}

int contaLumache(Nodo *_list){
   int cnt = 0;
   while(_list){
      cnt++;
      _list =(Nodo*) _list->next;
   }
   return(cnt);
}

void vediListaGara(Nodo *_list){
   if(_list){
      int i = 1;
      printf("\n## LUMACHE IN GARA ##\n");
      while(_list){
         printf("%d) %s %d %dmm/min\n", i, _list->lumaca.nome, _list->lumaca.n_gara, _list->lumaca.velocita);
         _list =(Nodo*) _list->next;
         i++;
      }
   }
   else{
      printf("Lista vuota, nessuna lumaca in gara");
   }
   printf("---------------------\n\n");
}

void ricercaLumaca(Nodo *_list, char _nome[]){
   if(_list){
      int i = 1;
      printf("\n## LUMACHE TROVATE ##\n");
      while(_list){
         if(strcmp(_list->lumaca.nome, _nome) == 0){
            printf("%d) %s %d %dmm/min\n", i, _list->lumaca.nome, _list->lumaca.n_gara, _list->lumaca.velocita);
            i++;
         }
         _list =(Nodo*) _list->next;         
      }
   }
   else{
      printf("Lista vuota, nessuna lumaca in gara");
   }
   printf("---------------------\n\n");

}

void vediVeloceLenta(Nodo *_list){
   Lumaca veloce;
   Lumaca lenta;

   if(_list){
      veloce = _list->lumaca;
      lenta = _list->lumaca;

      while(_list){
         if(_list->lumaca.velocita < lenta.velocita) lenta = _list->lumaca;
         if(_list->lumaca.velocita > veloce.velocita) veloce = _list->lumaca;
         _list = (Nodo*) _list->next;
      }

      printf("Lumaca piu' veloce: %s %d %dmm/min\n", veloce.nome, veloce.n_gara, veloce.velocita);
      printf("Lumaca piu' lenta: %s %d %dmm/min\n", lenta.nome, lenta.n_gara, lenta.velocita);
   }
   else{
      printf("Lista vuota, nessuna lumaca in gara");
   }
   printf("---------------------\n\n");

}

int ricercaPiuLenta(Nodo *_list){
   Lumaca lenta;
   if(_list){
      lenta = _list->lumaca;

      while(_list){
         if(_list->lumaca.velocita < lenta.velocita) lenta = _list->lumaca;
         _list = (Nodo*) _list->next;
      }
      return(lenta.n_gara);
   }
   else{
      return(-1);
   }
}

void escludiLumaca(Nodo **_list, int _ngara){
   if(*_list){
      int i=0;
      int pos = -1;

      Nodo *tmp;
      Nodo *tmp2;
      tmp = *_list;
      while(tmp){
         i++;
         if(tmp->lumaca.n_gara == _ngara)
            pos = i;
         tmp = (Nodo*) tmp->next;
      }

      if(pos != -1){
         printf("Trovata in posizione %d\n", pos);
         if(pos == 1)
            *_list = (Nodo*) (*_list)->next;
         else{
            tmp = *_list;
            for(i=1; i<pos-1; i++){
               tmp = (Nodo*) tmp->next;
            }
            tmp2 = (Nodo*) tmp->next;
            tmp->next = tmp2->next;            
         }
         printf("Lumaca Esclusa dalla Gara!\n");
      }
   }
   else{
      printf("Lista vuota, nessuna lumaca in gara");
   }
}

void salvaListaGara(Nodo *_list){
   FILE *fpouttxt;
   FILE *fpoutbin;

   fpouttxt = fopen("listaGara.txt", "wt");
   fpoutbin = fopen("listaGara.dat", "wb");

   int i=0;
   while(_list){
      i++;
      fprintf(fpouttxt,"%i %s %d %dmm/min\n", i, _list->lumaca.nome, _list->lumaca.n_gara, _list->lumaca.velocita);
      fwrite(&(_list->lumaca), sizeof(Lumaca), 1, fpoutbin);
      _list = (Nodo*) _list->next;
   }
   fclose(fpouttxt);
   fclose(fpoutbin);
}