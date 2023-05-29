#include <stdio.h>

int main(){
    int cnt_prodotti;
    int prezzo;
    int prezzo_min;
    int prezzo_max;
    int totale;
    int risposta;
    int prezzo_medio;

    cnt_prodotti = 0;
    totale = 0;
    do{     // ciclo principale, gira finche l'untente intende passare prodotti.
        printf("Inserisci prezzo: ");
        scanf("%d", &prezzo);
        fflush(stdin);
        cnt_prodotti = cnt_prodotti + 1;

        // determino se il prezzo inserito è il nuovo minimo o massimo
        if(cnt_prodotti == 1){
            prezzo_min = prezzo;
            prezzo_max = prezzo;
        }
        else{
            if(prezzo > prezzo_max)
                prezzo_max = prezzo;
            if(prezzo < prezzo_min)
                prezzo_min = prezzo;
        }

        // incremento il totale della spesa.
        totale = totale + prezzo;
        
        // chiedo all'utente se vuole proseguire oppure no.
        printf("Altro prodotto? (1->si/0->no): ");
        scanf("%d", &risposta);
        fflush(stdin);
    }while(risposta == 1);

    // determino il prezzo medio e stampo tutte le informazioni richieste.
    prezzo_medio = totale / cnt_prodotti;
    printf("Totale da pagare: %d\n", totale);
    printf("Prezzo minimo inserito: %d\n", prezzo_min);
    printf("Prezzo massimo inserito: %d\n", prezzo_max);
    printf("Prezzo medio dei prodotti: %d", prezzo_medio);

    return(0);
}