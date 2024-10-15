#include <stdio.h>
// sezione delle costanti.
const int DIM = 20;
const int DIM_L = 26;
// sezione dei prototipi.
/** 
 * Ritorna la lunghezza in caratteri della stringa passata come parametro.
 * @param char[] Stringa da utilizzare per il conteggio caratteri.
 * @return Numero di caratteri che compongono la stringa.
 */
int lunghezzaStringa(char _str[]);

/**
 * Verifica e ritorna un 1 se le due stringhe passate sono una l'anagramma
 * della'altra; altrimenti ritorna 0.
 * Anagramma: due parole sono anagrammi se sono formate dalle stesse lettere
 * in egual numero ma in posizioni diverse.
 * es. sotto -> tosto sono due anagrammi.
 * es. sotto -> cotto non sono anagrammi.
 */
int isAnagrammi(char _str1[], char _str2[]);

// sezione del main program.
int main(){
    char st1[DIM];
    char st2[DIM];

    printf("Inserisci parola 1: ");
    gets(st1);
    printf("Inserisci parola 2: ");
    gets(st2);

    printf("Le due parole sono: %s, %s.", st1, st2);
    if(isAnagrammi(st1, st2) == 1)
        printf("\n\nLe due parole sono Anagrammi.\n");
    else
        printf("\n\nLe due parole NON sono Anagrammi.\n");
    return(0);
}

// sezione di definizione delle funzioni.
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
int isAnagrammi(char _str1[], char _str2[]){
    int cntLettere[DIM_L];  // 26 celle intere da usare come contatori per ogni lettera dell'alfabeto.
    int indiceLettera;
    int i;
    int flag;

    // azzero il vettore contatori lettere
    for(i=0; i<DIM_L; i++){
        cntLettere[i] = 0;
    }
    // scorro tutta la str1 e per ogni lettera INCREMENTO il relativo contatore.
    for(i=0; i<lunghezzaStringa(_str1); i++){
        indiceLettera = _str1[i]-'a';
        cntLettere[indiceLettera]++;
    }
    // stampo per verifica le celle del vettore contatori
    /*for(i=0; i<DIM_L; i++){
        printf("%c: %d ", ('a'+i), cntLettere[i]);
        if((i%5 == 0) && (i!=0))
            printf("\n");
    }*/
    // scorro tutta la str2 e per ogni lettera DECREMENTO il relativo contatore.
    for(i=0; i<lunghezzaStringa(_str2); i++){
        indiceLettera = _str2[i]-'a';
        cntLettere[indiceLettera]--;
    }
    //printf("\n\n");
    // stampo per verifica le celle del vettore contatori
    /*for(i=0; i<DIM_L; i++){
        printf("%c: %d ", ('a'+i), cntLettere[i]);
        if((i%5 == 0) && (i!=0))
            printf("\n");
    }*/

    flag = 1;
    for(i=0; i<DIM_L; i++){
        if(cntLettere[i] != 0)
            flag = 0;
    }

    return(flag);
}