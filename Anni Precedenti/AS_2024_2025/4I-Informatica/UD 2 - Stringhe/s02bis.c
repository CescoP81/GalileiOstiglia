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
// Stampa per ogni lettera che compone la stringa il relativo codice decimale ASCII
//'ciao' -> 99 105 97 111
void contaAlfabeto(char _str[]);

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

    c = 'a';
    printf("%c -> %d", c, c);

    printf("\n\n");
    for(i=0; i<lunghezzaStringa(str); i++){
        printf("%c -> %d -> %d\n", str[i], str[i], str[i]-'a');
    }
    /*
    c -> 99 -> 2
    i -> 105 -> 8
    a -> 97 -> 0
    o -> 111 -> 14
    */
    printf("\n");
    contaAlfabeto(str);
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
void contaAlfabeto(char _str[]){
    int alfabeto[26];
    int i;

    // azzero il vettore
    for(i=0; i<26; i++)
        alfabeto[i] = 0;
    
    // conto le lettere aumentando i relativi contatori
    for(i=0; i<lunghezzaStringa(_str); i++){
        alfabeto[_str[i]-'a']++;
    }

    // stampo tutto il vettore per vedere le lettere e relative frequenze.
    for(i=0; i<26; i++){
        printf("%c: %d ", ('a'+i), alfabeto[i]);
        if((i+1)%5 == 0)
            printf("\n");
    }
}