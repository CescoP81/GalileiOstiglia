/* 
realizare unprogramma che richieda un numeo intero positivo 
inferiore o uguale a venti quindi stampa tutti i numeri
fino a uno che siano dispari 
*/

#include <stdio.h>
	int main(){
		int n1;
		int tmp;
		int cnt1,cnt2;
		
		do{
			printf("inserisci un numero minore uguale a 20: ");
			scanf("%d", &n1);
			fflush(stdin);
		}while(n1>20);
		tmp=n1;
		
		//ciclo da n1 fino a 1 per numeri dispari
		while(n1>=1){
			if(n1%2==1){
				printf("%d ", n1);
			}
			n1=n1-1;
		}
		printf("\n\n");
		//ciclo per scomposizione in fattori primi 
		n1=tmp;
		int div;
	
		div=2;
		printf("fattori primi del numero %d: ",n1);
		while(n1>1){
			if(n1%div==0){
				printf("%d ",div);
				n1=n1/div;
			}else{
				div++;
			}
		}
		// acquisire un secondo numero e comunicare quale dei due numeri ha più fattori primi
		int n2;
		do{
			printf("inserire n2: ");
			scanf("%d", &n2);
			fflush(stdin);
		}while(n2>20);
		
		div=2;
		cnt1=0;
		n1=tmp;
		while(n1>1){
			if(n1%div==0){
				cnt1=cnt1+1;
				n1=n1/div;
			}else{
				div++;
			}
		}
		div=2;
		cnt2=0;
		while(n1>1){
			if(n1%div==0){
				cnt2=cnt2+1;
				n1=n1/div;
			}else{
				div++;
			}
		}
		if(cnt1==cnt2){
			printf("cnt1 e cnt2 hanno lo stesso numero di numeri primi");
		}
		
		if(cnt1<cnt2){
			printf("cnt1 ha un numero inferiore di numeri primi rispetto n2");
		}	
		
		if(cnt1>cnt2){
			printf("cnt1 ha un numero superiore di numeri primi rispetto n1");
		}	
		
		return(0);
	}
