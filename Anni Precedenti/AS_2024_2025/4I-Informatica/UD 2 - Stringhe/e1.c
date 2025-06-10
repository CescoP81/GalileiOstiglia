#include <stdio.h>
// sezione delle costanti.
const int DIM = 20;
// sezione dei prototipi.
/** 
 * Ritorna la lunghezza in caratteri della stringa passata come parametro.
 * @param char[] Stringa da utilizzare per il conteggio caratteri.
 * @return Numero di caratteri che compongono la stringa.
 */
int lunghezzaStringa(char _str[]);
/**
 * Visualizza una stringa a video al contrario. Es. Ciao -> oaiC
 * @param char[] Stringa da utilizzare.
 */
void visualizzaRovescio(char _str[]);
/**
 * Modifica la stringa capovolgendola nel vettore.
 * @param char[] Stringa da utilizzare.
 */
void ribaltaStringa(char _str[]);
/**
 * Funzione che riceve una stringa e veerifica se è palindroma oppure no.
 * Una parola si dice palindroma quando è possibile leggerla sia da sinistra verso destra che
 * da destra verso sinistra.
 * @param char[] Stringa di riferimento da verificare.
 * @return Booleano 0/1 in caso negativo o affermativo.
 */
int isPalindroma(char _str[]);

// sezione del main program.
int main(){
    char str[DIM];

    // acquisisco una stringa da tastiera
    printf("Inserisci una parola: ");
    scanf("%s", str);
    fflush(stdin);

    // determinare la lunghezza della stringa
    int cnt;
    cnt = lunghezzaStringa(str);
    printf("Lunghezza: %d\n", cnt);

    // Visualizzo la stringa al contrario
    printf("Contrario: ");
    visualizzaRovescio(str);
    printf("\n\n");
    ribaltaStringa(str);
    printf("Stringa capovolta: %s\n", str);

    if(isPalindroma(str) == 1){
        printf("La parola %s e' palindroma.\n", str);
    }
    else{
        printf("La parola %s non e' palindroma.\n", str);
    }
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

void visualizzaRovescio(char _str[]){
    int lunghezza;
    int i;

    lunghezza = lunghezzaStringa(_str);
    for(i=lunghezza-1; i>=0; i--){
        printf("%c", _str[i]);
    }
}

void ribaltaStringa(char _str[]){
    int i;
    int lunghezza;
    char tmp;

    lunghezza = lunghezzaStringa(_str);
    for(i=0; i<(lunghezza/2); i++){
        tmp = _str[i];
        _str[i] = _str[lunghezza-i-1];
        _str[lunghezza-i-1] = tmp;
    }
}

int isPalindroma(char _str[]){
    int i; // variabile per il ciclo.
    int lung; // contiene la lunghezza della stringa.
    int palindroma; // flag 0/1 a seconda che sia o meno palindroma.

    lung = lunghezzaStringa(_str);
    palindroma = 1;
    for(i=0; i<lung; i++){
        if(_str[i] != _str[lung-i-1])
            palindroma = 0;
        // GUAI A VOI SE METTETE UNA ELSE CON palindroma = 1;
    }
    return(palindroma);
}