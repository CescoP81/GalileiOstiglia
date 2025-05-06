/*
    Esempio di base di costruzione e visualizzazione di una lista.
    - inserimento in testa.
    - visualizzazione della lista
    !! CON FUNZIONI !!
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valore;
    struct Nodo* next;
}Nodo;

/**
 * Visualizza la lista
 * @param Nodo* Riferimento alla testa della lista
 */
void vediLista(Nodo *_testa);
/**
 * Inserisce un nuovo nodo come testa della lista, riceve la testa e il valore da inserire come parametri. 
 * @param Nodo* Riferimento alla testa della lista. 
 * @param int Valore da inserire come informazione nel nodo. 
 * @return Riferimento alla nuova testa della lista. 
 */
Nodo* pushTesta(Nodo *_testa, int _val);
/**
 * Funziona che ritorna il numero di nodi presenti in una lista.
 * @param Nodo* Riferimento alla lista. 
 * @return Numero intero, nodi che compongono la lista.
 */
int contaNodi(Nodo *_testa);
/**
 * Funzione che estrae un nodo dalla testa della lista e restituisce al main il valore estratto.
 * @param Nodo* Riferimento alla testa della lista.
 * @param int Riferimento alla variabile in cui mettere il valore del nodo estratto. 
 * @return Riferimento alla nuova testa. 
 */
Nodo* popTesta(Nodo *_testa, int *_val);
/**
 * Restituisce la prima posizione nella lista (il numero del nodo) in cui compare il valore
 * ricercato e passato come parametro. 
 * @param Nodo* Riferimento alla testa della lista. 
 * @param int Valore da ricercare tra i nodi della lista. 
 * @return Posizione del nodo in cui compare il valore, se non presente ritorna -1
 */
int cercaValoreLista(Nodo *_testa, int _src);
/**
 * Restituisce il valore minimo o massimo presente nella lista. 
 * @param Nodo* Riferimento alla testa della lista.
 * @param int Criterio di ricerca 0->min 1->max.
 * @return Valore corrispondente al criterio impostato.
 */
int ricercaMinMaxLista(Nodo *_testa, int tipo);
/**
 * Resitutisce il valore medio tra tutti i valori contenuti nella lista. 
 * @param Nodo* Riferimento alla testa della lista. 
 * @return float Valor medio calcolato.
 */
float mediaValoriLista(Nodo *_testa);
/**
 * sostitusce nella lista tutti i valori uguali ad un valore x passato come parametro,
 * con un valore y passato come parametro.
 * @param Nodo* Riferimento alla testa della lista. 
 * @param int Valore da sostituire. 
 * @param int Valore sostitutivo. 
 * @return Numero di sostituzioni eseguite.
 */
int sostituisciValoreLista(Nodo *_testa, int _x, int _y);

// DA AGGIUNGERE
Nodo* pushCoda(...);
Nodo* popCoda(...);

/*## MAIN PROGRAM ## */
int main(){
    Nodo *testa;
    Nodo *tmp;
    int nrNodi;
    int vEstratto;
    testa = NULL;

    testa = pushTesta(testa, 3);
    testa = pushTesta(testa, 5);
    testa = pushTesta(testa, 12);
    testa = pushTesta(testa, 11);
    vediLista(testa);

    printf("\n\n");
    testa = pushTesta(testa, 3);
    testa = pushTesta(testa, 5);
    vediLista(testa);
//*/
    printf("\n\n");
    nrNodi = contaNodi(testa);
    printf("La lista e' composta da: %d Nodi\n", nrNodi);

    printf("\n\n");
    testa = popTesta(testa, &vEstratto);
    printf("Il valore estratto e': %d\n\n", vEstratto);
    vediLista(testa);

    printf("\n\n");
    printf("Valore 54 presente in posizione: %d\n", cercaValoreLista(testa, 54));
    printf("Valore 22 presente in posizione: %d\n", cercaValoreLista(testa, 22));
    printf("Valore 89 presente in posizione: %d\n", cercaValoreLista(testa, 89));
    printf("Valore 12 presente in posizione: %d\n", cercaValoreLista(testa, 12));

    printf("\n\n");
    printf("Valore minimo della lista: %d\n", ricercaMinMaxLista(testa, 0));
    printf("Valore minimo della lista: %d\n", ricercaMinMaxLista(testa, 1));
    printf("Valore minimo della lista: %d\n", ricercaMinMaxLista(testa, 5));
    tmp = NULL;
    printf("Valore minimo della lista: %d\n", ricercaMinMaxLista(tmp, 0));

    printf("\n\n");
    vediLista(testa);
    printf("Valor medio della lista: %.3f\n", mediaValoriLista(testa));

    printf("\n\n");
    printf("Valori 5 sistutuiti con 99: %d\n", sostituisciValoreLista(testa, 5, 99));
    vediLista(testa);
    return(0);
}

/*## SVILUPPO FUNZIONI ## */
void vediLista(Nodo *_testa){
    Nodo* tmp;
    // visualizzo la lista esistente con un ciclo
    tmp = _testa;                // faccio puntare TMP alla TESTA attuale della lista.
    printf("Testa: %d\n", tmp);
    while(tmp != NULL){
        printf("Addr: %d - Valore: %d - Next: %d\n", tmp, tmp->valore, tmp->next);
        tmp = tmp->next;
    }
}
Nodo* pushTesta(Nodo *_testa, int _val){
    Nodo *tmp;
    tmp = malloc(sizeof(Nodo)); // alloco in memoria un nuovo nodo e l'indirizzo lo assegno a tmp.
    tmp->valore = _val;           // assegno alla parte valore del nodo il numero 33.
    tmp->next = _testa;          // al puntatore al nodo successivo assegno la testa attuale.
    return(tmp); 
}
int contaNodi(Nodo *_testa){
    int cnt;
    Nodo *tmp;

    tmp = _testa;
    cnt=0;
    while(tmp != NULL){ // ciclo per passare tutti i nodi della lista finche tmp non vale NULL.
        cnt++;  // incremento il contatore dei nodi trovati.
        tmp = tmp->next;    // sposto il puntatore sul nodo successivo, dopo l'ultimo il puntatore vale NULL!
    }

    return(cnt);
}
Nodo* popTesta(Nodo *_testa, int *_val){
    Nodo *tmp;
    if(_testa != NULL){ // controllo se la lista è composta da almeno un nodo oppure se è vuota (NULL = vuota)
        // salvo nella variabile del MAIN il valore del nodo che voglio togliere.
        *_val = _testa->valore;

        // fase di cancellazione del nodo
        tmp = _testa;           // in un puntatore temporaneo mi salvo l'attuale testa della lista.
        _testa = _testa->next;  // sposto la testa al nodo successivo.
        free(tmp);              // dealloco la memoria allocata dalla malloc quando è stata fatta la pushTesta.
        return(_testa);         // ritorno la nuova testa al MAIN.
    }
    else{
        *_val = -1;
        return(NULL);
    }
}
int cercaValoreLista(Nodo *_testa, int _src){
    int pos;
    int cnt;
    Nodo *tmp;

    cnt = 0;
    pos = -1;
    tmp = _testa;
    while(tmp){
        cnt++;
        if(tmp->valore == _src){
            pos = cnt;
            return(pos);
        }
        tmp = tmp->next;
    }
    return(pos);
}
int ricercaMinMaxLista(Nodo *_testa, int tipo){
    int box;    // conterrà il minimo o il massimo in base alla ricerca da effettuare.
    Nodo *tmp;

    // imposto il tmp sull'attuale testa.
    tmp = _testa;
    if(tmp != NULL){
        box = tmp->valore;
          
        while(tmp){ // regola è: 0 indica un falso, qualunque vsalore != da 0 indica un vero -23 oppure +34 = VERO.
            if(tipo == 0)    // ricerco il minimo
                if(tmp->valore < box)
                    box = tmp->valore;
            if(tipo == 1)
                if(tmp->valore > box)
                    box = tmp->valore;
            
            tmp = tmp->next;
        }
        if(tipo == 0 || tipo == 1)
            return(box);
        else
            return(-1);
    }
    return(-1);    
}
float mediaValoriLista(Nodo *_testa){
    Nodo *tmp;
    float somma;
    int cnt;

    somma = 0.0;
    cnt = 0;
    tmp = _testa;
    while(tmp){
        cnt++;
        somma = somma + tmp->valore;
        tmp = tmp->next;
    }
    printf("%f %d\n", somma, cnt);
    return(somma / cnt); 
    // return(somma/contaNodi(_testa)); equivalente senza dover usare il cnt per contare i nodi.
}
int sostituisciValoreLista(Nodo *_testa, int _x, int _y){
    Nodo *tmp;
    int cnt;

    cnt = 0;
    tmp = _testa;
    while(tmp){
        if(tmp->valore == _x){
            tmp->valore = _y;
            cnt++;
        }
        tmp = tmp->next;
    }
    return(cnt);
}