#include <stdio.h>
const int DIM=20;

/** 
 * Ritorna la lunghezza in caratteri della stringa passata come parametro.
 * @param char[] Stringa da utilizzare per il conteggio caratteri.
 * @return Numero di caratteri che compongono la stringa.
 */
int lunghezzaStringa(char _str[]);

/**
 * Restituisce il carattere della stringaalla posizione scelta e passata come parametro.
 * @param char[] Stringa di riferimento
 * @param int Indice scelto dall'utente.
 * @return Carattere presente all'indice scelto, altrimenti -1.
 */
char charAt(char _str[], int _index);

/**
 * Sostituisce un carattere in una stringa all'indice indicato.
 * @param char[] Stringa di riferimento.
 * @param char Carattere da inserire nella stringa.
 * @param int Indice del carattere da sostituire 0->(len-1).
 */
void changeCharAt(char _str[], char _c, int _index);

int main(){
    char st[DIM];
    int indice;
    char carattere;

    printf("Inserisci una parola: ");
    gets(st);

    printf("Inserisci un indice: ");
    scanf("%d", &indice);
    fflush(stdin);

    carattere = charAt(st, indice);

    if(carattere == -1){
        printf("Indice scelto esterno alla stringa!\n");
    }
    else{
        printf("Carattere alla posizione %d -> %c", indice, carattere);
    }

    printf("Inserisci l'indice: ");
    scanf("%d", &indice);
    fflush(stdin);
    printf("Inserisci il carattere: ");
    scanf("%c", &carattere);
    changeCharAt(st, carattere, indice);

    printf("\nLa stringa modificata e': %s", st);
    return(0);
}

int lunghezzaStringa(char _str[]){
    int i;
    int cntLettere;

    i=0;
    cntLettere = 0;
    while(_str[i] != '\0'){
        cntLettere++;
        i++;
    }
    return(cntLettere);
}

char charAt(char _str[], int _index){
    if((_index >= 0) && (_index < lunghezzaStringa(_str))){
        return(_str[_index]);
    }
    else{
        return(-1);
    }
}

void changeCharAt(char _str[], char _c, int _index){
    if(_index >=0 && _index < lunghezzaStringa(_str)){
        _str[_index] = _c;
    }
}