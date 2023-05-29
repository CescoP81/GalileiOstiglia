/*  funzione di tipo stringa con argomenti 
	una stringa
	una puntatore a funzione (arg una stringa e return stringa)
*/
#include <stdio.h>
#include <string.h>

char* esercizio( char*, char(*)(char));
char (*f)(char);

char up(char);
void initStringa(char[], int);

int main(){
	char *str = malloc(sizeof(char) * 50);
	initStringa(str, 50);	
	printf("%s", esercizio(str, up));		// passo come argomento una funzione (con argomento una stringa ed una funzione
	return 0;
}

char* esercizio(char *s, char (*f)(char)){
	int i = 0;
	while( *(s+i) != '\0' ){
		*(s+i) = (*f)(*(s+i));	// passo puntatore alla cella di memoria della funzione
		i++;			        // incremento contatore
	}
	//*(s+i) = '\0';			// chiudo stringa
	
	return s;			        // ritorno la stringa
}


void initStringa(char _str[], int _dim){
    printf("Inserisci stringa: ");
    scanf("%s", _str);
    fflush(stdin);
}

char up(char c){
    if(c>='a' && c<='z')
	    return c-'a'+'A';
    else
        return(c);
}