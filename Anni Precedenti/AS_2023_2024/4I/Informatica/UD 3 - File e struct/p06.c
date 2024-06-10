/*
    Realizzare un file "valori.txt" con all'interno 20 valori casuali interi compresi tra 10 e 25,
    i valori devono essere scritti a mano nel file. Realizzare quindi un programma che aperto il file in lettura:
- [x] Visualizza a video tutti i valori presenti nel file.
- [x] Determina e comunica a video il valore maggiore e minore.
- [x] Determina la media dei valori presenti.
- [x] Visualizza a video tutti i valori superiori alla media e in una riga successiva tutti i valori inferiori alla media.
- [x] Richiede da tastiera un valore compreso tra 10 e 25 quindi salva in un secondo file "numeri2.txt" solo
        i valori maggiori o uguali al valore inserito, presenti nel file iniziale. 
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Visualizza tutti i valori presenti nel file passato
 * @param char* Nome del file da esaminare
*/
void showAllValues(char*);
/**
 * Determina il valore minore e maggiore presente nel file passato
 * @param char* Nome del file da esaminare
*/
void minMaxValue(char*);
/**
 * Calcola e ritorna la media dei valori presenti nel file passato
 * @param char* Nome del file da esaminare
 * @return Valore medio
*/
float avgValue(char*);
/**
 * Crea due righe distinte contenenti i valori superiori ed inferiori alla media generale.
 * @param char* Nome del file da esaminare
*/
void valuesLowerUpperAvg(char*);
/**
 * Crea un secondo file contenente solamente i valori superiori o uguali al valore passato.
 * @param char* Nome del file da esaminare
*/
void valuesUpperThan(char*, int);

int main(){
    int value;

    showAllValues("valori.txt");
    minMaxValue("valori.txt");
    printf("\nMedia dei valori: %.2f\n\n", avgValue("valori.txt"));
    valuesLowerUpperAvg("valori.txt");
    printf("\n\n");
    do{
        printf("Inserisci un valore tra 10 e 25: ");
        scanf("%d", &value);
        fflush(stdin);
    }while(value<10 || value>25);
    valuesUpperThan("valori.txt", value);

    return(0);
}

void showAllValues(char *_filename){
    FILE *fpin;
    int val;

    fpin = fopen(_filename, "rt");
    while(!feof(fpin)){
        fscanf(fpin, "%d", &val);
        printf("%d ", val);
    }
    fclose(fpin);
}
void minMaxValue(char *_filename){
    FILE *fpin;
    int val, min, max;

    fpin = fopen(_filename, "rt");
    fscanf(fpin, "%d", &val);
    min = val;
    max = val;
    while(!feof(fpin)){
        fscanf(fpin, "%d", &val);
        if(val < min)
            min = val;
        if(val > max)
            max = val;
    }
    fclose(fpin);

    printf("\nValore minimo e massimo trovati: %d <-> %d\n", min, max);
}
float avgValue(char *_filename){
    FILE *fpin;
    int val, somma, cnt;

    fpin = fopen(_filename, "rt");
    somma = 0;
    cnt = 0;
    while(!feof(fpin)){
        fscanf(fpin, "%d", &val);
        cnt++;
        somma = somma + val;
    }
    fclose(fpin);
    //printf("\nValori letti: %d", cnt);

    return((float)somma/cnt);
}
void valuesLowerUpperAvg(char *_filename){
    FILE *fpin;
    int val;
    float media;

    media = avgValue(_filename);
    // prima riga valori inferiori alla media
    printf("Valori inferiori alla media: ");
    fpin = fopen(_filename, "rt");
    while(!feof(fpin)){
        fscanf(fpin, "%d", &val);
        if(val < media)
            printf("%d ", val);
    }
    fclose(fpin);
    
    printf("\n");

    // seconda riga valori superiori alla media
    printf("Valori superiori alla media: ");
    fpin = fopen(_filename, "rt");
    while(!feof(fpin)){
        fscanf(fpin, "%d", &val);
        if(val > media)
            printf("%d ", val);
    }
    fclose(fpin);
}
void valuesUpperThan(char *_filename, int _value){
    FILE *fpin, *fpout;
    int val;

    fpin = fopen(_filename, "rt");
    fpout = fopen("valori2.txt", "wt");
    while(!feof(fpin)){
        fscanf(fpin, "%d", &val);
        if(val >= _value)
            fprintf(fpout, "%d ", val);
    }
    fclose(fpin);
    fclose(fpout);
}