/*1) realizzare un programma che richiama la funzione tabellina la quale riceve due valori passati per valore 
la funzione stampa tutte le tabelline dei valori compresi tra i due valori passati
2) creare una funzione che determina il numero minimo di bit per codificare un numero passato come valore.
3)creare una funzione che riceve un numero decimale (float), se il numero è nella condizione 0,... moltiplicarlo 
8 volte per 2 e ad ogni moltiplicazione stampare la parte intera prima di toglierla dal numero;
altrimenti stampare il messaggio non codificabile.
4) Creare una funzione che riceve tre parametri e restituisce un intero, la funzione ordina in modo crescente i tre parametri 
   e restituisce 1 se è stato effettuato almeno uno scambio.
*/

#include <stdio.h>

void tabellina (int, int );

int codifica (int );

void moltiplicazione(float);

int ordina(int *, int *, int *);

int main(){
	int val1;
	int val2;  
	float v=0;
	int v1 = 10;
	int v2 = 8;
	int v3 = 31;
	int y;
	
	/*
	do{
		printf("inserisci il primo valore: ");
		scanf("%d", &val1);
		fflush(stdin);
	}while(val1<1 || val1>10);
	
	do{
		printf("inserisci il secondo: ");
		scanf("%d", &val2);
		fflush(stdin);
	}while(val2<1 || val2>10);
	
	tabellina(val1, val2);
	scanf("%d", &val1);
	int x=codifica(val1);
	
	printf("\nIl numero minimo di bit necessario per codificare il numero e' %d \n", x);
	
	printf("inserisci un valore:");
	scanf("%f", &v);
	fflush(stdin);
	moltiplicazione(v);
	*/
	v1 = 24;
	v2 = 27;
	v3 = 30;
	y = ordina(&v1, &v2, &v3);
	printf("%d %d %d %d", y, v1, v2, v3);
}
void tabellina (int _val1, int _val2){
	int i; //variabile cnt per le righe
	int j;  //variabile cnt per le colonne 
	int mol;
	
	for (i=_val1; i<=_val2; i++ ){
		for(j=1; j<=10; j++){
			mol = i * j;
			printf("%4d", mol);	
		}
		printf("\n");
	}
}

int codifica (int _Val1 ){
	int divisore=2;
	int cnt=0;
	while(_Val1>0){
		cnt++;
		_Val1=_Val1/2;
	}
	return cnt;
}

void moltiplicazione(float _v){
	int i;
	//printf("ok %f\n", _v);
	if(_v<1){
		for(i=1; i<=8; i++){
			_v=_v*2;
			//printf("%f\n", _v);
			printf("%d\n", (int)_v);
			_v=_v-((int)_v);
		}
	}else{
		printf("il messaggio non � codificabile.");
	}
}

int ordina(int *v1, int *v2, int *v3){
	int tmp;
	int scambiati = 0;
	
	if(*v1 > *v2){
		tmp = *v1;
		*v1 = *v2;
		*v2 = tmp;
		scambiati = 1;
	}
	
	if(*v1 > *v3){
		tmp = *v1;
		*v1 = *v3;
		*v3 = tmp;
		scambiati = 1;
	}
	
	if(*v2 > *v3){
		tmp = *v2;
		*v2 = *v3;
		*v3 = tmp;
		scambiati = 1;
	}
	
	return(scambiati);	
}