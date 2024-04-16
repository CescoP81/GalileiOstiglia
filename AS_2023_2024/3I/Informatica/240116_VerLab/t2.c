#include <stdio.h>
#include <math.h>

/**
 * Visualizza il menu operativo
 * @return Valore scelto e controllato, dell'utente.
*/
int menu();
/**
 * Calcola la divisione A:B per sottrazioni successive, stampa il quoziente ed il relativo resto.
 * @param int Valore del dividendo.
 * @param int Valore del divisore.
*/
void divisioneSottrazioniSuccessive(int _a, int _b);
/**
 * Converte un numero da base 10 a base 8, il numero stampato deve essere letto da destra verso sinistra.
 * @param int Numero in base 10 da convertire.
*/
void convertiBase8(int _v);
/**
 * Calcola l'area del cerchio o del quadrato, la scelta controllata viene effettuata nel case del main.
 * @param int Misura da utilizzare come lato o come diametro.
 * @param int Figura scelta, 0 per cerchio 1 per quadrato.
*/
void areaCerchioQuadrato(int _m, int _f);
/**
 * Determina la cifra maggiore presente nel numero passato come parametro.
 * @param int Numero di cui calcolare la somma delle cifre.
*/
void cifraMaggiore(int _v);

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
                divisioneSottrazioniSuccessive(a, b);
                break;
            }
            case 2:{
                printf("Inserire valore da convertire: ");
                scanf("%d", &valoreDecimale);
                fflush(stdin);
                convertiBase8(valoreDecimale);
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
                cifraMaggiore(valoreDecimale);
                break;
            }
        }
    }while(scelta != 0);
    return(0);
}

int menu(){
    int scelta;
    do{
        printf("1-> Divisione sottrazioni successive.\n");
        printf("2-> Converti Base 8.\n");
        printf("3-> Area Cerchio o Quadrato.\n");
        printf("4-> Cifra Maggiore.\n");
        printf("0-> USCITA.\n");
        printf("scelta: ");
        scanf("%d", &scelta);
        fflush(stdin);
    }while(scelta<0 || scelta>4);
    return(scelta);
}
void divisioneSottrazioniSuccessive(int _a, int _b){
    int quoziente = 0;
    
    printf("%d:%d = ", _a, _b);
    while(_a >= _b){
        quoziente = quoziente + 1;
        _a = _a - _b;
    }
    printf("Quoziente: %d con resto %d", quoziente, _a);
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
void convertiBase8(int _v){
    int resto;
    if(_v <= pow(16,3)){
        printf("Valore ottale (leggerlo da destra verso sinistra): ");
        while(_v>0){
            resto = _v%8;

            if(resto>=0 && resto<=9)
                printf("%d", resto);
            
            _v = _v / 8;
        }
    }
    else{
        printf("Valore troppo grande per tre cifre ottali.");
    }
    printf("\n\n");
}
void cifraMaggiore(int _v){
    int maggiore;

    maggiore = 0;
    while(_v > 0){
        if(_v%10 > maggiore)
            maggiore = _v%10;
        _v = _v / 10;
    }
    printf("SLa cifra maggiore e': %d\n\n", maggiore);
}
