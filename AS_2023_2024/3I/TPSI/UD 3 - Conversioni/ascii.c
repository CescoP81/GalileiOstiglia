#include <stdio.h>

int main(){
    int i;
    for(i=1; i<=255; i++){
        printf("%4d: %c", i, i);
        if(i%20 == 0)
            printf("\n");
    }
    return(0);
}