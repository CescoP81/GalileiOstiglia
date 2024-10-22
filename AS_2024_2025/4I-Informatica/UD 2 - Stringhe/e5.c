/*
Realizzare un programma C che richieda l'inserimento di due parole st1 e st2 quindi
sviluppare i seguenti punti con relative funzioni:
1. Visualizza la stringa più lunga tra le due e calcola la differenza di lunghezza.
2. Verifica per ogni parola se è palindroma oppure no.
3. Per ogni parola conta e visualizza il numero di vocali presenti.
4. Calcola e restituisce al main la vocale più presente (sia per st1 che per st2).
5. Visualizza le lettere di st1 che compaiono anche in st2.
    pino
    pane
    -> p,n 
6. Visualizza le lettere di st2 che NON compaiono in st1.
7. Cifra la stringa st1 con un fattore k scelta compreso tra 5 e 10; la stringa cifrata
    viene stampata nel main e NON deve essere modificata st1.
*/
#include <stdio.h>
const int DIM = 20;
// -- prototipi delle funzioni 
/** 
 * Ritorna la lunghezza in caratteri della stringa passata come parametro.
 * @param char[] Stringa da utilizzare per il conteggio caratteri.
 * @return Numero di caratteri che compongono la stringa.
 */
int lunghezzaStringa(char _str[]);
/**
 * Verifica se una parola è palindroma, restituendo un valore compreso tra 0 e 1.
 * @param char[] Stringa di riferimento.
 * @return Valore 1-True / 0-False
 */
int isPalindroma(char _str[]);
/**
 * Conta e visualizza le vocali presenti nella stringa.
 * @param char[] Stringa di riferimento.
 */
void contaVocali(char _str[]);
/**
 * Restituisce la vocale che compare più volte nella stringa passata.
 * @param char[] Stringa di riferimento.
 * @return Vocale con frequenza maggiore.
*/
char vocalePiuPresente(char _str[]);
/**
 * Determina e visualizza le lettere di str1 che compaiono in str2
 * @param char[] Riferimento alla stringa 1.
 * @param char[] Riferimento alla stringa 2
 */
void lettereComuni(char _str1[], char _str2[]);
/**
 * Determina e visualizza le lettere di str2 che non compaiono in str1
 * @param char[] Riferimento alla stringa 1.
 * @param char[] Riferimento alla stringa 2
 */
void lettereNonComuni(char _str1[], char _str2[]);
/**
 * Cifra una stringa con un fattore K mantenendo inalterata la stringa originale.
 * @param char[] Riferimento alla stringa 1
 * @param int Fattore k da applicare.
 * @param char[] Riferimento alla stringa cifrata da costruire.
 */
void cifraStringa(char _str1[], int _k, char _str2[]);
// MAIN
int main(){
    char st1[DIM], st2[DIM];
    char st3[DIM];
    int len1, len2;

    printf("Stringa 1: ");
    gets(st1);

    printf("Stringa 2: ");
    gets(st2);

    printf("Stringhe: %s %s\n", st1, st2);

    // punto 1:
    len1 = lunghezzaStringa(st1);
    len2 = lunghezzaStringa(st2);
    if(len1 > len2){
        printf("L1: %d, L2: %d -> Quindi stringa 1 maggiore di stringa2.\n", len1, len2);
    }
    else{
        if(len1 < len2){
            printf("L1: %d, L2: %d -> Quindi stringa 2 maggiore di stringa 1.\n", len1, len2);
        }
        else{
            printf("Le due stringhe hanno lunghezza uguale.\n");
        }
    }
    printf("\n");

    // punto 2.
    if(isPalindroma(st1)){
        printf("La parola %s risulta essere palindroma.\n", st1);
    }
    if(isPalindroma(st2)){
        printf("La parola %s risulta essere palindroma.\n", st2);
    }
    printf("\n");

    // punto 3.
    contaVocali(st1);
    contaVocali(st2);
    printf("\n");

    // punto 4.
    printf("La lettera piu' presente in %s e': %c.\n", st1, vocalePiuPresente(st1));
    printf("La lettera piu' presente in %s e': %c.\n", st2, vocalePiuPresente(st2));
    printf("\n");

    // punto 5.
    lettereComuni(st1, st2);
    printf("\n");

    // punto 6.
    lettereNonComuni(st1, st2);
    printf("\n");

    // punto 7
    cifraStringa(st1, 3, st3);
    printf("Stringa originale %s -> Cifrata: %s\n", st1, st3);
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
int isPalindroma(char _str[]){
    int i;
    int len;
    int palindroma;

    palindroma = 1;
    len = lunghezzaStringa(_str);
    for(i=0; i<len; i++){
        if(_str[i] != _str[len-i-1])
            palindroma = 0;
        //else
        //    palindroma = 1;
        // errato mettere ELSE perchè basterebbe che l'ultimo controllo interessi due celle con lo stesso carattere
        // e la parola ritorna palindroma.
    }
    return(palindroma);
}
void contaVocali(char _str[]){
    int i;
    int len;
    int cntA, cntE, cntI, cntO, cntU;

    cntA = 0;
    cntE = 0;
    cntI = 0;
    cntO = 0;
    cntU = 0;
    len = lunghezzaStringa(_str);

    for(i=0; i<len; i++){
        if((_str[i] == 'a') || (_str[i] == 'A'))
            cntA++;
        if((_str[i] == 'e') || (_str[i] == 'E'))
            cntE++;
        if((_str[i] == 'i') || (_str[i] == 'I'))
            cntI++;
        if((_str[i] == 'o') || (_str[i] == 'O'))
            cntO++;
        if((_str[i] == 'u') || (_str[i] == 'U'))
            cntU++;
    }
    printf("a: %d, e: %d, i: %d, o: %d, u: %d\n", cntA, cntE, cntI, cntO, cntU);
    printf("Vocali totali: %d\n", (cntA + cntE + cntI + cntO + cntU));
}
char vocalePiuPresente(char _str[]){
int i;
    int len;
    int cntA, cntE, cntI, cntO, cntU;
    int max;
    char car;

    cntA = 0;
    cntE = 0;
    cntI = 0;
    cntO = 0;
    cntU = 0;
    len = lunghezzaStringa(_str);
    // conteggio delle vocali che compongono la stringa.
    for(i=0; i<len; i++){
        if((_str[i] == 'a') || (_str[i] == 'A'))
            cntA++;
        if((_str[i] == 'e') || (_str[i] == 'E'))
            cntE++;
        if((_str[i] == 'i') || (_str[i] == 'I'))
            cntI++;
        if((_str[i] == 'o') || (_str[i] == 'O'))
            cntO++;
        if((_str[i] == 'u') || (_str[i] == 'U'))
            cntU++;
    } 
    // determinazione della vocale più presente e reztituzione al main
    max = cntA;
    car = 'a';
    if(cntE > max){
        max = cntE;
        car = 'e';
    }
    if(cntI > max){
        max = cntI;
        car = 'i';
    }
    if(cntO > max){
        max = cntO;
        car = 'o';
    }
    if(cntU > max){
        max = cntU;
        car = 'u';
    }

    return(car);
}
void lettereComuni(char _str1[], char _str2[]){
    int i, j;
    int len1, len2;

    len1 = lunghezzaStringa(_str1);
    len2 = lunghezzaStringa(_str2);

    // doppio ciclo per i confronti
    printf("Lettere presenti in Stringa1 e anche in Stringa2:\n");
    for(i=0; i<len1; i++){
        for(j=0; j<len2; j++){
            if(_str1[i] == _str2[j]){
                printf("%c\n", _str1[i]);
            }
        }
    }
}
void lettereNonComuni(char _str1[], char _str2[]){
    int i, j;
    int len1, len2;
    int compare;

    len1 = lunghezzaStringa(_str1);
    len2 = lunghezzaStringa(_str2);

    for(i=0; i<len2; i++){
        compare = 0;
        for(j=0; j<len1; j++){
            if(_str2[i] == _str1[j]){
                compare = 1;
            }
        }
        if(!compare){ // if(compare == 0)
            printf("%c\n", _str2[i]);
        }
    }
}
void cifraStringa(char _str1[], int _k, char _str2[]){
    int i;
    int len;

    //for(i=0; i<DIM; i++)
    //    _str2[i] = '\0';
    len = lunghezzaStringa(_str1);
    for(i=0; i<len; i++){
        _str2[i] = _str1[i] + _k;
        if(_str2[i] > 'z'){
            _str2[i] = 'a' + (_str2[i] - 'z');
        }
    }
    _str2[i] = '\0';
}