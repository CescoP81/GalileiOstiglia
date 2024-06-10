#include <stdio.h>

void numeriPari(int _num);
void vediDivisori(int _num);

int main(){
    int numUtente;

    // inserimento controllato del numero iniziale scelto dall'utente.
    do{
        printf("Inserisci numero(10-30): ");
        scanf("%d", &numUtente);
        fflush(stdin);
    }while(numUtente<10 || numUtente>30);

    numeriPari(numUtente);

    return(0);
}

void numeriPari(int _num){
    int i;
    for(i=_num; i<=50; i++){
        if(i%2 == 0){
            printf("Numero pari: %d\n", i);
            printf("Divisori: ");
            vediDivisori(i);
            printf("\n");
        }
    }
}

void vediDivisori(int _num){
    int i;
    // ciclo per i che passa tutti i numeri da 1 al numero passato come parametro.
    for(i=1; i<=_num; i++){
        if(_num%i == 0)     // se la i divide perfettamente _num allora è un divisore e lo stampo.
            printf("%d ", i);
    }
}