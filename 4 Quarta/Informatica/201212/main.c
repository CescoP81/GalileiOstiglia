/*
Traccia:
Creare un programma C che gestisca un vettore di MASSIMO 10 stringhe in maniera dinamica. Il programma deve presentare all'avvio due cose:
1. le 10 stringhe presenti nel vettore.
2. un menu a tre voci:
	1. Inserisci
	2. Estrai
	3. USCITA

funzionalità:
1. Se vi è posto disponibile il programma richiede la stringa da inserire e la inserisce in ordine alfabetico crescente.
2. il programma richiede la posizione da libera (oppure la stringa da estrarre), quindi la toglie dal vettore.
3. il programma termina.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define DIM 20 //dimensione vettore di stringhe (colonne)
#define LUN 3 //lunghezza vettore di stringhe (righe)

void inserisci(char s[][DIM], int L, int D);
int estrai(char s[][DIM], int L, int D, char es[], int tro);

int main(){
	//CON LUN 10 BUG
    char str[LUN][DIM];
    char estr[DIM];
    int i, j, scelta;
    int ok = 0; //variabile che non fa eseguire case 2 senza aver eseguito prima il case 1
    int ind = 0; //variabile che tiene conto dell'indice d'inserimento e d'estrazione
    int trovato = 0;
    
    printf ("---Vettore---\n"); //pulizia della matrice di stringhe iniziale
    for(i=0; i<LUN; i++){
        str[i][0] = '\0';
    }

    do{
        //system ("CLS");
        
        printf ("---Vettore---\n");
        for(i=0; i<LUN; i++){
            printf("Cella %d: %s \n", i, str[i]);
        }
        
        printf ("\n---Menu'--");
        printf ("\n1. Inserisci\n");
		printf ("2. Estrai\n");
		printf ("3. USCITA\n");
        printf ("\nCosa scegli? ");
		scanf ("%d", &scelta);
		fflush (stdin);

        switch (scelta){
            case 1:{
                ok = 1;

                printf ("Inserire la stringa: ");
                scanf ("%s",str[ind]);
                fflush (stdin);
                inserisci(str, LUN, DIM);

                ind++;
                break;
            }
            case 2:{
                if (ok){
                	printf ("Stringa da estrarre: ");
                	scanf ("%s", estr);
                	fflush (stdin);
                    trovato = estrai(str, LUN, DIM, estr, trovato);
                    
                    if (trovato){
                    	ind--;
					}
                }else{
                    printf ("Eseguire prima il primo punto!");
                }
                break;
            }
            case 3:{
                printf("\nProgramma Terminato.");
                break;
            }
			default:{
				printf ("\nScelta non valida!");
				break;
			}
        }
        getchar();
    }while (scelta != 3); 
}

void inserisci(char s[][DIM], int L, int D){

    int i, j;
    char box[20];
    
    for (i=0; i<L; i++){
        for (j=L-1; j>i; j--){
            if (strcmp(s[j-1], s[j]) > 0 && strcmp(s[j], "") != 0){
                strcpy(box, s[j-1]);
                strcpy(s[j-1], s[j]);
                strcpy(s[j], box);
            }
        }
    }
}

int estrai(char s[][DIM], int L, int D, char es[], int tro){

    int i;

    for (i=0; i<L; i++){
        if (strcmp (s[i], es) == 0){
            strcpy (s[i], "");
            tro = 1;
        }
        if (tro == 1){
        	strcpy(s[i], s[i+1]);
		}
    }
    return (tro);
}
