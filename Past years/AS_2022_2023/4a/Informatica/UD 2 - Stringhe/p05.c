#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 100
/**
 * Calcola e restituisce la lunghezza di una stringa
 * @param char* Riferimento alla stringa da esaminare.
 * @return int Lunghezza della stringa.
*/
int strLength(char*);
/**
 * Verifica se una stringa è palindroma oppure no.
 * @param char* Riferimento alla stringa da esaminare.
 * @return int Booleano vero/falso.
*/
int checkPalindroma(char*);
/**
 * Verifica se due stringe sono una l'anagramma dell'altra.
 * @param char* Riferimento alla prima stringa.
 * @param char* Riferimento alla seconda stringa.
 * @return int Booleano vero/falso.
*/
int checkAnagramma(char*, char*);
/**
 * Stampa a video il numero di anagrammi richiesti partendo dalla stringa passata.
 * @param char* Riferimento alla stringa base.
 * @param int Numero di anagrammi da generare.
*/
void stampaAnagrammi(char*, int);
/**
 * Genera un anagramma partendo da una stringa base
 * @param char* Riferimento alla stringa base.
 * @param char* Riferimento alla stringa per l'anagramma.
*/
void generaAnagramma(char*, char*);

int main(){
    char *st1 = malloc(sizeof(char) * DIM);
    char *st2 = malloc(sizeof(char) * DIM);
    srand(time(NULL));

    printf("Inserisci una parola: ");
    scanf("%s", st1);
    fflush(stdin);

    if(checkPalindroma(st1))
        printf("Parola %s e' palindroma\n", st1);
    else
        printf("Parola %s non e' palindroma\n", st1);
    printf("\n");

    printf("Inserisci una seconda parola: ");
    scanf("%s", st2);
    fflush(stdin);

    if(checkAnagramma(st1, st2))
        printf("Le parole %s - %s sono Angrammi\n", st1, st2);
    else
        printf("Le parole %s - %s non sono Angrammi\n", st1, st2);
    printf("\n");

    //generaAnagramma(st1, st2);        // test della funzione che genera un singolo anagramma.
    //printf("Anagramma: %s", st2);
    printf("\nAnagrammi generati: ");
    stampaAnagrammi(st1, 5);
    
    return(0);
}

int strLength(char *_st){
    int i;
    i=0;
    while(*(_st+i) != '\0'){
        i++;
    }
    return(i);
}
int checkPalindroma(char *_st1){
    int i;
    int len;

    len = strLength(_st1);
    for(i=0; i<len; i++){
        if(*(_st1+i) != *(_st1+len-i-1))
            return(0);
    }
    return(1);
}
int checkAnagramma(char *_st1, char *_st2){
    int lettere[26];
    int i;
    int indexLettera;
    int len;
    for(i=0; i<26; i++)
        lettere[i] = 0;
    
    if(strLength(_st1) != strLength(_st2))
        return(0);
    else{
        len = strLength(_st1);
        for(i=0; i<len; i++){                   // scansionando tutta la stringa1 incremento i contatori del vettore lettere.
            indexLettera = *(_st1+i) - 'a';
            lettere[indexLettera]++;
        }

        for(i=0; i<len; i++){                   // scansionando tutta la stringa2 decremento i contatori del vettore lettere.
            indexLettera = *(_st2+i) - 'a';
            lettere[indexLettera]--;
        }

        for(i=0; i<26; i++){                    // controllo i contatori del vettore lettere
            if(lettere[i] != 0)
                return(0);                      // se un contatore è diverso da 0 le due stringhe non sono anagrammi         
        }
        return(1);                              // se arrivo qui, le due stringhe sono anagrammi.
    }
}
void generaAnagramma(char *_st1, char *_st2){
    int lettere[26];
    int i;
    int indexLettera;
    int len;

    for(i=0; i<26; i++)
        lettere[i] = 0;
    
    len = strLength(_st1);
    for(i=0; i<len; i++){                   // scansionando tutta la stringa1 incremento i contatori del vettore lettere.
        indexLettera = *(_st1+i) - 'a';
        lettere[indexLettera]++;
    }
    
    i=0;
    while(i < len){                         // ciclo per pescare "a caso" lettere da usare nella seconda stringa.
        do{
            indexLettera = rand()%26;
        }while(lettere[indexLettera] == 0);

        *(_st2+i) = 'a'+indexLettera;
        lettere[indexLettera]--;
        i++;
    }
    *(_st2+i) = '\0';
}
void stampaAnagrammi(char *_st1, int _n){
    char *stAnagramma = malloc(sizeof(char)*DIM);
    int i;
    i=0;
    while(i < _n){
        generaAnagramma(_st1, stAnagramma);     // sfrutto la funzione di base che genera un singolo anagramma, la richiamo n volte.
        printf("%s ", stAnagramma);
        i++;
    }
}