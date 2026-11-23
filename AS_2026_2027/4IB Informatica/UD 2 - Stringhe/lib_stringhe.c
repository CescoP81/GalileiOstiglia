#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib_stringhe.h"

void initStringa(int _dim, char _str[]){
    int i;
    for(i=0; i<_dim; i++)
        _str[i] = '\0';
}

void strCharByChar(int _dim, char _str[]){
    int i;
    for(i=0; i<_dim; i++)
        printf("%c", _str[i]);
}

int lunghezzaStringa(char _str[]){
    int len;
    
    len = 0;
    while(_str[len] != '\0')
        len++;
    
    return len;
}
int contaVocali(char _str[]){
    int i;
    int cntVocali;

    cntVocali = 0;
    for(i=0; i<lunghezzaStringa(_str); i++){
        if((_str[i] == 'a') || (_str[i] == 'e') || (_str[i] == 'i') || (_str[i] == 'o') || (_str[i] == 'u'))
            cntVocali++;
    }

    return cntVocali;
}

int isPalindroma(char _str[]){
    int i;
    int lunghezza;
    int palindroma;

    lunghezza = lunghezzaStringa(_str);

    palindroma = 1;
    for(i=0; i<lunghezza; i++){
        if(_str[i] != _str[lunghezza-i-1])
            palindroma = 0;
    }

    return palindroma;
}
/*
    palindroma = 1;
    str[] = A N N A
    confronta A - A 
    Confronta N - N
    confronta N - N
    confronta A - A

    palindroma = 1;
    str[] = A S S O
    confronta A - O -> palindroma = 0;
    confronta S - S
    confronta S - S
    confronta O - A -> palindroma = 0;
*/

void contaLettere(char _str[]){
    /* sfrutta le informazioni della ASCII TABLE dove una lettera è rappresentata
        da 8bit ovvero 1byte, quindi le possibili combinazioni sono 255.
        In particolare l'alfabeto minuscolo inizia dal carattere 97
        mentre l'alfabeto maiuscolo inizia dal carattere 65
    */
    int cnt_lettera[26]; // vettore dei contatori
    int indice;          // indice da usare sul vettore dei contatori
    int i;               // indice da usare con ciclo for sulla _str

    // azzero tutti i contatori.
    for(indice=0; indice<26; indice++)
        cnt_lettera[indice] = 0;

    // analizzo tutta la stringa _str utilizzando ogni singolo carattere per calcolare l'indice
    // sul vettore cnt_lettera
    for(i=0; i<lunghezzaStringa(_str); i++){
        //indice = _str[i] - 'a'; // calcolo l'indice nel vettore dei contatori associato alla lettera in esame.
        if(_str[i]>='a' && _str[i]<='z')
            indice = _str[i] - 'a';
        if(_str[i]>='A' && _str[i]<='Z')
            indice = _str[i] - 'A';

        cnt_lettera[indice]++;
    }

    // Stampo a video tutti i contatori per verificare che siano stati incrementati solo quelli della parola inserita.
    for(indice=0; indice<26; indice++){
        printf("%c -> %d\t", ('a'+indice), cnt_lettera[indice]);
        if((indice+1)%13 == 0)
            printf("\n");        
        
        /*if(cnt_lettera[indice] != 0){
            printf("%c -> %d\t", ('a'+indice), cnt_lettera[indice]);
            if((indice+1)%5 == 0)
                printf("\n");
        }*/
    }
}

int isAnagramma(char _str1[], char _str2[]){
    int i;      // variabile per muovermi sulle _str
    int indice; // variabile per muovermi nel vettore dei contatori lettere
    int cnt_lettera[26]; // vettore dei contatori.

    // azzero tutti i contatori.
    for(i=0; i<26; i++)
        cnt_lettera[i] = 0;
    
    // verifico le lunghezze delle due stringhe
    if(lunghezzaStringa(_str1) != lunghezzaStringa(_str2))
        return 0;   // se sono diverse non possono essere anagrammi
    else{
        // hanno stessa lunghezza, allora procedo a verificare/contare le lettere.
        for(i=0; i<lunghezzaStringa(_str1); i++){ // incremento i contatori usando str1
            indice = _str1[i] - 'a';
            cnt_lettera[indice]++;
        }

        for(i=0; i<lunghezzaStringa(_str2); i++){ // decremento i contatori usando str2
            indice = _str2[i] - 'a';
            cnt_lettera[indice]--;
        }

        // verifico che tutti i contatori siano a zero
        for(i=0; i<26; i++){
            if(cnt_lettera[i] != 0) // se un contatore non è a zero NON sono anagrammi
                return 0;
        }
        return 1; // se arrivo qui tutti i contatori erano a zero quindi SONO anagrammi
    }
}

void generaAnagramma(char _str1[], char _anagramma[]){
    int i;                  // indice per muovermi sui vettori
    int generato;           // flag che controlla se ho terminato di usare tutte le lettere originali
    int cnt_lettera[26];    // vettore dei contatori.
    int indiceContatore;    // indice per muovermi sul vettore dei contatori.
    int indice;

    // step 1: azzero il vettore dei contatori
    for(i=0; i<26; i++)
        cnt_lettera[i] = 0;

        // step 2: conto quali e quante lettere compongono la parola originale str1
    for(i=0; i<lunghezzaStringa(_str1); i++){
        indice = _str1[i] - 'a';
        cnt_lettera[indice]++;
    }

    // step 3: genero l'anagramma
    //srand(time(NULL));
    i = 0;
    do{
        generato = 1;
        indiceContatore = rand()%26;
        if(cnt_lettera[indiceContatore] > 0){
            _anagramma[i] = 'a'+ indiceContatore;
            i = i + 1;
            cnt_lettera[indiceContatore]--;
        }
        // controllo se ho finito le lettere a disposizione
        for(int j=0; j<26; j++){
            if(cnt_lettera[j] != 0)
                generato = 0;
        }
    }while(generato == 0);
   
    _anagramma[i] = '\0';
}