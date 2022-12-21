/* Abstract 1
Realizzare un programma C che richiede due valori da tastiera rispettivamente val1 e val2 che rispettino questi criteri:
val1 maggiore di 0 e minore di 10; val2 maggiore di val1 e minore di 50; quindi esegue le seguenti operazioni:
    A) Visualizza tutti i numeri pari tra val1 e val2 estremi compresi.
    B) Visualizza tutti i divisori di val1 che dividono anche val2.
    C) Visualizza le tabelline da 1 a val1 compreso.
    D) Verifica si val2 è primo oppure no.
    E) Richiede val3 accettando il valore solo se è compreso tra val1 e val2.
    F) Scompone il val3 in singole cifre visualizzandole una sotto l’altra e la loro media.
*/
#include <stdio.h>

int main(){
    int val1, val2, val3;         // variabili per i valori da richiedere da tastiera
    int cnt;
    int div;
    int riga, colonna;
    int resto;
    int somma;
    
    // FASE DI INPUT VALORI DUE CICLI SEPARATI PER VAL1 e VAL1
    do{
        printf("Inserisci val1: ");
        scanf("%d", &val1);
        fflush(stdin);
    }while(val1<=0 || val1>=10);

    do{
        printf("Inserisci val2: ");
        scanf("%d", &val2);
        fflush(stdin);
    }while(val2<val1 || val2>=50);

    // PUNTO A
    cnt = val1;
    while(cnt <= val2){
        if(cnt%2 == 0)
            printf("%d ", cnt);
        cnt = cnt + 1;
    }
    printf("\n\n");

    // PUNTO B
    div = 1;
    while(div <= val1){
        if((val1%div == 0) && (val2%div == 0)){
            printf("%d ", div);
        }
        div = div + 1;
    }
    printf("\n\n");

    // PUNTO C
    riga = 1;
    while(riga <= val1){
        colonna = 1;
        while(colonna <= val1){
            printf("%d ", (riga*colonna));
            colonna = colonna + 1;
        }
        printf("\n");
        riga = riga + 1;
    }
    printf("\n\n");

    // PUNTO D
    div = 1;
    cnt = 0;
    while(div <= val1){
        if(val1%div == 0)
            cnt = cnt + 1;
        div = div + 1;
    }
    if(cnt <= 2)
        printf("Val1 e' primo.");
    else
        printf("Val1 non e' primo");
    printf("\n\n");

    // PUNTO E
    do{
        printf("Inserisci val3: ");
        scanf("%d", &val3);
        fflush(stdin);
    }while(val3<val1 || val3>val2);
    printf("Valore accettato: %d", val3);
    printf("\n\n");

    // PUNTO E
    somma = 0;
    cnt = 0;
    while(val3>0){
        resto = val3 % 10;
        somma = somma + resto;
        cnt = cnt + 1;
        printf("%d\n", resto);
        val3 = val3 / 10;
    }
    printf("Media: %.2f", (float)somma/cnt);
    return(0);
}