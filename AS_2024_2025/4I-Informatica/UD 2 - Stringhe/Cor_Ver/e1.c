#include <stdio.h>
#include <string.h>

const int NSTRINGHE = 5;
const int DIM = 20;
/**
 * A Input di 5 stringhe da tastiera con lunghezza massima 20 caratteri, e visualizzazione ad inserimento avvenuto.
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
 * B Determina e visualizza la stringa più lunga e indica di quanti caratteri differisce da quella più corta.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 */
void B(char _parole[NSTRINGHE][DIM], int _ns);
/**
 * C Richiesta una lettera, conteggio di quante volte compare e restituzione al main di tale valore,
 * se la lettera non compare richiederne un’altra finche non viene inserita una lettera che compare almeno 1 volta.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 * @param char Carattere da ricercare in tutte le parole della matrice
 * @return Numero di volte che il carattere compare.
 */
int C(char _parole[NSTRINGHE][DIM], int _ns, char _csrc);
/**
 * D Richiesta di una seconda stringa ‘str2’ di 3 caratteri, verificare se str2 compare nella prima stringa dell’elenco inserito (al punto 1).
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 * @param char[] Stringa da ricercare nella prima parola inserita.
 * @return Conferma se compare; 1->Compare 0->Non compare.
 */
int D(char _parole[NSTRINGHE][DIM], int _ns, char _src[3]);
/**
 * E Richiedi due caratteri c1 e c2, in tutte le parole sostituire c1 con c2, quindi visualizzare l’elenco modificato.
 * @param char[][] Matrice per le stringhe
 * @param int Numero di stringhe nella matrice
 * @param char Carattere da ricercare e sostituire.
 * @param char Carattere sostitutivo.
 */
void E(char _parole[NSTRINGHE][DIM], int _ns, char _c1, char _c2);

int main(){
    char parole[NSTRINGHE][DIM+1], src[4];
    char c, occorrenze;
    char c1, c2;
    // punto A
    A(parole, NSTRINGHE);
    vediStringhe(parole, NSTRINGHE);

    // punto B
    B(parole, NSTRINGHE);
    
    // punto C
    occorrenze = 0;
    do{
        printf("Inserisci un carattere: ");
        scanf("%c", &c);
        fflush(stdin);
        occorrenze = C(parole, NSTRINGHE, c);
    }while(occorrenze == 0);
    printf("Il carattere %c compare %d volte tra tutte le parole.\n\n", c, occorrenze);

    // punto D
    printf("Inserisci sottostringa(3 caratteri): ");
    gets(src);
    if(D(parole, NSTRINGHE, src))
        printf("Sottostringa %s trovata nella parola %s.\n", src, parole[0]);
    else
        printf("Sottostringa non trovata!.\n");

    // punto E
    printf("\nInserisci carattere da sostituire: ");
    scanf("%c", &c1);
    fflush(stdin);
    printf("Inserisci carattere sostitutivo: ");
    scanf("%c", &c2);
    fflush(stdin);
    E(parole, NSTRINGHE, c1, c2);
    vediStringhe(parole, NSTRINGHE);

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
void B(char _parole[NSTRINGHE][DIM], int _ns){
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

    printf("Parola piu' lunga: %s con %d caratteri.\n", _parole[iMax], max);
    printf("Differisce dalla piu' corta '%s' per %d caratteri.\n", _parole[iMin], (max-min));
}
int C(char _parole[NSTRINGHE][DIM], int _ns, char _csrc){
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
int D(char _parole[NSTRINGHE][DIM], int _ns, char _src[3]){
    int i, j;
    int st1Len;
    int flag;

    st1Len = 0;
    while(_parole[0][st1Len] != '\0')
        st1Len++;
    flag = 0;
    for(i=0; i<=(st1Len-3) && (flag==0); i++){
        if(_parole[0][i] == _src[0]){
            j=0;
            flag = 1;
            while(_src[j] != '\0'){
                if(_parole[0][i+j] != _src[j])
                    flag = 0;
                j++;
            }
        }
    }
    return(flag);    
}
void E(char _parole[NSTRINGHE][DIM], int _ns, char _c1, char _c2){
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