#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "Persona.c"

int main(){
    Persona v[3];

    setPersona(&v[0],"Rossi",23);
    setPersona(&v[1],"Bianchi",50);
    setPersona(&v[2],"Verdi",30);

    for(int i=0; i<3; i++){
        stampaPersona(&v[i]);
    }
    return(0);
}