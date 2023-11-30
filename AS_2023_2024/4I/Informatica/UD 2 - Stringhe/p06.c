/*
	Creare un programma che genera una stringa casuale x5 volte rispettando il formato:
	m, M, N, M - N, m, M, J
	dove N indica un numero casuale tra 0 e 9;
	dove m indica una lettera casuale tra 'a' e 'z';
	dove M indica una lettera dell'alfabeto maiuscolo;
	dove J indica un carattere jolly tra i seguenti:
		- @;
		- #;
		- !;
		- &;
		- ?;
	ESEMPIO:
		a C 7 T - 2 s X #
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM = 10;

void initString(char[], int);

void randomString(char[]);

void printString(char[]);

int main(){
	char stringa[DIM];
	
	srand(time(NULL));
	
	initString(stringa, DIM);
	
	randomString(stringa);
	
	return(0);
}

void initString(char _str[], int _dim){
	int i;
	
	for(i = 0; i < _dim; i++){
		_str[i] = '\0';
	}
}

void randomString(char _str[]){
	char special[5] = {'@', '#', '!', '&', '?'};
	
	int i = 0;
	while(i < 5){
		_str[0] = 'a' + (rand() % ('z' - 'a' + 1));
		_str[1] = 'A' + (rand() % ('Z' - 'A' + 1));
		_str[2] = '0' + (rand() % ('9' - '0' + 1));
		_str[3] = 'A' + (rand() % ('Z' - 'A' + 1));
		_str[4] = '-';
		_str[5] = '0' + (rand() % ('9' - '0' + 1));
		_str[6] = 'a' + (rand() % ('z' - 'a' + 1));
		_str[7] = 'A' + (rand() % ('Z' - 'A' + 1));
		_str[8] = special[rand() % 5];
		printString(_str);
		i++;
	}	
}

void printString(char _str[]){
	int j = 0;
	while(_str[j] != '\0'){
		printf("%3c", _str[j]);
		j++;
	}
	printf("\n\n");	
}





