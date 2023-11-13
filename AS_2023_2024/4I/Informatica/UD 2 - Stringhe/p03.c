/**
 * Creare un programma C che soddisfi le seguenti richieste:
 * - [x] input di una stringa.
 * - [x] stampa di una stringa a video con funzione ricorsiva.
 * - [x] Conteggio delle lettere maiuscole e minuscole in una stringa.
 * - [x] Verifica se esistono doppie in una stringa 'otto', 'sette'.
 * - [x] Prima lettera sempre maiuscola (se la stringa inizia con una minuscola, la trasforma in maiuscola).
 * - [] Per ogni lettera calcola e stampa il numero di occorrenze (quante volte ogni lettera compare).
 * - [] Crea stringa inversa. (st1 è l'originale, st2 è l'inversa).
 * - [] Verifica se due stringhe sono anagrammi (st2 è anagramma di st1, anagramma: parole diverse ma formate dalle stesse lettere)
 * 
 * Utilizzare le funzioni già esistenti nel file lib.c/lib.h, le nuove funzioni prima farne un test nel main e poi spostarle nel file libreria.
*/
#include <stdio.h>
#include "lib.c"
const int DIM = 21;

void stampaStringaRicorsiva(char[], int);
void contaMaiuscoleMinuscole(char[]);
int verificaDoppie(char[]);
void primaLetteraMaiuscola(char[]);

int main(){
    char str[DIM];

    // punto 1
    initStringa(str, DIM);
    inputStringa(str);

    // punto 2
    stampaStringaRicorsiva(str, 0);

    // punto 3
    contaMaiuscoleMinuscole(str);

    // punto 4
    if(verificaDoppie(str))
        printf("\nNella stringa '%s' esistono una o piu' lettere doppie\n", str);
    else
        printf("\nNella stringa '%s' non sono presenti doppie.\n", str);
    
    // punto 5
    primaLetteraMaiuscola(str);
    printf("Stringa modificata: %s\n", str);

    
}

void stampaStringaRicorsiva(char _str[], int _index){
    if(_str[_index] != '\0'){
        printf("%c", _str[_index]);
        stampaStringaRicorsiva(_str, _index+1);
    }
}
void contaMaiuscoleMinuscole(char _str[]){
    int i;
    int cntMaiuscole, cntMinuscole, lungStringa;

    lungStringa = lunghezzaStringa(_str);
    cntMaiuscole = 0;
    cntMinuscole = 0;
    for(i=0; i<lungStringa; i++){
        if(_str[i]>='A' && _str[i]<='Z')
            cntMaiuscole = cntMaiuscole + 1;
        if(_str[i]>='a' && _str[i]<='z')
            cntMinuscole = cntMinuscole + 1;
    }
    printf("Maiuscole: %d - Minuscole: %d\n", cntMaiuscole, cntMinuscole);
}
int verificaDoppie(char _str[]){
    int i;
    int esistonoDoppie = 0;

    for(i=0; i<lunghezzaStringa(_str)-1; i++){
        if(_str[i]==_str[i+1])
            esistonoDoppie = 1;
    }

    return(esistonoDoppie);
}
void primaLetteraMaiuscola(char _str[]){
    int offsetAlfabeto;
    if(lunghezzaStringa(_str)>0){
        if(_str[0]>='a' && _str[0]<='z'){
            offsetAlfabeto = _str[0] - 'a';
            _str[0] = 'A' + offsetAlfabeto;
        }
    }
}