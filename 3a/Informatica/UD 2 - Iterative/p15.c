#include <stdio.h>

int main(){
    int div;
    int num;

    printf("Inserisci un numero: ");
    scanf("%d", &num);
    fflush(stdin);
    
    div = 2;
    while(num>1){
        if(num%div == 0){
            printf("%d ", div);
            num = num / div;
        }
        else
            div = div + 1;
    }
    return(0);
}