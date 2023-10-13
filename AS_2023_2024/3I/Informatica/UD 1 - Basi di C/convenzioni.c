/* -- Ogni listato C deve iniziare con un commento riportando le informazioni di seguito

    Author:     Cognome Nome
    Date:       gg/mm/aa
    Filename:   filename.c
    Desc:       Short description about the code.
*/
#include <stdio.h> // seguita da altre librerie se necessarie.

/* Parte riservata alle costanti, il nome delle costanti sempre in maiuscolo
    e se formate da più parole divise da underscore */
const int FATTORE=3;
const float PI_GRECO=3.14;

/* Parte riservata al MAIN program*/
int main(){
    // sezione iniziale di dichiarazione variabili
    int x;
    int y;
    int z;

    // esempio di indentazione if-else semplice
    if(x > y){
        x = x * 2;
    }
    else{
        x = x / 2;
    }

    // esempio di indentazione if-else innestati
    if(x > y){
        if(x > z){
            x = x + y;
        }
        else{
            x = x - z;
        }
    }
    else{
        x = y + z;
    }
    return(0);
}