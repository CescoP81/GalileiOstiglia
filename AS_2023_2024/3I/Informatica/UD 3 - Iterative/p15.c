#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int numero;
	int cnt;
	
	/* rand() genera un numero random casuale.
	   qualunque numero modulo 10 (%10) genera un resto compreso tra 0 e 9.
	*/
	cnt = 0;
	while(cnt<5){
		numero = rand() % 10; 
		printf("Numero generato random: %d\n", numero);
		cnt = cnt + 1;
	}
	return(0);
}
