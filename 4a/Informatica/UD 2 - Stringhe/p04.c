/*
Realizzare un programma per la gestione di una stringa inserita da tastiera (stringa allocata massimo 100byte), utilizzando un puntatore a stringa.
- [ ] initStringa() Richiede l'input di una stringa da tastiera.
- [ ] mergeStringhe() Concatena due stringhe, dividendole con uno spazio, in una terza stringa.
- [ ] splitStringAtPosition() divide una stringa in due parti partendo dalla posizione indicata come parametro.
- [ ] getSubString() restituisce la sottostringa presente tra due indici indicati (verificare gli indici).
*/
#include <stdio.h>
#include <stdlib.h>
/**
 * Funzione che inizializza una stringa richiedendola da tastiera
 * @param char* Riferimento alla stringa da utilizzare.
*/
void initStringa(char*);
/**
 * Funzione che fonde le due stringhe in una terza.
 * @param char* Riferimento alla prima stringa da utilizzare.
 * @param char* Riferimento alla seconda stringa da utilizzare.
 * @param char* Riferimento alla terza stringa da utilizzare come merge.
*/
void mergeStringhe(char*, char*, char*);
/**
 * Funzione che spezza una stringa in due parti partendo da una posizione data.
 * @param char* Riferimento alla prima stringa da utilizzare.
 * @param int Posizione da cui spezzare in due la stringa.
 * @param char* Riferimento a stringa -> la seconda parte di quella originale.
*/
void splitStringAtPosition(char*, int, char*);
/**
 * Funzione che determina la sottostringa tra due indici dati.
 * @param char* Riferimento alla prima stringa da utilizzare.
 * @param int indice inferiore.
 * @param int indice superiore.
 * @param char* Riferimento a stringa -> substring determinata.
*/
void getSubString(char*, int, int, char*);
int main(){
    char *s1, *s2, *s3;
    s1 = malloc(sizeof(char)*100);
    s2 = malloc(sizeof(char)*100);
    s3 = malloc(sizeof(char)*100);

    initStringa(s1);
    initStringa(s2);
    printf("\n\n");
    mergeStringhe(s1,s2,s3);
    printf("Stringa 3 (merge s1+s2): %s\n\n", s3);
    printf("\n");
    splitStringAtPosition(s1, 3, s2);
    printf("Prima parte: %s, seconda parte: %s\n", s1, s2);
    printf("\n");
    initStringa(s1);
    getSubString(s1, 3, 5, s2);
    printf("Substring: %s", s2);
    return(0);
}
// #### FUNZIONI ####
void initStringa(char *_str){
    printf("Inserisci una stringa: ");
    scanf("%s", _str);
    fflush(stdin);
}
void mergeStringhe(char *_str1, char *_str2, char *_str3){
    int i;  // utilizzo i sulle due stringhe base
    int j;  // utilizzo j sulla terza stringa come merge.

    i=0;
    j=0;
    while(*(_str1+i) != '\0'){
        *(_str3+j) = *(_str1+i);
        i++;
        j++;
    }

    *(_str3+j) = ' ';
    j++;

    i=0;
    while(*(_str2+i) != '\0'){
        *(_str3+j) = *(_str2+i);
        i++;
        j++;
    }
    *(_str3+j) = '\0';
}

void splitStringAtPosition(char *_str1, int _index, char *_str2){
    int i,j;
    int len; // lunghezza della stringa;

    // mi calcolo la lunghezza della stringa per verifica esistenza dell'indice.
    len=0;
    i=0;
    while(*(_str1+i) != '\0'){
        len++;
        i++;        
    }

    if(_index > 0 && _index < len){
        i = _index-1;
        j=0;
        while(*(_str1+i) != '\0'){
            *(_str2+j) = *(_str1+i);
            i++;
            j++;
        }
        *(_str2+j) = '\0';
        *(_str1 + _index -1) = '\0';
    }
    else{
        *_str2 = '\0';
    }
}

void getSubString(char *_str1, int _imin, int _imax, char *_str2){
    int i,j;
    int len; // lunghezza della stringa;

    // mi calcolo la lunghezza della stringa per verifica esistenza dell'indice.
    len=0;
    i=0;
    while(*(_str1+i) != '\0'){
        len++;
        i++;        
    }

    if(_imin>0 && _imax<=len && _imin<_imax){
        i = _imin-1;
        j = 0;
        while(i < _imax){
            *(_str2+j) = *(_str1+i);
            i++;
            j++;
        }
        *(_str2+j) = '\0';
    }
    else{
        *_str2 = 0;
    }
}