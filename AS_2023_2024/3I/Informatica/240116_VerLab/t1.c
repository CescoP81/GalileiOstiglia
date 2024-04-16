#include <stdio.h>
#include <math.h>

/**
 * Visualizza il menu operativo
 * @return Valore scelto e controllato, dell'utente.
*/
int menu();
/**
 * Calcola e stampa il prodott A x B con somme successive.
 * @param int Valore di A
 * @param int Valore di B
*/
void prodottoSommeSuccessive(int _a, int _b);
/**
 * Converte un numero da base 10 a base 16, il numero stampato deve essere letto da destra verso sinistra.
 * @param int Numero in base 10 da convertire.
*/
void convertiBase16(int _v);
/**
 * Calcola l'area del cerchio o del quadrato, la scelta controllata viene effettuata nel case del main.
 * @param int Misura da utilizzare come lato o come diametro.
 * @param int Figura scelta, 0 per cerchio 1 per quadrato.
*/
void areaCerchioQuadrato(int _m, int _f);
/**
 * Calcola la somma delle cifre che compongono il numero passato come parametro.
 * @param int Numero di cui calcolare la somma delle cifre.
*/
void sommaCifre(int _v);

int main(){
    int scelta;
    int a, b;
    int valoreDecimale;
    int misura, figura;

    do{
        scelta = menu();
        switch(scelta){
            case 1:{
                printf("Inserisci a: ");
                scanf("%d", &a);
                fflush(stdin);
                printf("Inserisci b: ");
                scanf("%d", &b);
                fflush(stdin);
                prodottoSommeSuccessive(a, b);
                break;
            }
            case 2:{
                printf("Inserire valore da convertire: ");
                scanf("%d", &valoreDecimale);
                fflush(stdin);
                convertiBase16(valoreDecimale);
                break;
            }
            case 3:{
                printf("Inserisci una misura: ");
                scanf("%d", &misura);
                fflush(stdin);
                do{
                    printf("0-> Cerchio\n");
                    printf("1-> Quadrato\n");
                    printf("Figura: ");
                    scanf("%d", &figura);
                    fflush(stdin);
                }while(figura<0 || figura>1);
                areaCerchioQuadrato(misura, figura);
                break;
            }
            case 4:{
                do{
                    printf("Inserisci un valore (1-9999): ");
                    scanf("%d", &valoreDecimale);
                    fflush(stdin);
                }while(valoreDecimale<1 || valoreDecimale>9999);
                sommaCifre(valoreDecimale);
                break;
            }
        }
    }while(scelta != 0);
    return(0);
}

int menu(){
    int scelta;
    do{
        printf("1-> Prodotto Somme Successive.\n");
        printf("2-> Converti Base 16.\n");
        printf("3-> Area Cerchio o Quadrato.\n");
        printf("4-> Somma cifre.\n");
        printf("0-> USCITA.\n");
        printf("scelta: ");
        scanf("%d", &scelta);
        fflush(stdin);
    }while(scelta<0 || scelta>4);
    return(scelta);
}
void prodottoSommeSuccessive(int _a, int _b){
    int prodotto;
    prodotto = 0;
    while(_b > 0){
        prodotto = prodotto + _a;
        _b = _b - 1;
    }
    printf("\nIl prodotto calcolato e': %d\n\n", prodotto);
}
void convertiBase16(int _v){
    int resto;
    if(_v <= pow(16,3)){
        printf("Valore esadecimale (leggerlo da destra verso sinistra): ");
        while(_v>0){
            resto = _v%16;

            if(resto>=0 && resto<=9)
                printf("%d", resto);
            if(resto == 10)
                printf("A");
            if(resto == 11)
                printf("B");
            if(resto == 12)
                printf("C");
            if(resto == 13)
                printf("D");
            if(resto == 14)
                printf("E");
            if(resto == 15)
                printf("F");
            
            _v = _v / 16;
        }
    }else{
        printf("Valore troppo grande per tre cifre esadecimali");
    }
    printf("\n\n");
}
void areaCerchioQuadrato(int _m, int _f){
    float area;
    if(_f == 0){
        area = 3.14 * _m * _m;
        printf("Area del cerchio: %.2f\n", area);    
    }
    if(_f == 1){
        area = _m * _m;
        printf("Area del quadrato: %.2f\n", area);
    }
    printf("\n");
}
void sommaCifre(int _v){
    int somma;

    somma = 0;
    while(_v > 0){
        somma = somma + (_v % 10);
        _v = _v / 10;
    }
    printf("Somma delle cifre: %d\n\n", somma);
}