#include <conio.h>
#include <stdio.h>

typedef struct{
    char autore[20];
}Libro;

int main(){
    Libro l;
    printf("%s", l.autore);
}