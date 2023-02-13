/*realizzare un programma che inserito un numero da tastiera 
intero compreso tra 5  e 25 genera un numero uguale di numeri primi casuali
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int n;
	int cnt;
	srand(time(NULL));
	int num;
	int div;
	int cntDiv;
	
	//1) input del numero iniziale
	do{
		printf("inserisci un numero compreso tra 5 e 25: ");
		scanf("%d", &n);
		fflush(stdin);
	}while((n<5) || (n>25));


	cnt=1;
	while(cnt<=n){
		num=1+rand()%50;
		cntDiv=0;
		div=1;
		while(div<=num){
			if(num%div==0){
				cntDiv++;
			}
			div++;			
		}
		if(cntDiv<=2){		
			printf("%d ", num);
			cnt++;
		}		
	}	
	return(0);
	
}
