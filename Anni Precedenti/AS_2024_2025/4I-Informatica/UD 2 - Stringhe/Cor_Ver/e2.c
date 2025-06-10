#include <stdio.h>
#include <string.h>

const int NSTRINGHE = 7;
const int DIM = 15;
/**
 * A Input di 7 stringhe da tastiera con lunghezza massima 15 caratteri, e visualizzazione ad inserimento avvenuto.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 */
void A(char _parole[NSTRINGHE][DIM], int _ns);
/**
 * Visualizzazione delle stringhe inserite nella matrice.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 */
void vediStringhe(char _parole[NSTRINGHE][DIM], int _ns);
/**
 * B Richiedi due caratteri c1 e c2, in tutte le parole sostituire c1 con c2, quindi visualizzare l’elenco modificato.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 * @param char Carattere da ricercare e sostituire.
 * @param char Carattere sostitutivo.
 */
void B(char _parole[NSTRINGHE][DIM], int _ns, char _c1, char _c2);
/**
 * C Determina e visualizza la stringa più lunga e indica di quanti caratteri differisce da quella più corta.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 */
void C(char _parole[NSTRINGHE][DIM], int _ns);
/**
 * D Richiesta una lettera, conteggio di quante volte compare e restituzione al main di tale valore,
 * se la lettera non compare richiederne un’altra finche non viene inserita una lettera che compare almeno 1 volta.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 * @param char Carattere da ricercare in tutte le parole della matrice
 * @return Numero di volte che il carattere compare.
 */
int D(char _parole[NSTRINGHE][DIM], int _ns, char _csrc);
/**
 * E Richiesta di una seconda stringa ‘str2’, verificare se str2 è anagramma della prima stringa dell’elenco,
 * in caso negativo indicare per quali lettere non è un anagramma.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 * @param char[] Stringa da ricercare nella prima parola inserita.
 */
void E(char _parole[NSTRINGHE][DIM], int _ns, char _src[DIM+1]);

int main(){
    char parole[NSTRINGHE][DIM+1], src[DIM+1];
    char c, occorrenze;
    char c1, c2;
    // punto A
    A(parole, NSTRINGHE);
    vediStringhe(parole, NSTRINGHE);

    // punto B
    printf("\nInserisci carattere da sostituire: ");
    scanf("%c", &c1);
    fflush(stdin);
    printf("Inserisci carattere sostitutivo: ");
    scanf("%c", &c2);
    fflush(stdin);
    B(parole, NSTRINGHE, c1, c2);
    vediStringhe(parole, NSTRINGHE);

    // punto C
    C(parole, NSTRINGHE);
    
    // punto D
    occorrenze = 0;
    do{
        printf("Inserisci un carattere: ");
        scanf("%c", &c);
        fflush(stdin);
        occorrenze = D(parole, NSTRINGHE, c);
    }while(occorrenze == 0);
    printf("Il carattere %c compare %d volte tra tutte le parole.\n\n", c, occorrenze);

    // punto E
    printf("Inserisci possibile anagramma: ");
    gets(src);
    E(parole, NSTRINGHE, src);
    return(0);
}

void A(char _parole[NSTRINGHE][DIM], int _ns){
    int i;
    for(i=0; i<_ns; i++){
        printf("Inserisci stringa [%d]: ", i);
        gets(_parole[i]);
    }
}
void vediStringhe(char _parole[NSTRINGHE][DIM], int _ns){
    int i;
    printf("\nParole Inserite:\n");
    for(i=0; i<_ns; i++){
        printf("[%d]: %s\n", i, _parole[i]);
    }
}
void B(char _parole[NSTRINGHE][DIM], int _ns, char _c1, char _c2){
    int i, j;
    for(i=0; i<_ns; i++){
        j=0;
        while(_parole[i][j] != '\0'){
            if(_parole[i][j] == _c1)
                _parole[i][j] = _c2;
            j++;
        }
    }
}
void C(char _parole[NSTRINGHE][DIM], int _ns){
    int i;
    int cnt;
    int min, max;
    int iMin, iMax;

    min = DIM;
    max = 0;
    iMin = 0;
    iMax = 0;
    for(i=0; i<_ns; i++){
        cnt = 0;
        while(_parole[i][cnt]!= '\0')
            cnt++;

        if(cnt < min){
            min = cnt;
            iMin = i;
        }
        if(cnt > max){
            max = cnt;
            iMax = i;
        }
    }

    printf("Parola piu' corta: %s con %d caratteri.\n", _parole[iMin], min);
    printf("Differisce dalla piu' lunga '%s' per %d caratteri.\n", _parole[iMax], (max-min));
}
int D(char _parole[NSTRINGHE][DIM], int _ns, char _csrc){
    int i, j, cnt;

    cnt = 0;
    for(i=0; i<_ns; i++){
        j = 0;
        while(_parole[i][j] != '\0'){
            if(_parole[i][j] == _csrc)
                cnt++;
            j++;
        }
    }
    return(cnt);
}
void E(char _parole[NSTRINGHE][DIM], int _ns, char _src[DIM+1]){
    int i, j;
    int alfabeto[26];

    int anagramma;

    for(i=0; i<26; i++)
        alfabeto[i] = 0;
    // incremento i contatori scorrendo la prima parola inserita delle 7 totali
    j=0;
    while(_parole[0][j] != '\0'){
        i = _parole[0][j] - 'a';
        alfabeto[i]++;
        j++;
    }

    // decremento i contatori scorrendo la parola da verificare.
    j=0;
    while(_src[j] != '\0'){
        i = _src[j] - 'a';
        alfabeto[i]--;
        j++;
    }

    anagramma = 1;
    for(i=0; i<26; i++){
        if(alfabeto[i] != 0)
            anagramma = 0;
    }
    if(anagramma)
        printf("La parola inserita %s e' anagramma di %s.\n", _src, _parole[0]);
    else{
        printf("Le due parole non sono anagrammi e differiscono per le seguenti lettere:\n");
        for(i=0; i<26; i++){
            if(alfabeto[i] != 0)
                printf("%c, ", ('a'+i));
        }
    }
}
