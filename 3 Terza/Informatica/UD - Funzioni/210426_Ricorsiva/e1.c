#include <conio.h>
#include <stdio.h>

int esponenziale(int _num, int _exp);
int fattoriale(int _num);

int main(){
    int num, exp;
    int ris;

    printf("Numero: ");
    scanf("%d", &num);
    fflush(stdin);
    printf("Esponente: ");
    scanf("%d", &exp);
    fflush(stdin);

    printf("\n\n");

    ris = esponenziale(num, exp);
    printf("Risultato potenza: %d", ris);

    printf("\n\n");

    printf("Numero: ");
    scanf("%d", &num);
    fflush(stdin);

    ris = fattoriale(num);
    printf("Risultato fattoriale: %d", ris);
    
    return(0);
}

int esponenziale(int _num, int _exp){
    if(_exp == 0){
        return(1);
    }
    if(_exp > 1){
        return(_num * esponenziale(_num, _exp-1));
    }
    else
        return(_num);
}

int fattoriale(int _num){
    if(_num>0)
        return(_num * fattoriale(_num-1));
    else
        return(1);
}