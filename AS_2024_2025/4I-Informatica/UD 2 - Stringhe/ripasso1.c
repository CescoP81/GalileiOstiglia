#include <stdio.h>

int contaConsonanti(char _parola[]);
void vediStringa(char _parola[], int pos);

const int DIM=25;

int main(){
	char parola[DIM+1];
	//inserimento di una parola da tastiera
	printf("Inserisci una parola: ");
	gets(parola);
	printf("%s", parola);
	
	//contaConsonanti(parola);
	vediStringa(parola, 1);
	printf("\n");
	vediStringa(parola, 0);
	return(0);
}

int contaConsonanti(char _parola[]){
	int i;
	int cnt=0;
	
	// for(i=0; i<DIM+1; i++){ 
	i=0;
	while(_parola[i]!='\0')	{
	
		if(_parola[i]!='a' && _parola[i]!='e' && _parola[i]!='i' && _parola[i]!='o' && _parola[i]!='u'){
			cnt++;
		}
		i=i+1;
	}
	printf("\n\n%d", cnt);
}
void vediStringa(char _parola[], int pos){
	//visualizza la stringa al contrario e successivamente visualizza
	//le lettere di posto pari se pos = 0, di posto dispari se pos = 1
	// ciao
	int i=0;
	int j;

	while(_parola[i]!='\0'){
		i++;
	}
	printf("\n\n%d\n", i);
	for(j=i-1; j>=0; j--){
		printf("%c", _parola[j]);
	}
	printf("\n");printf("\n");
	for(j=0; j<i; j++){
		/*if(j%2==0 && pos== 0){
			printf("%c", _parola[j]);
		}
		if(j%2==1 && pos == 1){
			printf("%c", _parola[j]);
		}*/
		if(j%2 == pos){
			printf("%c", _parola[j]);
		}
	}
}
