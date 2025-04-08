#include <stdio.h>
#include <string.h>

const int MAX_FUMETTI = 10;

typedef struct{
    char Titolo[20];
    int NrPagine;
    int Anno;
    float Prezzo;
}Fumetto;

/**
 * Aggiunge un fumetto al vettore esistente.
 * @param Fumetto[] Riferimento al vettore dei fumetti. 
 * @param int* Contatore dei fumetti presenti. 
 * @param Fumetto Struttura da copiare nella posizione libera del vettore. 
 */
void aggiungiFumetto(Fumetto _f[], int *_cnt, Fumetto _tmp);
/** 
 * Visualizza tutti i fumetti presenti.
 * @param Fumetto[] Riferimento al vettore dei fumetti. 
 * @param int* Contatore dei fumetti presenti.
 */
void visualizzaFumetti(Fumetto _f[], int _cnt);
/**
 * Ricerca tra i fumetti per titolo o per anno a scelta dell'utente. 
 * @param Fumetto[] Riferimento al vettore dei fumetti. 
 * @param int* Contatore dei fumetti presenti.
 * @param int Tipologia di ricerca 1 per titolo, 2 per anno. 
 * @param char[] Stringa del titolo da ricercare. 
 * @param int Intero dell'anno da ricercare. 
 */
void ricercaTitoloAnno(Fumetto _f[], int _cnt, int _srcTipo, char _srcTitolo[], int _srcAnno);
/**
 * Calcola e visualizza la media dei prezzi e delle pagine tra i fumetti presenti.
 * @param Fumetto[] Riferimento al vettore dei fumetti. 
 * @param int* Contatore dei fumetti presenti.
 */
void mediaPrezzoPagine(Fumetto _f[], int _cnt);
/**
 * Aggiorna un fumetto presente nel vettore, scelto per indice dall'utente. 
 * @param Fumetto[] Riferimento al vettore dei fumetti. 
 * @param int Indice della cella in cui sostituire la struttura. 
 * @param Fumetto Struttura sostitutiva a quella presente nel vettore. 
 */
void aggiornaFumetto(Fumetto _f[], int _indiceFumetto, Fumetto _tmp);

int main(){
    Fumetto fumetti[MAX_FUMETTI];
    Fumetto tmp;    // variabile singola di tipo fumetto per i punti 1 e 5.
    int scelta;
    int cntFumetti;
    char junk;
        
    int srcTipo;    // variabili per il punto 3 ricerche
    char srcTitolo[20];
    int srcAnno;

    int modificaFumettoNr; // variabile per il punto 5

    cntFumetti = 0;
    do{
        printf("\n-- MENU --\n");
        printf("1-> Aggiungi fumetto.\n");
        printf("2-> Visualizza tutti i fumetti.\n");
        printf("3-> Ricerca per titolo o anno.\n");
        printf("4-> Calcolo media prezzo e pagine.\n");
        printf("5-> Modifica dati di un fumetto.\n");
        printf("0-> USCITA.\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        junk = getchar();

        switch(scelta){
            case 1:{                
                if(cntFumetti < MAX_FUMETTI){
                    printf("Inserisci il titolo: ");
                    scanf("%s", tmp.Titolo);
                    junk = getchar();
                    printf("Inserisci il numero pagine: ");
                    scanf("%d", &(tmp.NrPagine));
                    junk = getchar();
                    printf("Inserisci l'anno di pubblicazione: ");
                    scanf("%d", &(tmp.Anno));
                    junk = getchar();
                    printf("Inserisci il prezzo: ");
                    scanf("%f", &(tmp.Prezzo));
                    junk = getchar();
                    aggiungiFumetto(fumetti, &cntFumetti, tmp);
                }
                else
                    printf("Posto esaurito.");
                break;
            }
            case 2:{
                if(cntFumetti > 0)
                    visualizzaFumetti(fumetti, cntFumetti);
                else
                    printf("Elenco ancora vuoto.");
                    break;
            }
            case 3:{
                do{
                    printf("1-> Ricerca per titolo.\n");
                    printf("2-> Ricerca per anno.\n");
                    printf("Scelta tipo: ");
                    scanf("%d", &srcTipo);
                    junk = getchar();
                }while((srcTipo < 1) || (srcTipo>2));
                if(srcTipo == 1){
                    printf("Inserisci titolo di ricerca: ");
                    scanf("%s", srcTitolo);
                    junk = getchar();
                }
                if(srcTipo == 2){
                    printf("Inserisci anno di ricerca: ");
                    scanf("%d", &srcAnno);
                    junk = getchar();
                }
                ricercaTitoloAnno(fumetti, cntFumetti, srcTipo, srcTitolo, srcAnno);
                break;
            }
            case 4:{
                mediaPrezzoPagine(fumetti, cntFumetti);
                break;
            }
            case 5:{
                visualizzaFumetti(fumetti, cntFumetti);
                printf("\n-- Quale fumetto modificare?: ");
                scanf("%d", &modificaFumettoNr);
                junk = getchar();
                if(modificaFumettoNr >0 && modificaFumettoNr <= cntFumetti){
                    printf("Inserisci il nuovo titolo: ");
                    scanf("%s", tmp.Titolo);
                    junk = getchar();
                    printf("Inserisci il numovo numero pagine: ");
                    scanf("%d", &(tmp.NrPagine));
                    junk = getchar();
                    printf("Inserisci il nuovo anno di pubblicazione: ");
                    scanf("%d", &(tmp.Anno));
                    junk = getchar();
                    printf("Inserisci il nuovo prezzo: ");
                    scanf("%f", &(tmp.Prezzo));
                    junk = getchar();

                    aggiornaFumetto(fumetti, modificaFumettoNr, tmp);
                    printf("\n\n");
                    printf("Aggiornamento completato...\n");
                    visualizzaFumetti(fumetti, cntFumetti);
                }
                else
                    printf("Indice del fumetto non valido...\n");
                break;
            }
        }
        printf("\n");
    }while(scelta != 0);
    return(0);
}

void aggiungiFumetto(Fumetto _f[], int *_cnt, Fumetto _tmp){
    int i;
    i = *_cnt;
    _f[i] = _tmp;
    (*_cnt)++;
}
void visualizzaFumetti(Fumetto _f[], int _cnt){
    int i;
    printf("#\t Titolo\t\tNr. pagine\tAnno\tPrezzo\n");
    for(i=0; i<_cnt; i++){
        printf("%d->\t", (i + 1));
        printf("%s\t\t%d\t\t%d\t%.2f\n", _f[i].Titolo, _f[i].NrPagine, _f[i].Anno, _f[i].Prezzo);
    }
}
void ricercaTitoloAnno(Fumetto _f[], int _cnt, int _srcTipo, char _srcTitolo[], int _srcAnno){
    int trovato;
    int i;

    trovato = 0;
    if(_srcTipo == 1){
        for(i=0; i<_cnt; i++){
            if(strcmp(_f[i].Titolo, _srcTitolo) == 0){
                printf("%d->\t", (i + 1));
                printf("%s\t\t%d\t%d\t%.2f\n", _f[i].Titolo, _f[i].NrPagine, _f[i].Anno, _f[i].Prezzo);
                trovato++;
            }
        }
        if(!trovato){
            printf("Nessun titolo trovato con titolo specificato.");
        }
    }
    if(_srcTipo == 2){
        for(i=0; i<_cnt; i++){
            if(_f[i].Anno == _srcAnno){
                printf("%d->\t", (i + 1));
                printf("%s\t\t%d\t%d\t%.2f\n", _f[i].Titolo, _f[i].NrPagine, _f[i].Anno, _f[i].Prezzo);
                trovato++;
            }
        }
        if(!trovato){
            printf("Nessun titolo trovato con anno specificato.");
        }
    }    
}
void mediaPrezzoPagine(Fumetto _f[], int _cnt){
    int i;
    int mediaPagine;
    float mediaPrezzo;

    mediaPagine = 0;
    mediaPrezzo = 0.0;
    for(i=0; i<_cnt; i++){
        mediaPagine += _f[i].NrPagine;
        mediaPrezzo += _f[i].Prezzo;
    }

    mediaPagine /= _cnt;
    mediaPrezzo /= _cnt;
    printf("Media dei prezzi: %.2f \t-\t Media delle pagine %d.", mediaPrezzo, mediaPagine);
}
void aggiornaFumetto(Fumetto _f[], int _indiceFumetto, Fumetto _tmp){
    _f[_indiceFumetto-1] = _tmp;
}