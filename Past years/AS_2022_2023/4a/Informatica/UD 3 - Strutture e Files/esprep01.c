
/*
	creare un prog che richiede parole in input le inserisce in un file di testo, una sotto l'altra, e termina se viene inserita la parola fine.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//area prototipi
void inputParola(char[]);

void scriviSuFile(char[], FILE *);

//cerca una parola nel file, se la trova la stampa e ritorna al main il numero di volte che è stata trovata.
int ricercaParola(char [], FILE *);


int main(){
	char s[20];
	FILE *punt;
	punt = fopen("parole.txt", "wt");
	do{
		/*printf("inserisci una parola: ");
		scanf("%s", s);
		fflush(stdin);
		*/
		
		inputParola(s);
		
		if(strcmp(s, "fine") != 0){
			/*fputs(s, punt);
			fputc('\n', punt);
			*/
			
			scriviSuFile(s, punt);
				
		}
	}while(strcmp(s, "fine") != 0);
	fclose(punt);
	punt = fopen("parole.txt", "rt");
	
	printf ("inserisci la parola da cercare: ");
	scanf ("%s", s);
	fflush (stdin);
	
	printf ("la parola cercata è stata trovata %d volte", ricercaParola(s, punt));
	fclose(punt);
	return(0);
}

void inputParola(char _parole[]){
	printf("Inserisci una parola: ");
	scanf("%s", _parole);
	fflush(stdin);
}

void scriviSuFile(char _parole[], FILE *_punt){
	fputs(_parole, _punt);
	fputc('\n', _punt);
}

int ricercaParola(char p[], FILE *_f){
	int numTimes = 0;
	char _s[20];
	fscanf(_f,"%s", _s);
	while (!feof(_f)){
		//fgets(_s,20,_f);
		printf ("%s\n", _s);	
		if (strcmp(_s, p)== 0)
			numTimes++;
		fscanf(_f,"%s", _s);
	}
	return numTimes;
}
