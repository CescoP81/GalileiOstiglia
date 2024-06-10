/*
    Realizzare il programma "Catch the Code" il quale all'avvio inizializza un vettore di 5 elementi interi
    con valori random compresi tra 0 e 9.
    Il programma deve richiedere all'utente di indovinare i 5 valori.
    - Richiede i 5 valori interi all'utente.
    - Verifica i valori con quelli presenti nel vettore
        - se il valore è esatto lo visualizza
        - se il valore non è esatto visualizza un ?
    - il gioco termina quando l'untente indovina tutte e 5 le cifre,
    comunicando anche il numero di tentativi effettuati.
    IL PROGRAMMA E' DA REALIZZARE CON LE FUNZIONI.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_VALUE = 10;           // limite del random 0<->9
const int NUMBER_OF_DIGITS = 5;     // numero di cifre che compongono il codice
const int MAX_TENTATIVI = 10;        // numero di tentativi possibili, utilizzato abilitando righe 65-71
/** 
 * Initialize the original code with random digits between 0 and 9
 * @param int[][] Reference to a matrix for original code and user code.
 * @param int Number of digits
 * 
*/
void initOriginalCode(int[][NUMBER_OF_DIGITS], int);
/**
 * Request of the user code, five digits between 0 and 9 with input control.
 * @param int[][] Reference to a matrix for original code and user code.
 * @param int Number of digits
*/
void insertUserCode(int[][NUMBER_OF_DIGITS], int);
/**
 * Verify the user code insered with the random code generated.
 * @param int[][] Reference to a matrix for original code and user code.
 * @param int Number of digits
 * @return Number of right digits matched
*/
int checkUserCode(int[][NUMBER_OF_DIGITS], int);


int main(){
    int code[2][NUMBER_OF_DIGITS];
    int cntTentativi;
    srand(time(NULL));

    // inizializzo il codice da indovinare
    initOriginalCode(code, NUMBER_OF_DIGITS);

    printf("Are You Ready?! :) \n");
    cntTentativi = 0;
    do{
        system("PAUSE");
        system("CLS");
        // for(int i=0; i<5; i++) printf("%d", code[0][i]); // ciclo di debug del codice in fase di testing del programma.
        cntTentativi++;
        insertUserCode(code, NUMBER_OF_DIGITS);
        printf("\n");
    }  // abilita (scommenta) uno dei due while seguenti per completare questo DO.

      // metti o togli /* ad inizio di questa riga per usare questo while e non avere limite di tentativi
    while(checkUserCode(code, NUMBER_OF_DIGITS) < NUMBER_OF_DIGITS);
    printf("\n\n !!Bravo!!\nHai indovinato il codice con %d tentativi", cntTentativi);
    // */

    /* // togli  o togli /* ad inizio di questa riga per usare questo while e avere un numero di tentativi massimo.
    while((checkUserCode(code, NUMBER_OF_DIGITS) < NUMBER_OF_DIGITS) && (cntTentativi<MAX_TENTATIVI));
    if(cntTentativi < MAX_TENTATIVI)
        printf("\n\n !!Bravo!!\nHai indovinato il codice con %d tentativi su %d massimi", cntTentativi, MAX_TENTATIVI);
    else
        printf("\n\n !!OH No!!\nHai terminato i tentativi!!");
    // */
    return(0);
}

void initOriginalCode(int _code[][NUMBER_OF_DIGITS], int _nog){
    int i;
    for(i=0; i<_nog; i++){
        _code[0][i] = rand()%MAX_VALUE;
    }
}

void insertUserCode(int _code[][NUMBER_OF_DIGITS], int _nog){
    int i;
    printf("\n ==INSERISCI LE 5 CIFRE==\n");
    for(i=0; i<_nog; i++){
        do{ // input controllato che l'utente inserisca cifre da 0 a 9.
            printf("Inserisci la %d cifra: ", i+1);
            scanf("%d", &_code[1][i]);
        }while(_code[1][i]<0 || _code[1][i]>=MAX_VALUE);
    }
}

int checkUserCode(int _code[][NUMBER_OF_DIGITS], int _nog){
    int i;
    int cntValidDigits = 0;
    printf("Match: ");
    for(i=0; i<_nog; i++){
        if(_code[0][i] == _code[1][i]){
            printf("%d ", _code[0][i]);
            cntValidDigits++;
        }
        else{
            printf("? ");
        }
    }
    printf("\n");
    return(cntValidDigits);
}