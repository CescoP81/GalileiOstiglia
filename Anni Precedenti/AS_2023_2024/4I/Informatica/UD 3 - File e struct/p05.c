/*
Creare un file di testo "parole.txt" contenente alcune parole di lunghezza
non superiore a 15 caratteri, divise da un "invio" (andata a capo).
L'ultima parola non ha l'invio finale. Il programma apre in lettura
il file e determina:
- [ ] Numero di parole presenti.
- [ ] Lunghezza media delle parole.
- [ ] Stampa a video delle eventuali parole palindrome.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int DIM = 15;

int main(){
    char str[DIM+1];
    FILE *fpIn;
    int cntParole;
    int totaleLettere;
    int i, palindroma;

    fpIn = fopen("parole.txt", "rt");
    cntParole = 0;
    totaleLettere = 0;
    // leggo una parola dal file.
    fscanf(fpIn, "%s", &str);
    while(!feof(fpIn)){
        cntParole++;                    // aumento il contatore parole lette
        totaleLettere = totaleLettere + strlen(str); //aggiungo il num di lettere.

        palindroma = 1;
        for(i=0; i<strlen(str)/2; i++){
            if(str[i] != str[(strlen(str)-i-1)])
                palindroma = 0;
        }
        if(palindroma == 1){
            printf("La parola %s e' palindroma\n", str);
        }
        // lettura della parola successiva.
        fscanf(fpIn, "%s", &str);
    }

    printf("\n\nTotale parole: %d\n", cntParole);
    printf("Lunghezza media: %d\n", totaleLettere/cntParole);

    return(0);
}
