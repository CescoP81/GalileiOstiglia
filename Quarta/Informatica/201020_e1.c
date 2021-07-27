#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define DIM 30
// prototipi
void inserisci_stringa(char []); // esegue l'input di una stringa da tastiera.
int conta_vocali(char []); 		// conta quante vocali sono presenti 
								//nella stringa e lo ritorna al main
int conta_lettera(char [], char);


int main(){
	char str[DIM];
	
	inserisci_stringa(str);
	
	printf("Stringa Inserita: %s\n", str);
	
	printf("Vocali presenti: %d\n", conta_vocali(str));
	
	getchar();
	return(0);	
}

void inserisci_stringa(char _s[]){
	printf("Stringa: ");
	//scanf("%s", _s); // acquisisce fino al carattere 'invio' oppure spazio.
	gets(_s);	// acquisisce fino al carattere 'invio'.
	fflush(stdin);
}

int conta_lettera(char _s[], char c){
	int i;
	int cnt;
	
	cnt=0;
	i = 0;
	while(_s[i] != '\0'){
		if(_s[i] == c) cnt++;
		i = i+1;
	}
	return(cnt);
}

int conta_vocali(char _s[]){
	int i;
	int cnt;
	/*
	cnt = 0;
	i = 0;
	while(_s[i] != '\0'){
		if(_s[i] == 'a')	cnt++;
		if(_s[i] == 'e')	cnt++;
		if(_s[i] == 'o')	cnt++;
		if(_s[i] == 'i')	cnt++;
		if(_s[i] == 'u')	cnt++;
		i = i + 1;
	}*/
	cnt = 0;
	cnt += conta_lettera(_s, 'a');
	cnt += conta_lettera(_s, 'e');
	cnt += conta_lettera(_s, 'i');
	cnt += conta_lettera(_s, 'o');
	cnt += conta_lettera(_s, 'u');
	return(cnt);
}
