#include <stdio.h>

// prototipo della funzione, verrà sviluppata sotto al main.
void funz(int);

int sommaValori(int,int);

int main(){
    int a = 6;
    printf("%d\n", &a);
    funz(a);
    printf("\n%d", a);

    a = sommaValori(4, 9);
    printf("\n%d", a);
    return(0);
}

// definsico la funzione con il suo codice.
int sommaValori(int op1, int op2){
    int risultato;
    risultato = op1 + op2;
    return(risultato);
}

void funz(int a){
    printf("%d\n", &a);
    printf("%d", a);
    a = a*2;
}