#include <stdio.h>

const int DIM=20;

/** 
 * Ritorna la lunghezza in caratteri della stringa passata come parametro.
 * @param char[] Stringa da utilizzare per il conteggio caratteri.
 * @return Numero di caratteri che compongono la stringa.
 */
int lunghezzaStringa(char _str[]);

int contaCarattere(char _str[], char _c);
int presentaDoppie(char _str[]);

int main(){
    int a, b;
    char str[DIM];
    char c;
    int tmp;
    int i;
    int contatoreLettera;

    printf("Inserisci una stringa: ");
    gets(str);

    printf("Inserisci un carattere: ");
    scanf("%c", &c);
    
    printf("\n\n%s -> %c\n\n", str, c);

    contatoreLettera = contaCarattere(str, c);
    printf("Il carattere compare nella stringa %d volta/e.\n", contatoreLettera);

    if(presentaDoppie(str) == 1)
        printf("La parola presenta almeno una doppia.\n");
    else
        printf("La parola NON presenta doppie lettere.\n");
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
int contaCarattere(char _str[], char _c){
    int cntVolte;
    int i;

    cntVolte = 0;
    for(i=0; i<lunghezzaStringa(_str); i++){
        if(_str[i] == _c)
            cntVolte++;
    }

    return(cntVolte);
}
int presentaDoppie(char _str[]){
    int trovataDoppia;
    int i;

    trovataDoppia = 0;
    for(i=0; i<lunghezzaStringa(_str); i++){
        if(_str[i] == _str[i+1])
            trovataDoppia = 1;
        // GUAI METTERE UN ELSE CON trovataDoppia=0;
    }
    return(trovataDoppia);
}