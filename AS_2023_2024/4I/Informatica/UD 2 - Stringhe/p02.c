/*
    creare un programma C che sfruttando la conoscenza delle stringhe permetta le seguenti
    funzioni:
    - [x] Inizializzazione di una stringa vuota.
    - [x] Inserimento di una stringa da tastiera.
    - [x] Conteggio delle lettere della stringa.
    - [x] Conteggio di una lettera inserita da tastiera.
    - [x] Conteggio di quante vocali compaiono nella stringa.
    - [x] Sostituzione di una lettera src con una lettera sostitutiva dst.
    - [x] Visualizzazione di una stringa al contrario.
    - [] Verifica se una parola inserita è palindroma.

    Ogni singolo punto è da realizzare con una specifica funzione, relativi parametri
    passati per valore/riferimento e con ritorno void o non-void. 
*/
#include <stdio.h>

const int DIM=21;
/**
 * Initialize a string to empty string with all '\0'.
 * @param char[] Reference to string(Array of char).
*/
void initStringa(char[], int);
/**
 * Request a string as input.
 * @param char[] Reference to string(Array of char).
*/
void inputStringa(char[]);
/**
 * Count and return the number of characters of the string.
 * @param char[] Reference to string(Array of char).
 * @return Number of characters.
*/
int lunghezzaStringa(char[]);
/**
 * Count and return the number of occurencies of a specific letter.
 * @param char[] Reference to string (Array of char).
 * @param char The selectec letter.
 * @return Number of occurencies 
*/
int contaLetteraStringa(char[], char);
/**
 * Count and return the number of all vocals
 * @param char[] Reference to string (Array of char)
 * @return Numbers of vocals.
*/
int contaVocaliStringa(char[]);
/**
 * Find and replace a specific letter with another one.
 * @param char[] Reference to string (Array of char).
 * @param char Letter to find and replace.
 * @param char New letter to use.
*/
void sostituisciCarattereStringa(char[], char, char);
/**
 * Print a string reversed.
 * @param char[] Reference to string (Array of char)
*/
void stampaContrarioStringa(char[]);
/**
 * Tests whether a string is equal to its opposite
 * @param char[] Reference to string (Array of char).
 * @return 1->True / 0->False 
*/
int verificaPalindroma(char[]);

int main(){
    char str[DIM];

    initStringa(str, DIM);
    inputStringa(str);
    printf("Stringa Inserita: %s.\n", str);
    printf("Lunghezza della stringa: %d.\n", lunghezzaStringa(str));
    printf("La lettera a compare %d volta/volte.\n", contaLetteraStringa(str, 'a'));
    printf("Nella stringa %s sono presenti %d vocali.\n", str, contaVocaliStringa(str));
    sostituisciCarattereStringa(str, 'a', 'z');
    printf("Stringa Inserita: %s.\n", str);
    printf("Stringa al contrario: ");
    stampaContrarioStringa(str);
    if(verificaPalindroma(str) == 1)
        printf("\nLa parola e' palindroma.");
    else
        printf("La parola NON E' palindroma.");
    return(0);
}

void initStringa(char _s[], int _dim){
    int i;
    for(i=0; i<_dim; i++)
        _s[i] = '\0';
}

void inputStringa(char _s[]){
    printf("Inserisci una parola: ");
    scanf("%s", _s);
}

int lunghezzaStringa(char _s[]){
    int i=0;
    while(_s[i] != '\0')
        i = i + 1;
    return(i);
}

int contaLetteraStringa(char _s[], char _c){
    int i;
    int cnt;

    i=0; 
    cnt=0;

    while(_s[i]!='\0'){
        if(_s[i] == _c){
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    return(cnt);
}

int contaVocaliStringa(char _s[]){
    int i;
    int cnt;

    i = 0;
    cnt = 0;
    while(_s[i] != '\0'){
        if(_s[i]=='a' || _s[i]=='e' || _s[i]=='i' || _s[i]=='o' || _s[i]=='u'){
            cnt = cnt + 1;
        }
        i = i + 1;
    } 
    return(cnt);
}

void sostituisciCarattereStringa(char _s[], char _src, char _dst){
    int i;

    i = 0;
    while(_s[i] != '\0'){
        if(_s[i] == _src)
            _s[i] = _dst;
        i = i + 1;
    }
}

void stampaContrarioStringa(char _s[]){
    int i;
    for(i=lunghezzaStringa(_s)-1; i>=0; i--)
        printf("%c", _s[i]);
}

int verificaPalindroma(char _s[]){
    int i;
    int lung = lunghezzaStringa(_s);
    for(i=0; i<lung; i++){
        if(_s[i] != _s[lung-i-1]){
            return(0);
        }
    }
    return(1);
}