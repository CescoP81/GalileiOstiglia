#include <stdio.h>
#include <string.h>

const int DIMVET = 5;

typedef struct{
    char nome[20];
    char cognome[20];
    int eta;
}Studente;

/**
 * Permette di inserire i dati di un singolo studente
 * @param Studente[] Vettore degli studenti.
 * @param int Indice della cella da riempire
 */
void insertStudente(Studente _v[], int _index);
/**
 * Visualizza tutti gli studenti inseriti
 * @param Studente[] Vettore degli studenti.
 * @param int Contatore degli studenti inseriti / celle occupate.
 */
void vediStudente(Studente _v[], int _cnt);
/**
 * Riordinamento del vettore secondo il cognome, utilizzo del Bubble Sort.
 * Attenzione che non sono state considerate maiuscole/minuscole quindi a parità di lettera viene rispettato l'ordine della tabella ASCII.
 * @param Studente[] Vettore degli studenti.
 * @param int Contatore degli studenti inseriti / celle occupate.
 */
void orderByCognome(Studente _v[], int _cnt);
/**
 * Riordinamento del vettore secondo l'età, utilizzo del Bubble Sort.
 * @param Studente[] Vettore degli studenti.
 * @param int Contatore degli studenti inseriti / celle occupate.
 */
void orderByEta(Studente _v[], int _cnt);

int main(){
    Studente v[DIMVET];
    int cnt;
    int scelta;
    char junk;


    cnt = 0;
    do{
        printf("1 -> Nuovo studente\n");
        printf("2 -> Visualizza Studenti\n");
        printf("3 -> Ordina per cognome (a-z)\n");
        printf("4 -> Ordina per età\n");
        printf("0 -> TERMINA\n");
        printf("scelta: ");
        scanf("%d", &scelta);
        junk = getchar();
        switch(scelta){
            case 1:{
                if(cnt < DIMVET){
                    insertStudente(v, cnt);
                    cnt = cnt + 1;
                }
                else{
                    printf("Spazio esarito!\n\n ");
                }
                break;
            }
            case 2:{
                vediStudente(v, cnt);
                break;
            }
            case 3:{
                orderByCognome(v, cnt);
                printf("Ordinamento per cognome (a->z) eseguito...\n");
                vediStudente(v, cnt);
                break;
            }
            case 4:{
                orderByEta(v, cnt);
                printf("Ordinamento per eta (min->max) eseguito...\n");
                vediStudente(v, cnt);
                break;
            }
        }
    }while(scelta!=0);
}

void insertStudente(Studente _v[], int _index){
    char junk;
    printf("Inserisci nome: ");
    gets(_v[_index].nome);
    printf("Inserisci cognome: ");
    gets(_v[_index].cognome);
    printf("Inserisci eta': ");
    scanf("%d",&(_v[_index].eta));
    junk = getchar();
}
void vediStudente(Studente _v[], int _cnt){
    int i;
    printf("\n\n-- LISTA STUDENTI --\n");
    for(i=0; i<_cnt; i++){
        printf("%s %s %d\n", _v[i].cognome, _v[i].nome, _v[i].eta);
    }
    printf("---- ---- ----\n");
}
void orderByCognome(Studente _v[], int _cnt){
    int i, j;
    Studente tmp;
    // bubble sort
    for(i=0; i<_cnt; i++){
        for (j=i; j<_cnt; j++){
            if(strcmp(_v[i].cognome, _v[j].cognome) == 1){
                tmp = _v[i];
                _v[i] = _v[j];
                _v[j] = tmp;
            }
        }
    }
}
void orderByEta(Studente _v[], int _cnt){
    int i, j;
    Studente tmp;
    // bubble sort
    for(i=0; i<_cnt; i++){
        for (j=i; j<_cnt; j++){
            if(_v[i].eta >_v[j].eta){
                tmp = _v[i];
                _v[i] = _v[j];
                _v[j] = tmp;
            }
        }
    }
}