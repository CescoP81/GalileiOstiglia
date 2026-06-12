#include <stdio.h>
#include "lib.h"

int numberOfDigits(int _n){
    int cntDigits;
    cntDigits = 0;

    if(_n == 0)
        return(1);
    else{
        // scompongo il numero in singole cifre eseguendo delle divisioni per 10 finche _n non diventa 0
        // ricordo che nel mondo degli interi una divisione non genera un numero con la virgola.
        while(_n > 0){
            cntDigits = cntDigits + 1;
            _n = _n / 10;
        }
        return(cntDigits);
    }
}

int avarageValueOfDigits(int _n){
    int cntDigits;
    int sommaDigits;
    int singleDigit;

    if(_n == 0)
        return(0);
    else{
        // come funzione sopra, ad ogni cifra estratta aumento il contatore ed aggiungo la cifra
        // ad una somma così da potermi calcolare la media delle cifre.
        sommaDigits = 0;
        cntDigits = 0;
        while(_n > 0){
            cntDigits = cntDigits + 1;
            singleDigit = _n % 10;
            sommaDigits = sommaDigits + singleDigit;
            _n = _n / 10;
        }
        // se la media calcolata fosse 6,3 sarà restituito il valore intero 6.
        return(sommaDigits/cntDigits);
    }
}

int majorDigit(int _n){
    int singleDigit;
    int maxDigit;
     
    if(_n == 0)
        return(0);
    else{
        // come funzione sopra, la prima cifra estratta la assegno di default a maxDigit che conterrà la cifra massima
        // passo poi al ciclo di scomposizione delle altre cifre che potrebbero costituirmi il numero originale
        // se una cifra risulta maggiore di maxDigit, allora maxDigit viene modificata con la nuova cifra.
        singleDigit = _n % 10;
        _n = _n / 10;
        maxDigit = singleDigit;
        while(_n > 0){
            singleDigit = _n % 10;
            _n = _n / 10;
            if(singleDigit > maxDigit)
                maxDigit = singleDigit;
        }
        // a ciclo terminato in maxDigit ho sicuramente la cifra più grande che compare nel numero originale.
        return(maxDigit);
    }
}

int reversedNumber(int _n){
    int newNumber;
    int singleDigit;

    if(_n == 0)
        return(0);
    else{
        // per realizzare questa funzione ho bisogno di una variabile 'newNumber' in cui costruire il nuovo numero
        // il numero originale lo scompongo in singole cifre come nelle funzioni sopra, ogni cifra viene aggiunta
        // a newNumber dopo che è stato moltiplicato per 10.

        // NOTA: lavorando per divisioni e moltiplicazioni funziona per qualsiasi numero e NON richiede l'uso
        // di vettori.
        newNumber = 0;
        while(_n > 0){
            singleDigit = _n % 10;
            _n = _n / 10;

            newNumber = newNumber * 10;
            newNumber = newNumber + singleDigit;
        }
        // ritorno il nuovo numero costituito dalle cifre di quello originale ma in ordine inverso.
        return(newNumber);
    }
}

//--- FUNZIONI PER ESERCIZIO 2 ---

int sommaCifre(int _n){
    int sommaDigits;
    int singleDigit;

    if(_n == 0)
        return(0);
    else{
        // come la funzione avarageValueDigits soltato che non calcola una media quind
        // viene tolto il contatore delle cifre estratte.
        sommaDigits = 0;
        while(_n > 0){
            singleDigit = _n % 10;
            sommaDigits = sommaDigits + singleDigit;
            _n = _n / 10;
        }
        // somma delle cifre che compongono il numero.
        return(sommaDigits);
    }
}

int numeroEquivalente(int _n){
    int newNumber;
    // il ciclo estrae numeri casuali finche il numero estratto è uguale al numero passato
    // oppure la somma delle cifre del primo numero è diversa dalla somma delle cifre del numero generato.
    do{
        newNumber = 1 + rand()%999;
    }while((newNumber == _n) || (sommaCifre(_n) != sommaCifre(newNumber)));

    return(newNumber);
}