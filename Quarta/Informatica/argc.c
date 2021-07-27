#include <conio.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int i;
    char *s;
    if(argc != 0){
        printf("%d\n", argc);
        for(i=1; i<argc; i++){
            printf("%s - ", argv[i]);
            s = argv[i];
            printf("%c\n", s[0]);
        }
    }
    return(0);
}