#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Nodo{
    int valore;
    struct Nodo *next;
}Nodo;
// == PROTOTIPI ==
/**
 * Inserisce un nuovo nodo in testa alla lista
 * @param Nodo* Puntatore alla testa attuale.
 * @param int Valore da inserire nel nuovo nodo.
 * @return Indirizzo della nuova testa della lista
*/
Nodo* pushTesta(Nodo *_t, int _val);
/**
 * Visualizza la lista con iterativa
 * @param Nodo* Puntatore alla testa attuale.
*/
void showLista(Nodo *_t);
/**
 * Estrae un nodo dalla testa della lista, esegue la FREE della memoria allocata.
 * @param Nodo* Puntatore alla testa attuale.
 * @return Nuovo indirizzo della testa.
*/
Nodo* popTesta(Nodo *_t);
/**
 * Conta e restituisce il numero di nodi che compongono una lista.
 * @param Nodo* Puntatore alla testa attuale.
 * @return Numero nodi della lista.
*/
int contaElementiLista(Nodo *_t);

/**
 * Visualizza un menu operativo e restituisce la scelta effettuata dall'utente.
 * @param Scelta effettuata dall'utente.
*/
int showMenu();
/**
 * Richiede il numero di nodi da generare ed utilizza la pushTesta epr generare i nodi.
 * @param Nodo* Riferimento alla testa.
 * @return Riferimento alla testa.
*/
Nodo* generaLista(Nodo *_t);
/**
 * Determina il valore minimo e massimo presenti nella lista.
 * @param Nodo* Riferimento alla testa della lista.
 * @param int* Riferimento alla variabile intera per il minimo.
 * @param int* Riferimento alla variabile intera per il massimo.
 * @return 1 se la funzione opera su lista esistente, 0 se viene passata una lista vuota.
*/
int minMaxLista(Nodo *_t, int *_min, int *_max);
/**
 * Dealloca tutti i nodi presenti nella lista passata, utilizza contaElementi e popTesta.
 * @param Nodo* Riferimento alla testa della lista.
 * @return Riferimento alla nuova testa della lista.
*/
Nodo* deleteLista(Nodo *_t);


// == MAIN ==
int main(){
    int scelta;
    Nodo *head;
    head = 0;
    int min, max;

    do{
        scelta = showMenu();
        switch(scelta){
            case 1:{
                head = generaLista(head);
                printf("Lista Generata...\n\n");
                break;
            }
            case 2:{
                showLista(head);
                printf("\n\n");
                break;
            }
            case 3:{
                head = popTesta(head);
                printf("\n\n");
                break;
            }
            case 4:{
                if(minMaxLista(head, &min, &max)){ // equivanete a minMax(head,&min,&max) == 1
                    printf("Minimo presente: %d\n", min);
                    printf("Massimo presente: %d\n",max);
                }
                break;
            }
            case 5:{
                head = deleteLista(head);
                break;
            }
        }
        system("PAUSE");
    }while(scelta!=0);
    return(0);
}

// == FUNZIONI ==
Nodo* pushTesta(Nodo *_t, int _val){
    Nodo *tmp;      // puntatore temporaneo al nodo che andrò ad allocare.

    tmp = malloc(sizeof(Nodo)); // alloco un nodo in memoria e l'indirizzo lo assegno a tmp.
    tmp->valore = _val;
    tmp->next = _t;

    return(tmp);
}
void showLista(Nodo *_t){
    Nodo *tmp;
    if(_t == 0){
        printf("Lista vuota.\n");
    }
    else{
        printf("Elementi della lista: ");
        tmp = _t;
        while(tmp != 0){     // (tmp != 0)
            printf("%d ", tmp->valore);
            tmp = tmp->next;
        }
        printf("\n");
    }
}
Nodo* popTesta(Nodo *_t){
    Nodo *tmp;

    if(_t != 0){    // Verifico di avere almeno un nodo da deallocare.
        tmp = _t->next;
        printf("Esce il valore: %d\n", _t->valore);
        free(_t);
        return(tmp);
    }
    else{
        printf("Lista vuota.\n");
        return(0);
    }
}
int contaElementiLista(Nodo *_t){
    Nodo *tmp;
    int cnt;

    tmp = _t;
    cnt = 0;
    while(tmp != 0){
        cnt++;
        tmp = tmp->next;
    }
    return(cnt);
}

int showMenu(){
    srand(time(NULL));
    int scelta;
    do{
        printf("1 -> Genera Lista\n");
        printf("2 -> Vedi la lista\n");
        printf("3 -> Estrai dalla testa\n");
        printf("4 -> Minimo massimo della lista\n");
        printf("5 -> Cancella la lista\n");
        printf("0 -> USCITA\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        fflush(stdin);
    }while(scelta<0 || scelta>5);
    return(scelta);
}
Nodo* generaLista(Nodo *_t){
    int nValori;

    printf("Quanti valori generare: ");
    scanf("%d", &nValori);
    fflush(stdin);
    for(;nValori>0;nValori--){
        _t = pushTesta(_t, (1 + rand()%99));
    }
    return(_t);
}
int minMaxLista(Nodo *_t, int *_min, int *_max){
    int min;
    int max;
    Nodo *tmp;

    tmp = _t;
    if(!tmp){       //equivalente a tmp==0
        printf("Lista vuota...\n");
        *_min = -1;
        *_max = -1;
        return(0);
    }
    else{
        min = tmp->valore;
        max = tmp->valore;
        while(tmp){
            if(tmp->valore < min)
                min = tmp->valore;
            if(tmp->valore > max)
                max = tmp->valore;
            tmp = tmp->next;
        }
        *_min = min;
        *_max = max;
        return(1);
    }
}
Nodo* deleteLista(Nodo *_t){
    while(contaElementiLista(_t) > 0){
        _t = popTesta(_t);
    }
    return(_t);
}