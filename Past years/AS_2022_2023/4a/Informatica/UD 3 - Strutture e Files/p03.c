/*
Realizzare un programma che gestendo una struttura Prodotto(nome, prezzo, sconto)
permetta di aggiungere prodotto ad un file binario catalogo.bin,
leggere e stampare a video l'intero catalogo,
ricercare un prodotto per nome, oppure per fascia di prezzo nel catalogo.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char nome[20];
    float prezzo;
    int sconto;
}Prodotto;



void initProdotto(Prodotto*);
void writeFile(Prodotto, char[]);
void listaProdotti(char[]);

int main(){
    Prodotto x;
    char filename[] = "catalogo.bin";

    // eseguo tre inserimenti fittizzi
    /*initProdotto(&x);
    writeFile(x, filename);
    initProdotto(&x);
    writeFile(x, filename);
    initProdotto(&x);
    writeFile(x, filename);*/
    listaProdotti(filename);
    return(0);
}

void initProdotto(Prodotto *_p){
    printf("Inserisci Nome: ");
    scanf("%s", (*_p).nome);
    fflush(stdin);
    printf("Inserisci prezzo: ");
    scanf("%f", &(*_p).prezzo);
    fflush(stdin);
    printf("Inserisci sconto: ");
    scanf("%d", &(*_p).sconto);
    fflush(stdin);
}

void writeFile(Prodotto _p, char _filename[]){
    FILE *fpOut = fopen(_filename, "a+");
    fwrite(&_p, sizeof(Prodotto), 1, fpOut);
    fclose(fpOut);
}

void listaProdotti(char _filename[]){
    Prodotto y;
    FILE *fpIn = fopen(_filename, "r");
    int n;   
    
    while(!feof(fpIn)){
        n = fread(&y, sizeof(Prodotto), 1, fpIn);
        printf("%d -> ", n);
        if(n > 0)
            printf("%s %.2f %d\n", y.nome, y.prezzo, y.sconto);
        //fread(&y, sizeof(Prodotto), 1, fpIn);
    }
    fclose(fpIn);
}