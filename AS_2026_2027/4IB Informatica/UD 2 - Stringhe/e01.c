/*
    Introduzione alla gestione delle stringhe in C
*/
#include <stdio.h>

#define DIM 20 // il vettore di caratteri sarà di 20 posizioni, MA i caratteri possibili saranno 19 + 1(terminatore) '\0'

int main(){
    char str[DIM];      // vettore per la stringa.
    int i;              // variabile per cicli sul vettore.
    char junk;          // svuota buffer di tastiera.
    int len;            // contatore delle lettere di una parola.

    // 1° inizializzo tutte le celle con caratter terminatore.
    for(i=0; i<DIM; i++)
        str[i] = '-'; // sbagliato mettere "\0"
    

    // 2° richiedo in input una stringa da tastiera.
    printf("Inserisci una parola: ");
    scanf("%s", str);
    junk = getchar();

    
    // 3° stampo la stringa inserita per verifica l'avvenuto inserimento corretto.
    printf("Parola inserita: %s\n", str);

    /*  Utilizzando scanf e printf con %s, la stringa viene acquisita o stampa fino al primo \0 trovato;
        in fase di input la scanf si ferma quando trova uno spazio oppure viene premuto invio,
        in fase di output la printf si ferma quando trova un '\0'
        es input:
        banana -> str[]=banana'\0'
        banane in pigiama -> str[]=banane'\0'
    */

    // 4° stampo tutto il vettore char-by-char
    printf("Vettore char-by-char: ");
    for(i=0; i<DIM; i++){
        if(str[i] != '\0')
            printf("%c", str[i]);
        else
            printf("*");
    }

    // 5° calcolo lunghezza di una parola
    len = 0;
    while(str[len] != '\0')
        len++;
    printf("\nLunghezza: %d\n", len);

    // 6° stampo la parola al contrario
    printf("Parola al contrario: ");
    for(i=len-1; i>=0; i--){
        printf("%c", str[i]);
    }
    return 0;
}