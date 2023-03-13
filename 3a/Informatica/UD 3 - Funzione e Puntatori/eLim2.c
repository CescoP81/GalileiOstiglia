/* realizza un programma con le seguenti funzioni
1. scambia: riceve 2 parametri e ne scambia i valori 
2. fattori primi: ricevi un parametro e visualizza i fattori primi
*/

void scambio(int x, int y);
void swap(int *a, int *b); 
void fattori (int a);

#include <stdio.h>
int main(){
	int a;
	int cnt;
	int b=12;
	
	printf("A: ");
	scanf("%d", &a);
	fflush(stdin);
	
	cnt=1;
	while(cnt<=a){
		if(a%cnt==0){
			printf("%d ", cnt);
		}
		cnt++;
	}
	swap(&a,&b);
	printf("\na=%d b=%d",a,b);
	fattori(a);
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void fattori (int a){
	int cnt = 2;
	while(a>1){
		if(a%cnt==0){
			printf("\n%d", cnt);
			a= a/cnt;
		}else{
			cnt++;
		}
	}
	
}

