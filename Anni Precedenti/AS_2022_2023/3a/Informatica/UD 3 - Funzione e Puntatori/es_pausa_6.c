/* creare un programma che richiede un numero intero compreso tra -100
e +100, se è negativo calcola e visualizza il valore assoluto, altrimenti
visualizza tutti i numeri pari divisibili per 3 e per 8 compresi tra 1 
e n inserito.
*/

#include <stdio.h>

int main(){
	int n;
	int cnt;
	
	do{
		printf("inserisci un numero: ");
		scanf("%d", &n);
		fflush(stdin);
	}while(n<-100 || n>+100);
	
	if(n<0){ //se numero negativo
		n=-n;
		printf("valore assoluto: %d", n);
	}
	
	if(n>0){
		cnt=1;
		while(cnt<=n){
			if(cnt%2==0){
				if(cnt%3==0){
					if(cnt%8==0){
						printf("%d ", cnt);
					}
				}
			}
			// oppure if((cnt%2==0) && (cnt%3==0) && (cnt%8==0))
			cnt++;
		}
	}
	return(0);
}
