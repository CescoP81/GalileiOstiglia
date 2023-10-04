#include <stdio.h>

int main()
{
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int e=0;
	int MAX=0;
	
	printf("Inserisci i 5 valori e ti calcolere' il maggiore\n");
	
	printf("A=");
	scanf("%d",&a);
	
	printf("B=");
	scanf("%d",&b);
	
	printf("C=");
	scanf("%d",&c);
	
	printf("D=");
	scanf("%D",&d);	
	
	printf("E=");
	scanf("%d",&e);
	
	MAX=a;

	if(b>MAX) {
		MAX=b;
	}	
	
	if(c>MAX) {
		MAX=c;
	}	
	
	if(d>MAX){
		MAX=d;
	}
		
	if(d>MAX){
		MAX=e;
	}
 	else{
 		
	}
	
	printf("Il valore maggiore e': ");
	printf("%d",MAX);

	return(0);	
}

