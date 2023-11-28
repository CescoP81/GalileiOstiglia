/*
    creare un programma che richiede l'inserimento di una stringa, quindi
    1. la visualizza al contrario con funzione ricorsiva
    2. passate 2 lettere determina quella che compare più volte 
    3. mette in maiuscolo a lettere alternate (prima si, seconda no, terza si, ...)
*/

#include <stdio.h>

int const DIM = 16;

void initStr(char *, int);
void stampaRicCont(char *);
char letteraFreq(char *, char, char, int);




int main(){
    char str[DIM];

    initStr(str, DIM);

    printf("inserisci una parola: \n");
    scanf("%s", str);

    stampaRicCont(str);
    
    char x = letteraFreq(str, 'a', 'r', DIM);
    printf("\n\nla lettera esce %c volte", x);


}

void initStr(char *str, int dim){
    for(int i = 0; i < dim; i++){        
        *(str+i) = '\0';
        //*str++;
    }
}



void stampaRicCont(char *str){

    if(*str != '\0'){
        stampaRicCont(str+1);
        printf("%c", *str);
    }
}

char letteraFreq(char *str, char l1, char l2, int dim){
    int x = 0;      //contatore per l1
    int y = 0;      //contatore per l2

    for(int i = 0; i < dim; i++){
        if(*(str+i) == l1){
            x++;
        }
        if(*(str+i) == l2){
            y++;
        }

    }

    if(x>y){
        return(l1);
    }
    else{
        return(l2);
    }
}
