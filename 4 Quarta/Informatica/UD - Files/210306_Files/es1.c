#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define DIM 3

typedef struct{
    char codice[5];
    int valore;
}Misura;


int main(){
    FILE *fpout;    // puntatore ad uno stream su disco fisso/usb, comunque stream a file. Per operazioni di SCRITTURA
    FILE *fpin;     // puntatore ad uno stream su disco fisso/usb, per operazioni di LETTURA.
    Misura vm[DIM];
    int i;

    for(i=0; i<DIM; i++){
        printf("Codice (4 char): ");
        scanf("%s", vm[i].codice);
        fflush(stdin);
        printf("Valore: ");
        scanf("%d", &vm[i].valore);
        fflush(stdin);
    }

    printf("\nElementi inseriti: ");
    for(i=0; i<DIM; i++){
        printf("%s \t %d\n", vm[i].codice, vm[i].valore);
    }

    /* Salvataggio su file dei dati inseriti nel vettore di strutture.
    MODE:
    w -> Write  [SE il file non esiste viene creato, SE esiste viene azzerato]
    a -> Append [SE il file esiste i nuovi dati vengono scritti in aggiunta]
    r -> Read   [SE il file esiste i dati possono essere letti]
    seconda lettera t -> Text / b -> Binary
    */
    fpout = fopen("archivio.bin", "wb");
    for(i=0; i<DIM; i++){
        fwrite(&vm[i], sizeof(Misura), 1, fpout);
    }
    fclose(fpout);

    // Riapro il file in lettura, leggo le strutture e le visualizzo a schermo.
    printf("\n\nStrutture lette da file:\n");
    fpin = fopen("archivio.bin", "rb");

    Misura tmp;
    fread(&tmp, sizeof(Misura), 1, fpin);
    while(!feof(fpin)){ // funzione feof() restituisce true se sono alla fine del file.
        printf("%s \t %d\n", tmp.codice, tmp.valore);
        fread(&tmp, sizeof(Misura), 1, fpin);
    }
    fclose(fpin);

    return(0);
}