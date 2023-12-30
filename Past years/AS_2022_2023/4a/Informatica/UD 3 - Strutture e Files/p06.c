/*
	Apre il file appena creato,
	legge le parole e ci dice la parola più lunga e ritorna la lunghezza
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototipi
void openFile(char []);
void mettiMaiuscolo(char []);


//Main
int main(){
	
	char filename[] = "esercizio.txt";
	
	openFile(filename);
	mettiMaiuscolo(filename);
	reversedWord("esercizio.txt");
	
	return (0);
}

//Funzioni
void openFile(char _filename[]){
	FILE *fpIn = fopen(_filename, "r");
	char parola[21];	//parola letta dal file.
	int maxLet;			//lunghezza massima trovata.
	char maxParola[21];	//parola con la lunghezza massima trovata.
	
	maxLet = 0;
	fscanf(fpIn, "%s", &parola);
	while(!feof(fpIn)){
		//printf("%s\n", parola);
		if (strlen(parola) > maxLet){
			maxLet = strlen(parola);
			strcpy(maxParola, parola);
		}
		fscanf(fpIn, "%s", &parola);
	}
	printf("\n%s: %d", maxParola, maxLet);
	fclose(fpIn);
}

//funz che legge le parole; per ogni parola se l'iniziale � minuscola la mette maiuscola
void mettiMaiuscolo(char _filename[]){
	FILE *fpIn = fopen(_filename, "r");
	char parola[21];
	fscanf(fpIn, "%s", &parola);
	while(!feof(fpIn)){
		if(parola[0] >= 'a' && parola[0] <= 'z'){
			//parola[0] = parola[0] -32;
			parola[0] = (parola[0]-'a')+'A';
		}
		printf("\n%s", parola);
		fscanf(fpIn, "%s", &parola);
	}
	fclose(fpIn);
}
// genera un secondo file chiamato reversed.txt e ci mette le parole del primo ma ribaltate al contrario 

void reversedWord(char _filename[]){
	FILE *fpIn = fopen(_filename, "r");
	FILE *fpOut = fopen("reversed.txt", "w");
	char parola[21];
	char tmp;
	fscanf(fpIn, "%s", &parola);
	int i;
	int len;
	while(!feof(fpIn)){
		len = strlen(parola);
		for(i = 0; i < len/2; i++){
			tmp = parola[i];
			parola[i] = parola[len-i-1];
			parola[len-i-1]	= tmp;
		}
		parola[len] = '\0';
		fprintf(fpOut, "%s\n", parola);
		fscanf(fpIn, "%s", &parola);
	}
	fclose(fpIn);
	fclose(fpOut);
	
	
}


