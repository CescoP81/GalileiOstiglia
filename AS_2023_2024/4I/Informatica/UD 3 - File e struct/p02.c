/*
    Esercizio di esempio per la lettura di parole da un file.
    Utilizzo la funzione fscanf(..) la quale si comporta come
    la scanf() quindi termina la lettura di una parola quando
    incontra il carattere ' ' spazio, oppure '\n' andata a capo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fpIn; // input da file, lo stream lo intendo dal file al pc.
    char str[20];

    fpIn = fopen("parole.txt", "rt");

    while(!feof(fpIn)){
        // leggo una parola dal file.
        fscanf(fpIn, "%s", &str);
        // stampo la parola letta e messa in str, a video.
        printf("%s\n", str);
    }

    fclose(fpIn);
    return(0);
}