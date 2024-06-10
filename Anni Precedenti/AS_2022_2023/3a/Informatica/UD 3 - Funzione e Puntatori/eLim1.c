/* 1) Funzione quadrato che riceve un parametro intero chiamato n;
	Se N è minore di 20 stampa un quadrato di asterischi pari a n, altrimenti stampa il messaggio 
	"quadrato non valido"
	2) Funzione prossimoPrimo riceve un numero n, determina e visualizza il successivo numero primo
	a n.
	3)funzione divisoriComuni, riceve due parametri interi, determina e 
	comunica quanti divisori sono comuni ai due parametri.
	4) Funzione generaPrimo, genera un numero primo random compreso tra due estremi passati come parametri.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quadrato(int);
int prossimoPrimo(int);
void divisoriComuni(int, int);
int generaPrimo (int, int);

int main(){
	int n;
	int m=30;
	int a;
	int r;
	
	srand(time(NULL));
	do{
		printf("Inserisci un valore: ");
		scanf("%d", &n);
		fflush(stdin);
	}while(n<10 || n>50);
	printf("%d\n", n);
	quadrato(n);	
	
	a = prossimoPrimo(n);
	printf("il prossimo valore primo è %d", a);
	
	divisoriComuni(n, m);
	
	r = generaPrimo(10, 25);
	printf("Il numero primo random generato e' %d", r);
	
}
void quadrato(int _n){
	int i;
	int j;
	
	if(_n<20){
		for(i=0; i<_n; i++){
			for(j=0; j<_n; j++)
				printf("* ");
			printf("\n");		
		}
	}else{
		printf("Quadrato non valido\n");
	}
}

int prossimoPrimo(int _n){
	int div;
	int i;
	
	do{
		_n++;
		div = 1;
		i = 0;
		while(div <= _n){
			if(_n % div == 0){
				i++;
			}
			div++;
		}
	}while(i > 2);
	return(_n);
}
void divisoriComuni(int _n, int _m){
	int i;
	int cnt=0;
	
	int max;
	int min=_n;
	
	if(min>_m){
		max=_n;
		min=_m;
	}
	else{
		min=_m;
		max=_n;
	}
	for(i=1;i<=min;i++){
		if(_n%i==0 && _m%i==0){
			cnt++;
		}
	}
	
	printf("\n%d", cnt);
}

int generaPrimo(int _min, int _max){
	int r;
	int div;
	int idiv;
	do{
		idiv = 0;
		r = _min + rand() % (_max - _min + 1);
		for(div = 1; div <= r; div++){
			if(r % div == 0){
				idiv++;
			}
		}
	}while(idiv > 2);
	
	return(r);
}



