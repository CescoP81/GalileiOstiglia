/* Abstract 2
Realizzare un programma C che richiede due valori da tastiera rispettivamente val1 e val2 che rispettino questi criteri:
val1 maggiore di 5 e minore di 15; val2 maggiore di val1 e minore di 50; quindi esegue le seguenti operazioni:
    A) Visualizza tutti i numeri dispari tra val2 e val1 estremi compresi.
    B) Visualizza tutti i divisori di val2 che non dividono anche val1.
    C) Visualizza le tabelline da val1 a 15 compreso.
    D) Verifica si val2 è perfetto oppure no.
    E) Richiede val3 accettando il valore solo se è multiplo di val1.
    F) Scompone il val3 in singole cifre visualizzandole una sotto l’altra e la loro somma totale.
*/
#include <stdio.h>

int main(){
    int val1, val2, val3;         // variabili per i valori da richiedere da tastiera
    int cnt;
    int div;
    int sommaDiv;
    int riga, colonna;
    int resto;
    int totale;
    
    // FASE DI INPUT VALORI DUE CICLI SEPARATI PER VAL1 e VAL1
    do{
        printf("Inserisci val1: ");
        scanf("%d", &val1);
        fflush(stdin);
    }while(val1<=5 || val1>=15);

    do{
        printf("Inserisci val2: ");
        scanf("%d", &val2);
        fflush(stdin);
    }while(val2<val1 || val2>=50);

    // PUNTO A
    cnt = val1;
    while(cnt <= val2){
        if(cnt%2 != 0) // oppure ==1
            printf("%d ", cnt);
        cnt = cnt + 1;
    }
    printf("\n\n");

    // PUNTO B
    div = 1;
    while(div <= val2){
        if((val2%div == 0) && (val1%div != 0)){
            printf("%d ", div);
        }
        div = div + 1;
    }
    printf("\n\n");

    // PUNTO C
    riga = val1;
    while(riga <= 15){
        colonna = 1;
        while(colonna <= 15){
            printf("%d ", (riga*colonna));
            colonna = colonna + 1;
        }
        printf("\n");
        riga = riga + 1;
    }
    printf("\n\n");

    // PUNTO D
    div = 1;
    sommaDiv = 0;
    while(div < val2){
        if(val1%div == 0)
            sommaDiv = sommaDiv + div;
        div = div + 1;
    }
    if(sommaDiv == val2)
        printf("Val2 e' perfetto.");
    else
        printf("Val2 non e' perfetto");
    printf("\n\n");

    // PUNTO E
    do{
        printf("Inserisci val3: ");
        scanf("%d", &val3);
        fflush(stdin);
    }while(val3%val1 != 0);
    printf("Valore accettato: %d", val3);
    printf("\n\n");

    // PUNTO E
    totale = 0;
    while(val3>0){
        resto = val3 % 10;
        totale = totale + resto;
        printf("%d\n", resto);
        val3 = val3 / 10;
    }
    printf("Totale: %d", totale);
    return(0);
}