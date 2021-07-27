#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int somma(int, int);
int dividi(int *);
int divisione(int, int, int *, int *);

int main(){
	int a, b, c, e;
	a = 5;
	b = 7;
	c = 0;
	e = 0;
	
	c = somma(a,b);
	printf("Somma: %d\n", c);
	
	c = 19;
	if(dividi(&c)){
		printf("La meta' e': %d\n",c);
	}
	else{
		printf("Numero dispari non divisibile, rimane %d.\n",c);	
	}
	
	a = 8;
	b = 0;
	if(divisione(a,b,&c,&e)){
		printf("%d/%d = %d - r:%d\n",a,b,c,e);
	}
	else
		printf("Divisione non valida, divisore = %d\n",b);
	
	return(0);
}

int somma(int _a, int _b){
	int r;
	r = _a + _b;
	//printf("%d", r);
	return(r);
}

int dividi(int *_a){
	if(*_a%2 == 0){
		*_a = *_a/2;
		return(1);
	}
	else{
		return(0);
	}	
}

int divisione(int _D, int _d, int *_q, int *_r){
	if(_d == 0)
		return(0);
	else{
		*_q = _D/_d;
		*_r = _D%_d;
		return(1);
	}
}






