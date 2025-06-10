#include <stdio.h>
#include <string.h>

const int DIMVET = 5;

typedef struct{
    char nome[20];
    char razza[20];
    int peso;
}Animale;

/**
 * Inserisci un numero animale all'inizio del vettore, sposando di una posizione tutti quelli presenti
 * @param Animale[] Vettore degli animali.
 * @param int Numero di animali presenti.
 */
void insertAnimale(Animale _v[], int _cnt);
/**
 * Visualizza tutti gli animali presenti
 * @param Animale[] Vettore degli animali.
 * @param int Numero di animali presenti.
 */
void vediAnimale(Animale _v[], int _cnt);
/**
 * Ricerca gli animali corrispondenti alla razza inserita.
 * @param Animale[] Vettore degli animali.
 * @param int Numero di animali presenti.
 * @param char[] Stringa rappresentante la razza inserita.
 */
void searchByRazza(Animale _v[], int _cnt, char _razzasrc[]);

int main(){
    Animale v[DIMVET];
    int cnt;
    char razza_src[20];
    int scelta;
    char junk;

    cnt = 0;
    do{
        printf("1 -> Inserisci un animale\n");
        printf("2 -> Vedi gli animali\n");
        printf("3 -> Ricerca per razza\n");
        printf("0 -> TERMINA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{
                if(cnt < DIMVET){
                    insertAnimale(v, cnt);
                    cnt = cnt + 1;
                }
                else{
                    printf("Spazio esaurito!\n");
                }
                break;
            }
            case 2:{
                vediAnimale(v, cnt);
                break;
            }
            case 3:{
                printf("Razza da ricercare: ");
                gets(razza_src);
                searchByRazza(v, cnt, razza_src);
                break;
            }
        }
    }while(scelta != 0);
}

void insertAnimale(Animale _v[], int _cnt){
    int i;
    char junk;

    for(i=_cnt; i>0; i--){
        _v[i] = _v[i-1];
    }
    i = 0;
    printf("Inserisci nome: ");
    gets(_v[i].nome);
    printf("Inserisci razza: ");
    gets(_v[i].razza);
    printf("Inserisci peso: ");
    scanf("%d", &(_v[i].peso));
    junk = getchar();
}
void vediAnimale(Animale _v[], int _cnt){
    int i;
    printf("\n--- LISTA ANIMALI ---\n");
    for(i=0; i<_cnt; i++){
        printf("%s %s %d\n", _v[i].nome, _v[i].razza, _v[i].peso);
    }
    printf(" ---- ---- ----\n\n");
}
void searchByRazza(Animale _v[], int _cnt, char _razzasrc[]){
    int i;

    printf("--- Animali di razza %s trovati ---\n", _razzasrc);
    for(i=0; i<_cnt; i++){
        if(strcmp(_v[i].razza, _razzasrc) == 0)
            printf("%s %s %d\n", _v[i].nome, _v[i].razza, _v[i].peso);
    }
    printf(" --- --- ---\n\n");
}