/*
    Esempio di scrittura e lettura di più strutture su un file Binario
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char cognome[20];
    int annoNascita;
}Contatto;

int main(){
    FILE *fpOut;    // per convenzione utilizzo fpOut per SCRIVERE DATI su un file.
    FILE *fpIn;     // per convenzione utilizzo fpIn per LEGGERE DATI da un file.

    Contatto c1, c2, c3;
    Contatto tmp;

    // inizializzo le tre strutture con alcuni valori per prova.
    strcpy(c1.nome, "Alberto");
    strcpy(c1.cognome, "Rossi");
    c1.annoNascita = 1996;

    strcpy(c2.nome, "Mariao");
    strcpy(c2.cognome, "Verdi");
    c2.annoNascita = 1998;

    strcpy(c3.nome, "Luca");
    strcpy(c3.cognome, "Benedetti");
    c3.annoNascita = 1996;

    // scrivo le strutture sul file.
    fpOut = fopen("contatti.dat", "a+b");

    /*
        Scrive un blocco di memoria nel file puntato da fpOut, i parametri sono
        1. indirizzo della struttura contenente i dati.
        2. La dimensione della struttura (sizeof restituisce il numero di byte della struttura).
        3. Quante strutture devono essere scritte.
        4. puntatore al file aperto in scrittura oppure in aggiunta. 
    */
    fwrite(&c1, sizeof(Contatto), 1, fpOut);
    fwrite(&c2, sizeof(Contatto), 1, fpOut);
    fwrite(&c3, sizeof(Contatto), 1, fpOut);

    // FONDAMENTALE chiudere lo stream al file una volta finite le operazioni di scrittura/lettura.
    fclose(fpOut);

    // Apro il file in lettura quindi con un ciclo iterativo leggo una struttura alla volta
    // e ne stampo il contenuto a video.
    fpIn = fopen("contatti.dat", "rb");
    fread(&tmp, sizeof(Contatto), 1, fpIn);
    while(!feof(fpIn)){
        printf("%s %s %d\n", tmp.cognome, tmp.nome, tmp.annoNascita);
        fread(&tmp, sizeof(Contatto), 1, fpIn);
    }
    fclose(fpIn);

    return(0);
}
/*
MODI DI APERTURA FILE
- w: Write (se il file non esiste lo crea, se esiste lo distrugge come nuovo)
- a: Append (apre il file in aggiunta, il nuovo contenuto viene inserito alla fine del file esistente)
- a+: Append  and Read apro un file in aggiunta ma posso anche leggere (spostando il puntatore)
- r: Read apre un file in sola lettura.
- r+: Apertura file in Lettura e Scrittura.

NB i modi seguiti da 't' oppure 'b' indicano Text oppure Binary
wt write in text.
wb write in binary.
*/